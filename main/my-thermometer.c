#include <stdio.h> // USES - basic c operations
#include <stdbool.h> // USES - bools in program

#include <esp_log.h> // USES - pushing logs into console

static const char *TAG = "my-thermometer";

void app_main(void)
{
    while (true)
    {
        ESP_LOGI(TAG, "Hello thermometer!");
    }
}
