#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "esp_http_server.h"
#include "esp_log.h"
#include "esp_spiffs.h"
#include "webserver.h"

#define TAG "webserver"
#define WS_URI "/ws"

static httpd_handle_t s_server = NULL;
static int s_ws_fd = -1;

static const char *mime_type_from_path(const char *path) {
    const char *ext = strrchr(path, '.');
    if (!ext) return "text/plain";
    if (strcmp(ext, ".html") == 0) return "text/html";
    if (strcmp(ext, ".css") == 0) return "text/css";
    if (strcmp(ext, ".js") == 0) return "application/javascript";
    if (strcmp(ext, ".png") == 0) return "image/png";
    if (strcmp(ext, ".ico") == 0) return "image/x-icon";
    return "text/plain";
}

static esp_err_t send_file(httpd_req_t *req, const char *path) {
    FILE *f = fopen(path, "r");
    if (!f) {
        httpd_resp_send_err(req, HTTPD_404_NOT_FOUND, "File not found");
        return ESP_FAIL;
    }

    httpd_resp_set_type(req, mime_type_from_path(path));
    char buf[512];
    size_t n;
    while ((n = fread(buf, 1, sizeof(buf), f)) > 0) {
        if (httpd_resp_send_chunk(req, buf, n) != ESP_OK) {
            fclose(f);
            return ESP_FAIL;
        }
    }
    fclose(f);
    httpd_resp_send_chunk(req, NULL, 0);
    return ESP_OK;
}

static esp_err_t static_handler(httpd_req_t *req) {
    char filepath[256];
    const char *uri = (strcmp(req->uri, "/") == 0) ? "/index.html" : req->uri;
    size_t base_len = strlen("/spiffs");
    size_t uri_len = strlen(uri);
    if (base_len + uri_len + 1 > sizeof(filepath)) {
        httpd_resp_send_err(req, HTTPD_414_URI_TOO_LONG, "URI too long");
        return ESP_FAIL;
    }
    memcpy(filepath, "/spiffs", base_len);
    memcpy(filepath + base_len, uri, uri_len);
    filepath[base_len + uri_len] = '\0';
    return send_file(req, filepath);
}

static esp_err_t ws_handler(httpd_req_t *req) {
    if (req->method == HTTP_GET) {
        s_ws_fd = httpd_req_to_sockfd(req);
        ESP_LOGI(TAG, "Websocket connected fd=%d", s_ws_fd);
        return ESP_OK;
    }

    httpd_ws_frame_t frame = {
        .type = HTTPD_WS_TYPE_TEXT,
        .payload = NULL,
        .len = 0,
    };

    esp_err_t ret = httpd_ws_recv_frame(req, &frame, 0);
    if (ret != ESP_OK) return ret;

    if (frame.len) {
        uint8_t *buf = calloc(1, frame.len + 1);
        if (!buf) return ESP_ERR_NO_MEM;
        frame.payload = buf;
        ret = httpd_ws_recv_frame(req, &frame, frame.len);
        free(buf);
        if (ret != ESP_OK) return ret;
    }

    if (frame.type == HTTPD_WS_TYPE_CLOSE) {
        ESP_LOGI(TAG, "Websocket closed");
        s_ws_fd = -1;
    }
    return ESP_OK;
}

static void start_httpd(void) {
    if (s_server) return;

    httpd_config_t config = HTTPD_DEFAULT_CONFIG();
    config.uri_match_fn = httpd_uri_match_wildcard;

    if (httpd_start(&s_server, &config) != ESP_OK) {
        ESP_LOGE(TAG, "Failed to start HTTP server");
        s_server = NULL;
        return;
    }

    const httpd_uri_t ws = {
        .uri = WS_URI,
        .method = HTTP_GET,
        .handler = ws_handler,
        .user_ctx = NULL,
        .is_websocket = true,
        .handle_ws_control_frames = true,
    };
    httpd_register_uri_handler(s_server, &ws);

    const httpd_uri_t files = {
        .uri = "/*",
        .method = HTTP_GET,
        .handler = static_handler,
        .user_ctx = NULL,
    };
    httpd_register_uri_handler(s_server, &files);

    ESP_LOGI(TAG, "HTTP server started");
}

static void start_spiffs(void) {
    esp_vfs_spiffs_conf_t conf = {
        .base_path = "/spiffs",
        .partition_label = "storage",
        .max_files = 5,
        .format_if_mount_failed = true,
    };
    esp_err_t ret = esp_vfs_spiffs_register(&conf);
    if (ret != ESP_OK) {
        ESP_LOGE(TAG, "SPIFFS mount failed (%s). Check partition table.", esp_err_to_name(ret));
        return;
    }
    size_t total = 0, used = 0;
    if (esp_spiffs_info(conf.partition_label, &total, &used) == ESP_OK) {
        ESP_LOGI(TAG, "SPIFFS mounted: total=%u bytes, used=%u bytes", (unsigned)total, (unsigned)used);
    }
}

void webserver_start(void) {
    start_spiffs();
    start_httpd();
}

void webserver_send(const char *dir_str, float speed) {
    if (!s_server || s_ws_fd < 0 || !dir_str) return;
    char msg[96];
    int n = snprintf(msg, sizeof(msg), "{\"dir\":\"%s\",\"speed\":%.3f}", dir_str, speed);
    if (n <= 0 || n >= (int)sizeof(msg)) return;

    httpd_ws_frame_t pkt = {
        .type = HTTPD_WS_TYPE_TEXT,
        .payload = (uint8_t *)msg,
        .len = strlen(msg),
    };
    esp_err_t ret = httpd_ws_send_frame_async(s_server, s_ws_fd, &pkt);
    if (ret != ESP_OK) {
        ESP_LOGW(TAG, "ws send failed: %s", esp_err_to_name(ret));
    }
}
