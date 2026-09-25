/*
 * ULTRASONIC_CFG.h
 *
 * Created: 9/22/2026 10:33:57 AM
 *  Author: Eltawel
 */ 


#ifndef ULTRASONIC_CFG_H_
#define ULTRASONIC_CFG_H_

#define ULTRASONIC_TRIG_PORT				DIO_PORTD
#define ULTRASONIC_TRIG_PIN					DIO_PIN2

#define ULTRASONIC_ECHO_PORT				DIO_PORTD
#define ULTRASONIC_ECHO_PIN					DIO_PIN6

/* Timer1 tick = 4us @ 16MHz with 64 prescaler */
#define ULTRASONIC_US_PER_TICK				4UL

#define ULTRASONIC_SPEED_OF_SOUND_CM_PER_US	((float)0.0343)

/* Max time to wait for echo (in microseconds), covers ~4m range + margin */
#define ULTRASONIC_TIMEOUT_US				30000UL


#endif /* ULTRASONIC_CFG_H_ */