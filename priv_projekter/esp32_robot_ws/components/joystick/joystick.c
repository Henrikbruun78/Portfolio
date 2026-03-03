#include <stdio.h>
#include <stdbool.h>
#include "driver/gpio.h"
#include "joystick.h"
#include "webserver.h"

// GPIOs driving LEDs for direction indication; adjust to match your wiring.
#define LED_FWD_GPIO   4
#define LED_BACK_GPIO  5
#define LED_LEFT_GPIO  6
#define LED_RIGHT_GPIO 7

static bool s_leds_inited = false;

static void leds_init_once(void) {
    if (s_leds_inited) return;
    const gpio_num_t pins[] = {
        LED_FWD_GPIO, LED_BACK_GPIO, LED_LEFT_GPIO, LED_RIGHT_GPIO,
    };
    for (size_t i = 0; i < sizeof(pins) / sizeof(pins[0]); i++) {
        gpio_reset_pin(pins[i]);
        gpio_set_direction(pins[i], GPIO_MODE_OUTPUT);
        gpio_set_level(pins[i], 0);
    }
    s_leds_inited = true;
}

static void leds_apply_dir(joystick_dir_t dir) {
    leds_init_once();
    bool fwd = false, back = false, left = false, right = false;
    switch (dir) {
    case JOY_DIR_UP: fwd = true; break;
    case JOY_DIR_DOWN: back = true; break;
    case JOY_DIR_LEFT: left = true; break;
    case JOY_DIR_RIGHT: right = true; break;
    case JOY_DIR_UP_LEFT: fwd = true; left = true; break;
    case JOY_DIR_UP_RIGHT: fwd = true; right = true; break;
    case JOY_DIR_DOWN_LEFT: back = true; left = true; break;
    case JOY_DIR_DOWN_RIGHT: back = true; right = true; break;
    case JOY_DIR_STOP:
    default: break;
    }
    gpio_set_level(LED_FWD_GPIO, fwd);
    gpio_set_level(LED_BACK_GPIO, back);
    gpio_set_level(LED_LEFT_GPIO, left);
    gpio_set_level(LED_RIGHT_GPIO, right);
}

const char *joystick_dir_to_str(joystick_dir_t dir) {
    switch (dir) {
    case JOY_DIR_UP: return "up";
    case JOY_DIR_DOWN: return "down";
    case JOY_DIR_LEFT: return "left";
    case JOY_DIR_RIGHT: return "right";
    case JOY_DIR_UP_LEFT: return "up_left";
    case JOY_DIR_UP_RIGHT: return "up_right";
    case JOY_DIR_DOWN_LEFT: return "down_left";
    case JOY_DIR_DOWN_RIGHT: return "down_right";
    case JOY_DIR_STOP:
    default: return "stop";
    }
}

void joystick_handle_command(joystick_dir_t dir, float speed, const char *raw_json) {
    // Stub: replace with motors_apply_direction later.
    printf("[joystick] dir=%s speed=%.3f raw=%s\n",
           joystick_dir_to_str(dir), speed, raw_json ? raw_json : "{}");
    leds_apply_dir(dir);
    webserver_send(joystick_dir_to_str(dir), speed);
}
