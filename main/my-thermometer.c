// C packages:
#include <stdio.h> // USES - basic c operations
#include <stdbool.h> // USES - bools in program

// ESP-IDF and hardware packages:
#include <esp_log.h> // USES - pushing logs into console
#include "freertos/FreeRTOS.h" // USES - uses FreeRTOS to steer processor ticks

// Custom modules:
#include "status_led.h" // RGB LED configuration

static const char *TAG = "my-thermometer";

void app_main(void)
{
    int color[3] = {255, 255, 255};
    led_configuration();
    dispaly_led_strip(color);
    vTaskDelay(pdMS_TO_TICKS(1000));
    clear_led_strip();
}
