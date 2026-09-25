/*
 * TIM0_PROG.c
 *
 * Created: 9/19/2026 8:29:37 AM
 *  Author: Eltawel
 */ 

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "TIM0_INTERFACE.h"
#include "TIM0_CFG.h"
#include "TIM0_REG.h"

void TIM0_Init(void)
{
	
	/* 1- Select Mode --> CTC */
		SET_BIT(TCCR0_REG, WGM01_BIT);
		CLEAR_BIT(TCCR0_REG, WGM00_BIT);
		
	/* 3- Set OCR Val */
		OCR0_REG = 250;
		
	/* 4-Set Prescaler */
		TCCR0_REG = (TCCR0_REG & 0xF8) | TIM0_64_PRESCALER;
		
	/* 5- Clear OCF0 */
		SET_BIT(TIFR_REG, OCF0_BIT);
}

void TIM0_DelayMS(u32 copy_u32delay)
{
	u32 Loc_counter = 0;
	
	for(Loc_counter = 0; Loc_counter < copy_u32delay; Loc_counter++)
	{
		while(GET_BIT(TIFR_REG, OCF0_BIT) == 0);
		
		SET_BIT(TIFR_REG, OCF0_BIT);
	}
}