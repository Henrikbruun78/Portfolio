#pragma once

// Start SPIFFS + HTTP server with websocket endpoint.
void webserver_start(void);

// Push joystick updates to connected websocket client (dir string + speed 0-1).
void webserver_send(const char *dir_str, float speed);
