/*
 * main.c
 *
 *  Created on: Oct 22, 2023
 *      Author: aya
 */


#include "../LIB/errorState.h"
#include "../LIB/types.h"


#include "../MCAL/DIO/DIO_int.h"

#include "../MCAL/SPI/SPI_priv.h"

#include <util/delay.h>


#define code  1

#if code==0  //MASTER
int main()
{
	DIO_enuSetPortDirection(DIO_u8PORTD,0xff);
	DIO_enuSetPinDirection(DIO_u8PORTB,DIO_u8PIN7,DIO_u8OUTPUT);
	DIO_enuSetPinDirection(DIO_u8PORTB,DIO_u8PIN6,DIO_u8INPUT);
	DIO_enuSetPinDirection(DIO_u8PORTB,DIO_u8PIN5,DIO_u8OUTPUT);
	DIO_enuSetPinDirection(DIO_u8PORTB,DIO_u8PIN4,DIO_u8OUTPUT);

	DIO_enuSetPinValue(DIO_u8PORTB,DIO_u8PIN4,DIO_u8HIGH);

	//_delay_ms(50);

	SPCR=0x53;
	DIO_enuSetPinValue(DIO_u8PORTB,DIO_u8PIN4,DIO_u8LOW);

	/*for(u8 i='A';i<'E';i++)
	{
		SPDR=i;//'A';
		while(!((SPSR>>SPSR_SPIF)&1));
		u8 slavedata=SPDR;
		DIO_enuSetPortValue(DIO_u8PORTD,slavedata);
	}*/

	while(1)
	{
		for(u8 i='A';i<'E';i++)
			{
				SPDR=i;//'A';
				while(!((SPSR>>SPSR_SPIF)&1));
				u8 slavedata=SPDR;
				DIO_enuSetPortValue(DIO_u8PORTD,slavedata);
			}
	}

	return 0;
}

#elif code==1   //SLAVE

int main()
{
	DIO_enuSetPortDirection(DIO_u8PORTD,0xff);
	DIO_enuSetPinDirection(DIO_u8PORTB,DIO_u8PIN7,DIO_u8INPUT);
	DIO_enuSetPinDirection(DIO_u8PORTB,DIO_u8PIN6,DIO_u8OUTPUT);
	DIO_enuSetPinDirection(DIO_u8PORTB,DIO_u8PIN5,DIO_u8INPUT);
	DIO_enuSetPinDirection(DIO_u8PORTB,DIO_u8PIN4,DIO_u8INPUT);



	SPCR=0x40;

	/*SPDR='B';
	while(!((SPSR>>SPSR_SPIF)&1));
	u8 slavedata=SPDR;
	DIO_enuSetPortValue(DIO_u8PORTD,slavedata);*/

	while(1)
	{
		for(u8 i='Z';i>'T';i--)
		{
			SPDR=i;//'B';
			while(!((SPSR>>SPSR_SPIF)&1));
			u8 slavedata=SPDR;
			DIO_enuSetPortValue(DIO_u8PORTD,slavedata);

		}

	}

	return 0;
}
#endif
