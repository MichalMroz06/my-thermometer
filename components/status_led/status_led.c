// C packages:
#include <stdio.h> // USES - basic C operations

// ESP-IDF and hardware packages:
#include "freertos/FreeRTOS.h" // USES - creating and declaring freertos functionalities
#include "freertos/task.h" // USES - creating async freertos tasks
#include <esp_log.h> // USES - pushing logs into console
#include "esp_err.h" // USES - checking if configuration of LED was successful
#include <led_strip.h> // USES - configuration and usage of RGB LED
#include "soc/clk_tree_defs.h" // USES - setting clock source

// Header for this module:
#include "status_led.h"


static const char *TAG = "my-thermometer";
static led_state_t current_state = LED_STATE_IDLE;
static led_strip_handle_t led_strip = NULL;

#define LED_GPIO  48 // Default pin for built-in ESP-32-S3 N16R8 DevKitC 1
#define LED_NUM  1 // Number of LEDs

static void led_task(void *pvParameter)
{
    while (1) {
        switch (current_state) {
            case LED_STATE_ERROR: // Red blink
                led_strip_set_pixel(led_strip, 0, 8, 0, 0);
                led_strip_refresh(led_strip);
                vTaskDelay(pdMS_TO_TICKS(500));

                led_strip_clear(led_strip);
                vTaskDelay(pdMS_TO_TICKS(500));
                break;
            case LED_STATE_CONNECTED: // Green static
                led_strip_set_pixel(led_strip, 0, 0, 5, 0);
                led_strip_refresh(led_strip);
                break;
            case LED_STATE_OFF: // Turn off
                led_strip_clear(led_strip);
                break;
            case LED_STATE_IDLE: // Blue static
            default:
                led_strip_set_pixel(led_strip, 0, 0, 0, 6);
                led_strip_refresh(led_strip);
                break;
        }
    }
}

void status_led_init(void)
{
    led_strip_config_t strip_config = {
        .strip_gpio_num = LED_GPIO,
        .max_leds = LED_NUM,
        .led_model = LED_MODEL_WS2812,
        .color_component_format = LED_STRIP_COLOR_COMPONENT_FMT_GRB,
        .flags = {
            .invert_out = false,
        }
    };

    led_strip_rmt_config_t rmt_config = {
        .clk_src = RMT_CLK_SRC_DEFAULT,
        .resolution_hz = 10 * 1000 * 1000, // 10 MHz
        .flags = {
            .with_dma = false,
        }
    };

    ESP_ERROR_CHECK(led_strip_new_rmt_device(&strip_config, &rmt_config, &led_strip));
    ESP_ERROR_CHECK(led_strip_clear(led_strip));

    xTaskCreate(led_task, "led_task", 2048, NULL, 5, NULL);
    ESP_LOGI(TAG, "Status LED initialized on %d pin.", LED_GPIO);
}

void status_led_set_state(led_state_t state)
{
    current_state = state;
}
