/*
 * TIM1_PROG.c
 *
 * Created: 9/19/2026 4:01:43 PM
 *  Author: Eltawel
 */ 

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "../../LIB/VECTOR_TABLE.h"
#include "../DIO/DIO_INTERFACE.h"
#include "TIM1_INTERFACE.h"
#include "TIM1_CFG.h"
#include "TIM1_REG.h"

void (*ICR_PTR)(void) = null;

void TIM1_FastPWM_Init(void)
{
	 /* Select Fast PWM OCR1A */
		SET_BIT(TCCR1A_REG, WGM10_BIT);
		SET_BIT(TCCR1A_REG, WGM11_BIT);
		SET_BIT(TCCR1B_REG, WGM12_BIT);
		SET_BIT(TCCR1B_REG, WGM13_BIT);
		
	/* Set DDR of the OC1A(PD5) & OC1B(PD4) Pin */
		//DIO_CFG_t OC1A_PIN = { .port = DIO_PORTD, .pin = DIO_PIN5, .dir = DIO_OUTPUT};
		DIO_CFG_t OC1B_PIN = { .port = DIO_PORTD, .pin = DIO_PIN4, .dir = DIO_OUTPUT};
			
		//DIO_SetPinDir(&OC1A_PIN);
		DIO_SetPinDir(&OC1B_PIN);
		
	/* Fast PWM Non Inverting Mode */
		CLEAR_BIT(TCCR1A_REG, COM1A0_BIT);
		SET_BIT(TCCR1A_REG, COM1A1_BIT);
		
		CLEAR_BIT(TCCR1A_REG, COM1B0_BIT);
		SET_BIT(TCCR1A_REG, COM1B1_BIT);
		
	/* Set Top Val */
		OCR1A_REG = 4999;
		
	/* Set Prescaler TIM1_64_CLK */
		
		TCCR1B_REG &= 0xF8;
		TCCR1B_REG |= TIM1_64_CLK;
}

void TIM1_FastPWM_SetDuty(u16 copy_u16val)
{
	OCR1B_REG = copy_u16val;
}

void TIM1_ICU_Init(TIM1_EDGE_t obj_1)
{
	/* Set Prescaler TIM1_64_CLK */
	
	TCCR1B_REG &= 0xF8;
	TCCR1B_REG |= TIM1_64_CLK;
	
	/* Enable Noise Canceler - filters electrical glitches on the Echo line */
	SET_BIT(TCCR1B_REG, ICNC1_BIT);
	
	/* Select Sens Contrl */
	switch(obj_1)
	{
		case TIM1_FALLING_EDGE: CLEAR_BIT(TCCR1B_REG, ICES1_BIT);	break;
		case TIM1_RISING_EDGE:	SET_BIT(TCCR1B_REG, ICES1_BIT);		break;
	}
	
	/* Clear any stale capture flag before (re)arming for a fresh edge */
	SET_BIT(TIFR_REG, ICF1_BIT);
	
	/* Enable ICR interrupt */
	SET_BIT(TIMSK_REG, TICIE1_BIT);
}

u16 TIM1_ICU_GetCapturedVal(void)
{
	return ICR1_REG;
}

void TIM1_ICU_SetCallBack(void(*PTR)(void))
{
	ICR_PTR = PTR;
}

ISR(TIMER1_CAPT)
{
	if(ICR_PTR != null)
	{
		ICR_PTR();
	}
}