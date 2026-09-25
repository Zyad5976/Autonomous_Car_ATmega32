/*
 * LED_PROG.c
 *
 * Created: 9/19/2026 6:23:51 AM
 *  Author: Eltawel
 */ 

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "../../MCAL/DIO/DIO_INTERFACE.h"
#include "LED_INTERFACE.h"

void LED_VoidON(DIO_PORT_t copy_eport, DIO_PIN_t copy_epin)
{
	DIO_CFG_t Loc_led = 
	{
		.port = copy_eport,
		.pin = copy_epin,
		.dir = DIO_OUTPUT,
		.val = DIO_HIGH,
	};
	
	DIO_SetPinDir(&Loc_led);
	DIO_SetPinVal(&Loc_led);
}

void LED_VoidOFF(DIO_PORT_t copy_eport, DIO_PIN_t copy_epin)
{
	DIO_CFG_t Loc_led =
	{
		.port = copy_eport,
		.pin = copy_epin,
		.dir = DIO_OUTPUT,
		.val = DIO_LOW,
	};
	
	DIO_SetPinDir(&Loc_led);
	DIO_SetPinVal(&Loc_led);
}

void LED_VoidToggle(DIO_PORT_t copy_eport, DIO_PIN_t copy_epin)
{
	DIO_CFG_t Loc_led =
	{
		.port = copy_eport,
		.pin = copy_epin,
		.dir = DIO_OUTPUT,
	};
	
	DIO_SetPinDir(&Loc_led);
	DIO_TogglePin(&Loc_led);	
}