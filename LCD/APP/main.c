/*
 * main.c
 *
 *  Created on: Aug 8, 2023
 *      Author: aya
 */

#include "../LIB/types.h"
#include "../LIB/errorState.h"

#include "../MCAL/DIO_int.h"

#include "../HAL/LCD_int.h"

#include "util/delay.h"

int main(void)
{

	LCD_enuInit();
	/*LCD_enuDisplayChar('A');
	LCD_enuDisplayChar('y');
	LCD_enuDisplayChar('A');*/
	LCD_enuGoToPosition(1,3);
	LCD_enuDisplayString("aya elsayed");
	LCD_enuGoToPosition(2,3);
	for(u8 i=0;i<255;i++)
	{
		LCD_enuDisplayNum(i);

		//LCD_enuSendSpecialNumber(i);

		_delay_ms(300);
			LCD_enuClearLcd();
	}
	LCD_enuDisplayNum(100);
	_delay_ms(3000);
	//LCD_enuSendCommand(0x01);
	LCD_enuClearLcd();

	return 0;
}
