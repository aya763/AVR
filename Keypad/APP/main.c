/*
 * main.c
 *
 *  Created on: Aug 8, 2023
 *      Author: aya
 */

#include "../LIB/types.h"
#include "../LIB/errorState.h"

#include "../MCAL/DIO_int.h"

#include "../HAL/LCD/LCD_int.h"
#include "../HAL/LCD/LCD_config.h"

#include "../HAL/KEYPAD/KPD_int.h"
#include "../HAL/KEYPAD/KPD_config.h"



#include "util/delay.h"

int main(void)
{
	DIO_enuInit();
	LCD_enuInit();
	u8 Local_u8Key;

	while(1)
	{


	 do
		{
			Local_u8Key=KPD_u8GetPressedKey();
		}while(Local_u8Key==0xff);

		//to display numbers
		//LCD_enuDisplayChar(Local_u8Key+'0');
		LCD_enuDisplayChar(Local_u8Key);

	}


	return 0;
}
