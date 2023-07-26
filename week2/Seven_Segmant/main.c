/*
 * main.c
 *
 *  Created on: Jul 25, 2023
 *      Author: aya
 */

#include "types.h"
#include "errorState.h"

#include "DIO_int.h"
#include "Seven_segmant_int.h"

#include "util/delay.h"

int main(void)
{
	ES_t error;
	DIO_enuInit();
	error=Seven_Segmant_enuInit();

	while(1)
	{
		//if(error==ES_OK)
		{
			for(u8 i=0;i<10;i++)
			{
				Seven_Segmant_enuDisplayNum(i);
				_delay_ms(500);
			}
		}
	}

	return 0;
}
