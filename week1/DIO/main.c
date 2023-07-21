/*
 * main.c
 *
 *  Created on: Jul 16, 2023
 *      Author: aya
 */

#include "types.h"
#include "errorState.h"
#include "DIO_int.h"
#include <util/delay.h>

int main(void)
{
	u8 segCthd []={ 0x3F,0x06,0x5B,
				        0x4F,0x66,0x6D,
						0x7D,0x07,0x7F,
						0x6F},i;

	DIO_enuInit();
	while(1)
	{
		for(i=0;i<10;i++)
		{
			DIO_enuSetPortValue(DIO_u8PORTA,segCthd[i]);
			_delay_ms(500);
		}
	}
}
