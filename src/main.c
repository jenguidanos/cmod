#include <freertos/FreeRTOS.h>
#include <freertos/task.h>
#include <nvs.h>
#include <nvs_flash.h>

#include "cmod.h"
#include "driver/gpio.h"
#include "esp_log.h"
#include "time.h"

#define LED 2 // LED connected to GPIO2

unsigned long micros() { return (unsigned long)(esp_timer_get_time()); }

int CMOD_MAIN() {
  esp_log_level_set("*", ESP_LOG_ERROR);
  esp_err_t ret = nvs_flash_init();
  if (ret == ESP_ERR_NVS_NO_FREE_PAGES ||
      ret == ESP_ERR_NVS_NEW_VERSION_FOUND) {
    ESP_ERROR_CHECK(nvs_flash_erase());
    ret = nvs_flash_init();
  }
  ESP_ERROR_CHECK(ret);

  cmod.init();
  cmod.setDebug(&CMOD_DEBUG_DEFAULT_MODULE);
  // BUGGY!!!
  // cmod.setNet(&CMOD_NET_DEFAULT_MODULE);

  gpio_config_t io_conf;
  io_conf.intr_type = GPIO_PIN_INTR_DISABLE;
  io_conf.mode = GPIO_MODE_OUTPUT;
  io_conf.pin_bit_mask = (1ULL << LED);
  io_conf.pull_down_en = 0;
  io_conf.pull_up_en = 0;
  gpio_config(&io_conf);

  while (1) {
    int64_t time_since_boot2 = esp_timer_get_time();
    cmod.log->info("Time %d us", (uint32_t)time_since_boot2 / 1000);

    gpio_set_level(LED, 0);
    vTaskDelay(500 / portTICK_RATE_MS);
    gpio_set_level(LED, 1);
    vTaskDelay(500 / portTICK_RATE_MS);
  }

  return 0;
}
