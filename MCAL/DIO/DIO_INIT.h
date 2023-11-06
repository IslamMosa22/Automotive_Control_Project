/*
 * DIO_INIT.h
 *
 *  Created on: Sep 6, 2023
 *      Author: DELL
 */

#ifndef MCAL_DIO_DIO_INIT_H_
#define MCAL_DIO_DIO_INIT_H_

#include "../../LIB/STD_types.h"

//the next variables in this file only i can call them

void MDIO_voidSetPinDirection(u8 A_u8PortNum,u8 A_u8PinNum,u8 A_u8PinDirection);    //M stands for MCAL file && A stands for Argument
void MDIO_voidSetPinValue(u8 A_u8PortNum,u8 A_u8PinNum,u8 A_u8PinValue);
u8 MDIO_u8GetPinValue(u8 A_u8PortNum,u8 A_u8PinNum);

void MDIO_voidSetPortDirection(u8 A_u8PortNum,u8 A_u8PortDirection);
void MDIO_voidSetPortValue(u8 A_u8PortNum,u8 A_u8PortValue);


#define PORTA 0
#define PORTB 1
#define PORTC 2
#define PORTD 3

#define PIN0 0
#define PIN1 1
#define PIN2 2
#define PIN3 3
#define PIN4 4
#define PIN5 5
#define PIN6 6
#define PIN7 7

#define HIGH 1
#define LOW  0

#define OUTPUT 1
#define INPUT  0

#endif /* MCAL_DIO_DIO_INIT_H_ */
