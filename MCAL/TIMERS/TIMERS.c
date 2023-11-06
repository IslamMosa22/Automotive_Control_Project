/*
 * TIMERS.c
 *
 *  Created on: Aug 24, 2023
 *      Author: Youssef
 */

#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"

#include "TIMERS_INIT.h"
#include "TIMERS_PRIV.h"
#include "TIMERS_Config.h"

static void (*G_voidFunc0)(void);
static u16 G_u16Counts0;

static void (*G_voidFunc1)(void);
static u16 G_u16Counts1;

static void (*G_voidFunc2)(void);
static u16 G_u16Counts2;


void MTIM_TimersInit()
{
#if(Timer0==Enable)
{

#if (Timer0_WGM==Normal)
	{
		CLR_BIT(TCCR0,7);
		CLR_BIT(TCCR0,6);
		CLR_BIT(TCCR0,3);
		CLR_BIT(TCCR0,5);
		CLR_BIT(TCCR0,4);
		SET_BIT(TIMSK,0);
		CLR_BIT(TIMSK,1);

	}
#elif(Timer0_WGM==Phase_PWM)
	{
		CLR_BIT(TCCR0,3);
		SET_BIT(TCCR0,6);
		SET_BIT(TCCR0,5);
		CLR_BIT(TCCR0,4);
	}
#elif(Timer0_WGM==CTC)
	{
		SET_BIT(TCCR0,7);
		SET_BIT(TCCR0,3);
		CLR_BIT(TCCR0,6);
		CLR_BIT(TCCR0,5);
		CLR_BIT(TCCR0,4);
		SET_BIT(TIMSK,1);
		CLR_BIT(TIMSK,0);
	}
#elif(Timer0_WGM==Fast_PWM||Fast0==Non_Inverted)
	{
		SET_BIT(TCCR0,6);
		SET_BIT(TCCR0,3);
		SET_BIT(TCCR0,5);
		CLR_BIT(TCCR0,4);
	}
#elif(Timer0_WGM==Fast_PWM||Fast0==Inverted)
	{
		SET_BIT(TCCR0,6);
		SET_BIT(TCCR0,3);
		SET_BIT(TCCR0,5);
		SET_BIT(TCCR0,4);
	}
#else
{
#error "Wrong WGM"
}
#endif
}
#endif


TCCR0=TCCR0 & 0xf8 ;



#if(Timer1==Enable)
{

#if (Timer1_WGM==Normal)
	{
		CLR_BIT(TCCR1A,0);
		CLR_BIT(TCCR1A,1);
		CLR_BIT(TCCR1B,3);
		CLR_BIT(TCCR1B,4);

		CLR_BIT(TCCR1A,3);
		CLR_BIT(TCCR1A,2);
		CLR_BIT(TCCR1A,7);
		CLR_BIT(TCCR1A,6);
		CLR_BIT(TCCR1A,5);
		CLR_BIT(TCCR1A,4);

		CLR_BIT(TIMSK,5);
		CLR_BIT(TIMSK,4);
		CLR_BIT(TIMSK,3);
		SET_BIT(TIMSK,2);
	}
#elif(Timer1_WGM==Phase_PWM)
	{
		CLR_BIT(TCCR1A,0);
		CLR_BIT(TCCR1A,1);
		SET_BIT(TCCR1B,3);
		SET_BIT(TCCR1B,4);

		SET_BIT(TCCR1A,7);
		SET_BIT(TCCR1A,5);
		CLR_BIT(TCCR1A,6);
		CLR_BIT(TCCR1A,4);

		CLR_BIT(TIMSK,5);
		CLR_BIT(TIMSK,4);
		CLR_BIT(TIMSK,3);
		CLR_BIT(TIMSK,2);
	}
#elif(Timer1_WGM==CTC)
	{
		CLR_BIT(TCCR1A,0);
		CLR_BIT(TCCR1A,1);
		CLR_BIT(TCCR1B,3);
		CLR_BIT(TCCR1B,4);

		SET_BIT(TCCR1A,3);
		CLR_BIT(TCCR1A,2);
		CLR_BIT(TCCR1A,7);
		CLR_BIT(TCCR1A,6);
		CLR_BIT(TCCR1A,5);
		CLR_BIT(TCCR1A,4);

		CLR_BIT(TIMSK,5);
		SET_BIT(TIMSK,4);
		SET_BIT(TIMSK,3);
		CLR_BIT(TIMSK,2);
	}
#elif(Timer1_WGM==Fast_PWM||Fast1==Non_Inverted)
	{
		CLR_BIT(TCCR1A,WGM10);
		SET_BIT(TCCR1A,WGM11);
		SET_BIT(TCCR1B,WGM12);
		SET_BIT(TCCR1B,WGM13);

		SET_BIT(TCCR1A,COM1A1);
		SET_BIT(TCCR1A,COM1B1);
		CLR_BIT(TCCR1A,COM1A0);
		CLR_BIT(TCCR1A,COM1B0);

		CLR_BIT(TIMSK,5);
		CLR_BIT(TIMSK,4);
		CLR_BIT(TIMSK,3);
		CLR_BIT(TIMSK,2);
		ICR1=20000; // fPWM=50Hz
	}
#elif(Timer1_WGM==Fast_PWM||Fast1==Inverted)
	{
		SET_BIT(TCCR1A,0);
		SET_BIT(TCCR1A,1);
		SET_BIT(TCCR1B,3);
		SET_BIT(TCCR1B,4);

		SET_BIT(TCCR1A,7);
		SET_BIT(TCCR1A,5);
		SET_BIT(TCCR1A,6);
		SET_BIT(TCCR1A,4);

		CLR_BIT(TIMSK,5);
		CLR_BIT(TIMSK,4);
		CLR_BIT(TIMSK,3);
		CLR_BIT(TIMSK,2);
		ICR1=20000; // fPWM=50Hz
	}
#else
{
#error "Wrong WGM"
}
#endif
}
#endif



 	SET_BIT(TCCR1B,7);
 	SET_BIT(TCCR1B,6);
	TCCR1B=TCCR1B & 0xf8 ;

#if(Timer2==Enable)
{

#if (Timer2_WGM==Normal)
	{
		CLR_BIT(TCCR2,7);
		CLR_BIT(TCCR2,6);
		CLR_BIT(TCCR2,3);
		CLR_BIT(TCCR2,5);
		CLR_BIT(TCCR2,4);
		SET_BIT(TIMSK,6);
		CLR_BIT(TIMSK,7);

	}
#elif(Timer2_WGM==Phase_PWM)
	{
		CLR_BIT(TCCR2,3);
		SET_BIT(TCCR2,6);
		SET_BIT(TCCR2,5);
		CLR_BIT(TCCR2,4);
		SET_BIT(TIMSK,7);
		SET_BIT(TIMSK,6);
	}
#elif(Timer2_WGM==CTC)
	{
		SET_BIT(TCCR2,7);
		SET_BIT(TCCR2,3);
		CLR_BIT(TCCR2,6);
		CLR_BIT(TCCR2,5);
		CLR_BIT(TCCR2,4);
		SET_BIT(TIMSK,7);
		CLR_BIT(TIMSK,6);
	}
#elif(Timer2_WGM==Fast_PWM||Fast2==Non_Inverted)
	{
		SET_BIT(TCCR2,6);
		SET_BIT(TCCR2,3);
		SET_BIT(TCCR2,5);
		CLR_BIT(TCCR2,4);
		SET_BIT(TIMSK,7);
		SET_BIT(TIMSK,6);
	}
#elif(Timer2_WGM==Fast_PWM||Fast2==Inverted)
	{
		SET_BIT(TCCR2,6);
		SET_BIT(TCCR2,3);
		SET_BIT(TCCR2,5);
		SET_BIT(TCCR2,4);
		SET_BIT(TIMSK,7);
		SET_BIT(TIMSK,6);
	}
#else
{
#error "Wrong WGM"
}

#endif
}
#endif


	TCCR2=TCCR2 & 0xf8 ;


}

