/*
 * TIM0_CFG.h
 *
 * Created: 9/19/2026 9:30:47 AM
 *  Author: Eltawel
 */ 


#ifndef TIM0_CFG_H_
#define TIM0_CFG_H_

typedef enum
{
	TIM0_NORMAL = 0,
	TIM0_PWM,
	TIM0_CTC,
	TIM0_FAST_PWM
}TIM0_WGM_t;

typedef enum
{
	TIM0_NO_CLK = 0,
	TIM0_NO_PRESCALING,
	TIM0_8_PRESCALER,
	TIM0_64_PRESCALER,
	TIM0_256_PRESCALER,
	TIM0_1024_PRESCALER,
}TIM0_PRESCALER_t;

#endif /* TIM0_CFG_H_ */