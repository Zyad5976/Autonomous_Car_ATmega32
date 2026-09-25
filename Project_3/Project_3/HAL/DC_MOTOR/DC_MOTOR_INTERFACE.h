/*
 * DC_MOTOR_INTERFACE.h
 *
 * Created: 9/19/2026 11:02:40 AM
 *  Author: Eltawel
 */ 


#ifndef DC_MOTOR_INTERFACE_H_
#define DC_MOTOR_INTERFACE_H_

/**
 * @brief Initializes the direction control pins for both motors as
 *        OUTPUT, and ensures both motors start in the STOP state.
 *        Does NOT initialize Timer2/PWM; TIM2_voidInit() must be
 *        called separately (e.g. in main, before this function).
 * @param None
 * @return None
 */
void DCMOTOR_Init(void);

/**
 * @brief Drives both motors forward (same direction), causing the
 *        car to move straight ahead.
 * @param None
 * @return None
 */
void DCMOTOR_MoveForward(void);

/**
 * @brief Drives both motors in reverse (same direction), causing the
 *        car to move straight backward.
 * @param None
 * @return None
 */
void DCMOTOR_MoveRevrse(void);

/**
 * @brief Turns the car right by stopping the right motor while driving
 *        the left motor forward (pivot turn).
 * @param None
 * @return None
 */
void DCMOTOR_MoveRight(void);

/**
 * @brief Turns the car left by stopping the left motor while driving
 *        the right motor forward (pivot turn).
 * @param None
 * @return None
 */
void DCMOTOR_MoveLeft(void);

/**
 * @brief Stops both motors immediately (IN1=IN2=0 for both motors,
 *        i.e. free-running stop, not active braking).
 * @param None
 * @return None
 */
void DCMOTOR_Stop(void);

#endif /* DC-MOTOR_INTERFACE_H_ */