.syntax unified
.cpu cortex-m4
.fpu softvfp
.thumb

.global vtable
.global default_interrupt_handler

/* The vector table. */
.type vtable, %object
.section .vector_table,"a",%progbits
vtable:
    .word _estack				// 0x0000 0000
    .word reset_handler			// 0x0000 0004
    .word NMI_handler			// 0x0000 0008
    .word hard_fault_handler	// 0x0000 000C
    .word 0						// 0x0000 0010
    .word 0						// 0x0000 0014
    .word 0						// 0x0000 0018
    .word 0						// 0x0000 001C
    .word 0						// 0x0000 0020
    .word 0						// 0x0000 0024
    .word 0						// 0x0000 0028
    .word 0						// 0x0000 002C
    .word 0						// 0x0000 0030
    .word 0						// 0x0000 0034
    .word 0						// 0x0000 0038
    .word SysTick_Handler		// 0x0000 003C

	// Interrupt Handlers
	.word 0 // WatchDog_IRQ_hander		// 0x0000 0040 (IRQ 0)
    .word 0								// 0x0000 0044 (IRQ 1)
    .word 0								// 0x0000 0048 (IRQ 2)
    .word 0								// 0x0000 004C (IRQ 3)
    .word 0								// 0x0000 0050 (IRQ 4)
    .word 0								// 0x0000 0054 (IRQ 5)
    .word EXTI0_IRQHandler				// 0x0000 0058 (IRQ 6)
    .word EXTI1_IRQHandler				// 0x0000 005C (IRQ 7)
    .word EXTI2_IRQHandler				// 0x0000 0060 (IRQ 8)
    .word EXTI3_IRQHandler				// 0x0000 0064 (IRQ 9)
    .word EXTI4_IRQHandler				// 0x0000 0068 (IRQ 10)
    .word 0								// 0x0000 006C (IRQ 11)
    .word 0								// 0x0000 0070 (IRQ 12)
    .word 0								// 0x0000 0074 (IRQ 13)
    .word 0								// 0x0000 0078 (IRQ 14)
    .word 0								// 0x0000 007C (IRQ 15)
    .word 0								// 0x0000 0080 (IRQ 16)
    .word 0								// 0x0000 0084 (IRQ 17)
    .word 0								// 0x0000 0088 (IRQ 18)
    .word 0								// 0x0000 008C (IRQ 19)
    .word 0								// 0x0000 0090 (IRQ 20)
    .word 0								// 0x0000 0094 (IRQ 21)
    .word 0								// 0x0000 0098 (IRQ 22)
    .word EXTI9_5_IRQHandler			// 0x0000 009C (IRQ 23)
    .word 0								// 0x0000 00A0 (IRQ 24)
    .word tim10_handler					// 0x0000 00A4 (IRQ 25)
    .word tim11_handler					// 0x0000 00A8 (IRQ 26)
    .word 0								// 0x0000 00AC (IRQ 27)
    .word 0								// 0x0000 00B0 (IRQ 28)
    .word 0								// 0x0000 00B4 (IRQ 29)
    .word 0								// 0x0000 00B8 (IRQ 30)
    .word 0								// 0x0000 00BC (IRQ 31)
    .word 0								// 0x0000 00C0 (IRQ 32)
    .word 0								// 0x0000 00C4 (IRQ 33)
    .word 0								// 0x0000 00C8 (IRQ 34)
    .word 0								// 0x0000 00CC (IRQ 35)
    .word 0								// 0x0000 00D0 (IRQ 36)
    .word 0								// 0x0000 00D4 (IRQ 37)
    .word 0								// 0x0000 00D8 (IRQ 38)
    .word 0								// 0x0000 00DC (IRQ 39)
    .word EXTI15_10_IRQHandler			// 0x0000 00E0 (IRQ 40)

    // (Location to boot from for RAM startup)
    #define boot_ram_base  0xF108F85F
    .word boot_ram_base

    /*
     * Setup weak aliases for each exception handler to the
     * default one. These can be updated later, or just
     * overridden since they're weak refs.
     * The reset_handler is set up separately.
     */
    .weak NMI_handler
    .thumb_set NMI_handler,default_interrupt_handler
    
	.weak hard_fault_handler
    .thumb_set hard_fault_handler,default_interrupt_handler
    
	.weak EXTI0_IRQHandler
    .thumb_set EXTI0_IRQHandler,default_interrupt_handler

	.weak EXTI1_IRQHandler
    .thumb_set EXTI1_IRQHandler,default_interrupt_handler

	.weak EXTI2_IRQHandler
    .thumb_set EXTI2_IRQHandler,default_interrupt_handler

	.weak EXTI3_IRQHandler
    .thumb_set EXTI3_IRQHandler,default_interrupt_handler
	
	.weak EXTI4_IRQHandler
    .thumb_set EXTI4_IRQHandler,default_interrupt_handler
	
	.weak EXTI9_5_IRQHandler
	.thumb_set EXTI9_5_IRQHandler,default_interrupt_handler
	
.size vtable, .-vtable

/*
 * A 'Default' interrupt handler. This is where interrupts
 * which are not otherwise configured will go.
 * It is an infinite loop, because...well, we weren't
 * expecting the interrupt, so what can we do?
 */
.section .text.default_interrupt_handler,"ax",%progbits
default_interrupt_handler:
    default_interrupt_loop:
      B default_interrupt_loop
.size default_interrupt_handler, .-default_interrupt_handler
