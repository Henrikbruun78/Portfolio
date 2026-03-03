#pragma once

typedef enum {
    JOY_DIR_STOP = 0,
    JOY_DIR_UP,
    JOY_DIR_DOWN,
    JOY_DIR_LEFT,
    JOY_DIR_RIGHT,
    JOY_DIR_UP_LEFT,
    JOY_DIR_UP_RIGHT,
    JOY_DIR_DOWN_LEFT,
    JOY_DIR_DOWN_RIGHT
} joystick_dir_t;

const char *joystick_dir_to_str(joystick_dir_t dir);
void joystick_handle_command(joystick_dir_t dir, float speed, const char *raw_json);
