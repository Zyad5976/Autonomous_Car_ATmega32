/*
 * SERVO_INTERFACE.h
 *
 * Created: 9/21/2026 8:21:41 PM
 *  Author: Eltawel
 */ 


#ifndef SERVO_INTERFACE_H_
#define SERVO_INTERFACE_H_

/*
 *@brief	Initialize the servo (sets up TIM1 PWM internally, moves to center)
 */
void Servo_Init(void);

/*
 *@brief	Move servo to a specific angle
 *@param	copy_s8Angle: angle from SERVO_MIN_ANGLE to SERVO_MAX_ANGLE
 */
void Servo_SetAngle(s8 copy_s8Angle);

#endif /* SERVO_INTERFACE_H_ */