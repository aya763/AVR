/*
 * main.c
 *
 *  Created on: Oct 22, 2023
 *      Author: aya
 */


#include "../LIB/errorState.h"
#include "../LIB/types.h"




#include "../MCAL/DIO/DIO_int.h"
#include "../MCAL/DIO/DIO_priv.h"
#include "../MCAL/I2C_TWI/TWI_int.h"

#include <util/delay.h>

#define code 1

#if code==0 //Master

int main(void)
{
	u8 Data;
	IIC_enuInit();
	u8 arr[]="ahmed";

	while(1)
	{

		if(ES_OK==IIC_enuStartCondition())
		{
			if(ES_OK==IIC_enuWriteSlaveAddress(5,0))
			{
				for(u8 i=0;arr[i]!=0;i++)
				{
					if(ES_OK==IIC_enuWriteData(arr[i]));
				}

			}
		}

		IIC_enuStopCondition();

		/*//send one character
		if(ES_OK==IIC_enuStartCondition())
		{
			if(ES_OK==IIC_enuWriteSlaveAddress(5,0))
			{
				if(ES_OK==IIC_enuWriteData('@'))
				{
					IIC_enuStopCondition();
				}
			}
		}*/

		/*
		if(ES_OK==IIC_enuCheckMyAddress())
		{
			if(ES_OK==IIC_enuReadData(&Data))
			{
				DDRC=Data;
				//DIO_enuSetPortValue(DIO_u8PORTA,Data);
			}
		}*/
	}



	return 0;
}
#elif code==1 //slave

int main(void)
{

	u8 Data;
	//DIO_enuSetPortDirection(DIO_u8PORTA,0xff);
	IIC_enuInit();

	while(1)
	{
		if(ES_OK==IIC_enuCheckMyAddress())
		{
			if(ES_OK==IIC_enuReadData(&Data))
			{
				DDRA=Data;
				//DIO_enuSetPortValue(DIO_u8PORTA,Data);
			}
		}
		/*
		if(ES_OK==IIC_enuStartCondition())
		{
			if(ES_OK==IIC_enuWriteSlaveAddress(2,0))
			{
				if(ES_OK==IIC_enuWriteData('#'))
				{
					IIC_enuStopCondition();
				}
			}
		}*/
	}


	return 0;
}
#endif







