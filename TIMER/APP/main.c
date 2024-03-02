/*
 * main.c
 *
 *  Created on: Oct 22, 2023
 *      Author: aya
 */

#include "../LIB/errorState.h"
#include "../LIB/types.h"


#include "../MCAL/DIO/DIO_int.h"
#include "../MCAL/GIE/GIE_int.h"

#include "../HAL/LCD/LCD_int.h"

#include "../MCAL/EINT/INT_config.h"
#include "../MCAL/EINT/INT_int.h"


#include "../MCAL/TIMER/TIMER0/TIMER0_int.h"

#include "../MCAL/TIMER/TIMER1/TIMER1_int.h"

#include "../MCAL/TIMER/ICU_HW/ICU_HW_int.h"

#include "../MCAL/ADC/ADC_int.h"

#include "../MCAL/TIMER/WATCHDOG/WDT_int.h"

#include <util/delay.h>


extern EINT_t EINT_tstrEINTcofig[3];

void LED (void)
{
	static u16 Local_u16Counter=0;
	Local_u16Counter++;


	if(Local_u16Counter==4000)
	{
		DIO_enuTogPinValue(DIO_u8PORTA,DIO_u8PIN0);
		Local_u16Counter=0;
	}

}

u8 segCthd []={ 0x3F,0x06,0x5B,
				        0x4F,0x66,0x6D,
						0x7D,0x07,0x7F,
						0x6F},sw1State,sw2State,counter=50,one,deci;

void sev_seg (void)
{
	static u16 Local_u16Counter=0;
	Local_u16Counter++;
	static u8 i=0;


		if(Local_u16Counter==1)
		{
		DIO_enuSetPinValue(DIO_u8PORTB,DIO_u8PIN1,DIO_u8HIGH);
		DIO_enuSetPortValue(DIO_u8PORTA,segCthd[i]);
		DIO_enuSetPinValue(DIO_u8PORTB,DIO_u8PIN0,DIO_u8LOW);
		}
		else if(Local_u16Counter==400)
		{
			DIO_enuSetPinValue(DIO_u8PORTB,DIO_u8PIN0,DIO_u8HIGH);
			DIO_enuSetPortValue(DIO_u8PORTA,segCthd[9-i]);
			DIO_enuSetPinValue(DIO_u8PORTB,DIO_u8PIN1,DIO_u8LOW);
			while(1)
			{
				if(Local_u16Counter==800 )
				{
					i++;
					Local_u16Counter=0;
					break;
				}
			}

	}
	if(i==9)
	{
		i=0;
	}

}

void PWM(void)
{
	static u8 Local_u8Counter=0;
	Local_u8Counter++;

	if(Local_u8Counter==5)
	{
		DIO_enuSetPinValue(DIO_u8PORTA,DIO_u8PIN0,DIO_u8LOW);
	}
	else if(Local_u8Counter==10)
	{
		DIO_enuSetPinValue(DIO_u8PORTA,DIO_u8PIN1,DIO_u8LOW);
	}
	else if(Local_u8Counter==15)
	{
		DIO_enuSetPinValue(DIO_u8PORTA,DIO_u8PIN2,DIO_u8LOW);
	}
	else if(Local_u8Counter==20)
	{
		DIO_enuSetPinValue(DIO_u8PORTA,DIO_u8PIN0,DIO_u8HIGH);
		DIO_enuSetPinValue(DIO_u8PORTA,DIO_u8PIN1,DIO_u8HIGH);
		DIO_enuSetPinValue(DIO_u8PORTA,DIO_u8PIN2,DIO_u8HIGH);
		Local_u8Counter=0;
	}
}

s32 Map(s32 InputMin,s32 InputMax,s32 OutputMin,s32 OutputMax,s32 InputVal )
{
	s32 OutputVal;
	OutputVal=InputVal-InputMin;
	OutputVal*=OutputMax-OutputMin;
	OutputVal/=InputMax-InputMin;
	OutputVal+=OutputMin;
	return OutputVal;
}

static u16 PeriodTicks=0,ONTimeTicks;


void ICU_SW(void)
{
	static u8 counter=0;
	counter++;

	if(counter==3)
	{
		TIMER1_enuSetTimerValue(0);
	}
	else if(counter==4)
	{
		TIMER1_enuReadTimerValue(&PeriodTicks);
		EINT_enuSelectSenceLevel(0,FALLING_EDGE);
	}
	else if(counter==5)
	{
		TIMER1_enuReadTimerValue(&ONTimeTicks);
		ONTimeTicks-=PeriodTicks;
		EINT_enuDisableINT(0);
	}
}

