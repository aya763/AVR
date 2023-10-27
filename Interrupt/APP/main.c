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

#include <util/delay.h>


extern EINT_t EINT_tstrEINTcofig[3];

void func(u8 i);

void tog(void);

int main()
{
	u8 func_par=5;

	DIO_enuSetPinDirection(DIO_u8PORTA ,DIO_u8PIN0 ,DIO_u8OUTPUT);
	DIO_enuSetPinDirection(DIO_u8PORTD ,DIO_u8PIN2 ,DIO_u8INPUT);  //INT0
	DIO_enuSetPinValue(DIO_u8PORTD ,DIO_u8PIN2 ,DIO_u8PULL_UP); //switch

	DIO_enuSetPinDirection(DIO_u8PORTD ,DIO_u8PIN3 ,DIO_u8INPUT);  //INT1
	DIO_enuSetPinValue(DIO_u8PORTD ,DIO_u8PIN3 ,DIO_u8PULL_UP); //switch

	DIO_enuSetPinDirection(DIO_u8PORTB ,DIO_u8PIN2 ,DIO_u8INPUT);  //INT2
	DIO_enuSetPinValue(DIO_u8PORTB ,DIO_u8PIN2 ,DIO_u8PULL_UP); //switch

	GIE_enuEnable();
	EINT_enuInit(EINT_tstrEINTcofig);

	//INT 0
	EINT_enuSelectSenceLevel(0,RISING_EDGE);
	EINT_enuCallBack(func,&func_par,0);

	//INT 1
	EINT_enuSelectSenceLevel(1,LOW_LEVEL);
	EINT_enuCallBack(tog,NULL,1);

	//INT 2
	EINT_enuSelectSenceLevel(2,FALLING_EDGE);
	EINT_enuCallBack(func,&func_par,2);

	while(1)
	{

	}


	return 0;
}

void tog(void)
{
	//func(5);
	DIO_enuTogPinValue(DIO_u8PORTA,DIO_u8PIN0);
}

void func(u8 i)
{
	//DIO_enuTogPinValue(DIO_u8PORTA,DIO_u8PIN0);

	for(u8 j=0;j<i;j++)
	{
		DIO_enuTogPinValue(DIO_u8PORTA,DIO_u8PIN0);
		_delay_ms(1000);
		if(j==5){break;}
	}

}


