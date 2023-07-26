/*
 * Seven_segmant_prog.c
 *
 *  Created on: Jul 25, 2023
 *      Author: aya
 */

#include "types.h"
#include "errorState.h"

#include "DIO_int.h"

#include "Seven_segmant_config.h"
#include "Seven_segmant_priv.h"

extern SEG_t SEVSEG_AstrSegConfig[SEG_NUM];

ES_t Seven_Segmant_enuInit(SEG_t *Copy_pstrSegConfig)
{
	ES_t Local_enuErrorState=ES_NOK;

	if(Copy_pstrSegConfig!=NULL)
	{
		u8 Local_u8Iter=0;
		for(Local_u8Iter=0;Local_u8Iter<SEG_NUM;Local_u8Iter++)
		{
			Local_enuErrorState=DIO_enuSetPinDirection(Copy_pstrSegConfig[Local_u8Iter].SEG_u8APort,Copy_pstrSegConfig[Local_u8Iter].SEG_u8APin,DIO_u8OUTPUT);
			if(Local_enuErrorState!=ES_OK) return Local_enuErrorState;
			Local_enuErrorState=DIO_enuSetPinDirection(Copy_pstrSegConfig[Local_u8Iter].SEG_u8BPort,Copy_pstrSegConfig[Local_u8Iter].SEG_u8BPin,DIO_u8OUTPUT);
			if(Local_enuErrorState!=ES_OK) return Local_enuErrorState;
			Local_enuErrorState=DIO_enuSetPinDirection(Copy_pstrSegConfig[Local_u8Iter].SEG_u8CPort,Copy_pstrSegConfig[Local_u8Iter].SEG_u8CPin,DIO_u8OUTPUT);
			if(Local_enuErrorState!=ES_OK) return Local_enuErrorState;
			Local_enuErrorState=DIO_enuSetPinDirection(Copy_pstrSegConfig[Local_u8Iter].SEG_u8DPort,Copy_pstrSegConfig[Local_u8Iter].SEG_u8DPin,DIO_u8OUTPUT);
			if(Local_enuErrorState!=ES_OK) return Local_enuErrorState;
			Local_enuErrorState=DIO_enuSetPinDirection(Copy_pstrSegConfig[Local_u8Iter].SEG_u8EPort,Copy_pstrSegConfig[Local_u8Iter].SEG_u8EPin,DIO_u8OUTPUT);
			if(Local_enuErrorState!=ES_OK) return Local_enuErrorState;
			Local_enuErrorState=DIO_enuSetPinDirection(Copy_pstrSegConfig[Local_u8Iter].SEG_u8FPort,Copy_pstrSegConfig[Local_u8Iter].SEG_u8FPin,DIO_u8OUTPUT);
			if(Local_enuErrorState!=ES_OK) return Local_enuErrorState;
			Local_enuErrorState=DIO_enuSetPinDirection(Copy_pstrSegConfig[Local_u8Iter].SEG_u8GPort,Copy_pstrSegConfig[Local_u8Iter].SEG_u8GPin,DIO_u8OUTPUT);
			if(Local_enuErrorState!=ES_OK) return Local_enuErrorState;

			if(Copy_pstrSegConfig[Local_u8Iter].SEG_u8CMN_Port!=NOT_CONNECTED && Copy_pstrSegConfig[Local_u8Iter].SEG_u8CMN_Pin!=NOT_CONNECTED)
			{
				Local_enuErrorState=DIO_enuSetPinDirection(Copy_pstrSegConfig[Local_u8Iter].SEG_u8CMN_Port,Copy_pstrSegConfig[Local_u8Iter].SEG_u8CMN_Pin,DIO_u8OUTPUT);
				if(Local_enuErrorState!=ES_OK) return Local_enuErrorState;
			}
			if(Copy_pstrSegConfig[Local_u8Iter].SEG_u8DOT_Port!=NOT_CONNECTED && Copy_pstrSegConfig[Local_u8Iter].SEG_u8DOT_Pin!=NOT_CONNECTED)
			{
				Local_enuErrorState=DIO_enuSetPinDirection(Copy_pstrSegConfig[Local_u8Iter].SEG_u8DOT_Port,Copy_pstrSegConfig[Local_u8Iter].SEG_u8DOT_Pin,DIO_u8OUTPUT);
				if(Local_enuErrorState!=ES_OK) return Local_enuErrorState;
			}
		}
	}
	else
	{
		Local_enuErrorState=ES_NULL_POINTER;
	}

	return Local_enuErrorState;
}

