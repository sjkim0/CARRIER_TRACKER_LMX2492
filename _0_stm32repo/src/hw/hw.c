/*
 * hw.c
 *
 *  Created on: Sep 5, 2024
 *      Author: ksj10
 */


#include "hw.h"


void hwInit(void)
{
	bspInit();
	MX_GPIO_Init();
	MX_DMA_Init();
	MX_SPI1_Init();
	MX_LPUART1_UART_Init();
}
