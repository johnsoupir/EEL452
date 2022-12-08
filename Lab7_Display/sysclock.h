#ifndef _SYSCLOCK_H_
#define _SYSCLOCK_H_

#include <stdio.h>

#include "cortex-m4.h"
#include "stm32f446.h"

// Functional Prototypes
void SysTick_Handler( void );
void Delay( uint32_t delay );
void SysTickConfigure( void );
void SysClockConfigure( void );

#endif  // _SYSCLOCK_H_
