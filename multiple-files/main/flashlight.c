/*****************************************************************************
 *
 * Title: Flashlight Task
 *
 * Path: multiple-files/main/flashlight.c
 *
 * Description: The flashlight source code for the project.
 *
 *****************************************************************************/

#include "./flashlight.h"

// Function Definitions
    void flashlight_task_init() 
    {
        flash_config_t config = {
            .pin = FLASHLIGHT_PIN,
            .timing_ms = FLASHLIGHT_TIMING_MS
        };
        
        flash_task_init(config);
    }
