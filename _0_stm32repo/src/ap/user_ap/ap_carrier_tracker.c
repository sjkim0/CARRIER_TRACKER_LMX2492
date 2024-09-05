/*
 * ap_carrier_tracker.c
 *
 *  Created on: Sep 5, 2024
 *      Author: ksj10
 */


#include "ap_carrier_tracker.h"


typedef struct
{
}ap_carrier_t;


ap_carrier_t ap_carrier_inst;


static void _readTest(void);


void apCarrierTrackerInit(void)
{
	// 0. READY LE PIN
	HAL_GPIO_WritePin(LE_GPIO_Port, LE_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(CE_GPIO_Port, CE_Pin, GPIO_PIN_SET);

	delayWhile(10);
}

void apCarrierTrackerLoop(void)
{
	_readTest();
}

static void _readTest(void)
{
	static int count = 0;
	uint8_t tx_data[2] = {0x00, };
	uint8_t rx_data = 0x00;
	HAL_GPIO_WritePin(LE_GPIO_Port, LE_Pin, GPIO_PIN_RESET);
	HAL_SPI_Transmit(&hspi1, tx_data, 2, 0xFF);
	HAL_SPI_Receive(&hspi1, &rx_data, 1, 0xFF);
	HAL_GPIO_WritePin(LE_GPIO_Port, LE_Pin, GPIO_PIN_SET);
	delayWhile(1000);
	uint8_t data[100] = {0 ,};
	count += 1;
	count %= 100;
	sprintf((char *)data, "%d : 0x%x\r\n", count, rx_data);
	HAL_UART_Transmit(&hlpuart1, data, strlen((char *)data), 0xFF);
}
