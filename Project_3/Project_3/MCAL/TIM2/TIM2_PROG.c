/*
 * TIM2_PROG.c
 *
 * Created: 9/22/2026 3:04:58 PM
 *  Author: Eltawel
 */ 

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "TIM2_INTERFACE.h"
#include "TIM2_CFG.h"
#include "TIM2_REG.h"
 
/*
 * OCR2 = (F_CPU / (Prescaler * Frequency)) - 1
 *      = (16,000,000 / (1 * 1,000,000)) - 1
 *      = 15
 * -> With No Prescaling (Prescaler=1), a compare match happens exactly
 *    every 1us at F_CPU = 16MHz.
 */
#define TIM2_TICK_OCR_VAL		15
 
void TIM2_Init(void)
{
	/* 1- Select Mode --> CTC */
	SET_BIT(TCCR2_REG, WGM21_BIT);
	CLEAR_BIT(TCCR2_REG, WGM20_BIT);
	
	/* 2- Set OCR Val for 1us tick @ 16MHz, No Prescaling */
	OCR2_REG = TIM2_TICK_OCR_VAL;
	
	/* 3- Set Prescaler --> No Prescaling */
	TCCR2_REG &= 0xF8;
	TCCR2_REG |= TIM2_NO_PRESCALING;
	
	/* 4- Clear any stale compare-match flag before first use */
	SET_BIT(TIFR_REG, OCF2_BIT);
}
 
void TIM2_DelayUS(u16 copy_u16delayus)
{
	u16 Loc_u16Counter;
	
	for(Loc_u16Counter = 0; Loc_u16Counter < copy_u16delayus; Loc_u16Counter++)
	{
		while(GET_BIT(TIFR_REG, OCF2_BIT) == 0);
		
		SET_BIT(TIFR_REG, OCF2_BIT);
	}
}
 