void MTIM_Timers_OVF (u8 A_u8TimerID,u16 A_u16Counts,void (A_voidFunc)(void))
{
	switch(A_u8TimerID)
	{
	case TIMER0:
	{
		G_u16Counts0=A_u16Counts;
		G_voidFunc0=A_voidFunc;
	}break;
	case TIMER1:
	{
		G_u16Counts1=A_u16Counts;
		G_voidFunc1=A_voidFunc;
	}break;
	case TIMER2:
	{
		G_u16Counts2=A_u16Counts;
		G_voidFunc2=A_voidFunc;
	}break;
	}
	MTIM_CountStart(A_u8TimerID);

}

void MTIM_Timers_CTC ( u8 A_u8TimerID ,u16 A_u16Counts , u16 A_u16CompareValue,void (A_voidFunc)(void))
{

	switch(A_u8TimerID)
	{
	case TIMER0:
	{
		OCR0=A_u16CompareValue;
		G_u16Counts0=A_u16Counts;
		G_voidFunc0=A_voidFunc;
	}break;
	case TIMER1:
	{
		OCR1AL=A_u16CompareValue;
		G_u16Counts1=A_u16Counts;
		G_voidFunc1=A_voidFunc;
	}break;
	case TIMER2:
	{
		OCR2=A_u16CompareValue;
		G_u16Counts2=A_u16Counts;
		G_voidFunc2=A_voidFunc;
	}break;
	}
	MTIM_CountStart(A_u8TimerID);

}
void MTIM_Time_Preload(u8 A_u8TimerID,u16 A_u16Num)
{
	switch (A_u8TimerID)
	{
	case TIMER0:TCNT0=(A_u16Num);break;
	case TIMER1:TCNT1=(A_u16Num);break;
	case TIMER2:TCNT2=(A_u16Num);break;
	}
}

