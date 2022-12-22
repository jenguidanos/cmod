#include "cmod-net-esp32wifi.h"

#include <string.h>

#include "cmod-conf.h"
#include "cmod.h"
#include "esp_event.h"
#include "esp_log.h"
#include "esp_system.h"
#include "esp_wifi.h"
#include "freertos/FreeRTOS.h"
#include "freertos/event_groups.h"
#include "freertos/task.h"
#include "lwip/err.h"
#include "lwip/sys.h"
#include "nvs_flash.h"

/* The examples use WiFi configuration that you can set via project
   configuration menu If you'd rather not, just change the below entries to
   strings with the config you want - ie #define EXAMPLE_WIFI_SSID "mywifissid"
*/
#define EXAMPLE_ESP_WIFI_SSID "HOME 2.4"
#define EXAMPLE_ESP_WIFI_PASS "1234asdf"
#define EXAMPLE_ESP_MAXIMUM_RETRY 10
#define ESP_WIFI_SCAN_AUTH_MODE_THRESHOLD WIFI_AUTH_WPA_WPA2_PSK

/* FreeRTOS event group to signal when we are connected*/
static EventGroupHandle_t s_wifi_event_group;

/* The event group allows multiple bits for each event, but we only care about
 * two events:
 * - we are connected to the AP with an IP
 * - we failed to connect after the maximum amount of retries */
#define WIFI_CONNECTED_BIT BIT0
#define WIFI_FAIL_BIT BIT1

static const char *TAG = "wifi station";

static int s_retry_num = 0;

static wifi_config_t wifi_config = {
    .sta = {.ssid = EXAMPLE_ESP_WIFI_SSID, .password = EXAMPLE_ESP_WIFI_PASS},
};

static void event_handler(void *arg, esp_event_base_t event_base,
                          int32_t event_id, void *event_data);
static void wifi_init_sta(void);

bool ESP32WiFi_init();
bool ESP32WiFi_enable();
bool ESP32WiFi_disable();
uint8_t ESP32WiFi_getCoverage();
bool ESP32WiFi_connect();
bool ESP32WiFi_disconnect();
bool ESP32WiFi_send(uint8_t *data);
bool ESP32WiFi_setPowerOn();
bool ESP32WiFi_setPowerOff();
bool ESP32WiFi_setStandby();

iNet cmod_net_esp32wifi = {.name = CMOD_NET_ESP32WiFi,

                           .init = ESP32WiFi_init,
                           .enable = ESP32WiFi_enable,
                           .disable = ESP32WiFi_disable,
                           .getCoverage = ESP32WiFi_getCoverage,

                           .connect = ESP32WiFi_connect,
                           .disconnect = ESP32WiFi_disconnect,
                           .send = ESP32WiFi_send,

                           .setPowerOn = ESP32WiFi_setPowerOn,
                           .setPowerOff = ESP32WiFi_setPowerOff,
                           .setStandby = ESP32WiFi_setStandby};

bool ESP32WiFi_init() {
  cmod.log->info("[INIT] NET esp32.");
  wifi_init_sta();
  return false;
}

bool ESP32WiFi_enable() { return false; }

bool ESP32WiFi_disable() { return false; }

uint8_t ESP32WiFi_getCoverage() { return 0; }

bool ESP32WiFi_connect() {
  ESP_ERROR_CHECK(esp_wifi_set_mode(WIFI_MODE_STA));
  ESP_ERROR_CHECK(esp_wifi_set_config(WIFI_IF_STA, &wifi_config));
  ESP_ERROR_CHECK(esp_wifi_start());

  ESP_LOGI(TAG, "wifi_init_sta finished.");

  /* Waiting until either the connection is established (WIFI_CONNECTED_BIT) or
   * connection failed for the maximum number of re-tries (WIFI_FAIL_BIT). The
   * bits are set by event_handler() (see above) */
  EventBits_t bits = xEventGroupWaitBits(s_wifi_event_group,
                                         WIFI_CONNECTED_BIT | WIFI_FAIL_BIT,
                                         pdFALSE, pdFALSE, portMAX_DELAY);

  /* xEventGroupWaitBits() returns the bits before the call returned, hence we
   * can test which event actually happened. */
  if (bits & WIFI_CONNECTED_BIT) {
    ESP_LOGI(TAG, "connected to ap SSID:%s password:%s", EXAMPLE_ESP_WIFI_SSID,
             EXAMPLE_ESP_WIFI_PASS);
  } else if (bits & WIFI_FAIL_BIT) {
    ESP_LOGI(TAG, "Failed to connect to SSID:%s, password:%s",
             EXAMPLE_ESP_WIFI_SSID, EXAMPLE_ESP_WIFI_PASS);
  } else {
    ESP_LOGE(TAG, "UNEXPECTED EVENT");
  }
  return false;
}

bool ESP32WiFi_disconnect() { return false; }

bool ESP32WiFi_send(uint8_t *data) { return false; }

bool ESP32WiFi_setPowerOn() { return false; }

bool ESP32WiFi_setPowerOff() { return false; }

bool ESP32WiFi_setStandby() { return false; }

static void event_handler(void *arg, esp_event_base_t event_base,
                          int32_t event_id, void *event_data) {
  ESP_LOGI(TAG, "ESP_WIFI_MODE_STA");
  if (event_base == WIFI_EVENT && event_id == WIFI_EVENT_STA_START) {
    esp_wifi_connect();
  } else if (event_base == WIFI_EVENT &&
             event_id == WIFI_EVENT_STA_DISCONNECTED) {
    if (s_retry_num < EXAMPLE_ESP_MAXIMUM_RETRY) {
      esp_wifi_connect();
      s_retry_num++;
      ESP_LOGI(TAG, "retry to connect to the AP");
    } else {
      xEventGroupSetBits(s_wifi_event_group, WIFI_FAIL_BIT);
    }
    ESP_LOGI(TAG, "connect to the AP fail");
  } else if (event_base == IP_EVENT && event_id == IP_EVENT_STA_GOT_IP) {
    ip_event_got_ip_t *event = (ip_event_got_ip_t *)event_data;
    ESP_LOGI(TAG, "got ip:" IPSTR, IP2STR(&event->ip_info.ip));
    s_retry_num = 0;
    xEventGroupSetBits(s_wifi_event_group, WIFI_CONNECTED_BIT);
  }
}

static void wifi_init_sta(void) {
  s_wifi_event_group = xEventGroupCreate();
  nvs_flash_init();
  ESP_ERROR_CHECK(esp_netif_init());

  ESP_ERROR_CHECK(esp_event_loop_create_default());
  esp_netif_create_default_wifi_sta();

  wifi_init_config_t cfg = WIFI_INIT_CONFIG_DEFAULT();
  ESP_ERROR_CHECK(esp_wifi_init(&cfg));

  esp_event_handler_instance_t instance_any_id;
  esp_event_handler_instance_t instance_got_ip;
  ESP_ERROR_CHECK(esp_event_handler_instance_register(
      WIFI_EVENT, ESP_EVENT_ANY_ID, &event_handler, NULL, &instance_any_id));
  ESP_ERROR_CHECK(esp_event_handler_instance_register(
      IP_EVENT, IP_EVENT_STA_GOT_IP, &event_handler, NULL, &instance_got_ip));
}
