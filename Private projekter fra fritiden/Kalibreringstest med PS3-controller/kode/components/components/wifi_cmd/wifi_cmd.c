#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_wifi.h"
#include "esp_event.h"
#include "esp_netif.h"
#include "nvs_flash.h"
#include "lwip/sockets.h"
#include "lwip/inet.h"
#include "joystick.h"

#define WIFI_SSID ""
#define WIFI_PASS ""
#define WIFI_CHANNEL 1
#define WIFI_MAX_CONN 4
#define UDP_PORT 3333
#define RX_BUF_SIZE 256

static joystick_dir_t parse_dir(const char *json);
static float parse_speed(const char *json);
static void udp_task(void *arg);
static void ip_event_handler(void *arg, esp_event_base_t base, int32_t id, void *data);

void wifi_cmd_start(void) {
    // Assumes nvs_flash_init already called in app_main.
    ESP_ERROR_CHECK(esp_netif_init());
    ESP_ERROR_CHECK(esp_event_loop_create_default());
    ESP_ERROR_CHECK(esp_event_handler_instance_register(IP_EVENT,
                                                        IP_EVENT_STA_GOT_IP,
                                                        ip_event_handler,
                                                        NULL,
                                                        NULL));

    esp_netif_create_default_wifi_sta();

    wifi_init_config_t cfg = WIFI_INIT_CONFIG_DEFAULT();
    ESP_ERROR_CHECK(esp_wifi_init(&cfg));

    wifi_config_t sta_cfg = {
        .sta = {
            .ssid = WIFI_SSID,
            .password = WIFI_PASS,
            .threshold.authmode = WIFI_AUTH_WPA2_PSK,
            .sae_pwe_h2e = WPA3_SAE_PWE_BOTH,
        },
    };

    ESP_ERROR_CHECK(esp_wifi_set_mode(WIFI_MODE_STA));
    ESP_ERROR_CHECK(esp_wifi_set_config(WIFI_IF_STA, &sta_cfg));
    ESP_ERROR_CHECK(esp_wifi_start());
    ESP_ERROR_CHECK(esp_wifi_connect());

    xTaskCreate(udp_task, "udp_cmd", 4096, NULL, 5, NULL);
    printf("[wifi_cmd] STA connecting to SSID=%s, UDP port=%d (DHCP IP will be logged)\n",
           (const char *)sta_cfg.sta.ssid, UDP_PORT);
}

static void udp_task(void *arg) {
    int sock = socket(AF_INET, SOCK_DGRAM, IPPROTO_IP);
    if (sock < 0) {
        printf("[wifi_cmd] socket failed\n");
        vTaskDelete(NULL);
    }
    struct sockaddr_in addr = {
        .sin_family = AF_INET,
        .sin_port = htons(UDP_PORT),
        .sin_addr.s_addr = htonl(INADDR_ANY),
    };
    if (bind(sock, (struct sockaddr *)&addr, sizeof(addr)) < 0) {
        printf("[wifi_cmd] bind failed\n");
        close(sock);
        vTaskDelete(NULL);
    }

    char rx[RX_BUF_SIZE];
    while (1) {
        int len = recvfrom(sock, rx, sizeof(rx) - 1, 0, NULL, NULL);
        if (len <= 0) continue;
        rx[len] = 0;

        // Debug: show each packet we receive.
        printf("[wifi_cmd] rx len=%d payload=%s\n", len, rx);

        joystick_dir_t dir = parse_dir(rx);
        float speed = parse_speed(rx);
        joystick_handle_command(dir, speed, rx);
    }
}

static int starts_with(const char *s, const char *pfx) {
    return strncmp(s, pfx, strlen(pfx)) == 0;
}

// Very small JSON digger for: {"dir":"up_left","speed":0.5,...}
static joystick_dir_t parse_dir(const char *json) {
    const char *key = "\"dir\"";
    const char *p = strstr(json, key);
    if (!p) return JOY_DIR_STOP;
    p = strchr(p + strlen(key), ':');
    if (!p) return JOY_DIR_STOP;
    p++;
    while (*p == ' ' || *p == '\"') p++;
    if (starts_with(p, "up_left")) return JOY_DIR_UP_LEFT;
    if (starts_with(p, "up_right")) return JOY_DIR_UP_RIGHT;
    if (starts_with(p, "down_left")) return JOY_DIR_DOWN_LEFT;
    if (starts_with(p, "down_right")) return JOY_DIR_DOWN_RIGHT;
    if (starts_with(p, "up")) return JOY_DIR_UP;
    if (starts_with(p, "down")) return JOY_DIR_DOWN;
    if (starts_with(p, "left")) return JOY_DIR_LEFT;
    if (starts_with(p, "right")) return JOY_DIR_RIGHT;
    return JOY_DIR_STOP;
}

static float parse_speed(const char *json) {
    const char *key = "\"speed\"";
    const char *p = strstr(json, key);
    if (!p) return 0.0f;
    p = strchr(p + strlen(key), ':');
    if (!p) return 0.0f;
    p++;
    return strtof(p, NULL);
}

static void ip_event_handler(void *arg, esp_event_base_t base, int32_t id, void *data) {
    (void)arg;
    if (base == IP_EVENT && id == IP_EVENT_STA_GOT_IP) {
        ip_event_got_ip_t *event = (ip_event_got_ip_t *)data;
        printf("[wifi_cmd] Got DHCP IP: " IPSTR "\n", IP2STR(&event->ip_info.ip));
    }
}
