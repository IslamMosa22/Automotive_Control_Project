/*
 * LCDinit.h
 *
 *  Created on: Aug 17, 2023
 *      Author: Youssef
 */

#ifndef HAL_LCD_LCDINIT_H_
#define HAL_LCD_LCDINIT_H_

#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"
#include "../../MCAL/DIO/DIO_INIT.h"
#include <util/delay.h>


#define DataPort     PORTA
#define ControlPort  PORTB
#define FunctionSet  0b00111000
#define DisplayOF    0b00001111
#define DisplayCLR   0b00000001
#define EntryMode    0b00000110



void HLCD_voidInit();
void HLCD_voidSendCommand(u8 A_u8cmd);
void HLCD_voidSendData(u8 A_u8Data);
void HLCD_voidClear();
void HLCD_voidCustomChar(u8 A_u8Index,u8 Arr[]);
void HLCD_voidDisplyNumber(s32 A_s32Number);
void HLCD_voidSetCursor(u8 A_u8Line, u8 A_u8Pos);
void HLCD_voidSendString   (u8* Str);

#endif /* HAL_LCD_LCDINIT_H_ */
