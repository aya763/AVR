/*
 * main.c
 *
 *  Created on: Jul 23, 2023
 *      Author: aya
 */

#include "types.h"
#include "errorState.h"
#include "DIO_int.h"
#include "Switch_config.h"
#include "Switch_int.h"



extern SW_t Switch_AstrSwitchState [SW_NUM];
int main (void)
{
	DIO_enuInit();
	Switch_enuInit(Switch_AstrSwitchState);
	u8 pinstate;
	while(1)
	{
		Switch_enuGetState(&Switch_AstrSwitchState[1],&pinstate);
		if(pinstate==0)
		{
			DIO_enuSetPinValue(DIO_u8PORTA,DIO_u8PIN0,DIO_u8HIGH);
		}
		else
		{
			DIO_enuSetPinValue(DIO_u8PORTA,DIO_u8PIN0,DIO_u8LOW);
		}
	}
}
