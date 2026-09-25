/*
 * TIM0_REG.h
 *
 * Created: 9/19/2026 8:28:50 AM
 *  Author: Eltawel
 */ 


#ifndef TIM0_REG_H_
#define TIM0_REG_H_

/************************************************************************/
/*                             REGISTERS                                */
/************************************************************************/
#define TIMSK_REG					*((volatile u8*)0x59)

#define TIFR_REG					*((volatile u8*)0x58)

#define TCCR0_REG					*((volatile u8*)0x53)

#define TCNT0_REG					*((volatile u8*)0x52)

#define OCR0_REG					*((volatile u8*)0x5C)

/************************************************************************/
/*                            REGISTER BITS                             */
/************************************************************************/

/* TCCR0_REG Bits */
#define FoC0_BIT			7		//Force Output Compare
#define WGM00_BIT			6		//Waveform Generation Mode
#define COM01_BIT			5		//Compare Match Output Mode
#define COM00_BIT			4		//Compare Match Output Mode
#define WGM01_BIT			3		//Waveform Generation Mode
#define CS02_BIT			2		//Clock Select
#define CS01_BIT			1		//Clock Select
#define CS00_BIT			0		//Clock Select

/* TIMSK_REG Bits */
#define OCIE0_BIT			1		//Timer/Counter0 Output Compare Match Interrupt Enable
#define TOIE0_BIT			0		//Timer/Counter0 Overflow Interrupt Enable

/* TIFR_REG Bits */
#define OCF0_BIT			1		//Output Compare Flag0
#define TOV0_BIT			0		//Timer/Counter0 Overflow Flag

#endif /* TIM0_REG_H_ */