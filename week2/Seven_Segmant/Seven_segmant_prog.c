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

ES_t Seven_Segmant_enuInit(void)
{
	ES_t Local_enuErrorState=ES_NOK;

	u32 Local_u32Check=0;
	Local_u32Check=DIO_enuSetPinDirection(SEG_APORT,SEG_APIN,DIO_u8OUTPUT);
	Local_u32Check |=(DIO_enuSetPinDirection(SEG_BPORT,SEG_BPIN,DIO_u8OUTPUT)<< 3);
	Local_u32Check |=(DIO_enuSetPinDirection(SEG_CPORT,SEG_CPIN,DIO_u8OUTPUT)<< 6);
	Local_u32Check |=(DIO_enuSetPinDirection(SEG_DPORT,SEG_DPIN,DIO_u8OUTPUT)<< 9);
	Local_u32Check |=(DIO_enuSetPinDirection(SEG_EPORT,SEG_EPIN,DIO_u8OUTPUT)<< 12);
	Local_u32Check |=(DIO_enuSetPinDirection(SEG_FPORT,SEG_FPIN,DIO_u8OUTPUT)<< 15);
	Local_u32Check |=(DIO_enuSetPinDirection(SEG_GPORT,SEG_GPIN,DIO_u8OUTPUT)<< 18);

#if SEG_CMN<=DIO_u8PIN7 && SEG_CMN_PORT<=DIO_u8PORTD
	DIO_enuSetPinDirection(SEG_CMN_PORT,SEG_CMN,DIO_u8OUTPUT);
#elif SEG_CMN==NOT_CONNECTED || SEG_CMN_PORT==NOT_CONNECTED

#else
#error"your common pin has a wrong selection"
#endif

#if SEG_DOT<=DIO_u8PIN7 && SEG_DOT_PORT<=DIO_u8PORTD
	DIO_enuSetPinDirection(SEG_DOT_PORT,SEG_DOT,DIO_u8OUTPUT);
#elif SEG_DOT==NOT_CONNECTED || SEG_DOT_PORT==NOT_CONNECTED

#else
#error"your DOT pin has a wrong selection"
#endif

	/**((u8*)0x43)=0;
	*((u8*)0x5c)=0;
	*((u8*)0x4a)=0;

	*((u8*)0x43)=(u8)Local_u32Check;
	*((u8*)0x5c)=(u8)(Local_u32Check>>8);
	*((u8*)0x4a)=(u8)(Local_u32Check>>16);*/



	u8 Local_u8Iter=0;
	for(Local_u8Iter=0;Local_u8Iter<SEG_USED_BITS_VAR_CHECK;Local_u8Iter+=3)//sizeof(Local_u32Check)*8
	{
		if((((Local_u32Check)>>Local_u8Iter)&SEG_MASK_3BIT)!=ES_OK)
		{
			return Local_enuErrorState;
		}
	}
	Local_enuErrorState=ES_OK;

	return Local_enuErrorState;
}

