// dac.c
// This software configures DAC output
// Runs on LM4F120 or TM4C123
// Program written by: put your names here
// Date Created: 3/6/17 
// Last Modified: 3/6/17 
// Lab number: 6
// Hardware connections
// TO STUDENTS "REMOVE THIS LINE AND SPECIFY YOUR HARDWARE********

#include <stdint.h>
#include "tm4c123gh6pm.h"
#include "piano.h"
// Code files contain the actual implemenation for public functions
// this file also contains an private functions and private data

// **************DAC_Init*********************
// Initialize 4-bit DAC, called once 
// Input: none
// Output: none
void DAC_Init(void){
	//turn on port B and make PB3-0 output
	volatile unsigned long delay;
	SYSCTL_RCGCGPIO_R |= 0x02;
	delay = SYSCTL_RCGCGPIO_R;
	GPIO_PORTB_AMSEL_R &= ~0x0F;
	GPIO_PORTB_DIR_R |= 0x0F;
	GPIO_PORTB_DEN_R |= 0x0F;
}

// **************DAC_Out*********************
// output to DAC
// Input: 4-bit data, 0 to 15 
// Output: none
void DAC_Out(uint32_t data){
	if(Piano_In() == 0)
		GPIO_PORTB_DATA_R = 0x00;
	else
		GPIO_PORTB_DATA_R = data;		//sets port B output equal to data
}
