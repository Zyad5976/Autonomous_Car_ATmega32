/*
 * TIM1_INTERFACE.h
 *
 * Created: 9/19/2026 4:01:20 PM
 *  Author: Eltawel
 */ 


#ifndef TIM1_INTERFACE_H_
#define TIM1_INTERFACE_H_

#include "TIM1_CFG.h"

/*
 *@brief	Initialize TIM1 in Fast PWM mode (used for Servo control)
 *@return	none
 */
void TIM1_FastPWM_Init(void);

/*
 *@brief	Set the compare value (duty cycle) for PWM output on OC1A
 *@param	copy_u16CompareVal: value to load into OCR1A
 *@return	none
 */
void TIM1_FastPWM_SetDuty(u16 copy_u16val);

/*
 *@brief	Initialize TIM1 in Input Capture mode (used to measure Echo pulse width)
 *@return	none
 */
void TIM1_ICU_Init(TIM1_EDGE_t obj_1);

/*
 *@brief	Read the last captured timer value (from ICR1 register)
 *@return	u16: captured value
 */
u16 TIM1_ICU_GetCapturedVal(void);

/*
 *@brief	Register a callback function to be called automatically when
 *          an Input Capture interrupt occurs
 *@param	copy_pFunc: pointer to the function to call
 *@return	Std_RET
 */
void TIM1_ICU_SetCallBack(void(*PTR)(void));

#endif /* TIM1_INTERFACE_H_ */