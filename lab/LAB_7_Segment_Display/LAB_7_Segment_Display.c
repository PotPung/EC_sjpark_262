#include "stm32f4xx.h"
#include "ecRCC.h"
#include "ecGPIO.h"

void setup(void);
	
int main(void) {	
	// Initialiization --------------------------------------------------------
	setup();
	
	
	// Inifinite Loop ----------------------------------------------------------
	while(1){
		GPIO_write(GPIOA, 5, LOW); //e 
		GPIO_write(GPIOA, 6, HIGH); //d
		GPIO_write(GPIOA, 7, HIGH); //c
		GPIO_write(GPIOB, 6, HIGH); //DP
		GPIO_write(GPIOC, 7, LOW); //g
		GPIO_write(GPIOA, 9, LOW); //f
		GPIO_write(GPIOA, 8, LOW); //a
		GPIO_write(GPIOB, 10, HIGH); //b
	}
}

void setup(void){
	RCC_HSI_init();
	GPIO_init(GPIOA, 5, OUTPUT);
	GPIO_init(GPIOA, 6, OUTPUT);
	GPIO_init(GPIOA, 7, OUTPUT);
	GPIO_init(GPIOB, 6, OUTPUT);
	GPIO_init(GPIOC, 7, OUTPUT);
	GPIO_init(GPIOA, 9, OUTPUT);
	GPIO_init(GPIOA, 8, OUTPUT);
	GPIO_init(GPIOB, 10, OUTPUT);
}