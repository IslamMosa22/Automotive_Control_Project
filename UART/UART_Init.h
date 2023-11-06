/*
 * UART_Init.h
 *
 *  Created on: Aug 28, 2023
 *      Author: Youssef
 */

#ifndef MCAL_UART_UART_INIT_H_
#define MCAL_UART_UART_INIT_H_


u8 MUART_u8Receive          (void);
void MUART_voidTransmit     ( u8 A_u8Data );
void MUART_voidInit         (void);
void MUART_voidBaud         (u16 A_u16Baud);

void MUART_voidSendString   (u8* Str);
void MUART_voidReceiveString(u8* Str);
void MUART_voidSendNumber   (u32 A_u32Number);
u32 MUART_u32ReceiveNumber(void);

#endif /* MCAL_UART_UART_INIT_H_ */
