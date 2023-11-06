/*
 * BIT_MATH.h
 *
 *  Created on: Sep 6, 2023
 *      Author: DELL
 */

#ifndef LIB_BIT_MATH_H_
#define LIB_BIT_MATH_H_

#define SET_BIT(Var,BitNo)    Var |=  (1 << (BitNo))
#define CLR_BIT(Var,BitNo)    Var &= ~(1 << (BitNo))
#define TOG_BIT(Var,BitNo)    Var ^=  (1 << (BitNo))
#define GET_BIT(Var,BitNo)    ((Var>>BitNo)&0x01)
#define SET_BYTE(Var,BitNo)    (Var & 0b00000000 | 0b11111111)

#endif /* LIB_BIT_MATH_H_ */
