/*
 * SERVO_PROG.c
 *
 * Created: 9/21/2026 8:21:55 PM
 *  Author: Eltawel
 */ 

#include "../../LIB/STD_TYPES.h"
#include "../../MCAL/TIM1/TIM1_INTERFACE.h"
#include "SERVO_INTERFACE.h"
#include "SERVO_CFG.h"

void Servo_Init(void)
{
	
	TIM1_FastPWM_Init();
	
}

void Servo_SetAngle(s8 copy_s8Angle)
{
	
	u16 Loc_u16Pulse;
	
	Loc_u16Pulse = SERVO_MIN_DUTY +
	((u32)(copy_s8Angle - SERVO_MIN_ANGLE) * (SERVO_MAX_DUTY - SERVO_MIN_DUTY))
	/ (SERVO_MAX_ANGLE - SERVO_MIN_ANGLE);
	
	TIM1_FastPWM_SetDuty(Loc_u16Pulse);
	
}