ES_t Seven_Segmant_enuDisplayNum(u8 Copy_u8SegID ,u8 Copy_u8Num)
{
	ES_t Local_enuErrorState=ES_NOK;
	if(Copy_u8Num<10 && Copy_u8SegID<SEG_NUM)
	{
		if(SEVSEG_AstrSegConfig[Copy_u8SegID].SEG_u8Type==COMMON_CATHODE)
		{
			Local_enuErrorState=DIO_enuSetPinValue(SEVSEG_AstrSegConfig[Copy_u8SegID].SEG_u8APort,SEVSEG_AstrSegConfig[Copy_u8SegID].SEG_u8APin,((SEG_Au8NumDisplay[Copy_u8Num]>>0)&SEG_MASK_BIT));
			if(Local_enuErrorState!=ES_OK) return Local_enuErrorState;
			Local_enuErrorState=DIO_enuSetPinValue(SEVSEG_AstrSegConfig[Copy_u8SegID].SEG_u8BPort,SEVSEG_AstrSegConfig[Copy_u8SegID].SEG_u8BPin,((SEG_Au8NumDisplay[Copy_u8Num]>>1)&SEG_MASK_BIT));
			if(Local_enuErrorState!=ES_OK) return Local_enuErrorState;
			Local_enuErrorState=DIO_enuSetPinValue(SEVSEG_AstrSegConfig[Copy_u8SegID].SEG_u8CPort,SEVSEG_AstrSegConfig[Copy_u8SegID].SEG_u8CPin,((SEG_Au8NumDisplay[Copy_u8Num]>>2)&SEG_MASK_BIT));
			if(Local_enuErrorState!=ES_OK) return Local_enuErrorState;
			Local_enuErrorState=DIO_enuSetPinValue(SEVSEG_AstrSegConfig[Copy_u8SegID].SEG_u8DPort,SEVSEG_AstrSegConfig[Copy_u8SegID].SEG_u8DPin,((SEG_Au8NumDisplay[Copy_u8Num]>>3)&SEG_MASK_BIT));
			if(Local_enuErrorState!=ES_OK) return Local_enuErrorState;
			Local_enuErrorState=DIO_enuSetPinValue(SEVSEG_AstrSegConfig[Copy_u8SegID].SEG_u8EPort,SEVSEG_AstrSegConfig[Copy_u8SegID].SEG_u8EPin,((SEG_Au8NumDisplay[Copy_u8Num]>>4)&SEG_MASK_BIT));
			if(Local_enuErrorState!=ES_OK) return Local_enuErrorState;
			Local_enuErrorState=DIO_enuSetPinValue(SEVSEG_AstrSegConfig[Copy_u8SegID].SEG_u8FPort,SEVSEG_AstrSegConfig[Copy_u8SegID].SEG_u8FPin,((SEG_Au8NumDisplay[Copy_u8Num]>>5)&SEG_MASK_BIT));
			if(Local_enuErrorState!=ES_OK) return Local_enuErrorState;
			Local_enuErrorState=DIO_enuSetPinValue(SEVSEG_AstrSegConfig[Copy_u8SegID].SEG_u8GPort,SEVSEG_AstrSegConfig[Copy_u8SegID].SEG_u8GPin,((SEG_Au8NumDisplay[Copy_u8Num]>>6)&SEG_MASK_BIT));
			if(Local_enuErrorState!=ES_OK) return Local_enuErrorState;
			//Local_enuErrorState=ES_OK;
		}
		else if(SEVSEG_AstrSegConfig[Copy_u8SegID].SEG_u8Type==COMMON_ANODE)
		{
			Local_enuErrorState=DIO_enuSetPinValue(SEVSEG_AstrSegConfig[Copy_u8SegID].SEG_u8APort,SEVSEG_AstrSegConfig[Copy_u8SegID].SEG_u8APin,!((SEG_Au8NumDisplay[Copy_u8Num]>>0)&SEG_MASK_BIT));
			if(Local_enuErrorState!=ES_OK) return Local_enuErrorState;
			Local_enuErrorState=DIO_enuSetPinValue(SEVSEG_AstrSegConfig[Copy_u8SegID].SEG_u8BPort,SEVSEG_AstrSegConfig[Copy_u8SegID].SEG_u8BPin,!((SEG_Au8NumDisplay[Copy_u8Num]>>1)&SEG_MASK_BIT));
			if(Local_enuErrorState!=ES_OK) return Local_enuErrorState;
			Local_enuErrorState=DIO_enuSetPinValue(SEVSEG_AstrSegConfig[Copy_u8SegID].SEG_u8CPort,SEVSEG_AstrSegConfig[Copy_u8SegID].SEG_u8CPin,!((SEG_Au8NumDisplay[Copy_u8Num]>>2)&SEG_MASK_BIT));
			if(Local_enuErrorState!=ES_OK) return Local_enuErrorState;
			Local_enuErrorState=DIO_enuSetPinValue(SEVSEG_AstrSegConfig[Copy_u8SegID].SEG_u8DPort,SEVSEG_AstrSegConfig[Copy_u8SegID].SEG_u8DPin,!((SEG_Au8NumDisplay[Copy_u8Num]>>3)&SEG_MASK_BIT));
			if(Local_enuErrorState!=ES_OK) return Local_enuErrorState;
			Local_enuErrorState=DIO_enuSetPinValue(SEVSEG_AstrSegConfig[Copy_u8SegID].SEG_u8EPort,SEVSEG_AstrSegConfig[Copy_u8SegID].SEG_u8EPin,!((SEG_Au8NumDisplay[Copy_u8Num]>>4)&SEG_MASK_BIT));
			if(Local_enuErrorState!=ES_OK) return Local_enuErrorState;
			Local_enuErrorState=DIO_enuSetPinValue(SEVSEG_AstrSegConfig[Copy_u8SegID].SEG_u8FPort,SEVSEG_AstrSegConfig[Copy_u8SegID].SEG_u8FPin,!((SEG_Au8NumDisplay[Copy_u8Num]>>5)&SEG_MASK_BIT));
			if(Local_enuErrorState!=ES_OK) return Local_enuErrorState;
			Local_enuErrorState=DIO_enuSetPinValue(SEVSEG_AstrSegConfig[Copy_u8SegID].SEG_u8GPort,SEVSEG_AstrSegConfig[Copy_u8SegID].SEG_u8GPin,!((SEG_Au8NumDisplay[Copy_u8Num]>>6)&SEG_MASK_BIT));
			if(Local_enuErrorState!=ES_OK) return Local_enuErrorState;
		}
	}
	else
	{
		Local_enuErrorState=ES_OUT_OF_RANGE;
	}

	return Local_enuErrorState;
}

