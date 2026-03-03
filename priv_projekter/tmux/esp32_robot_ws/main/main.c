#include <stdio.h>
#include "nvs_flash.h"
#include "wifi_cmd.h"
#include "webserver.h"
#include "joystick.h"

void app_main(void)
{
    // Init NVS for WiFi credentials and general storage.
    esp_err_t ret = nvs_flash_init();
    if (ret == ESP_ERR_NVS_NO_FREE_PAGES || ret == ESP_ERR_NVS_NEW_VERSION_FOUND) {
        nvs_flash_erase();
        nvs_flash_init();
    }

    // Start WiFi SoftAP + UDP listener for joystick commands.
    wifi_cmd_start();
    webserver_start();
}
