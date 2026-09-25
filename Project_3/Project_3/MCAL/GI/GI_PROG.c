/*
 * GI_PROG.c
 *
 * Created: 9/19/2026 7:26:34 AM
 *  Author: Eltawel
 */ 

#include "GI_INTERFACE.h"
#include "GI_REG.h"

void GI_InterruptEnable()
{
	__asm volatile("SEI");
}

void GI_InterruptDisable()
{
	__asm volatile("CLI");
}