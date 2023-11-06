/*
 * ADC_Init.h
 *
 *  Created on: Aug 24, 2023
 *      Author: Basim Osman
 */

#ifndef HAL_ADC_ADC_INIT_H_
#define HAL_ADC_ADC_INIT_H_
#include "../../LIB/STD_types.h"

#define AREF     0          //external voltage
#define AVCC     1         //AVCC with external capacitor at AREF pin
#define INTERNAL 2        // Internal 2.56V Voltage Reference with external capacitor at AREF pin

#define LEFT     0
#define RIGHT    1


void MADC_voidAdcInit();     //Voltage ref (input to the sensor not to the pin)

u16 MADC_u16AnalogDigitalConverter(u8 A_u8ChannelNum);


#endif /* HAL_ADC_ADC_INIT_H_ */
