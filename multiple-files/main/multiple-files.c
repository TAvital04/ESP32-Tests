/*****************************************************************************
 *
 * Title: Multiple Files
 *
 * Path: multiple-files/main/multiple-files.c
 *
 * Description: Main of a simple project to test a framework with multiple 
 * files. It calls the task functions for the green LED, blue LED, and 
 * flashlight.
 *
 *****************************************************************************/

#include "./multiple-files.h"

void app_main(void)
{
    green_led_init(GREEN_LED_PIN);
    blue_led_init(BLUE_LED_PIN);
    flashlight_init(FLASHLIGHT_PIN);
}
