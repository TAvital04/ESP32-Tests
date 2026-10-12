/*****************************************************************************
 *
 * Title: Blink LED
 *
 * Path: blink-led/main/blink-led.c
 *
 * Description: A simple file to test the framework by lighting up an LED
 *
 *****************************************************************************/

// Dependencies
	#include <stdio.h>

	#include "freertos/FreeRTOS.h"

	#include "freertos/task.h"
	#include "driver/gpio.h"

// Definitions
	#define FLASHLIGHT_PIN GPIO_NUM_4

// Main
	void app_main(void)
	{
		// Locals
		esp_err_t ret = ESP_OK;
		
		const TickType_t xDelay = pdMS_TO_TICKS(1000);

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
		
	cleanup:
		gpio_reset_pin(FLASHLIGHT_PIN);
	}