void MTIM_CountStart(u8 A_u8TimerID)
{
	switch(A_u8TimerID)
	{
	case TIMER0:TCCR0=((TCCR0 & 0xf8 )|(Timer0_Prescaler));break;
	case TIMER1:TCCR1B=((TCCR1B & 0xf8 )|(Timer1_Prescaler));break;
	case TIMER2:TCCR2=((TCCR2 & 0xf8 )|(Timer2_Prescaler));break;
	}

}
void MTIM_CountStop(u8 A_u8TimerID)
{
	switch(A_u8TimerID)
	{
	case TIMER0:TCCR0=TCCR0 & 0xf8;break;
	case TIMER1:TCCR1B=TCCR1B & 0xf8;break;
	case TIMER2:TCCR2=TCCR2 & 0xf8 ;break;
	}
}

void MTIM_FastPWM(u8 A_u8TimerID,u16 A_u16CompareValue)
{

	switch(A_u8TimerID)
	{
	case TIMER0 : OCR0=A_u16CompareValue ;break;
	case TIMER1 : OCR1A=A_u16CompareValue;break;
	case TIMER2 : OCR2=A_u16CompareValue ;break;
	}
	MTIM_CountStart(A_u8TimerID);

}



void __vector_5(void) __attribute__((signal));
void __vector_5(void)
{
	static u16 LS_u16Counts2=0;
	if(LS_u16Counts2==G_u16Counts2)
	{
		LS_u16Counts2=0;
		G_voidFunc2();
	}
	else
	{
	LS_u16Counts2++;
	}
}


void __vector_11(void) __attribute__((signal));
void __vector_11(void)
{

		static u16 LS_u16Counts0=0;
		if(LS_u16Counts0==G_u16Counts0)
		{
			LS_u16Counts0=0;
			G_voidFunc0();
		}
		else
		{
		LS_u16Counts0++;
		}


}

