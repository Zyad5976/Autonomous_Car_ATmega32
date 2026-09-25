/*
 * LCD_CFG.h
 *
 * Created: 9/19/2026 2:44:52 PM
 *  Author: Eltawel
 */ 


#ifndef LCD_CFG_H_
#define LCD_CFG_H_

/* define direction of LCD_PORT */
#define LCD_DIR_PORT		0xF3

/* define LCD Control & Data Port */
#define LCD_PORT			DIO_PORTA

/* define LCD Control Pins (RS, RW and E) */
#define LCD_RS_PIN			DIO_PIN0
//#define LCD_RW_PIN			GND
#define LCD_E_PIN			DIO_PIN1

/* define LCD Data Pins Assume we work on 4-bit configuration */
#define LCD_D4_PIN			DIO_PIN4
#define LCD_D5_PIN			DIO_PIN5
#define LCD_D6_PIN			DIO_PIN6
#define LCD_D7_PIN			DIO_PIN7

/* LCD Bits */
#define LCD_4_BIT			4

#endif /* LCD_CFG_H_ */