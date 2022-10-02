/**
******************************************************************************
* @author	Seongjun Park
* @Mod		2022-09-22
* @brief	Embedded Controller:  LAB Digital In/Out
*					 - Toggle LED LD2 by Button B1 pressing
* 
******************************************************************************
*/

#include "stm32f4xx.h"
#include "ecRCC.h"
#include "ecGPIO.h"

#define LED_PIN 	5
#define BUTTON_PIN 13

void setup(void);

void bit_Toggle(Port, pin);

int main(void) { 
	// Initialiization --------------------------------------------------------
	setup();
	// Inifinite Loop ----------------------------------------------------------
	while(1){
		if(GPIO_read(GPIOC, BUTTON_PIN) == 0)	
			bit_Toggle(GPIOA, LED_PIN)
		//	GPIO_write(GPIOA, LED_PIN, HIGH);
		else 					
		//	GPIO_write(GPIOA, LED_PIN, LOW);
	}
}


// Initialiization 
void setup(void)
{
	RCC_HSI_init();	
	GPIO_init(GPIOC, BUTTON_PIN, INPUT);  // calls RCC_GPIOC_enable()
	GPIO_init(GPIOA, LED_PIN, OUTPUT);    // calls ()
	GPIO_pupd(GPIOA, LED_PIN, 1);
	GPIO_otype(GPIOA, LED_PIN, 0);RCC_GPIOA_enable
}

void bit_Toggle(Port, pin){
		
}