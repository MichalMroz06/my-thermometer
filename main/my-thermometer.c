// C packages:
#include <stdio.h> // USES - basic c operations

// ESP-IDF and hardware packages:
#include <esp_log.h> // USES - pushing logs into console
#include "freertos/FreeRTOS.h" // USES - uses FreeRTOS to steer processor ticks

// Custom modules:
#include "status_led.h" // RGB LED configuration

static const char *TAG = "my-thermometer";

void app_main(void)
{
    status_led_init();

    // Example code to test functionality of LED states:
    ESP_LOGI(TAG, "Wi-Fi connecting! Switching LED to IDLE state.");
    status_led_set_state(LED_STATE_IDLE);
    vTaskDelay(pdMS_TO_TICKS(3000));
    ESP_LOGW(TAG, "Wi-Fi connection failed! Switching LED to ERROR state.");
    status_led_set_state(LED_STATE_ERROR);
    vTaskDelay(pdMS_TO_TICKS(3000));
    ESP_LOGI(TAG, "Wi-Fi connection successful! Switching LED to SUCCESS state.");
    status_led_set_state(LED_STATE_CONNECTED);
    vTaskDelay(pdMS_TO_TICKS(5000));
    ESP_LOGI(TAG, "Wi-Fi connection turned off! Switching LED to OFF state.");
    status_led_set_state(LED_STATE_OFF);
}
