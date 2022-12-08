#ifndef _IRQ_HANDLER_H_
#define _IRQ_HANDLER_H_

#include "stm32f446.h"

#ifdef __cplusplus
	extern "C" {
#endif

typedef int bool;
#define TRUE  1
#define FALSE 0

// Functional Prototypes
void EXTI0_IRQHandler();
void EXTI1_IRQHandler();
void EXTI2_IRQHandler();
void EXTI3_IRQHandler();
void EXTI4_IRQHandler();
void EXTI9_5_IRQHandler();
void EXTI15_10_IRQHandler();

#endif