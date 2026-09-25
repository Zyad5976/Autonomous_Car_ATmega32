/*
 * DIO_INTERFACE.h
 *
 * Created: 9/18/2026 4:02:51 PM
 *  Author: Eltawel
 */ 


#ifndef DIO_INTERFACE_H_
#define DIO_INTERFACE_H_

#include "DIO_CFG.h"

/* PIN Functions */

/*
 *@brief			Select The Direction(Input, Output) for the specific GPIO pin
 *@param			*obj_1: Pointer to the DIO Configuration Structure Containig -> Port, Pin, Dir and Val
 *@return			Std_RET: It's an u8 and it's points to unsigned char
 *@note				Ensure the pointer not equal NULL before calling
*/
Std_RET DIO_SetPinDir(const DIO_CFG_t *obj_1);

/*
 *@brief			Select The Value(Low, High) for the specific GPIO pin
 *@param			*obj_1: Pointer to the DIO Configuration Structure Containig -> Port, Pin, Dir and Val
 *@return			Std_RET: It's an u8 and it's points to unsigned char
 *@note				Ensure the pointer not equal NULL before calling
*/
Std_RET DIO_SetPinVal(const DIO_CFG_t *obj_1);

/*
 *@brief			Toggle The Value(Low, High) for the specific GPIO pin
 *@param			*obj_1: Pointer to the DIO Configuration Structure Containig -> Port, Pin, Dir and Val
 *@return			Std_RET: It's an u8 and it's points to unsigned char
 *@note				Ensure the pointer not equal NULL before calling
*/
Std_RET DIO_TogglePin(const DIO_CFG_t *obj_1);

/*
 *@brief			Read The Value(Low, High) for the specific GPIO pin
 *@param			*obj_1: Pointer to the DIO Configuration Structure Containig -> Port, Pin, Dir and Val
 *@return			Std_RET: It's an u8 and it's points to unsigned char
 *@note				Ensure the pointer not equal NULL before calling
*/
DIO_VAL_t DIO_ReadPinVal(const DIO_CFG_t *obj_1);

/* PORT Functions */

/**
*@brief		Select the Direction(Input, Output) for a specific GPIO Port
*@param		copy_eport: Target GPIO Port(PORT_A, PORT_B, PORT_C, PORT_D)
*@param		copy_u8dir: 8-bit value to be written on the port
*@return	none
*/
void DIO_SetPortDir(DIO_PORT_t copy_e8port, u8 copy_u8dir);

/**
*@brief		Select the Value(Low, High) for a specific GPIO Port
*@param		copy_eport: Target GPIO Port(PORT_A, PORT_B, PORT_C, PORT_D)
*@param		copy_u8dir: 8-bit direction value
*@return	none
*/
void DIO_SetPortVal(DIO_PORT_t copy_e8port, u8 copy_u8val);

#endif /* DIO_INTERFACE_H_ */