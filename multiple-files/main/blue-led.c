/*****************************************************************************
 *
 * Title: Blue LED Task
 *
 * Path: multiple-files/main/blue-led.c
 *
 * Description: The blue LED source code for the project.
 *
 *****************************************************************************/

#include "./blue-led.h"
#include "./config.h"

// Function Definitions
void blue_led_init() 
{
    // Locals
    flash_config_t config = {
        .pin = BLUE_LED_PIN,
        .timing_ms = BLUE_LED_TIMING_MS
    };

    // Code
    flash_task_init(config);
}
