/*
 * ap.c
 *
 *  Created on: Sep 5, 2024
 *      Author: ksj10
 */


#include "ap.h"


void apInit(void)
{
	apUartInit();
	apCarrierTrackerInit();
}

void apMain(void)
{
	while(true)
	{
		apUartLoop();
		apCarrierTrackerLoop();
	}
}
