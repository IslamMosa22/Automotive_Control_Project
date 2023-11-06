/*
 * TIMERS_Config.h
 *
 *  Created on: Aug 25, 2023
 *      Author: Youssef
 */

#ifndef MCAL_TIMERS_TIMERS_CONFIG_H_
#define MCAL_TIMERS_TIMERS_CONFIG_H_

/*
 * Enable
 * Disable
 */


#define Timer0 Enable
/*
 * Normal
 * Phase_PWM
 * CTC
 * Fast_PWM
 * */

#define Timer0_WGM Fast_PWM

/*Non_Inverted
 * Inverted
 * */

#define Fast0 Non_Inverted

/*Timer0 Pre-scaler Select Bits
 * PreScaling_8
 * PreScaling_64
 * PreScaling_256
 * PreScaling_1024
 * */

#define Timer0_Prescaler PreScaling_8

/*
 * Enable
 * Disable
 */


#define Timer1 Disable
/*
 * Normal
 * Phase_PWM
 * CTC
 * Fast_PWM
 * */

#define Timer1_WGM Fast_PWM

/*Non_Inverted
 * Inverted
 * */

#define Fast1 Non_Inverted

/*Timer0 Pre-scaler Select Bits
 * PreScaling_8
 * PreScaling_64
 * PreScaling_256
 * PreScaling_1024
 * */

#define Timer1_Prescaler PreScaling_8



/*
 * Enable
 * Disable
 */


#define Timer2 Enable
/*
 * Normal
 * Phase_PWM
 * CTC
 * Fast_PWM
 * */

#define Timer2_WGM Normal

/*Non_Inverted
 * Inverted
 * */

#define Fast2 Non_Inverted

/*Timer0 Pre-scaler Select Bits
 * PreScaling_8
 * PreScaling_64
 * PreScaling_256
 * PreScaling_1024
 * */

#define Timer2_Prescaler PreScaling_8



#endif /* MCAL_TIMERS_TIMERS_CONFIG_H_ */
