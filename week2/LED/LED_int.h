/*
 * LED_int.h
 *
 *  Created on: Jul 23, 2023
 *      Author: aya
 */

#ifndef LED_INT_H_
#define LED_INT_H_

ES_t LED_enuInit(LED_t * copy_pstrLedConfig);

ES_t LED_enuTurnON(LED_t * copy_pstrLedID);

ES_t LED_enuTurnOFF(LED_t * copy_pstrLedID);

#endif /* LED_INT_H_ */
