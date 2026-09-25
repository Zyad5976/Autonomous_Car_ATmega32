/*
 * Project_3.c
 *
 * Created: 9/18/2026 3:16:56 PM
 * Author : Eltawel
 */ 

#include "main.h"

#define SAFE_ZONE				10
#define SERVO_RIGHT				90
#define SERVO_LEFT			    (-90)
#define SERVO_CENTER			0

#define SCAN_SETTLE_MS			5000
#define TURN_DURATION_MS		800
#define REVERSE_DURATION_MS		800

static void U16_ToString(u16 copy_u16val, u8 *copy_u8buffer)
{
	u8 Loc_u8Digits[5];
	u8 Loc_u8Index = 0;
	u8 Loc_u8i;

	if(copy_u16val == 0)
	{
		copy_u8buffer[0] = '0';
		copy_u8buffer[1] = '\0';
		return;
	}

	while(copy_u16val > 0)
	{
		Loc_u8Digits[Loc_u8Index] = (copy_u16val % 10) + '0';
		copy_u16val /= 10;
		Loc_u8Index++;
	}

	for(Loc_u8i = 0; Loc_u8i < Loc_u8Index; Loc_u8i++)
	{
		copy_u8buffer[Loc_u8i] = Loc_u8Digits[Loc_u8Index - 1 - Loc_u8i];
	}
	copy_u8buffer[Loc_u8i] = '\0';
}

int main(void)
{

	TIM0_Init();
	LCD_Init();
	TIM2_Init();
	Servo_Init();
	DCMOTOR_Init();
	Ultrasonic_Init();
	GI_InterruptEnable();
	
	LCD_Clear();
	LCD_SendString((u8*)"Autonomous Car");
	TIM0_DelayMS(1000);
	
	LCD_Clear();
	LCD_SendString((u8*)"Let's Start ^_^");
	TIM0_DelayMS(1000);
	LCD_Clear();
	
	u8 Loc_Buffer[5];
	u16 Loc_dist;
	u16 Loc_LeftDist;
	u16 Loc_RightDist;
	
	Servo_SetAngle(SERVO_CENTER);
	TIM0_DelayMS(SCAN_SETTLE_MS);	
	
    while (1) 
    {
		Loc_dist = Ultrasonic_GetDistance();
		
		LCD_Clear();
		LCD_SendString((u8*)"Dist:");
		LCD_SendString((u8*)" ");
		U16_ToString(Loc_dist, Loc_Buffer);
		LCD_SendString(Loc_Buffer);
		LCD_SendString((u8*)"cm");
		TIM0_DelayMS(1000);
		
		if((Loc_dist != 0) && (Loc_dist > SAFE_ZONE))
		{
			DCMOTOR_MoveForward();
			continue;
		}
		
		DCMOTOR_Stop();
		LCD_Clear();
		LCD_SendString((u8*)"Obstacle! Scan");
		
		Servo_SetAngle(SERVO_LEFT);
		TIM0_DelayMS(SCAN_SETTLE_MS);
		Loc_LeftDist = Ultrasonic_GetDistance();
		
		Servo_SetAngle(SERVO_RIGHT);
		TIM0_DelayMS(SCAN_SETTLE_MS);
		Loc_RightDist = Ultrasonic_GetDistance();
		
		Servo_SetAngle(SERVO_CENTER);
		TIM0_DelayMS(SCAN_SETTLE_MS);
		
		if((Loc_LeftDist != 0) && (Loc_LeftDist >= Loc_RightDist))
		{
			LCD_Clear();
			LCD_SendString((u8*)"Turning Left");
			DCMOTOR_MoveLeft();
			TIM0_DelayMS(TURN_DURATION_MS);
			DCMOTOR_Stop();
		}
		else if(Loc_RightDist != 0)
		{
			LCD_Clear();
			LCD_SendString((u8*)"Turning Right");
			DCMOTOR_MoveRight();
			TIM0_DelayMS(TURN_DURATION_MS);
			DCMOTOR_Stop();
		}
		else
		{
			LCD_Clear();
			LCD_SendString((u8*)"Blocked-Reverse");
			DCMOTOR_MoveRevrse();
			TIM0_DelayMS(REVERSE_DURATION_MS);
			DCMOTOR_Stop();
		}
		
    }
}

