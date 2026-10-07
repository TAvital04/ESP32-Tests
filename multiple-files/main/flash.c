/*****************************************************************************
 *
 * Title: Flashing Source Code
 *
 * Path: multiple-files/main/flash.c
 *
 * Description: The source code for the flashing functionality.
 *
 *****************************************************************************/

#include "./flash.h"

void flash_task_init(flash_config_t config)
{
    xTaskCreate((TaskFunction_t)flash_task, "flash_task", STACK_SIZE, (void *)config, TASK_PRIORITY, NULL);
}

void flash_task(void *pvParameters)
{
    // Locals
    flash_config_t config = *(flash_config_t *)pvParameters;
    uint8_t pin = config.pin;
    int timing_ms = config.timing_ms;

    esp_err_t ret = ESP_OK;
    const TickType_t xDelay = pdMS_TO_TICKS(timing_ms);

    // Code
        // Reset the pin
        gpio_reset_pin(pin);

        // Set the pin direction to output
        ret = gpio_set_direction(pin, GPIO_MODE_OUTPUT);
        if(ret) {
            goto cleanup;
        }

        // Stay running
        while(true) { 

            // Turn on the LED        
            ret = gpio_set_level(pin, 1);
            if(ret) {
                goto cleanup;
            }

            // Wait for the specified timing
            vTaskDelay(xDelay);

            // Turn off the LED
            ret = gpio_set_level(pin, 0);
            if(ret) {
                goto cleanup;
            }

            // Wait for the specified timing
            vTaskDelay(xDelay);
        }

cleanup: gpio_reset_pin(pin);
}

