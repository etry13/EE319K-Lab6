// Lab6.c
// Runs on LM4F120 or TM4C123
// Use SysTick interrupts to implement a 4-key digital piano
// MOOC lab 13 or EE319K lab6 starter
// Program written by: put your names here
// Date Created: 3/6/17 
// Last Modified: 3/6/17 
// Lab number: 6
// Hardware connections
// TO STUDENTS "REMOVE THIS LINE AND SPECIFY YOUR HARDWARE********


#include <stdint.h>
#include "tm4c123gh6pm.h"
#include "Sound.h"
#include "Piano.h"
#include "TExaS.h"
#include "dac.h"

#define C	2389
#define D 4257
#define E 3792
#define F 3579

// basic functions defined at end of startup.s
void DisableInterrupts(void); // Disable interrupts
void EnableInterrupts(void);  // Enable interrupts
void HeartBeat_Init(void);

int main(void){      
  TExaS_Init(SW_PIN_PE3210,DAC_PIN_PB3210,ScopeOn);    // bus clock at 80 MHz
	DAC_Init();
	Piano_Init();
  Sound_Init(50000);
	//HeartBeat_Init();
  // other initialization
  EnableInterrupts();
  while(1){
		GPIO_PORTF_DATA_R ^= 0x04;					//turn heartbeat on/off
		/*switch(Piano_In()){
			case 1 : Sound_Play(C); break;		//play C note if PE0 pressed
			case 2 : Sound_Play(D); break;		//play D note if PE1 pressed
			case 4 : Sound_Play(E); break;		//play E note if PE2 pressed
			case 8 : Sound_Play(F); break;		//play F note if PE3 pressed
			default : Sound_Play(0);
		}*/
		Sound_Play(C);
  }    
}

void HeartBeat_Init(void){
	volatile unsigned long delay;		//initialize heartbeat
	SYSCTL_RCGCGPIO_R |= 0x20;
	delay = SYSCTL_RCGCGPIO_R;
	GPIO_PORTF_DIR_R |= 0x04;
	GPIO_PORTF_DEN_R |= 0x04;
}