ES_t Seven_Segmant_enuEnableCommon(u8 Copy_u8SegID)
{
	ES_t Local_enuErrorState=ES_NOK;

	if(Copy_u8SegID<SEG_NUM)
	{
		if(SEVSEG_AstrSegConfig[Copy_u8SegID].SEG_u8CMN_Port!=NOT_CONNECTED && SEVSEG_AstrSegConfig[Copy_u8SegID].SEG_u8CMN_Pin!=NOT_CONNECTED)
		{
			if(SEVSEG_AstrSegConfig[Copy_u8SegID].SEG_u8Type==COMMON_CATHODE)
			{
				Local_enuErrorState=DIO_enuSetPinValue(SEVSEG_AstrSegConfig[Copy_u8SegID].SEG_u8CMN_Port,SEVSEG_AstrSegConfig[Copy_u8SegID].SEG_u8CMN_Pin,DIO_u8LOW);
			}
			else if(SEVSEG_AstrSegConfig[Copy_u8SegID].SEG_u8Type==COMMON_ANODE)
			{
				Local_enuErrorState=DIO_enuSetPinValue(SEVSEG_AstrSegConfig[Copy_u8SegID].SEG_u8CMN_Port,SEVSEG_AstrSegConfig[Copy_u8SegID].SEG_u8CMN_Pin,DIO_u8HIGH);
			}
		}
	}
	else
	{
		Local_enuErrorState=ES_OUT_OF_RANGE;
	}

	return Local_enuErrorState;
}

ES_t Seven_Segmant_enuDisableCommon(u8 Copy_u8SegID)
{
	ES_t Local_enuErrorState=ES_NOK;

	if(Copy_u8SegID<SEG_NUM)
	{
		if(SEVSEG_AstrSegConfig[Copy_u8SegID].SEG_u8CMN_Port!=NOT_CONNECTED && SEVSEG_AstrSegConfig[Copy_u8SegID].SEG_u8CMN_Pin!=NOT_CONNECTED)
		{
			if(SEVSEG_AstrSegConfig[Copy_u8SegID].SEG_u8Type==COMMON_CATHODE)
			{
				Local_enuErrorState=DIO_enuSetPinValue(SEVSEG_AstrSegConfig[Copy_u8SegID].SEG_u8CMN_Port,SEVSEG_AstrSegConfig[Copy_u8SegID].SEG_u8CMN_Pin,DIO_u8HIGH);
			}
			else if(SEVSEG_AstrSegConfig[Copy_u8SegID].SEG_u8Type==COMMON_ANODE)
			{
				Local_enuErrorState=DIO_enuSetPinValue(SEVSEG_AstrSegConfig[Copy_u8SegID].SEG_u8CMN_Port,SEVSEG_AstrSegConfig[Copy_u8SegID].SEG_u8CMN_Pin,DIO_u8LOW);
			}
		}
	}
	else
	{
		Local_enuErrorState=ES_OUT_OF_RANGE;
	}

	return Local_enuErrorState;
}

