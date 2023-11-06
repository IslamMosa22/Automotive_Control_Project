/*
 * TIMERS_INIT.h
 *
 *  Created on: Aug 24, 2023
 *      Author: Youssef
 */

#ifndef MCAL_TIMERS_TIMERS_INIT_H_
#define MCAL_TIMERS_TIMERS_INIT_H_

#define TIMER0 1
#define TIMER1 2
#define TIMER2 3

void MTIM_TimersInit();
void MTIM_Timers_OVF (u8 A_u8TimerID,u16 A_u8Counts,void (A_voidFunc)(void));
void MTIM_Timers_CTC (u8 A_u8TimerID,u16 A_u8Counts,u16 A_u16CompareValue,void (A_voidFunc)(void));
void MTIM_FastPWM(u8 A_u8TimerID,u16 A_u16CompareValue);
void MTIM_CompareValue (u16 A_u16CompareValue);
void MTIM_Time_Preload(u8 A_u8TimerID,u16 A_u8Num);
void MTIM_CountStart(u8 A_u8TimerID);
void MTIM_CountStop(u8 A_u8TimerID);


#endif /* MCAL_TIMERS_TIMERS_INIT_H_ */
