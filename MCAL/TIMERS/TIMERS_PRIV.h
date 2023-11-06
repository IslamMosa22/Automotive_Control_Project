/*
 * TIMERS_PRIV.h
 *
 *  Created on: Aug 25, 2023
 *      Author: Youssef
 */

#ifndef MCAL_TIMERS_TIMERS_PRIV_H_
#define MCAL_TIMERS_TIMERS_PRIV_H_

#define TIMSK  *((volatile u8*) 0x59)
#define TIFR   *((volatile u8*) 0x58)

#define TCCR0  *((volatile u8*) 0x53)
#define TCNT0  *((volatile u8*) 0x52)
#define OCR0   *((volatile u8*) 0x5C)



#define PreScaling_8    2
#define PreScaling_64   3
#define PreScaling_256  4
#define PreScaling_1024 5

#define Normal    1
#define Phase_PWM 2
#define CTC       3
#define Fast_PWM  4

#define Non_Inverted 1
#define Inverted     2

#define Enable 1
#define Disable 0

#define TCCR1A  *((volatile u8*)  0x4f)
#define TCCR1B  *((volatile u8*)  0x4e)
#define TCCR1   *((volatile u16*) 0x4e)

#define TCNT1H  *((volatile u8*)  0x4d)
#define TCNT1L  *((volatile u8*)  0x4c)
#define TCNT1   *((volatile u16*) 0x4c)

#define OCR1AH  *((volatile u8*)  0x4b)
#define OCR1AL  *((volatile u8*)  0x4a)
#define OCR1A   *((volatile u16*) 0x4a)

#define OCR1BH  *((volatile u8*)  0x49)
#define OCR1BL  *((volatile u8*)  0x48)
#define OCR1B   *((volatile u16*) 0x48)

#define ICR1H   *((volatile u8*)  0x47)
#define ICR1L   *((volatile u8*)  0x46)
#define ICR1    *((volatile u16*) 0x46)

#define TCCR2   *((volatile u8*)  0x45)
#define TCNT2   *((volatile u8*)  0x44)
#define OCR2    *((volatile u8*)  0x43)



#define COM1A1 7
#define COM1A0 6
#define COM1B1 5
#define COM1B0 4
#define FOC1A  3
#define FOC1B  2
#define WGM11  1
#define WGM10  0

#define WGM13  4
#define WGM12  3

#endif /* MCAL_TIMERS_TIMERS_PRIV_H_ */
