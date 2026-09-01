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

	#include "driver/gpio.h"

// Definitions
	#define FLASHLIGHT_PIN GPIO_NUM_4

// Main
	void app_main(void)
	{
		// Locals
		esp_err_t ret = ESP_OK;

		// Code
		
			// Reset the pin
			gpio_reset_pin(FLASHLIGHT_PIN);

			// Set the pin direction to output
			ret = gpio_set_direction(FLASHLIGHT_PIN, GPIO_MODE_OUTPUT);
			if(ret) {
				goto cleanup;
			}

			// Turn on the LED		

			ret = gpio_set_level(FLASHLIGHT_PIN, 1);
			if(ret) {
				goto cleanup;
			}

			// Stay running
			while(true) { 
				
			}
		
	cleanup:
		gpio_reset_pin(FLASHLIGHT_PIN);
	}
