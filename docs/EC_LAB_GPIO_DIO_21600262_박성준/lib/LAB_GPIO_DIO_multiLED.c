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



#define BUTTON_PIN 13




int main(void) { 
	// Initialiization --------------------------------------------------------
	setup();
	// Inifinite Loop ----------------------------------------------------------
	int num = 0;
	
	while(1){
		led_select (num % 4);
		if(GPIO_read(GPIOC, BUTTON_PIN) == LOW) num++;
		if(num>3) num = 0;
		
		for (int i =0; i<300000; i++){
		}
	}

}


// Initialiization 
void setup(void)
{
	RCC_HSI_init(); //CLK
	
	//Button init
	GPIO_init(GPIOC, BUTTON_PIN, INPUT);
	GPIO_pupd(GPIOC, BUTTON_PIN, EC_PU);
	
	//LED init
	GPIO_init(GPIOA, LED_PIN_0, OUTPUT);
	GPIO_otype(GPIOA, LED_PIN_0, EC_PP);
	GPIO_pupd(GPIOA, LED_PIN_0, EC_PU);
	GPIO_ospeed(GPIOA, LED_PIN_0, EC_MS);
	
	GPIO_init(GPIOA, LED_PIN_1, OUTPUT);
	GPIO_otype(GPIOA, LED_PIN_1, EC_PP);
	GPIO_pupd(GPIOA, LED_PIN_1, EC_PU);
	GPIO_ospeed(GPIOA, LED_PIN_1, EC_MS);
	
	GPIO_init(GPIOA, LED_PIN_2, OUTPUT);
	GPIO_otype(GPIOA, LED_PIN_2, EC_PP);
	GPIO_pupd(GPIOA, LED_PIN_2, EC_PU);
	GPIO_ospeed(GPIOA, LED_PIN_2, EC_MS);
	
	GPIO_init(GPIOB, LED_PIN_3, OUTPUT);
	GPIO_otype(GPIOB, LED_PIN_3, EC_PP);
	GPIO_pupd(GPIOB, LED_PIN_3, EC_PU);
	GPIO_ospeed(GPIOB, LED_PIN_3, EC_MS);
}


