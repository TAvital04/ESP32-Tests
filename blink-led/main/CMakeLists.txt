idf_component_register(
	SRCS "blink-led.c"
	INCLUDE_DIRS "."
	REQUIRES esp_driver_uart
	REQUIRES freertos
	REQUIRES esp_driver_gpio
)
