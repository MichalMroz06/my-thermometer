// C packages:
#include <stdio.h> // USES - basic C operations
#include <stdbool.h> // USES - bool operations

// ESP-IDF and hardware packages:
#include <esp_log.h> // USES - pushing logs into console
#include "esp_err.h" // USES - checking if configuration of LED was successful
#include <led_strip.h> // USES - configuration and usage of RGB LED
#include "soc/clk_tree_defs.h" // USES - setting clock source

// Header for this module:
#include "status_led.h"


static const char *TAG = "my-thermometer";

#define LED_GPIO  48 // Default pin for built-in ESP-32-S3 N16R8 DevKitC 1
#define LED_NUM  1 // Number of LEDs

static led_strip_handle_t led_strip;

float brightness = 0.15f;

uint8_t diamed_red;
uint8_t diamed_green;
uint8_t diamed_blue;

void led_configuration(void)
{
    ESP_LOGI(TAG, "Configuring RGB LED on pin: %d.", LED_GPIO);

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
}

void dispaly_led_strip(int color[])
{
    diamed_red = (uint8_t)(color[0] * brightness);
    diamed_green = (uint8_t)(color[1] * brightness);
    diamed_blue = (uint8_t)(color[2] * brightness);

    ESP_ERROR_CHECK(led_strip_set_pixel(led_strip, 0, diamed_red, diamed_green, diamed_blue));
    ESP_ERROR_CHECK(led_strip_refresh(led_strip));
}

void clear_led_strip(void)
{
    ESP_ERROR_CHECK(led_strip_clear(led_strip));
}