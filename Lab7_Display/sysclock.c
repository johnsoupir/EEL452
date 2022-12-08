#include <stdio.h>

#include "stm32f446.h"
#include "sysclock.h"

uint32_t clock_tick;


void SysTick_Handler( void )
{
	clock_tick++;
}

uint32_t getTick()
{
	return clock_tick;
}


void Delay( uint32_t delay )
{
	uint32_t	start_tick = clock_tick;
	
	while (( clock_tick - start_tick ) < delay );
}


void SysTickConfigure( void )
{
	SYSTICK->LOAD = 15999;
	SYSTICK->VALUE = 0;
	SYSTICK->CTRL = SYSTICK_CLKSRC_PROCESSOR 	// SysTick Control and Status Register
					| SYSTICK_TICKINT_ENABLE 
					| SYSTICK_ENABLE;
}

void SysClockConfigure( void )
{
	// Enable the System Clock
	RCC->APB2ENR |= RCC_APB2ENR_SYSCFGEN;
	
	// Configure RCC Clock Control Register
	RCC->CR |= (( uint32_t )RCC_CR_HSION );							// Enable HSI
	while (( RCC->CR & RCC_CR_HSIRDY ) == 0 );						// Wait for HSI Ready
	
	// Configure RCC Clock Configuration Register
	RCC->CFGR |= RCC_CFGR_PPRE1_DIV1;
	RCC->CFGR |= RCC_CFGR_PPRE2_DIV1;
	RCC->CFGR |= RCC_CFGR_HPRE_DIV1;
	
	// Make sure the HSI Clock is Running
	RCC->CFGR = RCC_CFGR_SW_HSI;									// HSI is System Clock
	while (( RCC->CFGR & RCC_CFGR_SWS ) != RCC_CFGR_SWS_HSI );		// Wait for HSI 
}



