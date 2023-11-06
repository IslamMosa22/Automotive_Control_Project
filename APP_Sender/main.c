/*
 * main.c
 *
 *  Created on: Sep 5, 2023
 *      Author: Eslam Mosa
 */
//#include "../MCAL/ADC/ADC_Init.h"
#include "../MCAL/DIO/DIObasim.h"
#include "../MCAL/INTERRUPT/GlobalEnable_Init.h"
#include "../MCAL/TIMERS/TIMERS_INIT.h"
#include "../MCAL/INTERRUPT/INT_Init.h"
#include "../LIB/BIT_MATH.h"

void Motor_Specs(u8 MotorSpeed , u8 MotorDirection );

void main()
{

	MDIO_voidSetPinDirection(PORTD,PIN0,OUTPUT);
	MDIO_voidSetPinDirection(PORTD,PIN1,OUTPUT);

	MDIO_voidSetPinDirection(PORTD,PIN2,INPUT);  // FOR EXT INT
	MDIO_voidSetPinValue(PORTD,PIN2,HIGH);

	//MDIO_voidSetPinDirection(PORTB,PIN0,OUTPUT);   // Button for speed
	//MDIO_voidSetPinValue(PORTB,PIN0,HIGH);         // pull up resistor activation

	MDIO_voidSetPinDirection(PORTB,PIN3,OUTPUT);   // TIMER PIN

	MTIM_TimersInit();
	//MTIM_FastPWM(TIMER0,0);

	MGLOBAL_INTERRUPT_voidEnable();
	MEXTERNAL_INTERRUPT_voidSenseControl(INT0,Falling_Edge);
	MEXTERNAL_INTERRUPT_voidEnable(INT0);



	while(1)
	{

		/* Controlling Motor Direction Using Push Button on PORTB-PIN0  */
   /*
		if(MDIO_u8GetPinValue(PORTB,PIN0)==0)
		{
			MDIO_voidSetPinValue(PORTD,PIN0,HIGH);
			MDIO_voidSetPinValue(PORTD,PIN1,LOW);
		}
		else
		{
			MDIO_voidSetPinValue(PORTD,PIN0,LOW);   // CCW   L
			MDIO_voidSetPinValue(PORTD,PIN1,HIGH);
		}

   */
	}


}
    /* External Interrupt to Control Motor Speed */
/*
void __vector_1 (void) __attribute__ ((signal));
void __vector_1 (void)
{
	static u8 Speed = 1;
	if(Speed == 1)
	{
		MTIM_FastPWM(TIMER0,50);
		Speed++;
	}
	else if (Speed == 2)
	{
		MTIM_FastPWM(TIMER0,100);
		Speed++;

	}
	else if (Speed == 3)
	{
		MTIM_FastPWM(TIMER0,255);
		Speed = 1;

	}


}
*/
void Motor_Specs(u8 MotorSpeed , u8 MotorDirection )
{
	u8 compareValue ;

compareValue = MotorSpeed * 255 / 100.0 ;

MTIM_FastPWM(TIMER0,compareValue);

if (MotorDirection == 'R')
{
	MDIO_voidSetPinValue(PORTD,PIN0,HIGH);
	MDIO_voidSetPinValue(PORTD,PIN1,LOW);

}
else if(MotorDirection == 'L')
{
	MDIO_voidSetPinValue(PORTD,PIN0,LOW);
	MDIO_voidSetPinValue(PORTD,PIN1,HIGH);

}

}
void __vector_1 (void) __attribute__ ((signal));
void __vector_1 (void)
{
 static u8 var = 1;
 if (var==1)
 {
	 Motor_Specs( 20 , 'L' );
	 var=2;
 }
 else
 {
	 MTIM_CountStop(TIMER0);
	 var=1;
 }

}
