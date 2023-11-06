/*
 * UART_Priv.h
 *
 *  Created on: Aug 28, 2023
 *      Author: Youssef
 */

#ifndef MCAL_UART_UART_PRIV_H_
#define MCAL_UART_UART_PRIV_H_

#define  UBRRL  *((volatile u8*) 0x29)
#define  UCSRB  *((volatile u8*) 0x2a)
#define  UCSRA  *((volatile u8*) 0x2b)
#define  UDR    *((volatile u8*) 0x2c)
#define  UBRRH  *((volatile u8*) 0x40)
#define  UCSRC  *((volatile u8*) 0x40)

#define RXC   7
#define UDRE  5
#define TXC   6

#define RXEN  4
#define TXEN  3

#define URSEL 7
#define USBS  3
#define UCSZ0 1

#endif /* MCAL_UART_UART_PRIV_H_ */
