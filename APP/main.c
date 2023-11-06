/*
 * main.c
 *
 *  Created on: Sep 6, 2023
 *      Author: Eslam Mosa
 */
#include "../LIB/BIT_MATH.h"
#include "../LIB/STD_types.h"
#include "../MCAL/DIO/DIO_INIT.h"
#include "../MCAL/INTERRUPT/GlobalEnable_Init.h"
#include "../MCAL/TIMERS/TIMERS_INIT.h"
#include "../MCAL/INTERRUPT/INT_Init.h"
#include "../UART/MCAL/UART/UART_Init.h"
#include "../UART/MCAL/UART/UART_Priv.h"
#include "../UART/MCAL/UART/UART_Config.h"
#include "../HAL/StepperMotor/StepperMotorProject_init.h"
#include "../HAL/StepperMotor/StepperMotorProject_Priv.h"
#include "../HAL/StepperMotor/StepperMotorProject_Config.h"
#include "../HAL/LCD/LCDinit.h"

#include <util/delay.h>

void	F_voidCheckFormat(u8* Str);
void    F_voidGetVar(u8* Str);

u8 G_u8Speed=0;
u8 G_u8DcDirection=0;
u8 G_u8Angle=0;
u8 G_u8StepperDirection=0;
u8 G_u8Flag =0;
//void Motor_Specs(u8 MotorSpeed , u8 MotorDirection );

void main()
{
	u8  Arr1[10];

	MDIO_voidSetPinDirection(PORTD,PIN3,OUTPUT);
	MDIO_voidSetPinDirection(PORTD,PIN4,OUTPUT);
	MDIO_voidSetPortDirection(PORTA,0xff);
	MDIO_voidSetPortDirection(PORTB,0xFF);
	MDIO_voidSetPinDirection(PORTD,PIN2,INPUT);  // FOR EXT INT
	MDIO_voidSetPinValue(PORTD,PIN2,HIGH);
	MDIO_voidSetPinDirection(PORTB,PIN3,OUTPUT);   // TIMER PIN

	HLCD_voidInit();
	MUART_voidInit();
	HStepMotor_voidInitialization();
	MTIM_TimersInit();

	/*interrupt*/
	MGLOBAL_INTERRUPT_voidEnable();
	MEXTERNAL_INTERRUPT_voidSenseControl(INT0,Low_Level);
	MEXTERNAL_INTERRUPT_voidEnable(INT0);





	MUART_voidReceiveString(Arr1);
	F_voidGetVar(Arr1);
	HStepMotor_voidDirAngle(G_u8StepperDirection,G_u8Angle);

	while(1)
	{


		   F_voidCheckFormat(Arr1);

		    if(G_u8Flag == 0)
		    {
		        HLCD_voidSendString("Speed:");
		        HLCD_voidDisplyNumber(G_u8Speed);
		        HLCD_voidSendData(G_u8DcDirection);
		        HLCD_voidSetCursor(1,0);
		        HLCD_voidSendString("Angle:");
		        HLCD_voidDisplyNumber(G_u8Angle);
		        HLCD_voidSendData(G_u8StepperDirection);
		        _delay_ms(1000);
		        HLCD_voidClear();
		    }
		    else
		    {
		        HLCD_voidSendString("Wrong Format");
		        _delay_ms(100);
		        HLCD_voidClear();
		    }

	    _delay_ms(200);
	}


}

void Motor_Specs(u8 MotorSpeed , u8 MotorDirection )
{
	u8 compareValue ;

compareValue = (u16) MotorSpeed * 255 / 100.0 ;



if (MotorDirection =='F')
{
	MDIO_voidSetPinValue(PORTD,PIN3,HIGH);
	MDIO_voidSetPinValue(PORTD,PIN4,LOW);

}
else if(MotorDirection =='B')
{
	MDIO_voidSetPinValue(PORTD,PIN3,LOW);
	MDIO_voidSetPinValue(PORTD,PIN4,HIGH);

}
MTIM_FastPWM(TIMER0,compareValue);
}


void	F_voidCheckFormat(u8* Str)
{


		if (Str[0]=='0')
		{}
		else if (Str[0]=='1')
		{
			if (Str [1]=='0' && Str[2]=='0')
			{}
			else
			{
			G_u8Flag=1;
			}
		}
		else
		{
			G_u8Flag=1;
		}

		if (Str[3]!='F' && Str[3] !='B')
		{
			G_u8Flag=1;
		}
		if (Str[4]>'4')
		{
			G_u8Flag=1;
		}
		if( Str[4]== '4' && Str[5]>'5')
		{
			G_u8Flag=1;
		}
		if (Str[6]!='R' && Str[6] !='L')
		{
			G_u8Flag=1;
		}
		if (Str[7]!='E')
		{
			G_u8Flag=1;
		}


	if(G_u8Flag==1)
	{
		HLCD_voidSendString("Wrong Format");
		_delay_ms(1000);
		HLCD_voidClear();
	}
}

void    F_voidGetVar(u8* Str)
{
	 G_u8Speed = ((Str[0] - 0x30) * 100) + ((Str[1] - 0x30) * 10) + (( Str[2] - 0x30));
	 G_u8DcDirection = Str[3];
	 G_u8Angle=((Str[4]-0x30)*10)+((Str[5]-0x30));
	 G_u8StepperDirection=Str[6];
}

void __vector_1 (void) __attribute__ ((signal));
void __vector_1 (void)
{
 static u8 var = 1;
 if (var==1)
 {
	 Motor_Specs(G_u8Speed ,G_u8DcDirection);
	 var=2;
 }
 else
 {
	 MDIO_voidSetPinValue(PORTD,PIN3,LOW);
	 MDIO_voidSetPinValue(PORTD,PIN4,LOW);
	 var=1;
 }

}