ES_t Seven_Segmant_enuEnableDot(u8 Copy_u8SegID)
{
	ES_t Local_enuErrorState=ES_NOK;

	if(Copy_u8SegID<SEG_NUM)
	{
		if(SEVSEG_AstrSegConfig[Copy_u8SegID].SEG_u8DOT_Port!=NOT_CONNECTED && SEVSEG_AstrSegConfig[Copy_u8SegID].SEG_u8DOT_Pin!=NOT_CONNECTED)
		{
			if(SEVSEG_AstrSegConfig[Copy_u8SegID].SEG_u8Type==COMMON_CATHODE)
			{
				Local_enuErrorState=DIO_enuSetPinValue(SEVSEG_AstrSegConfig[Copy_u8SegID].SEG_u8DOT_Port,SEVSEG_AstrSegConfig[Copy_u8SegID].SEG_u8DOT_Pin,DIO_u8HIGH);
			}
			else if(SEVSEG_AstrSegConfig[Copy_u8SegID].SEG_u8Type==COMMON_ANODE)
			{
				Local_enuErrorState=DIO_enuSetPinValue(SEVSEG_AstrSegConfig[Copy_u8SegID].SEG_u8DOT_Port,SEVSEG_AstrSegConfig[Copy_u8SegID].SEG_u8DOT_Pin,DIO_u8LOW);
			}
		}
	}
	else
	{
		Local_enuErrorState=ES_OUT_OF_RANGE;
	}

	return Local_enuErrorState;
}

ES_t Seven_Segmant_enuDisableDot(u8 Copy_u8SegID)
{
	ES_t Local_enuErrorState=ES_NOK;

	if(Copy_u8SegID<SEG_NUM)
	{
		if(SEVSEG_AstrSegConfig[Copy_u8SegID].SEG_u8DOT_Port!=NOT_CONNECTED && SEVSEG_AstrSegConfig[Copy_u8SegID].SEG_u8DOT_Pin!=NOT_CONNECTED)
		{
			if(SEVSEG_AstrSegConfig[Copy_u8SegID].SEG_u8Type==COMMON_CATHODE)
			{
				Local_enuErrorState=DIO_enuSetPinValue(SEVSEG_AstrSegConfig[Copy_u8SegID].SEG_u8DOT_Port,SEVSEG_AstrSegConfig[Copy_u8SegID].SEG_u8DOT_Pin,DIO_u8LOW);
			}
			else if(SEVSEG_AstrSegConfig[Copy_u8SegID].SEG_u8Type==COMMON_ANODE)
			{
				Local_enuErrorState=DIO_enuSetPinValue(SEVSEG_AstrSegConfig[Copy_u8SegID].SEG_u8DOT_Port,SEVSEG_AstrSegConfig[Copy_u8SegID].SEG_u8DOT_Pin,DIO_u8HIGH);
			}
		}
	}
	else
	{
		Local_enuErrorState=ES_OUT_OF_RANGE;
	}

	return Local_enuErrorState;
}

