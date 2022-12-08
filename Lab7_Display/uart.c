#include <stdint.h>

#include "stm32f446.h"                  // Device header
#include "uart.h"

//   <o>Baudrate
#define USART_BAUDRATE          115200

//   <o>USART clock
#define USART_CLK            16000000

/* Define  Baudrate setting (BRR) for USART */
#define __DIV(__PCLK, __BAUD)       ((__PCLK*25)/(4*__BAUD))
#define __DIVMANT(__PCLK, __BAUD)   (__DIV(__PCLK, __BAUD)/100)
#define __DIVFRAQ(__PCLK, __BAUD)   (((__DIV(__PCLK, __BAUD) - (__DIVMANT(__PCLK, __BAUD) * 100)) * 16 + 50) / 100)
#define __USART_BRR(__PCLK, __BAUD) ((__DIVMANT(__PCLK, __BAUD) << 4)|(__DIVFRAQ(__PCLK, __BAUD) & 0x0F))


/**
  Initialize stdout for UART2
  \return          0 on success, or -1 on error.
*/
void stdout_init (void) 
{
    RCC->AHB1ENR  |=   ( 1ul <<  0 );                        /* Enable GPIOA clock */
    RCC->APB1ENR  |=   ( 1ul << 17 );                        /* Enable USART#2 clock */

    /* Configure PA3 to USART2_RX, PA2 to USART2_TX */
    GPIOA->AFRL.data &= ~((15ul << 4* 3) | (15ul << 4* 2) );
    GPIOA->AFRL.data |=  (( 7ul << 4* 3) | ( 7ul << 4* 2) );
    GPIOA->MODER.data  &= ~(( 3ul << 2* 3) | ( 3ul << 2* 2) );
    GPIOA->MODER.data  |=  (( 2ul << 2* 3) | ( 2ul << 2* 2) );


    USART2->BRR  = __USART_BRR(USART_CLK, USART_BAUDRATE);  /* 115200 baud @ 12MHz   */
    USART2->CR3    = 0x0000;                                /* no flow control */
    USART2->CR2    = 0x0000;                                /* 1 stop bit */
    USART2->CR1    = ((   1ul <<  2) |                      /* enable RX */
                    (   1ul <<  3) |                      /* enable TX */
                    (   0ul << 12) |                      /* 1 start bit, 8 data bits */
                    (   1ul << 13) );                     /* enable USART */
}


/**
  Put a character to the stdout

  \param[in]   ch  Character to output
  \return          The character written, or -1 on write error.
*/
int stdout_putchar( int ch ) 
{
    while ( !( USART2->SR & 0x0080 ));
    USART2->DR = ( ch & 0xFF );
    return( ch );
}


/**
  Accept a character string, send them one by one to stdout

  \param[in]   str  String to output
  \return          The character written, or -1 on write error.
*/
int puts( const char *str )
{
	int index;
	int count = 0;
	
	for ( index=0; ; index++ )
	{
		if ( str[index] == '\0' )
		{
			stdout_putchar( '\n' );
			break;
		}
		stdout_putchar( str[index] );
		count++;
	}
	return count;
}