void ICU_HW(void)
{
	static u8 counter=0;
	static u16 Read1,Read2,Read3;
	counter++;

	if(counter==1)
	{
		ICU_enuReadInputCapture(&Read1);
	}
	else if(counter==2)
	{
		ICU_enuReadInputCapture(&Read2);
		PeriodTicks=Read2-Read1;
		ICU_enuSetTriggerEdge(ICU_FALLING_EDGE_SELECT);
	}
	else if(counter==3)
	{
		ICU_enuReadInputCapture(&Read3);
		ONTimeTicks=Read3-Read2;
		ICU_enuDisableINTERRUPT();
	}
}


void tog(void *p)
{
	DIO_enuTogPinValue(DIO_u8PORTA,DIO_u8PIN0);
}

int main()
{
	//test ASych >>does not work
	DIO_enuSetPinDirection(DIO_u8PORTA,DIO_u8PIN0,DIO_u8OUTPUT);
	DIO_enuSetPinValue(DIO_u8PORTA,DIO_u8PIN0,DIO_u8HIGH);
	TIMER0_enuInit();
	TIMER0_enuSetAsychDelay(1000,tog,NULL);
	GIE_enuEnable();

/*
	//WATCH DOG>> Blink Led
	DIO_enuSetPinDirection(DIO_u8PORTB,DIO_u8PIN7,DIO_u8OUTPUT);
	DIO_enuSetPinValue(DIO_u8PORTB,DIO_u8PIN7,DIO_u8HIGH);
	_delay_ms(1000);
	DIO_enuSetPinValue(DIO_u8PORTB,DIO_u8PIN7,DIO_u8LOW);
	WDT_enuEnable();
	WDT_enuSleep(SLEEP_TIME_1000_MS);
	//WDT_enuDisable();
	 *
	 */

/*
	//ICU by Hardware using Timer0 >>FAST PWM & Pres=8 & Timer1(Normal MODE) & ICU
	LCD_enuInit();

	DIO_enuSetPinDirection(DIO_u8PORTB,DIO_u8PIN3,DIO_u8OUTPUT);//OC0

	DIO_enuSetPinDirection(DIO_u8PORTD,DIO_u8PIN6,DIO_u8INPUT);//ICP1

	ICU_enuInit();
	ICU_enuCallBack(&ICU_HW,NULL);
	ICU_enuEnableINTERRUPT();

	TIMER1_enuInit();

	//TIMER0_enuSetCTC(64);
	TIMER0_enuInit();
	TIMER0_enuGeneratePWM(25); //Duty=25%

	GIE_enuEnable();
*/
/*
	//ICU by software using Timer0 >>FAST PWM & Pres=8 & Timer1(Normal MODE)  & EXTI INTerrupt
	LCD_enuInit();

	DIO_enuSetPinDirection(DIO_u8PORTB,DIO_u8PIN3,DIO_u8OUTPUT);//OC0

	DIO_enuSetPinDirection(DIO_u8PORTD,DIO_u8PIN2,DIO_u8INPUT);
	EINT_enuInit(EINT_tstrEINTcofig);
	EINT_enuSelectSenceLevel(0,RISING_EDGE);
	EINT_enuCallBack(&ICU_SW,NULL,0);

	EINT_enuEnableINT(0);

	TIMER1_enuInit();

	TIMER0_enuSetCTC(64);//TIMER0_enuGeneratePWM(25); //Duty=25%
	TIMER0_enuInit();

	GIE_enuEnable();
*/

/*
	//pot&servo
	//OC1A pin
	DIO_enuSetPinDirection(DIO_u8PORTD,DIO_u8PIN5,DIO_u8OUTPUT);
	DIO_enuSetPinValue(DIO_u8PORTD,DIO_u8PIN5,DIO_u8LOW);
	TIMER1_enuInit();
	TIMER1_enuSetICR(20000);
	u16 value_angle;
	//potentiometer
	DIO_enuSetPinDirection(DIO_u8PORTA,DIO_u8PIN3,DIO_u8INPUT);
	u16 ADC_Read;
	u8 ADC_8bitRead;

	ADC_enuEnable();
	ADC_enuInit();
	ADC_enuSelectChannel(3);
	ADC_enuDisableTriggeringMode();
	ADC_enuDisableInterruptMode();
	//ADC_enuRead(&ADC_Read);

	//print angle value on lcd to check why it does not work
	LCD_enuInit();

*/

	//generate pwm wave for servo motor using TIMER1
	/*
	TIMER1_enuInit();
	TIMER1_enuSetICR(20000);
	TIMER1_enuSetChannelACTC(1000);

	DIO_enuSetPinDirection(DIO_u8PORTD,DIO_u8PIN5,DIO_u8OUTPUT);
	DIO_enuSetPinValue(DIO_u8PORTD,DIO_u8PIN5,DIO_u8LOW);
    */

	/*
	//FAST PWM

	DIO_enuSetPinDirection(DIO_u8PORTB,DIO_u8PIN3,DIO_u8OUTPUT);
	TIMER0_enuInit();

	//GENERETE PWM using TIMER0 >>pres=64
	DIO_enuSetPinDirection(DIO_u8PORTA,DIO_u8PIN0,DIO_u8OUTPUT);
	DIO_enuSetPinValue(DIO_u8PORTA,DIO_u8PIN0,DIO_u8HIGH);
	DIO_enuSetPinDirection(DIO_u8PORTA,DIO_u8PIN1,DIO_u8OUTPUT);
	DIO_enuSetPinValue(DIO_u8PORTA,DIO_u8PIN1,DIO_u8HIGH);
	DIO_enuSetPinDirection(DIO_u8PORTA,DIO_u8PIN2,DIO_u8OUTPUT);
	DIO_enuSetPinValue(DIO_u8PORTA,DIO_u8PIN2,DIO_u8HIGH);
	TIMER0_enuEnableCTCINTERRUPT();
	TIMER0_enuSetCTC(125);

	TIMER0_enuInit();
	TIMER0_enuCallBackCTC(&PWM,NULL);

	GIE_enuEnable();

*/
/*
	//Toggle led every one second using CTC Mode
	DIO_enuSetPinDirection(DIO_u8PORTA,DIO_u8PIN0,DIO_u8OUTPUT);
	DIO_enuSetPinValue(DIO_u8PORTA,DIO_u8PIN0,DIO_u8HIGH);

	TIMER0_enuEnableCTCINTERRUPT();
	TIMER0_enuSetCTC(250);

	TIMER0_enuInit();
	TIMER0_enuCallBackCTC(&LED,NULL);

	GIE_enuEnable();
*/
/*
//POV 2Segmant
	DIO_enuSetPortDirection(DIO_u8PORTA,0xff); //2segmant

	DIO_enuSetPinDirection(DIO_u8PORTB,DIO_u8PIN0,DIO_u8OUTPUT);
	DIO_enuSetPinDirection(DIO_u8PORTB,DIO_u8PIN1,DIO_u8OUTPUT);

	DIO_enuSetPinValue(DIO_u8PORTB,DIO_u8PIN0,DIO_u8HIGH);
	DIO_enuSetPinValue(DIO_u8PORTB,DIO_u8PIN1,DIO_u8HIGH);

	TIMER0_enuEnableCTCINTERRUPT();
	TIMER0_enuSetCTC(250);

	TIMER0_enuInit();
	TIMER0_enuCallBackCTC(&sev_seg,NULL);

	GIE_enuEnable();

*/
	while(1)
	{

/*
		//POV using sync delay
		for(u8 i=0;i<10;i++)
		{
			DIO_enuSetPinValue(DIO_u8PORTB,DIO_u8PIN1,DIO_u8HIGH);
			DIO_enuSetPortValue(DIO_u8PORTA,segCthd[i]);
			DIO_enuSetPinValue(DIO_u8PORTB,DIO_u8PIN0,DIO_u8LOW);
			TIMER0_enuSetSychDelay(100);
			DIO_enuSetPinValue(DIO_u8PORTB,DIO_u8PIN0,DIO_u8HIGH);
			DIO_enuSetPortValue(DIO_u8PORTA,segCthd[9-i]);
			DIO_enuSetPinValue(DIO_u8PORTB,DIO_u8PIN1,DIO_u8LOW);
			TIMER0_enuSetSychDelay(100);

			//_delay_ms(50);
		}
		TIMER0_enuSetSychDelay(1000);
		//DIO_enuTogPinValue(DIO_u8PORTA,DIO_u8PIN0);//Test sync delay
*/

/*
		//ICU
		while((PeriodTicks==0) && (ONTimeTicks==0));

		LCD_enuGoToPosition(1,1);
		LCD_enuSendSpecialNumber(PeriodTicks);
		LCD_enuGoToPosition(2,1);
		LCD_enuSendSpecialNumber(ONTimeTicks);
*/
		//pot&servo
		/*
		ADC_enuStartConversion();
		ADC_enuPollingSystem();
		ADC_enuRead(&ADC_Read);
		//ADC_enuReadHighValue(&ADC_8bitRead);
		//f32 float_num=0.146*(f32)ADC_Read+750;

		value_angle=6.86*ADC_Read+750;
		//value_angle=Map(0,1024,750,2500,ADC_8bitRead);
		LCD_enuDisplayNum(value_angle);
		TIMER1_enuSetChannelACTC(value_angle);
		_delay_ms(1000);
		LCD_enuClearLcd();
*/
		//generate pwm wave for servo motor using TIMER1
		/*
		for(u16 i=750;i<2500;i++)
		{
			TIMER1_enuSetChannelACTC(i);
			_delay_ms(10);
		}
		*/
		//fast PWM
		/*
		for(u8 i=0;i<255;i++)
		{
			TIMER0_enuSetCTC(i);
			_delay_ms(10);
		}

		for(u8 duty=0;duty<100;duty++)
		{
			TIMER0_enuGeneratePWM(duty);
			_delay_ms(10);
		}
		 */

	}
	return 0;
}


