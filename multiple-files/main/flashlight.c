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
#include "./config.h"

void flashlight_task_init() 
{
    // Locals
    flash_config_t config = {
        .pin = FLASHLIGHT_PIN,
        .timin  g_ms = FLASHLIGHT_TIMING_MS
    };

    // Code
    flash_task_init(config);
}
