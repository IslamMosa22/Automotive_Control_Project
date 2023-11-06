/*
 * INT_Init.h
 *
 *  Created on: Aug 22, 2023
 *      Author: Basim Osman
 */

#ifndef HAL_INTERRUPT_INT_INIT_H_
#define HAL_INTERRUPT_INT_INIT_H_

#include "../../LIB/STD_types.h"

#define GIFR_REG      *((volatile u8*)  0x5A )

#define Low_Level     0
#define OnChange      1
#define Falling_Edge  2
#define Rising_Edge   3

#define INT0          0
#define INT1          1
#define INT2          2



// Note INT2 pin has falling and rising edges only



void MEXTERNAL_INTERRUPT_voidSenseControl(u8 A_u8External_INT_Line, u8 A_u8External_Sense);
void MEXTERNAL_INTERRUPT_voidEnable(u8 A_u8Interrupt_Line);
void MEXTERNAL_INTERRUPT_voidDisable(u8 A_u8Interrupt_Line);                //InterruptLine == INT0 or INT1 or INT2 ,, 1 or 2 or 3


#endif /* HAL_INTERRUPT_INT_INIT_H_ */
