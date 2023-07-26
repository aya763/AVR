/*
 * Seven_segmant_int.h
 *
 *  Created on: Jul 25, 2023
 *      Author: aya
 */

#ifndef SEVEN_SEGMANT_INT_H_
#define SEVEN_SEGMANT_INT_H_

ES_t Seven_Segmant_enuInit(SEG_t *Copy_pstrSegConfig);

ES_t Seven_Segmant_enuDisplayNum(u8 Copy_u8SegID ,u8 Copy_u8Num);

ES_t Seven_Segmant_enuEnableCommon(u8 Copy_u8SegID);

ES_t Seven_Segmant_enuDisableCommon(u8 Copy_u8SegID);

ES_t Seven_Segmant_enuEnableDot(u8 Copy_u8SegID);

ES_t Seven_Segmant_enuDisableDot(u8 Copy_u8SegID);

ES_t Seven_Segmant_enuClearDisplay(u8 Copy_u8SegID);


#endif /* SEVEN_SEGMANT_INT_H_ */
