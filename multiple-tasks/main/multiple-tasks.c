/*****************************************************************************
 *
 * Title: Multiple Tasks
 *
 * Path: multiple-tasks/main/multiple-tasks.c
 *
 * Description: A simple file to test the framework by lighting up a series
 * of LEDs
 *
 *****************************************************************************/

// Dependencies
    #include <stdio.h>

    #include "freertos/FreeRTOS.h"

    #include "freertos/task.h"
    #include "driver/gpio.h"
    #include "driver/gpio_etm.h"

// Definitions
    #define TASK_PRIORITY 2
    #define STACK_SIZE 2048

    #define GREEN_LED GPIO_NUM_15
    #define BLUE_LED GPIO_NUM_14
    #define FLASHLIGHT_PIN GPIO_NUM_4

// Function Prototypes
    void blink_green_led(void *pvParameters);
    void blink_blue_led(void *pvParameters);
    void blink_flashlight(void *pvParameters);

// Function Definitions
    void blink_green_led(void *pvParameters)
    {
        // Locals
        esp_err_t ret = ESP_OK;
        const TickType_t xDelay = pdMS_TO_TICKS(1000);

        // Code
            // Reset the pin
            gpio_reset_pin(GREEN_LED);

            // Set the pin direction to output
            ret = gpio_set_direction(GREEN_LED, GPIO_MODE_OUTPUT);
            if(ret) {
                goto cleanup;
            }

            // Stay running
            while(true) {
                
                // Turn on the LED        
                ret = gpio_set_level(GREEN_LED, 1);
                if(ret) {
                    goto cleanup;
                }

                // Wait 1 second
                vTaskDelay(xDelay);

                // Turn off the LED
                ret = gpio_set_level(GREEN_LED, 0);
                if(ret) {
                    goto cleanup;
                }

                // Wait 1 second
                vTaskDelay(xDelay);
            }

    cleanup: gpio_reset_pin(GREEN_LED);
    }

    void blink_blue_led(void *pvParameters)
    {
        // Locals
        esp_err_t ret = ESP_OK;
        const TickType_t xDelay = pdMS_TO_TICKS(2000);

        // Code
            // Reset the pin
            gpio_reset_pin(BLUE_LED);

            // Set the pin direction to output
            ret = gpio_set_direction(BLUE_LED, GPIO_MODE_OUTPUT);
            if(ret) {
                goto cleanup;
            }

            // Stay running
            while(true) {
                
                // Turn on the LED        
                ret = gpio_set_level(BLUE_LED, 1);
                if(ret) {
                    goto cleanup;
                }

                // Wait 1 second
                vTaskDelay(xDelay);

                // Turn off the LED
                ret = gpio_set_level(BLUE_LED, 0);
                if(ret) {
                    goto cleanup;
                }

                // Wait 1 second
                vTaskDelay(xDelay);
            }
    
    cleanup: gpio_reset_pin(BLUE_LED);
    }

    void blink_flashlight(void *pvParameters)
    {
        // Locals
        esp_err_t ret = ESP_OK;
        const TickType_t xDelay = pdMS_TO_TICKS(3000);

        // Code
            // Reset the pin
            gpio_reset_pin(FLASHLIGHT_PIN);

            // Set the pin direction to output
            ret = gpio_set_direction(FLASHLIGHT_PIN, GPIO_MODE_OUTPUT);
            if(ret) {
                goto cleanup;
            }

            // Stay running
            while(true) { 

                // Turn on the LED        
                ret = gpio_set_level(FLASHLIGHT_PIN, 1);
                if(ret) {
                    goto cleanup;
                }

                // Wait 3 seconds
                vTaskDelay(xDelay);

                // Turn off the LED
                ret = gpio_set_level(FLASHLIGHT_PIN, 0);
                if(ret) {
                    goto cleanup;
                }

                // Wait 3 seconds
                vTaskDelay(xDelay);
            }

    cleanup: gpio_reset_pin(FLASHLIGHT_PIN);
    }

void app_main(void)
{
    xTaskCreate(&blink_green_led, "blink_green_led", STACK_SIZE, NULL, TASK_PRIORITY, NULL);
    xTaskCreate(&blink_blue_led, "blink_blue_led", STACK_SIZE, NULL, TASK_PRIORITY, NULL);
    xTaskCreate(&blink_flashlight, "blink_flashlight", STACK_SIZE, NULL, TASK_PRIORITY, NULL);
}
