/*
 * main.c
 *
 *  Created on: Jul 23, 2023
 *      Author: aya
 */

#include "types.h"
#include "errorState.h"

#include "DIO_int.h"
#include "LED_config.h"
#include "LED_int.h"
#include "Switch_config.h"
#include "Switch_int.h"

#include <util/delay.h>

extern LED_t LED_AstrLedConfig[LED_NUM];
extern SW_t Switch_AstrSwitchState [SW_NUM];

int main(void)
{
	DIO_enuInit();
	LED_enuInit(LED_AstrLedConfig);
	Switch_enuInit(Switch_AstrSwitchState);
	u8 pinstate=0;
	while(1)
	{
		Switch_enuGetState(&Switch_AstrSwitchState[1],&pinstate);
		if(pinstate==0)
		LED_enuTurnON(&LED_AstrLedConfig[1]);
		else
		LED_enuTurnOFF(&LED_AstrLedConfig[1]);

	}
}
