/**
******************************************************************************
* @author	Seongjun Park
* @Mod		2022-10-10   	
* @brief	Embedded Controller:  LAB 7-segment 
*					 - 7 segment decoder
* 					-  PA5, PA6, PA7, PB6, PC7, PA9, PA8, PB10  for DOUT
******************************************************************************
*/

#include "stm32f4xx.h"
#include "ecGPIO.h"
#include "ecRCC.h"

#define LED_PIN 	5
#define BUTTON_PIN 13

void setup(void);


int main(void) { 
	// Initialiization --------------------------------------------------------
	setup();
	unsigned int cnt = 0; //count
	
	// Inifinite Loop ----------------------------------------------------------
	while(1){
		sevensegment_decode(cnt % 10); 
		if(GPIO_read(GPIOC, BUTTON_PIN) == 0) cnt++; // count by pushing button
		if (cnt > 9) cnt = 0; // count initialization
		for(int i = 0; i < 300000;i++){} //debouncing
	}
}


// Initialiization 
void setup(void)
{
	RCC_HSI_init();
	// Dgital In for Button(B1)
	GPIO_init(GPIOC, BUTTON_PIN, INPUT); // calls RCC_GPIOC_enable()
	GPIO_pupd(GPIOC, BUTTON_PIN, EC_PD); // Button pin -> pull down
	
	// Dgital Out for 7-Segment
	sevensegment_init();
}



