/*
 * UART.c
 *
 *  Created on: Aug 28, 2023
 *      Author: Youssef
 */

#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"

#include "UART_Init.h"
#include "UART_Priv.h"
#include "UART_Config.h"

void MUART_voidInit(void)
{
	/* Enable receiver and transmitter */
	UCSRB = (1<<RXEN)|(1<<TXEN);
	/* Set frame format: 8data, 2stop bit */
	UCSRC = (1<<URSEL)|(0<<USBS)|(3<<UCSZ0);
	/*Setting baud rate to 9600 (Standard) */
	UBRRH = (u8)(51>>8);
	UBRRL = (u8)51;

}

u8 MUART_u8Receive(void)
{

	/* Wait for data to be received */
	while ( !(UCSRA & (1<<RXC)) );
	/* Get and return received data from buffer */
	return UDR;

}

void MUART_voidTransmit( u8 A_u8Data )
{
	/* Wait for empty transmit buffer */
	while ( !( UCSRA & (1<<UDRE)) );
	/* Put data into buffer, sends the data */
	UDR = A_u8Data;
}

void MUART_voidBaud(u16 A_u16Baud)
{
	UBRRH = (u8)(A_u16Baud>>8);
	UBRRL = (u8)A_u16Baud;
}


void MUART_voidSendString   (u8* Str)
{
	u8 L_u8Counter;
	while(Str[L_u8Counter]!='\0')
	{

		MUART_voidTransmit(Str[L_u8Counter]);
		L_u8Counter++;

	}
	MUART_voidTransmit(Str[L_u8Counter]);
}
void MUART_voidReceiveString(u8* Str)
{
	u8 L_u8Count=0;

	while(1)
	{
		Str[L_u8Count]=MUART_u8Receive();
		if (Str[L_u8Count]=='\0')
		{
			break;
		}
		L_u8Count++;
	}

}
void MUART_voidSendNumber(u32 A_u32Number)
{
	for (u8 L_u8Counter=0;L_u8Counter<4;L_u8Counter++)
	{
		MUART_voidTransmit((A_u32Number>>(8*L_u8Counter)));
	}
}
u32 MUART_u32ReceiveNumber(void)
{
	u32 L_u32Number=0;
	for (u8 L_u8Counter=0;L_u8Counter<4;L_u8Counter++)
	{
		L_u32Number=L_u32Number | (MUART_u8Receive()<<(8*L_u8Counter));
	}
	return L_u32Number;
}
