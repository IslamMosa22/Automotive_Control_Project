/*
 * config.h
 *
 *  Created on: Aug 24, 2023
 *      Author: Basim Osman
 */

#ifndef HAL_ADC_CONFIG_H_
#define HAL_ADC_CONFIG_H_



/*
 * AREF
 * AVCC
 * INTERNAL
 *  */
#define VoltageRef AVCC

/*
 *LEFT
 *RIGHT
 */

#define AdjustType  RIGHT

 /*
  * for prescaling by 2 (devide the system signal freq by 2 ) i've to reset the next 3 bits in ADCSRA ( ADC Control and Status Register A )
  * */
#define  ADPS0    0
#define  ADPS1    1
#define  ADPS2    2

/*
 * change the first 3 numbers only to change prescaling
 *
 * */

#define PRESCALING  0b00000011

/*TRIGGER SOURCE */

#define TRIGGER_SOURCE  0b00000000   // change bits num 5,6,7

#endif /* HAL_ADC_CONFIG_H_ */
