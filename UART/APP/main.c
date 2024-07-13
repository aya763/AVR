/*
 * main.c
 *
 *  Created on: Oct 22, 2023
 *      Author: aya
 */


#include "../LIB/errorState.h"
#include "../LIB/types.h"


#include "../MCAL/DIO/DIO_int.h"

#include "../MCAL/USART/USART_int.h"

#include <util/delay.h>


ES_t compare(const char* str1,const char* str2)
{
	u8 i=0;
	for ( ; str1[i]!='\0' && str2[i]!='\0' ; i++)
	{
		if(str1[i]!=str2[i])
		{
			break;
		}
	}
	if(str1[i]==0 && str2[i]==0)
	{
		return ES_OK;
	}
	return ES_NOK;
}







int main()
{
	//Set direction for TX & RX PIN
	DIO_enuSetPinDirection(DIO_u8PORTD,DIO_u8PIN1,DIO_u8OUTPUT);//TX
	DIO_enuSetPinDirection(DIO_u8PORTD,DIO_u8PIN0,DIO_u8INPUT);//RX

	USART_enuInit();

	u8 Data;
	u16 data16;

	// LED & BUZZER
	char data[20];

	DIO_enuSetPinDirection(DIO_u8PORTA,DIO_u8PIN1,DIO_u8OUTPUT);//led
	DIO_enuSetPinDirection(DIO_u8PORTA,DIO_u8PIN7,DIO_u8OUTPUT);//buzzer

	// new line \r , new line in putty \r\n
	USART_enuSendString("Welcome to your smart system\r");
	USART_enuSendString("Now, your house is in your hand\r");

	while(1)
	{

		USART_enuSendString("Enter your choice: ");
		USART_enuRecieveString(data);
		USART_enuSendString(data);
		USART_enuSendString("\r");


		if(ES_OK==compare(data,"ledon"))
		{
			DIO_enuSetPinValue(DIO_u8PORTA,DIO_u8PIN7,DIO_u8LOW);
			DIO_enuSetPinValue(DIO_u8PORTA,DIO_u8PIN1,DIO_u8HIGH);
			USART_enuSendString("Led turned ON \r");
		}
		else if(ES_OK==compare(data,"ledoff"))
		{
			DIO_enuSetPinValue(DIO_u8PORTA,DIO_u8PIN7,DIO_u8LOW);
			DIO_enuSetPinValue(DIO_u8PORTA,DIO_u8PIN1,DIO_u8LOW);
			USART_enuSendString("Led turned OFF \r");
		}
		else
		{
			DIO_enuSetPinValue(DIO_u8PORTA,DIO_u8PIN7,DIO_u8HIGH);
			USART_enuSendString("Wrong Choice \r");
		}



		/* //Test
		USART_enuRecieveChar(&Data);
		USART_enuSendChar(Data);
		*/
/*
		USART_enuRecieve(&data16);
		USART_enuTransmit(data16);
*/

	}

	return 0;
}
