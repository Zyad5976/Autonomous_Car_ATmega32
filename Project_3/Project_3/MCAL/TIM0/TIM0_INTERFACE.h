/*
 * TIM0_INTERFACE.h
 *
 * Created: 9/19/2026 8:29:10 AM
 *  Author: Eltawel
 */ 


#ifndef TIM0_INTERFACE_H_
#define TIM0_INTERFACE_H_

/**
*@brief		Initializes Timer0 in CTC Mode with Prescaler 64 for 1ms timing tick
*@param		None
*@return	None
*/
void TIM0_Init(void);

/**
*@brief		Generates a synchronous (blocking) delay in milliseconds using Timer0 CTC Mode
*@param		copy_u32delayms: Desired delay time in milliseconds
*@return	None
*/
void TIM0_DelayMS(u32 copy_u32delay);

#endif /* TIM0_INTERFACE_H_ */