ES_t Seven_Segmant_enuDisplayNum(u8 Copy_u8Num)
{
	ES_t Local_enuErrorState=ES_NOK;
	if(Copy_u8Num<10)
	{
#if SEG_TYPE == COMMON_CATHODE
		u32 Local_u32Check=0;
		Local_u32Check=DIO_enuSetPinValue(SEG_APORT,SEG_APIN,((SEG_Au8NumDisplay[Copy_u8Num]>>0)&SEG_MASK_BIT));
		Local_u32Check |=(DIO_enuSetPinValue(SEG_BPORT,SEG_BPIN,((SEG_Au8NumDisplay[Copy_u8Num]>>1)&SEG_MASK_BIT))<< 3);
		Local_u32Check |=(DIO_enuSetPinValue(SEG_CPORT,SEG_CPIN,((SEG_Au8NumDisplay[Copy_u8Num]>>2)&SEG_MASK_BIT))<< 6);
		Local_u32Check |=(DIO_enuSetPinValue(SEG_DPORT,SEG_DPIN,((SEG_Au8NumDisplay[Copy_u8Num]>>3)&SEG_MASK_BIT))<< 9);
		Local_u32Check |=(DIO_enuSetPinValue(SEG_EPORT,SEG_EPIN,((SEG_Au8NumDisplay[Copy_u8Num]>>4)&SEG_MASK_BIT))<< 12);
		Local_u32Check |=(DIO_enuSetPinValue(SEG_FPORT,SEG_FPIN,((SEG_Au8NumDisplay[Copy_u8Num]>>5)&SEG_MASK_BIT))<< 15);
		Local_u32Check |=(DIO_enuSetPinValue(SEG_GPORT,SEG_GPIN,((SEG_Au8NumDisplay[Copy_u8Num]>>6)&SEG_MASK_BIT))<< 18);

		u8 Local_u8Iter=0;
		for(Local_u8Iter=0;Local_u8Iter<SEG_USED_BITS_VAR_CHECK;Local_u8Iter+=3)
		{
			if((((Local_u32Check)>>Local_u8Iter)&SEG_MASK_3BIT)!=ES_OK)
			{
				return Local_enuErrorState;
			}
		}
		Local_enuErrorState=ES_OK;
#elif SEG_TYPE ==COMMON_ANODE
		u32 Local_u32Check=0;
		Local_u32Check=DIO_enuSetPinValue(SEG_APORT,SEG_APIN,!((SEG_Au8NumDisplay[Copy_u8Num]>>0)&SEG_MASK_BIT));
		Local_u32Check |=(DIO_enuSetPinValue(SEG_BPORT,SEG_BPIN,!((SEG_Au8NumDisplay[Copy_u8Num]>>1)&SEG_MASK_BIT))<< 3);
		Local_u32Check |=(DIO_enuSetPinValue(SEG_CPORT,SEG_CPIN,!((SEG_Au8NumDisplay[Copy_u8Num]>>2)&SEG_MASK_BIT))<< 6);
		Local_u32Check |=(DIO_enuSetPinValue(SEG_DPORT,SEG_DPIN,!((SEG_Au8NumDisplay[Copy_u8Num]>>3)&SEG_MASK_BIT))<< 9);
		Local_u32Check |=(DIO_enuSetPinValue(SEG_EPORT,SEG_EPIN,!((SEG_Au8NumDisplay[Copy_u8Num]>>4)&SEG_MASK_BIT))<< 12);
		Local_u32Check |=(DIO_enuSetPinValue(SEG_FPORT,SEG_FPIN,!((SEG_Au8NumDisplay[Copy_u8Num]>>5)&SEG_MASK_BIT))<< 15);
		Local_u32Check |=(DIO_enuSetPinValue(SEG_GPORT,SEG_GPIN,!((SEG_Au8NumDisplay[Copy_u8Num]>>6)&SEG_MASK_BIT))<< 18);

		u8 Local_u8Iter=0;
		for(Local_u8Iter=0;Local_u8Iter<SEG_USED_BITS_VAR_CHECK;Local_u8Iter+=3)
		{
			if((((Local_u32Check)>>Local_u8Iter)&SEG_MASK_3BIT)!=ES_OK)
			{
				return Local_enuErrorState;
			}
		}
		Local_enuErrorState=ES_OK;
#else
#error"SEG type has a wrong selection"
#endif
	}
	else
	{
		Local_enuErrorState=ES_OUT_OF_RANGE;
	}

	return Local_enuErrorState;
}

ES_t Seven_Segmant_enuEnableCommon(void)
{
	ES_t Local_enuErrorState=ES_NOK;

#if SEG_CMN<=DIO_u8PIN7 && SEG_CMN_PORT<=DIO_u8PORTD
	#if SEG_TYPE==COMMON_CATHODE
		Local_enuErrorState=DIO_enuSetPinValue(SEG_CMN_PORT,SEG_CMN,DIO_u8LOW);
	#elif SEG_TYPE==COMMON_ANODE
		Local_enuErrorState=DIO_enuSetPinValue(SEG_CMN_PORT,SEG_CMN,DIO_u8HIGH);
	#else
	#error"SEG type has a wrong selection"
	#endif
#elif SEG_CMN==NOT_CONNECTED || SEG_CMN_PORT==NOT_CONNECTED

#else
#error"your common pin has a wrong selection"
#endif

	return Local_enuErrorState;
}

ES_t Seven_Segmant_enuDisableCommon(void)
{
	ES_t Local_enuErrorState=ES_NOK;
#if SEG_CMN<=DIO_u8PIN7 && SEG_CMN_PORT<=DIO_u8PORTD
	#if SEG_TYPE==COMMON_CATHODE
		Local_enuErrorState=DIO_enuSetPinValue(SEG_CMN_PORT,SEG_CMN,DIO_u8HIGH);
	#elif SEG_TYPE==COMMON_ANODE
		Local_enuErrorState=DIO_enuSetPinValue(SEG_CMN_PORT,SEG_CMN,DIO_u8LOW);
	#else
	#error"SEG type has a wrong selection"
	#endif
#elif SEG_CMN==NOT_CONNECTED || SEG_CMN_PORT==NOT_CONNECTED

#else
#error"your common pin has a wrong selection"
#endif

	return Local_enuErrorState;
}

