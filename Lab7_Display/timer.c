#include "stm32f446.h"
#include "uart.h"
#include "main.h"
#include "sysclock.h"
#include <stdio.h>

void tim10_enable()
{
	TIM10->CR1 |= 0x0085;
	TIM10->DIER |= 0x00000001;
	TIM10->CNT = 0;
	TIM10->PSC = 1;
	TIM10->ARR = 1000;
}

void tim11_enable()
{

}





void tim10_handler()
{


			if ( GPIOA->IDR.bit5 == 0 )
			{
				printf( "Internal LED On\r\n" );
				GPIOA->ODR.bit5 = 1;
			}
			else
			{
				printf( "Internal LED Off\r\n" );
				GPIOA->ODR.bit5 = 0;
			}


}

void tim11_handler()
{

}
