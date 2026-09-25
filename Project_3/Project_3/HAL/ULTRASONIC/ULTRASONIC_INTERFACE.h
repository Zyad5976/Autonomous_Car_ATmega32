/*
 * ULTRASONIC_INTERFACE.h
 *
 * Created: 9/22/2026 10:34:15 AM
 *  Author: Eltawel
 */ 


#ifndef ULTRASONIC_INTERFACE_H_
#define ULTRASONIC_INTERFACE_H_

/*
 *@brief	Initialize the trigger pin and TIM1 Input Capture unit
 */
void Ultrasonic_Init(void);

/*
 *@brief	Send a trigger pulse, measure echo width, and return distance
 *@return	Distance in cm (0 if no valid echo received within timeout)
 */
u16 Ultrasonic_GetDistance(void);


#endif /* ULTRASONIC_INTERFACE_H_ */