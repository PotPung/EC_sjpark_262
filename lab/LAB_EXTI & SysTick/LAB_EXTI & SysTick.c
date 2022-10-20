#include "stm32f411xe.h"
#include "ecGPIO.h"
#include "ecRCC.h"
#include "ecEXTI.h"

LED_init(GPIO_TypeDef *Port, int pin, int mode, int otype, int pupd, int ospeed);
// Initialiization 
void setup(void)
{
	RCC_HSI_init();
	LED_init(GPIOA,PIN_5,OUTPUT, EC_PP, EC_PU, EC_MS);
	LED_init(GPIOA,PIN_6,OUTPUT, EC_PP, EC_PU, EC_MS);
	LED_init(GPIOA,PIN_7,OUTPUT, EC_PP, EC_PU, EC_MS);
	LED_init(GPIOB,PIN_6,OUTPUT, EC_PP, EC_PU, EC_MS);
	EXTI_init(GPIOC,PIN_13,FALL,0);
	GPIO_init(GPIOC, PIN_13 , OUTPUT);
	GPIO_pudr(GPIOC, PIN_13, EC_PU);
}

int main(void) { 
	// Initialiization --------------------------------------------------------
	setup();
	
	// Inifinite Loop ----------------------------------------------------------
	while(1){}
}

void EXTI15_10_IRQHandler(void) {  
	if (is_pending_EXTI(BUTTON_PIN)) {
		LED_toggle();
		clear_pending_EXTI(BUTTON_PIN); // cleared by writing '1'
	}
}


LED_init(int port, int pin, int mode, int otype, int pupd, int ospeed){
	GPIO_init(port, pin, mode);
	GPIO_otype(port, pin, otype);
	GPIO_pupd(port, pin, pupd);
	GPIO_ospeed(port, pin, ospeed);
}