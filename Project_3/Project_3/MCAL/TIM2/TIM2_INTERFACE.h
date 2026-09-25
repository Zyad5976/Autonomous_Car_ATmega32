/*
 * TIM2_INTERFACE.h
 *
 * Created: 9/22/2026 3:04:35 PM
 *  Author: Eltawel
 */ 


#ifndef TIM2_INTERFACE_H_
#define TIM2_INTERFACE_H_


/**
*@brief		Initializes Timer2 in CTC Mode with No Prescaling for a 1us timing tick
*@param		None
*@return	None
*/
void TIM2_Init(void);

/**
*@brief		Generates a synchronous (blocking) delay in microseconds using Timer2 CTC Mode
*@param		copy_u16delayus: Desired delay time in microseconds
*@return	None
*/
void TIM2_DelayUS(u16 copy_u16delayus);

#endif /* TIM2_INTERFACE_H_ */