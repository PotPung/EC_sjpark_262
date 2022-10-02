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

#define LED_PIN_0 5 //PA5
#define LED_PIN_1	6 //PA6
#define LED_PIN_2 7 //PA7
#define LED_PIN_3	6	//PB6

#define BUTTON_PIN 13
int ledPin[4][4] ={{1,0,0,0},{0,1,0,0},{0,0,1,0},{0,0,0,1}};

void setup(void);
void led_select(int);
void LED_Toggle(void);




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

void led_select(int _num){
	GPIO_write(GPIOA, LED_PIN_0,ledPin[_num][0]);
	GPIO_write(GPIOA, LED_PIN_1, ledPin[_num][1]);
	GPIO_write(GPIOA, LED_PIN_2, ledPin[_num][2]);
	GPIO_write(GPIOB, LED_PIN_3, ledPin[_num][3]);
	
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

