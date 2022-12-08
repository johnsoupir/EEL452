/**
 * Main program.
 */
 
#include "main.h"
#include "sysclock.h"
#include "uart.h"
#include "7segment.h"

bool user_button_pressed = FALSE;

unsigned char segmentNumberArray[] = 
{
	SEGMENT_NBR_0,
	SEGMENT_NBR_1,
	SEGMENT_NBR_2,
	SEGMENT_NBR_3,
	SEGMENT_NBR_4,
	SEGMENT_NBR_5,
	SEGMENT_NBR_6,
	SEGMENT_NBR_7,
	SEGMENT_NBR_8,
	SEGMENT_NBR_9,
	SEGMENT_NBR_A,
	SEGMENT_NBR_B,
	SEGMENT_NBR_C,
	SEGMENT_NBR_D,
	SEGMENT_NBR_E,
	SEGMENT_NBR_F
};



const char alphaArray[] = {
  SEGMENT_LETTER_A,
  SEGMENT_LETTER_B,
  SEGMENT_LETTER_C,
  SEGMENT_LETTER_D,
  SEGMENT_LETTER_E,
  SEGMENT_LETTER_F,
  SEGMENT_LETTER_G,
  SEGMENT_LETTER_H,
  SEGMENT_LETTER_I,
  SEGMENT_LETTER_J,
  SEGMENT_LETTER_K,
  SEGMENT_LETTER_L,
  SEGMENT_LETTER_M,
  SEGMENT_LETTER_N,
  SEGMENT_LETTER_O,
  SEGMENT_LETTER_P,
  SEGMENT_LETTER_Q,
  SEGMENT_LETTER_R,
  SEGMENT_LETTER_S,
  SEGMENT_LETTER_T,
  SEGMENT_LETTER_U,
  SEGMENT_LETTER_V,
  SEGMENT_LETTER_W,
  SEGMENT_LETTER_X,
  SEGMENT_LETTER_Y,
  SEGMENT_LETTER_Z
};


unsigned char number=0;

