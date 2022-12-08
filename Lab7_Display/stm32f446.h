#ifndef _STM32F446_H_
#define _STM32F446_H_

#ifdef __cplusplus
    extern "C" {
#endif

#include <stdint.h>

/*!< Microcontroller Base Addresses */
#define FLASH_BASE                  (( uint32_t )0x08000000UL )             /*!< FLASH base address in the alias region */
#define SRAM_BASE                   (( uint32_t )0x20000000UL )             /*!< SRAM base address in the alias region */

/*!< AHB1 Peripherals */
#define GPIOA_REGISTERS            	(( uint32_t )0x40020000UL )				/*!< 0x40020000 to 0x400203FF */
#define GPIOB_REGISTERS				(( uint32_t )0x40020400UL )				/*!< 0x40020400 to 0x400207FF */
#define GPIOC_REGISTERS				(( uint32_t )0x40020800UL )				/*!< 0x40020800 to 0x40020BFF */
#define RCC_REGISTERS           	(( uint32_t )0x40023800UL )

/*!<APB1 Peripherals */
#define USART2_REGISTERS            (( uint32_t )0x40004400UL )

/*!<APB2 Peripherals */
#define EXTI_REGISTERS				(( uint32_t )0x40013C00UL )
#define SYSCFG_REGISTERS			(( uint32_t )0x40013800UL )

/*!< Register Memory Maps */
#define EXTI						(( EXTI_TypeDef * )EXTI_REGISTERS )
#define GPIOA                       (( GPIO_TypeDef * )GPIOA_REGISTERS )
#define GPIOB                       (( GPIO_TypeDef * )GPIOB_REGISTERS )
#define GPIOC                       (( GPIO_TypeDef * )GPIOC_REGISTERS )
#define GPIOC_32                    (( uint32_t * )GPIOC_REGISTERS )
#define RCC                         (( RCC_TypeDef * )RCC_REGISTERS )
#define SYSCFG						(( SYSCFG_TypeDef * )SYSCFG_REGISTERS )
#define USART2						(( USART_TypeDef * )USART2_REGISTERS )

/*!< RCC AHB1 Peripheral Clock Enable Register Bit Assignments */
#define RCC_AHB1ENR_GPIOA    		0x1                        	/*!< GPIOA Clock Enable */
#define RCC_AHB1ENR_GPIOB			0x2							/*!< GPIOB Clock Enable */
#define RCC_AHB1ENR_GPIOC			0x4							/*!< GPIOC Clock Enable */

#define RCC_APB1ENR_PWREN			0x10000000
#define RCC_APB2ENR_SYSCFGEN		0x4000						/*!< System Configuration Controller Clock Enable */

/*Timer 9 and 10*/
#define TIM10_REG 0x40014400
#define TIM11_REG 0x40014800

#define TIM10 ((TIM_TypeDef * ) TIM10_REG)
#define TIM11 ((TIM11_TypeDef *) TIM11_REG)


typedef struct 
{
	volatile uint32_t CR1;
	volatile uint32_t SMCR;
	volatile uint32_t DIER;
	volatile uint32_t SR;
	volatile uint32_t EGR;
	volatile uint32_t CCMR1;
	volatile uint32_t RESERVED01;
	volatile uint32_t CCEN;
	volatile uint32_t CNT;
	volatile uint32_t PSC;
	volatile uint32_t ARR;
	volatile uint32_t RESERVED02;
	volatile uint32_t CCR1;
	volatile uint32_t RESERVED03;
	volatile uint32_t OR;
} TIM_TypeDef;
		
typedef union
{
	uint32_t data;
	struct 
	{
		uint32_t bit0: 1;
		uint32_t bit1: 1;
		uint32_t bit2: 1;
		uint32_t bit3: 1;
		uint32_t bit4: 1;
		uint32_t bit5: 1;
		uint32_t bit6: 1;
		uint32_t bit7: 1;
		uint32_t bit8: 1;
		uint32_t bit9: 1;
		uint32_t bit10: 1;
		uint32_t bit11: 1;
		uint32_t bit12: 1;
		uint32_t bit13: 1;
		uint32_t bit14: 1;
		uint32_t bit15: 1;
		uint32_t bit16: 1;
		uint32_t bit17: 1;
		uint32_t bit18: 1;
		uint32_t bit19: 1;
		uint32_t bit20: 1;
		uint32_t bit21: 1;
		uint32_t bit22: 1;
		uint32_t bit23: 1;
		uint32_t bit24: 1;
		uint32_t bit25: 1;
		uint32_t bit26: 1;
		uint32_t bit27: 1;
		uint32_t bit28: 1;
		uint32_t bit29: 1;
		uint32_t bit30: 1;
		uint32_t bit31: 1;
	};
} reg32bit;


typedef enum
{
	/****** Cortex-M4 Proecessor Exception Numbers ******/
	NonMaskableInt_IRQn 		= -14,
	HardFault_IRQn				= -13,
	MemoryManagement_IRQn		= -12,
	BusFault_IRQn				= -11,
	UsageFault_IRQn				= -10,
	SVCall_IRQn					= -5,
	DebugMonitor_IRQn			= -4,
	PendSV_IRQn					= -2,
	SysTick_IRQn				= -1,
	
	/****** STM32 Specific Interrupt Numbers ******/
	WWDG_IRQn		= 0,
	PVD_PVM_IRQn	= 1,
	TAMP_STAMP_IRQn	= 2,
	RTC_WKUP_IRQn	= 3,
	FLASH_IRQn		= 4,
	RCC_IRQn		= 5,
	EXTI0_IRQn		= 6,
	EXTI1_IRQn		= 7,
	EXTI2_IRQn		= 8,
	EXTI3_IRQn		= 9,
	EXTI4_IRQn		= 10,
	EXTI9_5_IRQn    = 23,
	EXTI15_10_IRQn	= 40
} IRQ_Type;


typedef struct
{
	volatile uint32_t IMR;			/*!< Address offset: 0x00 */
	volatile uint32_t EMR;			/*!< Address offset: 0x04 */
	volatile uint32_t RTSR;			/*!< Address offset: 0x08 */
	volatile uint32_t FTSR;			/*!< Address offset: 0x0C */
	volatile uint32_t SWIER;		/*!< Address offset: 0x10 */
	volatile uint32_t PR;			/*!< Address offset: 0x14 */
} EXTI_TypeDef;

typedef struct
{
    reg32bit MODER;        /*!< GPIO Port Mode Register,                   Address offset: 0x00 */
    reg32bit OTYPER;       /*!< GPIO Port Output Type Register,            Address offset: 0x04 */
    reg32bit OSPEEDR;      /*!< GPIO Port Output Speed Register,           Address offset: 0x08 */
    reg32bit PUPDR;        /*!< GPIO Port Pull-Up/Pull-Down Register,      Address offset: 0x0C */
	reg32bit IDR;
	reg32bit ODR;
    reg32bit BSRR;         /*!< GPIO Port Bit Set/Reset Register,          Address offset: 0x18 */
    reg32bit LCKR;         /*!< GPIO Port Configuration Lock Register,     Address offset: 0x1C */
    reg32bit AFRL;         /*!< GPIO Alternate Function Low Register,      Address offset: 0x20 */
	reg32bit AFRH;         /*!< GPIO Alternate Function High Register,     Address offset: 0x24 */
} GPIO_TypeDef;


/********************************************************************/
/*                    Reset and Clock Control                       */
/********************************************************************/
#define RCC_CR_HSION				0x00000001
#define RCC_CR_HSIRDY				0x00000002

#define RCC_CR_HSEON				0x00010000
#define RCC_CR_HSERDY				0x00020000

/* Bits SW[1:0] - System Clock Switch */
#define RCC_CFGR_SW					0x00000003
#define RCC_CFGR_SW_HSI				0x00000000				/* HSI Selected as System Clock */
#define RCC_CFGR_SW_HSE				0x00000001

/* Bits SWS[1:0] - System Clock Switch Status */
#define RCC_CFGR_SWS				0x0000000C
#define RCC_CFGR_SWS_HSI			0x00000000				/* HSI Oscillator used as System Clock */
#define RCC_CFGR_SWS_HSE			0x00000004

/* Bits HPRE[3:0] - AHB Prescaler */
#define RCC_CFGR_HPRE				0x000000F0				/* HPRE[3:0] bits (AHB Prescaler) */
#define RCC_CFGR_HPRE_DIV1			0x00000000				/* SYSCLK not divided */
#define RCC_CFGR_HPRE_DIV2			0x00000080				/* SYSCLK divided by 2*/
#define RCC_CFGR_HPRE_DIV4			0x00000090				/* SYSCLK divided by 4*/
#define RCC_CFGR_HPRE_DIV8			0x000000A0				/* SYSCLK divided by 8 */
#define RCC_CFGR_HPRE_DIV16			0x000000B0				/* SYSCLK divided by 16 */
#define RCC_CFGR_HPRE_DIV64			0x000000C0				/* SYSCLK divided by 64 */
#define RCC_CFGR_HPRE_DIV128		0x000000D0				/* SYSCLK divided by 128 */
#define RCC_CFGR_HPRE_DIV256		0x000000E0				/* SYSCLK divided by 256 */
#define RCC_CFGR_HPRE_DIV512		0x000000F0				/* SYSCLK divided by 512 */

/* Bits PPRE1[2:0] - APB Low-Speed Prescaler (APB1) */
#define RCC_CFGR_PPRE1_DIV1			0x00000000				/* HCLK Not Divided */
#define RCC_CFGR_PPRE1_DIV2			0x00001000				/* HCLK Divided by 2 */
#define RCC_CFGR_PPRE1_DIV4			0x00001400				/* HCLK Divided by 4 */
#define RCC_CFGR_PPRE1_DIV8			0x00001800				/* HCLK Divided by 8 */
#define RCC_CFGR_PPRE1_DIV16		0x00001C00				/* HCLK Divided by 16 */


/* Bits PPRE2[2:0] - APB High-Speed Prescaler (APB2) */
#define RCC_CFGR_PPRE2_DIV1			0x00000000				/* HCLK Not Divided */
#define RCC_CFGR_PPRE2_DIV2			0x00008000				/* HCLK Divided by 2 */
#define RCC_CFGR_PPRE2_DIV4			0x0000A000				/* HCLK Divided by 4 */
#define RCC_CFGR_PPRE2_DIV8			0x0000C000				/* HCLK Divided by 8 */
#define RCC_CFGR_PPRE2_DIV16		0x0000E000				/* HCLK Divided by 16 */


#define RCC_CR_PLLON				0x01000000				
#define RCC_CR_PLLRDY				0x02000000
#define RCC_PLLCFGR_PLLSRC_HSI		0x00000000
#define RCC_CFGR_SW					0x00000003				/* SW[1:0] bits (System Clock Switch) */

typedef struct
{
    volatile uint32_t CR;           /*!< RCC Clock Control Register,                                  Address offset: 0x00 */
    volatile uint32_t PLLCFGR;      /*!< RCC PLL Configuration Register,                              Address offset: 0x04 */
    volatile uint32_t CFGR;         /*!< RCC Clock Configuration Register,                            Address offset: 0x08 */
    volatile uint32_t CIR;          /*!< RCC Clock Interrupt Register,                                Address offset: 0x0C */
    volatile uint32_t AHB1RSTR;     /*!< RCC AHB1 Peripheral Reset Register,                          Address offset: 0x10 */
    volatile uint32_t AHB2RSTR;     /*!< RCC AHB2 Peripheral Reset Register,                          Address offset: 0x14 */
    volatile uint32_t AHB3RSTR;     /*!< RCC AHB3 Peripheral Reset Register,                          Address offset: 0x18 */
             uint32_t RESERVED01;   /*!< Reserved,                                                    Address offset: 0x1C */
    volatile uint32_t APB1RSTR;     /*!< RCC APB1 Peripheral Reset Register,                          Address offset: 0x20 */
    volatile uint32_t APB2RSTR;     /*!< RCC APB2 Peripheral Reset Register,                          Address offset: 0x24 */
             uint32_t RESERVED02;   /*!< Reserved,                                                    Address offset: 0x28 */
             uint32_t RESERVED03;   /*!< Reserved,                                                    Address offset: 0x2C */
    volatile uint32_t AHB1ENR;      /*!< RCC AHB1 Peripheral Clock Enable Register,                   Address offset: 0x30 */
    volatile uint32_t AHB2ENR;      /*!< RCC AHB2 Peripheral Clock Enable Register,                   Address offset: 0x34 */
    volatile uint32_t AHB3ENR;      /*!< RCC AHB3 Peripheral Clock Enable Register,                   Address offset: 0x38 */
             uint32_t RESERVED04;   /*!< Reserved,                                                    Address offset: 0x3C */
    volatile uint32_t APB1ENR;      /*!< RCC APB1 Peripheral Clock Enable Register,                   Address offset: 0x40 */
    volatile uint32_t APB2ENR;      /*!< RCC APB2 Peripheral Clock Enable Register,                   Address offset: 0x44 */
             uint32_t RESERVED05;   /*!< Reserved,                                                    Address offset: 0x48 */
             uint32_t RESERVED06;   /*!< Reserved,                                                    Address offset: 0x4C */
    volatile uint32_t AHB1LPENR;    /*!< RCC AHB1 Peripheral Clock Enable in Low Power Mode Register, Address offset: 0x50 */
    volatile uint32_t AHB2LPENR;    /*!< RCC AHB1 Peripheral Clock Enable in Low Power Mode Register, Address offset: 0x54 */
    volatile uint32_t AHB3LPENR;    /*!< RCC AHB1 Peripheral Clock Enable in Low Power Mode Register, Address offset: 0x58 */
             uint32_t RESERVED07;   /*!< Reserved,                                                    Address offset: 0x5C */
    volatile uint32_t APB1LPENR;    /*!< RCC APB1 Peripheral Clock Enable in Low Power Mode Register, Address offset: 0x60 */
    volatile uint32_t APB2LPENR;    /*!< RCC APB2 Peripheral Clock Enable in Low Power Mode Register, Address offset: 0x64 */
             uint32_t RESERVED08;   /*!< Reserved,                                                    Address offset: 0x68 */
             uint32_t RESERVED09;   /*!< Reserved,                                                    Address offset: 0x6C */
    volatile uint32_t BDCR;         /*!< RCC Backup Domain Control Register,                          Address offset: 0x70 */
    volatile uint32_t CSR;          /*!< RCC Clock Control & Status Register,                         Address offset: 0x74 */
             uint32_t RESERVED10;   /*!< Reserved,                                                    Address offset: 0x78 */
             uint32_t RESERVED11;   /*!< Reserved,                                                    Address offset: 0x7C */
    volatile uint32_t SSCGR;        /*!< RCC Spread Spectrum Clock Generation Register,               Address offset: 0x80 */
    volatile uint32_t PLLI2SCFGR;   /*!< RCC PLLI2S Configuration Register,                           Address offset: 0x84 */
    volatile uint32_t PLLSAICFGR;   /*!< RCC PLL Configuration Register,                              Address offset: 0x88 */
    volatile uint32_t DCKCFGR;      /*!< RCC Dedicated Clock Configuration Register,                  Address offset: 0x8C */
    volatile uint32_t CKGATENR;     /*!< RCC Clocks Gated Enable Register,                            Address offset: 0x90 */
    volatile uint32_t DCKCFGR2;     /*!< RCC Dedicated Clocks Configuration Register 2,               Address offset: 0x94 */   
} RCC_TypeDef;


typedef struct
{
	volatile uint32_t MEMRMP;			/*!< Address offset: 0x00 */
	volatile uint32_t PMC;				/*!< Address offset: 0x04 */
	volatile uint32_t EXTICR1;			/*!< Address offset: 0x08 */
	volatile uint32_t EXTICR2;			/*!< Address offset: 0x0C */
	volatile uint32_t EXTICR3;			/*!< Address offset: 0x10 */
	volatile uint32_t EXTICR4;			/*!< Address offset: 0x14 */
	volatile uint32_t RESERVED01;		/*!< Address offset: 0x18 */
	volatile uint32_t RESERVED02;		/*!< Address offset: 0x1C */
	volatile uint32_t CMPCR;			/*!< Address offset: 0x20 */
	volatile uint32_t RESERVED03;		/*!< Address offset: 0x24 */
	volatile uint32_t RESERVED04;		/*!< Address offset: 0x28 */
	volatile uint32_t CFGR;				/*!< Address offset: 0x2C */
} SYSCFG_TypeDef;


typedef struct
{
	volatile uint32_t SR;				/*!< USART Status Register */
	volatile uint32_t DR;				/*!< USART Data Register */
	volatile uint32_t BRR;				/*!< USART Baud Rate Generator */
	volatile uint32_t CR1;				/*!< USART Control Register 1 */
	volatile uint32_t CR2;				/*!< USART Control Register 2 */
	volatile uint32_t CR3;				/*!< USART Control Register 3 */
	volatile uint32_t GTPR;				/*!< USART Guard Time */
} USART_TypeDef;


#endif
