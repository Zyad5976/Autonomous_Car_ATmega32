/*
 * main.h
 *
 * Created: 9/18/2026 3:26:34 PM
 *  Author: Eltawel
 */ 


#ifndef MAIN_H_
#define MAIN_H_

/* LIBRARY */
#include "../LIB/CPU_CLOCK.h"
#include "../LIB/STD_TYPES.h"
#include "../LIB/BIT_MATH.h"
#include "../LIB/VECTOR_TABLE.h"

/* MCAL */
#include "../MCAL/DIO/DIO_INTERFACE.h"
#include "../MCAL/GI/GI_INTERFACE.h"
#include "../MCAL/TIM0/TIM0_INTERFACE.h"
#include "../MCAL/TIM1/TIM1_INTERFACE.h"
#include "../MCAL/TIM2/TIM2_INTERFACE.h"

/* HAL */
#include "../HAL/LED/LED_INTERFACE.h"
#include "../HAL/DC_MOTOR/DC_MOTOR_INTERFACE.h"
#include "../HAL/LCD/LCD_INTERFACE.h"
#include "../HAL/SERVO/SERVO_INTERFACE.h"
#include "../HAL/ULTRASONIC/ULTRASONIC_INTERFACE.h"


#endif /* MAIN_H_ */