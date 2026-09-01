// Imports
#include <stdio.h>
#include <string.h>

#include "freertos/task.h"

// Definitions
#define STACK_SIZE 	200
#define TASK_PRIORITY 	2

#define UART_PORT_NUM	UART_NUM_0
#define UART_RX_LEN	UART_HW_FIFO_LEN(UART_NUM)
#define UART_TX_LEN	0
#define UART_QUEUE_LEN	10
#define UART_FLAGS	0
#define BAUD_RATE	115200

void app_main(void)
{
	// Set up uart communication
	char* uart_tx_string;
	QueueHandle_t uart_queue;
	
	uart_driver_install(
		UART_NUM,
		UART_RX_LEN,
		UART_TX_LEN,
		UART_QUEUE_LEN,
		&uart_queue,
		UART_FLAGS
	);

	uart_set_baudrate(UART_NUM, 115200);

	uart_tx_string = "Calling tasks...";
	uart_write_bytes(
		UART_PORT_NUM,
		(const char*)uart_tx_string,
		strlen(uart_tx_string)
	);

	// Create the tasks
	TaskHandle_t blue_led_task_handle = NULL;
	TaskHandle_t green_led_task_handle = NULL;

	xTaskCreate(
		blue_led_task,
		"Blue LED Task",
		STACK_SIZE,
		NULL,
		TASK_PRIORITY,
		&blue_led_task_handle
	);

	xTaskCreate(
		green_led_task,
		"Green LED Task",
		STACK_SIZE,
		NULL,
		TASK_PRIORITY,
		&green_led_task_handle
	);

	uart_tx_string = "Finished calling tasks!";
	uart_write_bytes(
		UART_PORT_NUM,
		(const char*)uart_tx_string,
		strlen(uart_tx_string)
	);
}
