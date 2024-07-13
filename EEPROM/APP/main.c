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
#include "../HAL/EEPROM/EEPROM_int.h"

#include <util/delay.h>

int main(void)
{
	EEPROM_enuInit();
	u8 data;
	EEPROM_enuWriteData(15,'a');
	_delay_ms(150);
	EEPROM_enuReadData(15,&data);
	DDRA=data;



	return 0;
}







