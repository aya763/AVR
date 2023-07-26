/*
 * Seven_segmant_config.c
 *
 *  Created on: Jul 25, 2023
 *      Author: aya
 */

#include "types.h"
#include "errorState.h"

#include "DIO_int.h"

#include "Seven_segmant_config.h"
#include "Seven_segmant_priv.h"

SEG_t SEVSEG_AstrSegConfig[SEG_NUM]={
		{DIO_u8PORTA,DIO_u8PIN2,//pin a
		 DIO_u8PORTB,DIO_u8PIN4, //pin b
		 DIO_u8PORTC,DIO_u8PIN2, //pin c
		 DIO_u8PORTA,DIO_u8PIN7, //pin d
		 DIO_u8PORTC,DIO_u8PIN5, //pin e
		 DIO_u8PORTD,DIO_u8PIN3, //pin f
		 DIO_u8PORTA,DIO_u8PIN0, //pin g
		 DIO_u8PORTD,DIO_u8PIN7, //pin cmn
		 NOT_CONNECTED,NOT_CONNECTED, //pin dot
		 COMMON_CATHODE //type
		},//seg 0
		{DIO_u8PORTD,DIO_u8PIN0,//pin a
		 DIO_u8PORTA,DIO_u8PIN5, //pin b
		 DIO_u8PORTA,DIO_u8PIN3, //pin c
		 DIO_u8PORTB,DIO_u8PIN5, //pin d
		 DIO_u8PORTB,DIO_u8PIN1, //pin e
		 DIO_u8PORTC,DIO_u8PIN1, //pin f
		 DIO_u8PORTC,DIO_u8PIN6, //pin g
		 DIO_u8PORTD,DIO_u8PIN6, //pin cmn
		 NOT_CONNECTED,NOT_CONNECTED, //pin dot
		 COMMON_ANODE //type
		}//seg 1

};

