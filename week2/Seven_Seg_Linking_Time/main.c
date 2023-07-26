/*
 * main.c
 *
 *  Created on: Jul 25, 2023
 *      Author: aya
 */

#include "types.h"
#include "errorState.h"

#include "DIO_int.h"
#include "Seven_segmant_config.h"
#include "Seven_segmant_int.h"

#include "util/delay.h"

extern SEG_t SEVSEG_AstrSegConfig[SEG_NUM];

int main(void)
{
	DIO_enuInit();
	Seven_Segmant_enuInit(SEVSEG_AstrSegConfig);

	while(1)
	{
		Seven_Segmant_enuDisableCommon(0);
		Seven_Segmant_enuDisplayNum(0,9);
		Seven_Segmant_enuEnableCommon(0);
		_delay_ms(10);

		Seven_Segmant_enuDisableCommon(0);
		Seven_Segmant_enuDisplayNum(1,6);
		Seven_Segmant_enuEnableCommon(1);
		_delay_ms(10);

		Seven_Segmant_enuDisableCommon(1);

		//if(error==ES_OK)
		/*{
			for(u8 i=0;i<10;i++)
			{
				Seven_Segmant_enuDisplayNum(0,i);
				Seven_Segmant_enuDisplayNum(1,0);
				for(u8 j=0;j<10;j++)
				{
					Seven_Segmant_enuDisplayNum(1,j);
					_delay_ms(300);
				}

			}
		}*/
	}

	return 0;
}
