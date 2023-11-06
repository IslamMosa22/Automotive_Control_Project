/*
 * ADC.c
 *
 *  Created on: Aug 24, 2023
 *      Author: Basim Osman
 */
#include "priv.h"
#include "ADC_Init.h"
#include "config.h"
#include "../../LIB/BIT_MATH.h"



void MADC_voidAdcInit()
{
	/* select voltage ref */

	switch(VoltageRef)
	{
	case AREF:      CLR_BIT(ADMUX,6);
				    CLR_BIT(ADMUX,7);
					break;


	case AVCC:      SET_BIT(ADMUX,6);
					CLR_BIT(ADMUX,7);
					break;

	case INTERNAL:  SET_BIT(ADMUX,6);
	                SET_BIT(ADMUX,7);
	                break;

	}

	/*Adjusting (ADC left or Right as it's 10 bit so i use 2 bytes , if left so start from the first address of the left , else start from address of bit num 6 of the left*/

	switch(AdjustType)
	{
	case LEFT:   SET_BIT(ADMUX,5);    break;

	case RIGHT:  CLR_BIT(ADMUX,5);    break;

	}


	/*ADC Auto Trigger Enable*/         //start automatically all time and consume power

	SET_BIT(ADCSRA , 5);

	/*Auto trigger source   >>> Free running mode */

	SFIOR = ( SFIOR & 0b00011111 ) | ( TRIGGER_SOURCE );

	/*Enable */

	SET_BIT(ADCSRA,7);

	/*prescaling =8 */

	 //ADCSRA|= (1<<ADPS0) | (1<<ADPS1) | (0<<ADPS2) ;  // reset first , second and third bit

	ADCSRA = ( ADCSRA & 0b11111000 ) | PRESCALING;

	 /*Enable interrupt*/

	 SET_BIT(ADCSRA,3);
}


/* Disable*/

//void MADC_voidDisable()
//{
	//CLR_BIT(ADCSRA,ADEN);

//}

u16 MADC_u16AnalogDigitalConverter(u8 A_u8ChannelNum)
{
	u16 L_u16ADC_Reading;

	/*Channel number */

	ADMUX=(ADMUX & 0xE0) | (A_u8ChannelNum & 0x07 );  //changing the first 3 bit depends on channel num and bits 4, 5 are zeros , // 0xf8  ,0xE0

	/*start conversion */

	SET_BIT(ADCSRA,6);

	/*for polling */

	//while(GET_BIT(ADCSRA , 4 ) !=1 )   // haven't completed conversion , still inside loop
	//{}

	// clear flag
	//SET_BIT(ADCSRA , 4 );

	/* ADC_READING = ADCL_VALUE + ADCH_VALUE */

	L_u16ADC_Reading = ADCL | ADCH<<8 ;     //shift the ADCH left 8 bits to add the 10 bits

	//L_u16ADC_Reading = ADCL + ADCH * 256 ;

	return L_u16ADC_Reading;


}

