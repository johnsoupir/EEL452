#ifndef _MAIN_H_
#define _MAIN_H_

#include <stdint.h>
#include "cortex-m4.h"

typedef int bool;
#define FALSE 0
#define TRUE  1

// Define GPIO Pins
#define ONBOARD_LED_PORT	
#define ONBOARD_LED_PIN    	5			/* GPIO Port A */
#define USER_BUTTON_PIN		13			/* GPIO Port C */


/* Function Prototypes */
bool isPinSet( uint32_t gpio, uint32_t pin );
void pinSet( uint32_t gpio, uint32_t pin );
void pinReset(uint32_t gpio, uint32_t pin );

#endif
