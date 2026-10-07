/*****************************************************************************
 *
 * Title: Multiple Files Header
 *
 * Path: multiple-files/main/multiple-files.h
 *
 * Description: The header for the multiple-files.c source code.
 *
 *****************************************************************************/

#ifndef MULTIPLE_FILES_H
#define MULTIPLE_FILES_H

#include "./green-led.h"
#include "./blue-led.h"
#include "./flashlight.h"

#define GREEN_LED_PIN           GPIO_NUM_15
#define BLUE_LED_PIN            GPIO_NUM_14
#define FLASHLIGHT_PIN          GPIO_NUM_4

#define GREEN_LED_TIMING_MS     1000
#define BLUE_LED_TIMING_MS      2000
#define FLASHLIGHT_TIMING_MS    3000

#endif // MULTIPLE_FILES_H