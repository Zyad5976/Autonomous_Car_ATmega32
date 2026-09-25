/*
 * LCD_INTERFACE.h
 *
 * Created: 9/19/2026 2:45:05 PM
 *  Author: Eltawel
 */ 


#ifndef LCD_INTERFACE_H_
#define LCD_INTERFACE_H_

/**
* @brief Initializes the LCD in 4-bit mode according to the standard
*        HD44780 initialization sequence (function set, display ON,
*        clear display, entry mode set), using pin configuration
*        defined in LCD_CFG.h.
* @param None
* @return None
* @note Relies on TIM0_voidDelayMs() for the required timing delays
*       between initialization steps.
*/
void LCD_Init(void);

/**
 * @brief Sends a command byte to the LCD (e.g. clear display, cursor
 *        home, display ON/OFF...). Internally splits the byte into
 *        two 4-bit nibbles since the driver operates in 4-bit mode.
 * @param copy_u8command Command byte, as defined by the HD44780 command set.
 * @return None
 */
void LCD_SendCommand(u8 copy_u8command);

/**
 * @brief Sends a single character of data to be displayed at the
 *        current cursor position.
 * @param copy_u8data ASCII character to display.
 * @return None
 */
void LCD_SendData(u8 copy_u8data);

/**
 * @brief CLear the LCD from any data to displayed nothing
 * @param none
 * @return None
 */
void LCD_Clear(void);

/**
 * @brief Sends a null-terminated string to be displayed starting at
 *        the current cursor position.
 * @param copy_pu8string Pointer to a null-terminated character array (string).
 * @return None
 */
void LCD_SendString(u8 *copy_u8string);

#endif /* LCD_INTERFACE_H_ */