int main(void) 
{
	bool flashLED = TRUE;
	
	// Configure the SysTick to operate at 1 mS
	SysTickConfigure();
	
	// Configure the System Clocks
	SysClockConfigure();
	
	// Enable GPIO Port A Clock
	RCC->AHB1ENR |= RCC_AHB1ENR_GPIOA;

	// Enable GPIO Port C Clock 
	RCC->AHB1ENR |= RCC_AHB1ENR_GPIOC;
	

	// Initialize GPIOA Port, Pin 5 - On-Board LED
	// Set GPIO Port A, Bit 5 as a General Purpose Output
	GPIOA->MODER.bit10 = 1;
	GPIOA->MODER.bit11 = 0;
	


	//Set up the port C as outputs
	GPIOC->MODER.bit0 = 1;
	GPIOC->MODER.bit1 = 0;

	GPIOC->MODER.bit2 = 1;
	GPIOC->MODER.bit3 = 0;

	GPIOC->MODER.bit4 = 1;
	GPIOC->MODER.bit5 = 0;

	GPIOC->MODER.bit6 = 1;
	GPIOC->MODER.bit7 = 0;

	GPIOC->MODER.bit8 = 1;
	GPIOC->MODER.bit9 = 0;

	GPIOC->MODER.bit10 = 1;
	GPIOC->MODER.bit11 = 0;

	GPIOC->MODER.bit12 = 1;
	GPIOC->MODER.bit13 = 0;


	//Set port A and B for enable pins
	GPIOA->MODER.bit0 = 1;
	GPIOA->MODER.bit1 = 0;

	GPIOA->MODER.bit2 = 1;
	GPIOA->MODER.bit3 = 0;

	GPIOA->MODER.bit4 = 1;
	GPIOA->MODER.bit5 = 0;

	GPIOA->MODER.bit6 = 1;
	GPIOA->MODER.bit7 = 0;

	GPIOA->MODER.bit8 = 1;
	GPIOA->MODER.bit9 = 0;

	GPIOB->MODER.bit0 = 1;
	GPIOB->MODER.bit1 = 0;

	GPIOB->MODER.bit6 = 1;
	GPIOB->MODER.bit7 = 0;
	
	


	// Initialize GPIOC Port, Pin 13 - On-Board User Button
	// Set GPI0 Port C, Bit 13 for Input
	GPIOC->MODER.bit27 = 0;
	GPIOC->MODER.bit26 = 0;
	
	// Set GPIO Port C, Bit 13 for Pull-Up
	GPIOC->PUPDR.bit27 = 0;
	GPIOC->PUPDR.bit26 = 1;

	// Enable GPIO13 Interrupt for GPIO Port C
	SYSCFG->EXTICR4 |= 0x00000020;
	
	// Set up Interrupt Handler for Interrupt Pin 13, Port C
	EXTI->FTSR &= 0xFFFFDFFF;
	EXTI->RTSR |= 0x00002000;
	EXTI->EMR &= 0xFFFFDFFF;
	EXTI->IMR |= 0x00002000; 
	
	// Enable Interrupt 40 in Nested Vector Interrupt Controller
	NVIC_EnableIRQ( EXTI15_10_IRQn );
	
	GPIOA->ODR.bit5 = 0;		// Turn OFF LED
	
	stdout_init();
	//tim10_enable();

	int display(unsigned char symbol, int digit, int time)
	{
		switch(digit)
		{
			case 0:
				GPIOA->ODR.bit0 = 1;
				GPIOC->ODR.data = ~alphaArray[symbol];
				Delay(time);
				GPIOA->ODR.bit0 = 0;
     			break;
    		case 1:
				GPIOA->ODR.bit1 = 1;
				GPIOC->ODR.data = ~alphaArray[symbol];
				Delay(time);
				GPIOA->ODR.bit1 = 0;
    			break;
   			case 2:
				GPIOA->ODR.bit4 = 1;
				GPIOC->ODR.data = ~alphaArray[symbol];
				Delay(time);
				GPIOA->ODR.bit4 = 0;
    			break;
    		case 3:
				GPIOA->ODR.bit5 = 1;
				GPIOC->ODR.data = ~alphaArray[symbol];
				Delay(time);
				GPIOA->ODR.bit5 = 0;
    			break;
    		default:
  				return 1;
      			break;
		}
	}

	int displayNum(unsigned char symbol, int digit, int time)
	{
		switch(digit)
		{
			case 0:
				GPIOA->ODR.bit0 = 1;
				GPIOC->ODR.data = ~segmentNumberArray[symbol];
				Delay(time);
				GPIOA->ODR.bit0 = 0;
     			break;
    		case 1:
				GPIOA->ODR.bit1 = 1;
				GPIOC->ODR.data = ~segmentNumberArray[symbol];
				Delay(time);
				GPIOA->ODR.bit1 = 0;
    			break;
   			case 2:
				GPIOA->ODR.bit4 = 1;
				GPIOC->ODR.data = ~segmentNumberArray[symbol];
				Delay(time);
				GPIOA->ODR.bit4 = 0;
    			break;
    		case 3:
				GPIOA->ODR.bit5 = 1;
				GPIOC->ODR.data = ~segmentNumberArray[symbol];
				Delay(time);
				GPIOA->ODR.bit5 = 0;
    			break;
    		default:
  				return 1;
      			break;
		}
	}








	int blah = 0;
	int wait = 300;	
	unsigned char counter = 0;
	uint32_t startTick = 0;
	uint32_t endTick = 0;
	uint32_t delayTime = 500;
	uint32_t delayCount = 10;

	int timeOn = 1;

	while (1)
	{	

		/*
		int thisTime = getTick();
		while(getTick() < (thisTime+3000))
		{
			display(5,0,1);
			display(21,1,1);
			display(2,2,1);
			display(7,3,1);

		}
		*/

		int seconds = 0;
		for (int t=0; t<=1234; t++)
		{
			int place0 = (t/1000)%10;
			int place1 = (t/100)%10;
			int place2 = (t/10)%10;
			int place3 = (t/1)%10;
			
			startTick = getTick();
			endTick = startTick + delayCount;
			while(getTick() < endTick)
			{
				displayNum(place0,0,1);
				displayNum(place1,1,1);
				displayNum(place2,2,1);
				displayNum(place3,3,1);
			}
		}







		number=0;
		counter=0;

		for(int i=1; i<=9; i++){

		startTick = getTick();
		endTick = startTick + delayTime;
		while(getTick() < endTick)
		{

			number=counter;
			displayNum(number,0,1);
			number++;
			displayNum(number,1,1);
			number++;
			displayNum(number,2,1);
			number++;
			displayNum(number,3,1);
			//Delay(1);
			//Delay(1000);
			//number++;

		}

		counter++;

		}

		number=0;
		counter=0;

		for(int i=0; i<=26; i++){


		startTick = getTick();
		endTick = startTick + delayTime;
		while(getTick() < endTick)
		{

			number=counter;
			display(number,0,1);
			number++;
			display(number,1,1);
			number++;
			display(number,2,1);
			number++;
			display(number,3,1);
			//Delay(1);
			//Delay(1000);
			//number++;

		}

		counter++;

		}

		/*

		GPIOA->ODR.bit0 = 1;
		GPIOC->ODR.data = ~segmentNumberArray[number++];
		Delay(500);
		GPIOA->ODR.bit0 = 0;


		GPIOA->ODR.bit1 = 1;
		GPIOC->ODR.data = ~segmentNumberArray[number++];
		Delay(500);
		GPIOA->ODR.bit1 = 0;


		GPIOA->ODR.bit4 = 1;
		GPIOC->ODR.data = ~segmentNumberArray[number++];
		Delay(500);
		GPIOA->ODR.bit4 = 0;


		GPIOA->ODR.bit3 = 1;
		GPIOC->ODR.data = ~segmentNumberArray[number++];
		Delay(500);
		GPIOA->ODR.bit3 = 0;

		*/


		//GPIOC->ODR.data = ~segmentNumberArray[number++];
		//number %= 16;
		//Delay(1000);

		//GPIOC->ODR.data = alphaArray[number++];
		//number %= 16;
		//Delay(50);




		/*
		GPIOC->ODR.data = SEGMENT_NBR_0;
		Delay(wait);
		GPIOC->ODR.data = SEGMENT_NBR_1;
		Delay(wait);
		GPIOC->ODR.data = SEGMENT_NBR_2;
		Delay(wait);
		GPIOC->ODR.data = SEGMENT_NBR_3;
		Delay(wait);
		GPIOC->ODR.data = SEGMENT_NBR_4;
		Delay(wait);
		GPIOC->ODR.data = SEGMENT_NBR_5;
		Delay(wait);
		GPIOC->ODR.data = SEGMENT_NBR_6;
		Delay(wait);
		GPIOC->ODR.data = SEGMENT_NBR_7;
		Delay(wait);
		GPIOC->ODR.data = SEGMENT_NBR_8;
		Delay(wait);
		GPIOC->ODR.data = SEGMENT_NBR_9;
		Delay(wait);
		GPIOC->ODR.data = SEGMENT_NBR_A;
		Delay(wait);
		GPIOC->ODR.data = SEGMENT_NBR_B;
		Delay(wait);
		GPIOC->ODR.data = SEGMENT_NBR_C;
		Delay(wait);
		GPIOC->ODR.data = SEGMENT_NBR_D;
		Delay(wait);
		GPIOC->ODR.data = SEGMENT_NBR_E;
		Delay(wait);
		GPIOC->ODR.data = SEGMENT_NBR_F;
		Delay(wait);
	*/	




		//blah++;
		/*
		if ( flashLED == TRUE )
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

			Delay( 500 );
		}
		
		if ( user_button_pressed == TRUE )
		{
			if ( flashLED == TRUE )
			{
				GPIOA->ODR.bit5 = 0;
				flashLED = FALSE;
			}
			else
			{
				flashLED = TRUE;
			}
			user_button_pressed = FALSE;
		}
		*/
	}
}
