/*
 * ULTRASONIC_PROG.c
 *
 * Created: 9/22/2026 10:34:34 AM
 *  Author: Eltawel
 */ 


#include "../../LIB/STD_TYPES.h"
#include "../../MCAL/DIO/DIO_INTERFACE.h"
#include "../../MCAL/TIM2/TIM2_INTERFACE.h"
#include "../../MCAL/TIM1/TIM1_INTERFACE.h"
#include "../../MCAL/GI/GI_INTERFACE.h"
#include "ULTRASONIC_INTERFACE.h"
#include "ULTRASONIC_CFG.h"

static DIO_CFG_t Loc_ULTRA_TRIG = {.port = ULTRASONIC_TRIG_PORT, .pin = ULTRASONIC_TRIG_PIN, .dir = DIO_OUTPUT, .val = DIO_LOW};
static DIO_CFG_t Loc_ULTRA_ECHO = {.port = ULTRASONIC_ECHO_PORT, .pin = ULTRASONIC_ECHO_PIN, .dir = DIO_INPUT};

static volatile u16 Loc_u16RisingTick  = 0;
static volatile u16 Loc_u16FallingTick = 0;
static volatile u8  Loc_u8CaptureState = 0;   /* 0 = waiting rising, 1 = waiting falling, 2 = done */
static volatile u8  Loc_u8NewDataReady = 0;

static void Ultrasonic_VoidEchoCallback(void)
{
	if(Loc_u8CaptureState == 0)
	{
		Loc_u16RisingTick = TIM1_ICU_GetCapturedVal();
		TIM1_ICU_Init(TIM1_FALLING_EDGE);   /* flip edge for the next capture */
		Loc_u8CaptureState = 1;
	}
	else if(Loc_u8CaptureState == 1)
	{
		Loc_u16FallingTick = TIM1_ICU_GetCapturedVal();
		Loc_u8CaptureState = 2;
		Loc_u8NewDataReady = 1;
	}
}

void Ultrasonic_Init(void)
{
	DIO_SetPinDir(&Loc_ULTRA_TRIG);
	DIO_SetPinVal(&Loc_ULTRA_TRIG);
	DIO_SetPinDir(&Loc_ULTRA_ECHO);

	TIM1_ICU_SetCallBack(Ultrasonic_VoidEchoCallback);
	TIM1_ICU_Init(TIM1_RISING_EDGE);
	GI_InterruptEnable();
}

u16 Ultrasonic_GetDistance(void)
{
	u32 Loc_u32Timeout = 0;
	u16 Loc_u16Ticks;
	u32 Loc_u32PulseWidthUS;

	Loc_u8CaptureState = 0;
	Loc_u8NewDataReady = 0;
	TIM1_ICU_Init(TIM1_RISING_EDGE);   /* arm for a fresh rising edge */

	/* Send 10us trigger pulse */
	Loc_ULTRA_TRIG.val = DIO_HIGH;
	DIO_SetPinVal(&Loc_ULTRA_TRIG);
	TIM2_DelayUS(10);
	Loc_ULTRA_TRIG.val = DIO_LOW;
	DIO_SetPinVal(&Loc_ULTRA_TRIG);

	/* Wait for the ISR to capture both edges (timing here is loose polling only) */
	while((Loc_u8NewDataReady == 0) && (Loc_u32Timeout < ULTRASONIC_TIMEOUT_US))
	{
		TIM2_DelayUS(1);
		Loc_u32Timeout++;
	}

	if(Loc_u8NewDataReady == 0)
	{
		return 0;   /* timeout - no echo captured */
	}

	/* Real hardware-timed measurement, immune to software loop overhead */
	Loc_u16Ticks = (u16)(Loc_u16FallingTick - Loc_u16RisingTick);
	Loc_u32PulseWidthUS = (u32)Loc_u16Ticks * ULTRASONIC_US_PER_TICK;

	return (u16)((Loc_u32PulseWidthUS * ULTRASONIC_SPEED_OF_SOUND_CM_PER_US) / 2);
}