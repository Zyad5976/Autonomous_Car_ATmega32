/*
 * DIO_CFG.h
 *
 * Created: 9/18/2026 9:48:25 PM
 *  Author: Eltawel
 */ 


#ifndef DIO_CFG_H_
#define DIO_CFG_H_

/* Direction */
typedef enum{
	DIO_INPUT = 0,
	DIO_OUTPUT,
	DIO_DIR_ERR
}DIO_DIR_t;

/* Value */
typedef enum{
	DIO_LOW = 0,
	DIO_HIGH,
	DIO_VAL_ERR
}DIO_VAL_t;

/* Ports */
typedef enum{
	DIO_PORTA = 0,
	DIO_PORTB,
	DIO_PORTC,
	DIO_PORTD,
}DIO_PORT_t;

/* Pins */
typedef enum{
	DIO_PIN0 = 0,
	DIO_PIN1,
	DIO_PIN2,
	DIO_PIN3,
	DIO_PIN4,
	DIO_PIN5,
	DIO_PIN6,
	DIO_PIN7,
}DIO_PIN_t;

/* DIO CFG */
typedef struct{
	DIO_PORT_t port;
	DIO_PIN_t  pin;
	DIO_DIR_t  dir;
	DIO_VAL_t  val;
}DIO_CFG_t;

#endif /* DIO_CFG_H_ */