/*****************************************************************************
 *
 * Title: Flashing Header
 *
 * Path: multiple-files/main/flash.h
 *
 * Description: The header for the flashing source code.
 *
 *****************************************************************************/

#ifndef FLASH_H
#define FLASH_H

// Dependancies
#include <stdint.h>

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

#include "driver/gpio.h"

// Definitions
#define TASK_PRIORITY 2
#define STACK_SIZE 2048

#include "multiple-files.h"

// Structs
typedef struct {
    uint8_t pin;
    int timing_ms;
} flash_config_t;

// Function Prototypes
void flash_task_init(flash_config_t config);

#endif // FLASH_H
