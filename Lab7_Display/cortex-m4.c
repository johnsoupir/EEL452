#include <stdint.h>
#include "cortex-m4.h"

void NVIC_EnableIRQ( IRQ_Type irq_no )
{
	uint8_t index = irq_no / 32;
	uint8_t irq_shift = irq_no % 32;
	
	if ( irq_no > 0 )
	{
		NVIC->ISER[index] |= 0x01 << irq_shift;
	}
}

void NVIC_DisableIRQ( IRQ_Type irq_no )
{
	uint8_t index = irq_no / 32;
	uint8_t irq_shift = irq_no % 32;
	
	if ( irq_no > 0 )
	{
		NVIC->ISER[index] &= ~( 0x01 << irq_shift );
	}
}