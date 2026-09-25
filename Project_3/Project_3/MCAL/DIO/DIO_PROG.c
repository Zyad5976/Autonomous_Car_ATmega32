/*
 * DIO_PROG.c
 *
 * Created: 9/18/2026 4:03:08 PM
 *  Author: Eltawel
 */ 

/************************************************************************/
/*                               INCLUDES                               */
/************************************************************************/
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "DIO_INTERFACE.h"
#include "DIO_REG.h"

/************************************************************************/
/*                               Functions                              */
/************************************************************************/

Std_RET DIO_SetPinDir(const DIO_CFG_t *obj_1)
{
	Std_RET ret = E_OK;
	
	if(obj_1 == null)
	{
		ret = E_NOK;
	}
	else
	{
		switch(obj_1->port)
		{
			case DIO_PORTA:
						if(obj_1->dir == DIO_OUTPUT)
						{
							SET_BIT(DDRA_REG, obj_1->pin);
						}
						else if(obj_1->dir == DIO_INPUT)
						{
							CLEAR_BIT(DDRA_REG, obj_1->pin);
						}
						break;
						
			case DIO_PORTB:
						if(obj_1->dir == DIO_OUTPUT)
						{
							SET_BIT(DDRB_REG, obj_1->pin);
						}
						else if(obj_1->dir == DIO_INPUT)
						{
							CLEAR_BIT(DDRB_REG, obj_1->pin);
						}
						break;
						
			case DIO_PORTC:
						if(obj_1->dir == DIO_OUTPUT)
						{
							SET_BIT(DDRC_REG, obj_1->pin);
						}
						else if(obj_1->dir == DIO_INPUT)
						{
							CLEAR_BIT(DDRC_REG, obj_1->pin);
						}
						break;
						
			case DIO_PORTD:
						if(obj_1->dir == DIO_OUTPUT)
						{
							SET_BIT(DDRD_REG, obj_1->pin);
						}
						else if(obj_1->dir == DIO_INPUT)
						{
							CLEAR_BIT(DDRD_REG, obj_1->pin);
						}
						break;
						
			default:	ret = E_NOK;	break;
		}
	}
	
	return ret;
}

Std_RET DIO_SetPinVal(const DIO_CFG_t *obj_1)
{
	Std_RET ret = E_OK;
	
	if(obj_1 == null)
	{
		ret = E_NOK;
	}
	else
	{
		switch(obj_1->port)
		{
			case DIO_PORTA:
						if(obj_1->val == DIO_HIGH)
						{
							SET_BIT(PORTA_REG, obj_1->pin);
						}
						else if(obj_1->val == DIO_LOW)
						{
							CLEAR_BIT(PORTA_REG, obj_1->pin);
						}
						break;
						
			case DIO_PORTB:
						if(obj_1->val == DIO_HIGH)
						{
							SET_BIT(PORTB_REG, obj_1->pin);
						}
						else if(obj_1->val == DIO_LOW)
						{
							CLEAR_BIT(PORTB_REG, obj_1->pin);
						}
						break;
						
			case DIO_PORTC:
						if(obj_1->val == DIO_HIGH)
						{
							SET_BIT(PORTC_REG, obj_1->pin);
						}
						else if(obj_1->val == DIO_LOW)
						{
							CLEAR_BIT(PORTC_REG, obj_1->pin);
						}
						break;
						
			case DIO_PORTD:
						if(obj_1->val == DIO_HIGH)
						{
							SET_BIT(PORTD_REG, obj_1->pin);
						}
						else if(obj_1->val == DIO_LOW)
						{
							CLEAR_BIT(PORTD_REG, obj_1->pin);
						}
						break;
						
			default:	ret = E_NOK;	break;
		}
	}
	
	return ret;	
}

Std_RET DIO_TogglePin(const DIO_CFG_t *obj_1)
{
	Std_RET ret = E_OK;
	
	if(obj_1 == null)
	{
		ret = E_NOK;
	}
	else
	{
		switch(obj_1->port)
		{
			case DIO_PORTA:
						TOGGLE_BIT(PORTA_REG, obj_1->pin);
						break;
						
			case DIO_PORTB:
						TOGGLE_BIT(PORTB_REG, obj_1->pin);
						break;
						
			case DIO_PORTC:
						TOGGLE_BIT(PORTC_REG, obj_1->pin);
						break;
			
			case DIO_PORTD:
						TOGGLE_BIT(PORTD_REG, obj_1->pin);
						break;
		}
	}
	
	return ret;
}

DIO_VAL_t DIO_ReadPinVal(const DIO_CFG_t *obj_1)
{
	DIO_VAL_t ret;
	
	if(obj_1 == null)
	{
		ret = DIO_VAL_ERR;
	}
	else
	{
		switch(obj_1->port)
		{
			case DIO_PORTA:	ret = GET_BIT(PINA_REG, obj_1->pin);	break;
			case DIO_PORTB:	ret = GET_BIT(PINB_REG, obj_1->pin);	break;
			case DIO_PORTC:	ret = GET_BIT(PINC_REG, obj_1->pin);	break;
			case DIO_PORTD:	ret = GET_BIT(PIND_REG, obj_1->pin);	break;
			default:		ret = DIO_VAL_ERR;		break;
		}
	}
	
	return ret;
}

void DIO_SetPortDir(DIO_PORT_t copy_e8port, u8 copy_u8dir)
{	
	switch(copy_e8port)
	{
		case DIO_PORTA:	DDRA_REG = copy_u8dir;	break;
		case DIO_PORTB:	DDRB_REG = copy_u8dir;	break;
		case DIO_PORTC:	DDRC_REG = copy_u8dir;	break;
		case DIO_PORTD:	DDRD_REG = copy_u8dir;	break;
	}
	
}

void DIO_SetPortVal(DIO_PORT_t copy_e8port, u8 copy_u8val)
{
	switch(copy_e8port)
	{
		case DIO_PORTA:	PORTA_REG = copy_u8val;	break;
		case DIO_PORTB:	PORTB_REG = copy_u8val;	break;
		case DIO_PORTC:	PORTC_REG = copy_u8val;	break;
		case DIO_PORTD:	PORTD_REG = copy_u8val;	break;
	}
}