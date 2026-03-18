#include <arpa/inet.h>
#include <errno.h>
#include <fcntl.h>
#include <linux/joystick.h>
#include <math.h>
#include <netinet/in.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define DEFAULT_IP "192.168.1.55"
#define DEFAULT_PORT 3333
#define DEFAULT_DEV "/dev/input/js0"
#define DEFAULT_DEADZONE 0.10

static double clamp(double v, double lo, double hi) {
    return v < lo ? lo : (v > hi ? hi : v);
}

static double norm_axis(int16_t raw) {
    return clamp((double)raw / 32767.0, -1.0, 1.0);
}

// Map normalized X/Y into a 9-way direction + speed (0..1).
static void dir_speed_from_axes(double x, double y, double deadzone,
                                const char **dir_out, double *speed_out) {
    double mag = hypot(x, y);
    if (mag < deadzone) {
        *dir_out = "stop";
        *speed_out = 0.0;
        return;
    }

    double ang_deg = atan2(-y, x) * (180.0 / M_PI); // up is -Y
    double a = fmod(ang_deg + 360.0, 360.0);
    struct sector {
        const char *name;
        double lo, hi;
    } sectors[] = {
        {"right", 337.5, 382.5}, {"right", -22.5, 22.5},
        {"up_right", 22.5, 67.5}, {"up", 67.5, 112.5},
        {"up_left", 112.5, 157.5}, {"left", 157.5, 202.5},
        {"down_left", 202.5, 247.5}, {"down", 247.5, 292.5},
        {"down_right", 292.5, 337.5},
    };
    for (size_t i = 0; i < sizeof(sectors) / sizeof(sectors[0]); i++) {
        if (a >= sectors[i].lo && a < sectors[i].hi) {
            *dir_out = sectors[i].name;
            *speed_out = clamp(mag, 0.0, 1.0);
            return;
        }
    }
    *dir_out = "stop";
    *speed_out = 0.0;
}

static void usage(const char *prog) {
    fprintf(stderr,
            "Usage: %s [--ip <addr>] [--port <num>] [--dev <path>] [--deadzone <0-1>] [--verbose]\n"
            "Defaults: ip=%s port=%d dev=%s deadzone=%.2f\n",
            prog, DEFAULT_IP, DEFAULT_PORT, DEFAULT_DEV, DEFAULT_DEADZONE);
}

int main(int argc, char **argv) {
    const char *ip = DEFAULT_IP;
    const char *dev = DEFAULT_DEV;
    int port = DEFAULT_PORT;
    double deadzone = DEFAULT_DEADZONE;
    bool verbose = false;

    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], "--ip") == 0 && i + 1 < argc) {
            ip = argv[++i];
        } else if (strcmp(argv[i], "--port") == 0 && i + 1 < argc) {
            port = atoi(argv[++i]);
        } else if (strcmp(argv[i], "--dev") == 0 && i + 1 < argc) {
            dev = argv[++i];
        } else if (strcmp(argv[i], "--deadzone") == 0 && i + 1 < argc) {
            deadzone = atof(argv[++i]);
        } else if (strcmp(argv[i], "--verbose") == 0) {
            verbose = true;
        } else {
            usage(argv[0]);
            return 1;
        }
    }

    int js_fd = open(dev, O_RDONLY);
    if (js_fd < 0) {
        perror("open joystick");
        return 1;
    }

    int sock = socket(AF_INET, SOCK_DGRAM, 0);
    if (sock < 0) {
        perror("socket");
        close(js_fd);
        return 1;
    }

    struct sockaddr_in dest = {
        .sin_family = AF_INET,
        .sin_port = htons((uint16_t)port),
    };
    if (inet_pton(AF_INET, ip, &dest.sin_addr) != 1) {
        fprintf(stderr, "Invalid IP: %s\n", ip);
        close(sock);
        close(js_fd);
        return 1;
    }

    printf("Streaming %s -> %s:%d (deadzone=%.2f)\n", dev, ip, port, deadzone);

    double lx = 0.0, ly = 0.0;
    struct js_event e;
    while (1) {
        ssize_t n = read(js_fd, &e, sizeof(e));
        if (n == -1) {
            if (errno == EINTR) continue;
            perror("read");
            break;
        }
        if (n != sizeof(e)) {
            fprintf(stderr, "short read (%zd), exiting\n", n);
            break;
        }

        if (e.type & JS_EVENT_INIT) e.type &= ~JS_EVENT_INIT;
        if (e.type != JS_EVENT_AXIS) continue;

        if (e.number == 0) {
            lx = norm_axis(e.value);
        } else if (e.number == 1) {
            ly = norm_axis(e.value);
        } else {
            continue;
        }

        const char *dir = "stop";
        double speed = 0.0;
        dir_speed_from_axes(lx, ly, deadzone, &dir, &speed);

        char msg[64];
        int len = snprintf(msg, sizeof(msg), "{\"dir\":\"%s\",\"speed\":%.3f}", dir, speed);
        if (len <= 0 || len >= (int)sizeof(msg)) continue;

        if (sendto(sock, msg, (size_t)len, 0, (struct sockaddr *)&dest, sizeof(dest)) < 0) {
            perror("sendto");
            break;
        }
        if (verbose) printf("sent %s\n", msg);
    }

    close(sock);
    close(js_fd);
    return 0;
}
