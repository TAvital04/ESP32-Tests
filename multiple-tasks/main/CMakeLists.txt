idf_component_register(
    SRCS "multiple-tasks.c"
    INCLUDE_DIRS "."
    REQUIRES freertos
    REQUIRES esp_driver_gpio    
)
