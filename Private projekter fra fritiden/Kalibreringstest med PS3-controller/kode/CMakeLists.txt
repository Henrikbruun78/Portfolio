cmake_minimum_required(VERSION 3.16)

include($ENV{IDF_PATH}/tools/cmake/project.cmake)
project(ESP32_ROBOT_WS)

# Build a SPIFFS image from the files under spiffs/ and bundle it for flashing
spiffs_create_partition_image(storage spiffs FLASH_IN_PROJECT)
