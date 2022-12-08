#include <stdint.h>
#include "irq_handler.h"

extern bool user_button_pressed;

void EXTI15_10_IRQHandler()
{
	// Check to see which Interrupt was Triggered
	if ( EXTI->PR & ( 1 << 10 ))
	{
		EXTI->PR |= ( 1 << 10 );
	}
	if ( EXTI->PR & ( 1 << 11 ))
	{
		EXTI->PR |= ( 1 << 11 );
	}
	if ( EXTI->PR & ( 1 << 12 ))
	{
		EXTI->PR |= ( 1 << 12 );
	}
	if ( EXTI->PR & ( 1 << 13 ))
	{
		EXTI->PR |= ( 1 << 13 );
		user_button_pressed = TRUE;
	}
	if ( EXTI->PR & ( 1 << 14 ))
	{
		EXTI->PR |= ( 1 << 14 );
	}
	if ( EXTI->PR & ( 1 << 15 ))
	{
		EXTI->PR |= ( 1 << 15 );
	}
}
