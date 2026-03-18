idf_component_register(
    SRCS "main.c"
    INCLUDE_DIRS "."
    REQUIRES freertos driver nvs_flash joystick wifi_cmd webserver
)
