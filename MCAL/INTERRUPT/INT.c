/*
 * INT.c
 *
 *  Created on: Aug 22, 2023
 *      Author: Basim Osman
 */

#include "INT_Init.h"
#include "../../LIB/BIT_MATH.h"


#define STATUS_REG    *((volatile u8*) 0x5f)        // to enable global register
#define MCUCR         *((volatile u8*) 0x55)       // Control register   , MCU Control Register – MCUCR
#define MCUCSR        *((volatile u8*) 0x54)      // Control and status register  , MCU Control and Status Register – MCUCSR
#define GICR          *((volatile u8*) 0x5B)     //general interrupt register    , General Interrupt Control Register – GICR
#define GIFR          *((volatile u8*) 0x5A)    // genral flag register (managed by hardware )  , General Interrupt Flag Register – GIFR


void MEXTERNAL_INTERRUPT_voidSenseControl(u8 A_u8External_INT_Line, u8 A_u8ExternalInterrupt_Sense)
{
	switch(A_u8External_INT_Line)   //switch on INTERRUPT pins
	{
	case INT0:

		switch(A_u8ExternalInterrupt_Sense)    // switch on sensing (falling, rising edge...etc)
				{
				case Low_Level :
													CLR_BIT(MCUCR,0);
													CLR_BIT(MCUCR,1);
													break;

				case OnChange :
													SET_BIT(MCUCR,0);
													CLR_BIT(MCUCR,1);
													break;

				case Falling_Edge :
													CLR_BIT(MCUCR,0);
													SET_BIT(MCUCR,1);
													break;

				case Rising_Edge :
													SET_BIT(MCUCR,0);
													SET_BIT(MCUCR,1);
													break;
				}
	break;

	case INT1 :

		switch(A_u8ExternalInterrupt_Sense)
				{
				case Low_Level :
													CLR_BIT(MCUCR,2);
													CLR_BIT(MCUCR,3);
													break;

				case OnChange :
											    	SET_BIT(MCUCR,2);
													CLR_BIT(MCUCR,3);
													break;

				case Falling_Edge :
													CLR_BIT(MCUCR,2);
													SET_BIT(MCUCR,3);
													break;

				case Rising_Edge :
													SET_BIT(MCUCR,2);
													SET_BIT(MCUCR,3);
													break;

				}

	break;
	case INT2 :

#if A_u8ExternalInterrupt_Sense >1 && A_u8ExternalInterrupt_Sense<4

		switch(A_u8ExternalInterrupt_Sense)
				{

				case Falling_Edge :        CLR_BIT(MCUCSR,6);     break;       // INT2 includes falling and rising only

				case Rising_Edge  :         SET_BIT(MCUCSR,6);     break;

				}


#endif
	break;
	}

}

void MEXTERNAL_INTERRUPT_voidEnable(u8 A_u8Interrupt_Line)
{
	switch(A_u8Interrupt_Line)
	{
	case INT0 :     SET_BIT(GICR,6);      break;     // set bit 6 in GICR for enabling external interruption on pin INT0

	case INT1 :     SET_BIT(GICR,7);      break;

	case INT2 :     SET_BIT(GICR,5);      break;

	}

}

void MEXTERNAL_INTERRUPT_voidDisable(u8 A_u8Interrupt_Line)
{
	switch(A_u8Interrupt_Line)
	{
	case INT0 :    CLR_BIT(GICR,6);      break;      // as settig bit 6 in GICR for enabling external interruption on pin INT0 So CLEARing it will disable it

	case INT1 :    CLR_BIT(GICR,7);      break;

	case INT2 :    CLR_BIT(GICR,5);      break;

	}

}
