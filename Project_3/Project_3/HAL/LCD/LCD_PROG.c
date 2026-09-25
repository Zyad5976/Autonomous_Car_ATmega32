/*
 * LCD_PROG.c
 *
 * Created: 9/19/2026 2:45:17 PM
 *  Author: Eltawel
 */ 

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "../../LIB/CPU_CLOCK.h"
#include "../../MCAL/TIM0/TIM0_INTERFACE.h"
#include "../../MCAL/DIO/DIO_INTERFACE.h"
#include "LCD_INTERFACE.h"
#include "LCD_CFG.h"


/**
 * @brief Sends the upper nibble (4 bits) of a byte to the LCD data pins
 *        (D4-D7), then triggers an Enable pulse to latch it.
 *        Used internally to implement 4-bit mode communication, where
 *        every full byte (command or data) is split into two nibbles.
 * @param copy_u8data The nibble to send, expected in the upper 4 bits
 *                     of the byte (lower 4 bits are ignored/masked).
 * @return None
 */
static void LCD_SendHalfData(u8 copy_u8data)
{
	static const u8 Loc_LCD_BITS[LCD_4_BIT] = {LCD_D4_PIN, LCD_D5_PIN, LCD_D6_PIN, LCD_D7_PIN};
	u8 Loc_LCD_Counter = 0;
	DIO_CFG_t Loc_LCD_PIN = { .port = LCD_PORT, .dir = DIO_OUTPUT};
	
	for(Loc_LCD_Counter = 0; Loc_LCD_Counter < LCD_4_BIT; Loc_LCD_Counter++)
	{
		Loc_LCD_PIN.pin = Loc_LCD_BITS[Loc_LCD_Counter];
		
		Loc_LCD_PIN.val = GET_BIT(copy_u8data, Loc_LCD_Counter);
		DIO_SetPinVal(&Loc_LCD_PIN);
	}
}

/**
 * @brief Generates the Enable (E) pulse required by the HD44780
 *        controller to latch data/command bits that are currently
 *        set on the data pins. Sequence: E=1, short delay, E=0.
 * @param None
 * @return None
 */
static void LCD_SendEnablePulse()
{
	DIO_CFG_t Loc_LCD = { .port = LCD_PORT, .pin = LCD_E_PIN, .dir = DIO_OUTPUT};
	
	Loc_LCD.val = DIO_HIGH;
	DIO_SetPinVal(&Loc_LCD);
	
	TIM0_DelayMS(10);
	
	Loc_LCD.val = DIO_LOW;
	DIO_SetPinVal(&Loc_LCD);
	
	TIM0_DelayMS(2);
}

void LCD_Init(void)
{
	/* 1- Set LCD_PORT Direction*/
	DIO_SetPortDir(LCD_PORT, LCD_DIR_PORT);
	
	/* 2- Delay(40ms) */
	TIM0_DelayMS(600);
	
	/* 3- Send Half Data */
	LCD_SendHalfData(0x02);
	LCD_SendEnablePulse();
	LCD_SendHalfData(0x02);
	LCD_SendEnablePulse();
	LCD_SendHalfData(0x08);
	LCD_SendEnablePulse();
	
	/* 4- Send Command */
	LCD_SendCommand(0x0C);
	
	/* 5- Clear LCD */
	LCD_Clear();
}


void LCD_SendCommand(u8 copy_u8command)
{
	 /* Set Rs --> 0 */
	 DIO_CFG_t Loc_LCD = { .port = LCD_PORT, .pin = LCD_RS_PIN, .dir = DIO_OUTPUT, .val = DIO_LOW};
	 DIO_SetPinVal(&Loc_LCD);
	 
	 LCD_SendHalfData((copy_u8command >> 4) & 0x0F);
	 LCD_SendEnablePulse();
	 TIM0_DelayMS(5);
	 
	 LCD_SendHalfData(copy_u8command & 0x0F);
	 LCD_SendEnablePulse();
	 TIM0_DelayMS(5);
	
}

void LCD_SendData(u8 copy_u8data)
{
	 
	 DIO_CFG_t Loc_LCD = { .port = LCD_PORT, .pin = LCD_RS_PIN, .dir = DIO_OUTPUT, .val = DIO_HIGH};
	 DIO_SetPinVal(&Loc_LCD);
	 
	 
	 LCD_SendHalfData((copy_u8data >> 4) & 0x0F);
	 LCD_SendEnablePulse();
	 TIM0_DelayMS(5);
	 
	 
	 LCD_SendHalfData(copy_u8data & 0x0F);
	 LCD_SendEnablePulse();
	 TIM0_DelayMS(5);
	 
}

void LCD_Clear(void)
{
	LCD_SendCommand(0x01);
	TIM0_DelayMS(500);
}

void LCD_SendString(u8 *copy_u8string)
{
	u8 Loc_LCD_Counter = 0;
	
	while(copy_u8string[Loc_LCD_Counter] != nul)
	{
		LCD_SendData(copy_u8string[Loc_LCD_Counter]);
		Loc_LCD_Counter++;
	}
}