/*****************************************************************************
 *
 * Title: Config File
 *
 * Path: multiple-files/main/config.h
 *
 * Description: The header for the multiple-files.c source code.
 *
 *****************************************************************************/

#ifndef CONFIG_H
#define CONFIG_H

#define GREEN_LED_PIN           GPIO_NUM_15
#define BLUE_LED_PIN            GPIO_NUM_14
#define FLASHLIGHT_PIN          GPIO_NUM_4

#define GREEN_LED_TIMING_MS     1000
#define BLUE_LED_TIMING_MS      2000
#define FLASHLIGHT_TIMING_MS    3000

#endif // CONFIG_H