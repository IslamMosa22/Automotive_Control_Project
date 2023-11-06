/*
 * GlobalEnable.c
 *
 *  Created on: Aug 23, 2023
 *      Author: Basim Osman
 */

#include "GlobalEnable_Init.h"
#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_types.h"

#define STATUS_REG    *((volatile u8*) 0x5f)        // to enable global register on bit 7 from

void MGLOBAL_INTERRUPT_voidEnable()
{
	SET_BIT(STATUS_REG,7);
}

void MGLOBAL_INTERRUPT_voidDisable()
{
	CLR_BIT(STATUS_REG,7);
}
