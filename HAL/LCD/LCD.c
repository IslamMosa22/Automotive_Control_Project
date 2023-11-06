/*
 * LCD.c
 *
 *  Created on: Aug 17, 2023
 *      Author: Youssef
 */

#include "LCDinit.h"


void HLCD_voidInit()
{
	// Wait for more than 30ms
		_delay_ms(30);
	// Function Set --> 0b00111000
		HLCD_voidSendCommand(FunctionSet);
	//wait for more than 39us
		_delay_ms(1);
	// Display ON/OFF -->  0b00001111
		HLCD_voidSendCommand(DisplayOF);
	//wait for more than 39us
		_delay_ms(1);
	//Display Clear --> 0b00000001
		HLCD_voidSendCommand(DisplayCLR);
	//wait for more than 1.53ms
		_delay_ms(2);
	//Entry Mode Set --> 0b00000110
		HLCD_voidSendCommand(EntryMode);

}
void HLCD_voidSendCommand(u8 A_u8cmd)
{
	// RS--> LOW  .... R/W -->LOW

		MDIO_voidSetPinValue(ControlPort,PIN0,LOW);
		MDIO_voidSetPinValue(ControlPort,PIN1,LOW);
	// Enable HIGH
		MDIO_voidSetPinValue(ControlPort,PIN2,HIGH);
	// delay
		_delay_ms(1);
		MDIO_voidSetPortValue(DataPort,A_u8cmd);

		MDIO_voidSetPinValue(ControlPort,PIN2,LOW);


}
void HLCD_voidSendData(u8 A_u8Data)
{
	// RS--> HIGH  .... R/W -->LOW

		MDIO_voidSetPinValue(ControlPort,PIN0,HIGH);
		MDIO_voidSetPinValue(ControlPort,PIN1,LOW);
		MDIO_voidSetPortValue(DataPort,A_u8Data);
	// Enable HIGH
		MDIO_voidSetPinValue(ControlPort,PIN2,HIGH);
	// delay
		_delay_ms(1);

		MDIO_voidSetPinValue(ControlPort,PIN2,LOW);
}
void HLCD_voidClear()
{
	HLCD_voidSendCommand(DisplayCLR);
	_delay_ms(2);
}


void HLCD_voidCustomChar(u8 A_u8Index,u8 Arr[8])
{
	if (A_u8Index <8)
	{
		HLCD_voidSendCommand(0x40+A_u8Index*8);

		for (u8 L_u8Counter =0 ; L_u8Counter <8; L_u8Counter++)
		{
			HLCD_voidSendData(Arr[L_u8Counter]);
		}

		HLCD_voidSendCommand(0x80);
	}
}

void HLCD_voidSendString   (u8* Str)
{
	u8* L_u8Count=Str;
	while(*L_u8Count!='\0')
	{
		HLCD_voidSendData(*L_u8Count);
		L_u8Count++;
	}
}
void HLCD_voidDisplyNumber(s32 A_s32Number)
{
	u32 L_u32Number=1;
		if(A_s32Number==0)
		{
		HLCD_voidSendData('0');
		}

		else if(A_s32Number<0)
		{
			HLCD_voidSendData('-');
			A_s32Number=A_s32Number*-1;

		}
		{
			while(A_s32Number!=0)
			{
			L_u32Number=L_u32Number*10+A_s32Number%10;
			A_s32Number=A_s32Number/10;
			}
			while(L_u32Number!=1)
			{
				HLCD_voidSendData(0x30+L_u32Number%10);
				L_u32Number=L_u32Number/10;
			}

		}

}

void HLCD_voidSetCursor(u8 A_u8Line, u8 A_u8Pos)
{
	HLCD_voidSendCommand(0x80+A_u8Line*64+A_u8Pos);

}
