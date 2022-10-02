/**
******************************************************************************
* @author	Seongjun Park
* @Mod		2022 - 10 - 03
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

void LED_Toggle(void);

int main(void) { 
	// Initialiization --------------------------------------------------------
	setup();
	// Inifinite Loop ----------------------------------------------------------
	while(1){
		LED_Toggle();
//		if(GPIO_read(GPIOC, BUTTON_PIN) == 0)	GPIO_write(GPIOA, LED_PIN, HIGH);
//		else 					GPIO_write(GPIOA, LED_PIN, LOW);
		for (int i =0; i<300000; i++){
		}
		
	}

}


// Initialiization 
void setup(void)
{
	RCC_HSI_init(); //CLK
	GPIO_init(GPIOC, BUTTON_PIN, INPUT);  // calls RCC_GPIOC_enable()
	GPIO_init(GPIOA, LED_PIN, OUTPUT);    // calls RCC_GPIOA_enable()
	GPIO_pupd(GPIOC, BUTTON_PIN, EC_PU);
	GPIO_otype(GPIOA, LED_PIN, EC_OD);
	GPIO_pupd(GPIOA, LED_PIN, EC_PU);
	GPIO_ospeed(GPIOA, LED_PIN, EC_MS);
}

void LED_Toggle(void){
	if(GPIO_read(GPIOC, BUTTON_PIN) == LOW){
		if(GPIO_read(GPIOA, LED_PIN) == LOW){
			GPIO_write(GPIOA, LED_PIN, HIGH);
		}
		else{
			GPIO_write(GPIOA, LED_PIN, LOW);
		}
	}
	else{
		if(GPIO_read(GPIOA, LED_PIN) == LOW){
			GPIO_write(GPIOA, LED_PIN, LOW);
		}
		else{
			GPIO_write(GPIOA, LED_PIN, HIGH);
		}
	}
	
}

