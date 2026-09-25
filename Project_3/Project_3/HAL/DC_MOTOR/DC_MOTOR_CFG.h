/*
 * DC_MOTOR_CFG.h
 *
 * Created: 9/19/2026 11:02:21 AM
 *  Author: Eltawel
 */ 


#ifndef DC_MOTOR_CFG_H_
#define DC_MOTOR_CFG_H_

/*
	IN_1 & IN_2 For Left Side
	IN_3 & IN_4 For Right Side
*/

/* First Motor Driver For 2 Motors */
#define DC_MOTOR1_PORT				DIO_PORTB

#define DC_MOTOR1_IN1_PIN			DIO_PIN0
#define DC_MOTOR1_IN2_PIN			DIO_PIN1
#define DC_MOTOR1_IN3_PIN			DIO_PIN2
#define DC_MOTOR1_IN4_PIN			DIO_PIN3

/************************************************************************
 Second Motor Driver For 2 Onther Motors 
#define DC_MOTOR2_PORT				DIO_PORTC

#define DC_MOTOR2_IN1_PIN			DIO_PIN7
#define DC_MOTOR2_IN2_PIN			DIO_PIN6
#define DC_MOTOR2_IN3_PIN			DIO_PIN5
#define DC_MOTOR2_IN4_PIN			DIO_PIN4
************************************************************************/

#endif /* DC_MOTOR_CFG_H_ */