ES_t Seven_Segmant_enuEnableDot(void)
{
	ES_t Local_enuErrorState=ES_NOK;
#if SEG_DOT<=DIO_u8PIN7 && SEG_DOT_PORT<=DIO_u8PORTD
	#if SEG_TYPE==COMMON_CATHODE
		Local_enuErrorState=DIO_enuSetPinValue(SEG_CMN_PORT,SEG_CMN,DIO_u8HIGH);
	#elif SEG_TYPE==COMMON_ANODE
		Local_enuErrorState=DIO_enuSetPinValue(SEG_CMN_PORT,SEG_CMN,DIO_u8LOW);
	#else
	#error"SEG type has a wrong selection"
	#endif
#elif SEG_DOT==NOT_CONNECTED || SEG_DOT_PORT==NOT_CONNECTED

#else
#error"your DOT pin has a wrong selection"
#endif

	return Local_enuErrorState;
}

ES_t Seven_Segmant_enuDisableDot(void)
{
	ES_t Local_enuErrorState=ES_NOK;
#if SEG_DOT<=DIO_u8PIN7 && SEG_DOT_PORT<=DIO_u8PORTD
	#if SEG_TYPE==COMMON_CATHODE
		Local_enuErrorState=DIO_enuSetPinValue(SEG_CMN_PORT,SEG_CMN,DIO_u8LOW);
	#elif SEG_TYPE==COMMON_ANODE
		Local_enuErrorState=DIO_enuSetPinValue(SEG_CMN_PORT,SEG_CMN,DIO_u8HIGH);
	#else
	#error"SEG type has a wrong selection"
	#endif
#elif SEG_DOT==NOT_CONNECTED || SEG_DOT_PORT==NOT_CONNECTED

#else
#error"your DOT pin has a wrong selection"
#endif

	return Local_enuErrorState;
}

ES_t Seven_Segmant_enuClearDisplay(void)
{
	ES_t Local_enuErrorState=ES_NOK;
#if SEG_TYPE == COMMON_CATHODE
		u32 Local_u32Check=0;
		Local_u32Check =  DIO_enuSetPinValue(SEG_APORT,SEG_APIN,DIO_u8LOW);
		Local_u32Check |=(DIO_enuSetPinValue(SEG_BPORT,SEG_BPIN,DIO_u8LOW)<< 3);
		Local_u32Check |=(DIO_enuSetPinValue(SEG_CPORT,SEG_CPIN,DIO_u8LOW)<< 6);
		Local_u32Check |=(DIO_enuSetPinValue(SEG_DPORT,SEG_DPIN,DIO_u8LOW)<< 9);
		Local_u32Check |=(DIO_enuSetPinValue(SEG_EPORT,SEG_EPIN,DIO_u8LOW)<< 12);
		Local_u32Check |=(DIO_enuSetPinValue(SEG_FPORT,SEG_FPIN,DIO_u8LOW)<< 15);
		Local_u32Check |=(DIO_enuSetPinValue(SEG_GPORT,SEG_GPIN,DIO_u8LOW)<< 18);

		u8 Local_u8Iter=0;
		for(Local_u8Iter=0;Local_u8Iter<SEG_USED_BITS_VAR_CHECK;Local_u8Iter+=3)
		{
			if((((Local_u32Check)>>Local_u8Iter)&SEG_MASK_3BIT)!=ES_OK)
			{
				return Local_enuErrorState;
			}
		}
		Local_enuErrorState=ES_OK;
#elif SEG_TYPE ==COMMON_ANODE
		u32 Local_u32Check=0;
		Local_u32Check=DIO_enuSetPinValue(SEG_APORT,SEG_APIN,DIO_u8HIGH);
		Local_u32Check |=(DIO_enuSetPinValue(SEG_BPORT,SEG_BPIN,DIO_u8HIGH)<< 3);
		Local_u32Check |=(DIO_enuSetPinValue(SEG_CPORT,SEG_CPIN,DIO_u8HIGH)<< 6);
		Local_u32Check |=(DIO_enuSetPinValue(SEG_DPORT,SEG_DPIN,DIO_u8HIGH)<< 9);
		Local_u32Check |=(DIO_enuSetPinValue(SEG_EPORT,SEG_EPIN,DIO_u8HIGH)<< 12);
		Local_u32Check |=(DIO_enuSetPinValue(SEG_FPORT,SEG_FPIN,DIO_u8HIGH)<< 15);
		Local_u32Check |=(DIO_enuSetPinValue(SEG_GPORT,SEG_GPIN,DIO_u8HIGH)<< 18);

		u8 Local_u8Iter=0;
		for(Local_u8Iter=0;Local_u8Iter<SEG_USED_BITS_VAR_CHECK;Local_u8Iter+=3)
		{
			if((((Local_u32Check)>>Local_u8Iter)&SEG_MASK_3BIT)!=ES_OK)
			{
				return Local_enuErrorState;
			}
		}
		Local_enuErrorState=ES_OK;
#else
#error"SEG type has a wrong selection"
#endif

	return Local_enuErrorState;
}