ES_t Seven_Segmant_enuClearDisplay(u8 Copy_u8SegID)
{
	ES_t Local_enuErrorState=ES_NOK;

	if( Copy_u8SegID<SEG_NUM)
		{
			if(SEVSEG_AstrSegConfig[Copy_u8SegID].SEG_u8Type==COMMON_CATHODE)
			{
				Local_enuErrorState=DIO_enuSetPinValue(SEVSEG_AstrSegConfig[Copy_u8SegID].SEG_u8APort,SEVSEG_AstrSegConfig[Copy_u8SegID].SEG_u8APin,DIO_u8LOW);
				if(Local_enuErrorState!=ES_OK) return Local_enuErrorState;
				Local_enuErrorState=DIO_enuSetPinValue(SEVSEG_AstrSegConfig[Copy_u8SegID].SEG_u8BPort,SEVSEG_AstrSegConfig[Copy_u8SegID].SEG_u8BPin,DIO_u8LOW);
				if(Local_enuErrorState!=ES_OK) return Local_enuErrorState;
				Local_enuErrorState=DIO_enuSetPinValue(SEVSEG_AstrSegConfig[Copy_u8SegID].SEG_u8CPort,SEVSEG_AstrSegConfig[Copy_u8SegID].SEG_u8CPin,DIO_u8LOW);
				if(Local_enuErrorState!=ES_OK) return Local_enuErrorState;
				Local_enuErrorState=DIO_enuSetPinValue(SEVSEG_AstrSegConfig[Copy_u8SegID].SEG_u8DPort,SEVSEG_AstrSegConfig[Copy_u8SegID].SEG_u8DPin,DIO_u8LOW);
				if(Local_enuErrorState!=ES_OK) return Local_enuErrorState;
				Local_enuErrorState=DIO_enuSetPinValue(SEVSEG_AstrSegConfig[Copy_u8SegID].SEG_u8EPort,SEVSEG_AstrSegConfig[Copy_u8SegID].SEG_u8EPin,DIO_u8LOW);
				if(Local_enuErrorState!=ES_OK) return Local_enuErrorState;
				Local_enuErrorState=DIO_enuSetPinValue(SEVSEG_AstrSegConfig[Copy_u8SegID].SEG_u8FPort,SEVSEG_AstrSegConfig[Copy_u8SegID].SEG_u8FPin,DIO_u8LOW);
				if(Local_enuErrorState!=ES_OK) return Local_enuErrorState;
				Local_enuErrorState=DIO_enuSetPinValue(SEVSEG_AstrSegConfig[Copy_u8SegID].SEG_u8GPort,SEVSEG_AstrSegConfig[Copy_u8SegID].SEG_u8GPin,DIO_u8LOW);
				if(Local_enuErrorState!=ES_OK) return Local_enuErrorState;
			}
			else if(SEVSEG_AstrSegConfig[Copy_u8SegID].SEG_u8Type==COMMON_ANODE)
			{
				Local_enuErrorState=DIO_enuSetPinValue(SEVSEG_AstrSegConfig[Copy_u8SegID].SEG_u8APort,SEVSEG_AstrSegConfig[Copy_u8SegID].SEG_u8APin,DIO_u8HIGH);
				if(Local_enuErrorState!=ES_OK) return Local_enuErrorState;
				Local_enuErrorState=DIO_enuSetPinValue(SEVSEG_AstrSegConfig[Copy_u8SegID].SEG_u8BPort,SEVSEG_AstrSegConfig[Copy_u8SegID].SEG_u8BPin,DIO_u8HIGH);
				if(Local_enuErrorState!=ES_OK) return Local_enuErrorState;
				Local_enuErrorState=DIO_enuSetPinValue(SEVSEG_AstrSegConfig[Copy_u8SegID].SEG_u8CPort,SEVSEG_AstrSegConfig[Copy_u8SegID].SEG_u8CPin,DIO_u8HIGH);
				if(Local_enuErrorState!=ES_OK) return Local_enuErrorState;
				Local_enuErrorState=DIO_enuSetPinValue(SEVSEG_AstrSegConfig[Copy_u8SegID].SEG_u8DPort,SEVSEG_AstrSegConfig[Copy_u8SegID].SEG_u8DPin,DIO_u8HIGH);
				if(Local_enuErrorState!=ES_OK) return Local_enuErrorState;
				Local_enuErrorState=DIO_enuSetPinValue(SEVSEG_AstrSegConfig[Copy_u8SegID].SEG_u8EPort,SEVSEG_AstrSegConfig[Copy_u8SegID].SEG_u8EPin,DIO_u8HIGH);
				if(Local_enuErrorState!=ES_OK) return Local_enuErrorState;
				Local_enuErrorState=DIO_enuSetPinValue(SEVSEG_AstrSegConfig[Copy_u8SegID].SEG_u8FPort,SEVSEG_AstrSegConfig[Copy_u8SegID].SEG_u8FPin,DIO_u8HIGH);
				if(Local_enuErrorState!=ES_OK) return Local_enuErrorState;
				Local_enuErrorState=DIO_enuSetPinValue(SEVSEG_AstrSegConfig[Copy_u8SegID].SEG_u8GPort,SEVSEG_AstrSegConfig[Copy_u8SegID].SEG_u8GPin,DIO_u8HIGH);
				if(Local_enuErrorState!=ES_OK) return Local_enuErrorState;
			}
		}
		else
		{
			Local_enuErrorState=ES_OUT_OF_RANGE;
		}

	return Local_enuErrorState;
}



