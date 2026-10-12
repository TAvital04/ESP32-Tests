/*****************************************************************************
 *
 * Title: Green LED Task
 *
 * Path: multiple-files/main/green-led.c
 *
 * Description: The green LED source code for the project.
 *
 *****************************************************************************/

#include "./green-led.h"
#include "./config.h"

void green_led_init() 
{
    // Locals
    flash_config_t config = {
        .pin = GREEN_LED_PIN,
        .timing_ms = GREEN_LED_TIMING_MS
    };

    // Code
    flash_task_init(config);
}
