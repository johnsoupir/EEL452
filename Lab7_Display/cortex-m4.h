#ifndef _CORTEX_M4_H_
#define _CORTEX_M4_H_

#ifdef __cplusplus
	extern "C" {
#endif

#include "stm32f446.h"

#define SYSTICK_REGISTERS	(( uint32_t )0xE000E010UL )
#define NVIC_REGISTERS		(( uint32_t )0xE000E100UL )

#define SYSTICK				(( SYSTICK_TypeDef * )SYSTICK_REGISTERS )
#define NVIC				(( NVIC_TypeDef * )NVIC_REGISTERS )

#define SYSTICK_CLKSRC_EXTERNAL 	0x00000000             	/*!< SysTick Clock Source - External */
#define SYSTICK_CLKSRC_PROCESSOR	0x00000004				/*!< SysTick Clock Source - Processor */
#define SYSTICK_TICKINT_DISABLE		0x00000000
#define SYSTICK_TICKINT_ENABLE		0x00000002
#define SYSTICK_DISABLE				0x00000000
#define SYSTICK_ENABLE				0x00000001


typedef struct
{
	volatile uint32_t CTRL;		// Control and Status Register
	volatile uint32_t LOAD;		// Reload Value Register
	volatile uint32_t VALUE;	// Current Value Register
	volatile uint32_t CALIB;	// Calibration Value Register
} SYSTICK_TypeDef;

typedef struct
{
	volatile uint32_t ISER[8U];		/*!< Interrupt Set Enable Register, 0xE000E100 - 0xE000E11C */
	uint32_t RESERVED0[24U];
	volatile uint32_t ICER[8U];		/*!< Interrupt Clear Enable Register, 0xE000E180 - 0xE000E19C */
	uint32_t RESERVED1[24U];
	volatile uint32_t ISPR[8U];		/*!< Interrupt Set Pending Register */
	uint32_t RESERVED2[24U];
	volatile uint32_t ICPR[8U];		/*!< Interrupt Clear Pending Register */
	uint32_t RESERVED3[24U];
	volatile uint32_t IABR[8U];		/*!< Interrupt Active Bit Register */
	uint32_t RESERVED4[24U];
	volatile uint32_t IP[8U];		/*!< Interrupt Priority Register */
	uint32_t RESERVED5[24U];
	volatile uint32_t STIR;			/*!< Software Trigger Interrupt Register */
} NVIC_TypeDef;

// Functional Prototypes
void NVIC_EnableIRQ( IRQ_Type irq_no );
void NVIC_DisableIRQ( IRQ_Type irq );

#endif
