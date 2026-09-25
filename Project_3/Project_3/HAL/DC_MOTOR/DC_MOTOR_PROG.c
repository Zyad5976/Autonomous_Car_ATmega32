/*
 * DC_MOTOR_PROG.c
 *
 * Created: 9/19/2026 11:02:55 AM
 *  Author: Eltawel
 */ 

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "../../MCAL/DIO/DIO_INTERFACE.h"
#include "DC_MOTOR_INTERFACE.h"
#include "DC_MOTOR_CFG.h"

/* Driver 1 Pins */
DIO_CFG_t M1_IN1 = { .port = DC_MOTOR1_PORT, .pin = DC_MOTOR1_IN1_PIN, .dir = DIO_OUTPUT};
DIO_CFG_t M1_IN2 = { .port = DC_MOTOR1_PORT, .pin = DC_MOTOR1_IN2_PIN, .dir = DIO_OUTPUT};
DIO_CFG_t M1_IN3 = { .port = DC_MOTOR1_PORT, .pin = DC_MOTOR1_IN3_PIN, .dir = DIO_OUTPUT};
DIO_CFG_t M1_IN4 = { .port = DC_MOTOR1_PORT, .pin = DC_MOTOR1_IN4_PIN, .dir = DIO_OUTPUT};

/* Driver 2 Pins */
//DIO_CFG_t M2_IN1 = { .port = DC_MOTOR2_PORT, .pin = DC_MOTOR1_IN1_PIN, .dir = DIO_INPUT};
//DIO_CFG_t M2_IN2 = { .port = DC_MOTOR2_PORT, .pin = DC_MOTOR1_IN2_PIN, .dir = DIO_INPUT};
//DIO_CFG_t M2_IN3 = { .port = DC_MOTOR2_PORT, .pin = DC_MOTOR1_IN3_PIN, .dir = DIO_INPUT};
//DIO_CFG_t M2_IN4 = { .port = DC_MOTOR2_PORT, .pin = DC_MOTOR1_IN4_PIN, .dir = DIO_INPUT};

void DCMOTOR_Init(void)
{	
	/* Set Direction for M1 */
	DIO_SetPinDir(&M1_IN1);
	DIO_SetPinDir(&M1_IN2);
	DIO_SetPinDir(&M1_IN3);
	DIO_SetPinDir(&M1_IN4);
	
	/* Set Direction for M1 */
	//DIO_SetPinDir(&M2_IN1);
	//DIO_SetPinDir(&M2_IN2);
	//DIO_SetPinDir(&M2_IN3);
	//DIO_SetPinDir(&M2_IN4);
	
	/* STart with Everything is OFF */
	DCMOTOR_Stop();
}

void DCMOTOR_MoveForward(void)
{
	M1_IN1.val = DIO_HIGH;
	DIO_SetPinVal(&M1_IN1);
	M1_IN2.val = DIO_LOW;
	DIO_SetPinVal(&M1_IN2);
	M1_IN3.val = DIO_LOW;
	DIO_SetPinVal(&M1_IN3);
	M1_IN4.val = DIO_HIGH;
	DIO_SetPinVal(&M1_IN4);
	
}

void DCMOTOR_MoveRevrse(void)
{
	M1_IN1.val = DIO_LOW;
	DIO_SetPinVal(&M1_IN1);
	M1_IN2.val = DIO_HIGH;
	DIO_SetPinVal(&M1_IN2);
	M1_IN3.val = DIO_HIGH;
	DIO_SetPinVal(&M1_IN3);
	M1_IN4.val = DIO_LOW;
	DIO_SetPinVal(&M1_IN4);
}

void DCMOTOR_MoveRight(void)
{
	M1_IN1.val = DIO_HIGH;
	DIO_SetPinVal(&M1_IN1);
	M1_IN2.val = DIO_LOW;
	DIO_SetPinVal(&M1_IN2);
	M1_IN3.val = DIO_HIGH;
	DIO_SetPinVal(&M1_IN3);
	M1_IN4.val = DIO_LOW;
	DIO_SetPinVal(&M1_IN4);
}

void DCMOTOR_MoveLeft(void)
{
	M1_IN1.val = DIO_LOW;
	DIO_SetPinVal(&M1_IN1);
	M1_IN2.val = DIO_HIGH;
	DIO_SetPinVal(&M1_IN2);
	M1_IN3.val = DIO_LOW;
	DIO_SetPinVal(&M1_IN3);
	M1_IN4.val = DIO_HIGH;
	DIO_SetPinVal(&M1_IN4);	
}

void DCMOTOR_Stop(void)
{
	M1_IN1.val = DIO_LOW;
	DIO_SetPinVal(&M1_IN1);
	M1_IN2.val = DIO_LOW;
	DIO_SetPinVal(&M1_IN2);
	M1_IN3.val = DIO_LOW;
	DIO_SetPinVal(&M1_IN3);
	M1_IN4.val = DIO_LOW;
	DIO_SetPinVal(&M1_IN4);	
}