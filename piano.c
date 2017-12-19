// Piano.c
// This software configures the off-board piano keys
// Runs on LM4F120 or TM4C123
// Program written by: put your names here
// Date Created: 3/6/17 
// Last Modified: 3/6/17 
// Lab number: 6
// Hardware connections
// TO STUDENTS "REMOVE THIS LINE AND SPECIFY YOUR HARDWARE********

// Code files contain the actual implemenation for public functions
// this file also contains an private functions and private data
#include <stdint.h>
#include "tm4c123gh6pm.h"

// **************Piano_Init*********************
// Initialize piano key inputs, called once 
// Input: none 
// Output: none
void Piano_Init(void){ 
	//turn on port E and make PE3-0 inputs
	volatile unsigned long delay;
	SYSCTL_RCGCGPIO_R |= 0x10;
	delay = SYSCTL_RCGCGPIO_R;
	GPIO_PORTE_DEN_R |= 0x0F;
	
	/*SYSCTL_RCGCGPIO_R |= 0x20;
	while((SYSCTL_RCGCGPIO_R & 0x20) == 0);
	
	//init PF1-3
	GPIO_PORTF_LOCK_R = 0x4C4F434B;
	GPIO_PORTF_CR_R |= 0x1E;
	GPIO_PORTF_PUR_R |= 0x12;
	GPIO_PORTF_DIR_R &= 0x00;
	GPIO_PORTF_DEN_R |= 0x1E;*/
}

// **************Piano_In*********************
// Input from piano key inputs 
// Input: none 
// Output: 0 to 7 depending on keys
// 0x01 is just Key0, 0x02 is just Key1, 0x04 is just Key2
uint32_t Piano_In(void){
  return GPIO_PORTF_DATA_R & 0x0F;		//returns what keys are being pressed
}
