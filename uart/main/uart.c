// Imports
#include <stdio.h>
#include <string.h>

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/uart.h"

// Definitions
#define BAUD_RATE			115200
#define DATA_BITS			UART_DATA_8_BITS
#define STOP_BITS			UART_STOP_BITS_1
#define PARITY				UART_PARITY_DISABLE
#define FLOW_CONTROL		UART_HW_FLOWCTRL_DISABLE
#define SOURCE_CLK			UART_SCLK_DEFAULT

#define PORT_NUM			UART_NUM_0
#define RX_BUFFER_LENGTH	1024
#define TX_BUFFER_LENGTH	0
#define QUEUE_LENGTH		0
#define FLAGS				0

void app_main(void)
{
	// Set up UART
	esp_err_t ret = ESP_OK;

	char* uart_tx_string;

	uart_config_t config = {
	    .baud_rate  = BAUD_RATE,
	    .data_bits  = DATA_BITS,
	    .parity     = PARITY,
	    .stop_bits  = STOP_BITS,
	    .flow_ctrl  = FLOW_CONTROL,
	    .source_clk = SOURCE_CLK,
	};
	
	ret = uart_param_config(PORT_NUM, &config);

	if(ret != ESP_OK) {
		goto cleanup;
	}


	uart_driver_install(
		PORT_NUM,
		RX_BUFFER_LENGTH * 2,
		TX_BUFFER_LENGTH,
		QUEUE_LENGTH,
		NULL,
		FLAGS		
	);

	if(ret != ESP_OK) {
		goto cleanup;
	}


	// Send a message
	uart_tx_string = "\r\n\nHello World!\r\n\n";

	uart_write_bytes(
		PORT_NUM, 
		(const char*)uart_tx_string, 
		strlen(uart_tx_string
	));

	if(ret != ESP_OK) {
		goto cleanup;
	}


cleanup:
	abort();
}


