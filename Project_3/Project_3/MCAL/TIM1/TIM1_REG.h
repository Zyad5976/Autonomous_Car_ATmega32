/*
 * TIM1_REG.h
 *
 * Created: 9/19/2026 4:00:50 PM
 *  Author: Eltawel
 */ 


#ifndef TIM1_REG_H_
#define TIM1_REG_H_

/************************************************************************/
/*                             REGISTERS                                */
/************************************************************************/

#define TCCR1A_REG				*((volatile u8*)0x4F)

#define TCCR1B_REG				*((volatile u8*)0x4E)

#define TCNT1_REG				*((volatile u16*)0x4C)	/* TCNT1H + TCNT1L */

#define OCR1A_REG				*((volatile u16*)0x4A)	/* OCRA1H + OCRA1L */

#define OCR1B_REG				*((volatile u16*)0X48)  /* OCR1BH + OCR1BL */

#define ICR1_REG				*((volatile u16*)0x46)	/* ICR1H + ICR1L */

#define TIMSK_REG				*((volatile u8*)0x59)

#define TIFR_REG				*((volatile u8*)0x58)

/************************************************************************/
/*                           REGISTERS BITS                             */
/************************************************************************/

/* TCCR1A_REG Bits */
#define COM1A1_BIT				7		// Compare Output Mode for Compare A
#define COM1A0_BIT				6		// Compare Output Mode for Compare A

#define COM1B1_BIT				5		// Compare Output Mode for Compare B
#define COM1B0_BIT				4		// Compare Output Mode for Compare B

#define FOC1A_BIT				3		// Force Output Compare for Compare Unit A
#define FOC1B_BIT				2		// Force Output Compare for Compare Unit B

#define WGM11_BIT				1		// Waveform Generation Mode
#define WGM10_BIT				0		// Waveform Generation Mode

/* TCCR1B_REG Bits */
#define ICNC1_BIT				7		// Input Capture Noise Canceler
#define ICES1_BIT				6		// Input Capture Edge Select
#define WGM13_BIT				4		// Waveform Generation Mode
#define WGM12_BIT				3		// Waveform Generation Mode
#define CS12_BIT				2		// Clock Select
#define CS11_BIT				1		// Clock Select
#define CS10_BIT				0		// Clock Select

/* TIMSK_REG Bits */
#define TICIE1_BIT				5		// Timer/Counter1 Input Capture Interrupt Enable
#define OCIE1A_BIT				4		// Timer/Counter1 Output Compare A Match Interrupt Enable
#define OCIE1B_BIT				3		// Timer/Counter1 Output Compare B Match Interrupt Enable 
#define TOIE1_BIT				2		// Timer/Counter1 Overflow Interrupt Enable

/* TIFR_REG Bits */
#define ICF1_BIT				5		// Timer/Counter1 Input Capture Flag
#define OCF1A_BIT				4		// Timer/Counter1 Output Compare A Flag
#define OCF1B_BIT				3		// Timer/Counter1 Output Compare B Flag
#define TOV1_BIT				2		// Timer/Counter1 Flag

#endif /* TIM1_REG_H_ */