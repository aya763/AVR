/*
 * main.c
 *
 *  Created on: Oct 22, 2023
 *      Author: aya
 */

#include "../LIB/errorState.h"
#include "../LIB/types.h"


#include "../MCAL/EINT/INT_config.h"
#include "../MCAL/EINT/INT_int.h"

#include "../MCAL/DIO/DIO_int.h"
#include "../MCAL/GIE/GIE_int.h"

#include "../MCAL/ADC/ADC_int.h"

#include "../HAl/LCD/LCD_int.h"

#include "../HAL/LM35/LM35_config.h"
#include "../HAL/LM35/LM35_int.h"



#include <util/delay.h>

extern EINT_t EINT_tstrEINTcofig[3];

extern TR_t LM35_AstrLM35Config[2
								];


u8 flag=0;
void read(void*p)
{
	LCD_enuClearLcd();
	ADC_enuRead((u16*)p);
	flag=1;
}

void read_temp(void*p)
{
	LCD_enuClearLcd();
	LM35_enuGetTemp((f32 *)p);
	flag=1;
}


int main()
{

	//LM35Driver with INTERRUPT MODE & LCD
		f32 adc32=0;

		LCD_enuInit();

		DIO_enuSetPinDirection(DIO_u8PORTD,DIO_u8PIN2,DIO_u8INPUT);

		EINT_enuInit(EINT_tstrEINTcofig);
		EINT_enuSelectSenceLevel(0,FALLING_EDGE);
		EINT_enuEnableINT(0);

		ADC_enuEnable();
		LM35_enuInit(LM35_AstrLM35Config);
		ADC_enuEnableTriggeringMode(ADC_EXT_INT0_REQ);
		ADC_enuEnableInterruptMode();
		ADC_enuCallBack(read_temp ,&adc32);
		ADC_enuStartConversion();

		GIE_enuEnable();


		while(1)
		{
			if(flag==1)
			{
			LCD_enuDisplayNum(adc32);
			flag=0;
			}
		}


/*
	//LM35 driver with single MODE & LCD
			f32 adc32=0;

			LCD_enuInit();

			ADC_enuEnable();

			LM35_enuInit(LM35_AstrLM35Config);


			ADC_enuDisableTriggeringMode();
			ADC_enuDisableInterruptMode();

			while(1)
			{

				ADC_enuStartConversion();
				ADC_enuPollingSystem();
				LCD_enuClearLcd();
				LM35_enuGetTemp(&adc32);
				flag=1;


				if(flag==1)
				{
				LCD_enuDisplayNum(adc32);
				_delay_ms(500);
				flag=0;
				}

			}
*/

/*
	//LM35 with single MODE & LCD
		u16 adc16=0;

		LCD_enuInit();

		DIO_enuSetPinDirection(DIO_u8PORTA,DIO_u8PIN2,DIO_u8INPUT);

		ADC_enuEnable();
		ADC_enuInit();
		ADC_enuSelectChannel(2);
		ADC_enuDisableTriggeringMode();
		ADC_enuDisableInterruptMode();

		while(1)
		{


			ADC_enuStartConversion();
			ADC_enuPollingSystem();
			LCD_enuClearLcd();
			ADC_enuRead(&adc16);

			flag=1;



			if(flag==1)
			{
			LCD_enuDisplayNum(adc16);
			_delay_ms(500);
			flag=0;
			}

		}

*/

	/*
	//LM35 with INTERRUPT MODE & LCD
	u16 adc16=0;

	LCD_enuInit();

	DIO_enuSetPinDirection(DIO_u8PORTA,DIO_u8PIN2,DIO_u8INPUT);
	DIO_enuSetPinDirection(DIO_u8PORTD,DIO_u8PIN2,DIO_u8INPUT);

	EINT_enuInit(EINT_tstrEINTcofig);
	EINT_enuSelectSenceLevel(0,FALLING_EDGE);
	EINT_enuEnableINT(0);

	ADC_enuEnable();
	ADC_enuInit();
	ADC_enuSelectChannel(2);
	ADC_enuEnableTriggeringMode(ADC_EXT_INT0_REQ);
	ADC_enuEnableInterruptMode();
	ADC_enuCallBack(read ,&adc16);
	ADC_enuStartConversion();

	GIE_enuEnable();


	while(1)
	{
		if(flag==1)
		{
		LCD_enuDisplayNum(adc16);
		flag=0;
		}
	}
	*/

	/*
	//INTERRUPT MODE
	u16 adc16=0;

	DIO_enuSetPortDirection(DIO_u8PORTC,0xff); //PORTC OUTPUT read value of adc on it
	DIO_enuSetPinDirection(DIO_u8PORTA,DIO_u8PIN2,DIO_u8INPUT);
	DIO_enuSetPinDirection(DIO_u8PORTD,DIO_u8PIN2,DIO_u8INPUT);

	EINT_enuInit(EINT_tstrEINTcofig);
	EINT_enuSelectSenceLevel(0,FALLING_EDGE);
	EINT_enuEnableINT(0);

	ADC_enuEnable();
	ADC_enuInit();
	ADC_enuSelectChannel(2);
	ADC_enuEnableTriggeringMode(ADC_EXT_INT0_REQ);
	ADC_enuEnableInterruptMode();
	ADC_enuCallBack(read ,&adc16);
	ADC_enuStartConversion();

	GIE_enuEnable();


	while(1)
	{


		DIO_enuSetPortValue(DIO_u8PORTC,adc16);
	}
 */

	/*

	//single mode (polling system)
	DIO_enuSetPortDirection(DIO_u8PORTC,0xff); //PORTC OUTPUT read value of adc on it
	DIO_enuSetPinDirection(DIO_u8PORTA,DIO_u8PIN2,DIO_u8INPUT);
	ADC_enuEnable();
	ADC_enuInit();
	ADC_enuSelectChannel(2);
	ADC_enuDisableTriggeringMode();
	ADC_enuDisableInterruptMode();
	u8 adcRead=0;
	u16 adc16=0;

	while(1)
	{

		ADC_enuStartConversion();
		ADC_enuPollingSystem();
		ADC_enuReadHighValue(&adcRead);
		DIO_enuSetPortValue(DIO_u8PORTC,adcRead);
	}
	*/











	return 0;
}




