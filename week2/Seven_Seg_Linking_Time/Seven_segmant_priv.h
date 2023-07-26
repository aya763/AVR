/*
 * Seven_segmant_priv.h
 *
 *  Created on: Jul 25, 2023
 *      Author: aya
 */

#ifndef SEVEN_SEGMANT_PRIV_H_
#define SEVEN_SEGMANT_PRIV_H_

#define COMMON_ANODE	5
#define COMMON_CATHODE	19
#define NOT_CONNECTED 	20

#define SEG_MASK_3BIT	7
#define SEG_USED_BITS_VAR_CHECK		21

#define SEG_MASK_BIT  1



static u8 SEG_Au8NumDisplay []= {  0x3f, 0x06, 0x5B,
							0x4F, 0x66, 0x6D,
							0x7D, 0x07, 0x7F,
							0x6F};


#endif /* SEVEN_SEGMANT_PRIV_H_ */
