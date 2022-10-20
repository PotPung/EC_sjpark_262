/**
******************************************************************************
* @author  SSSLAB
* @Mod		 2022-8-12 by YKKIM  	
* @brief   Embedded Controller:  Tutorial _____
*					 - ____________________
* 
******************************************************************************
*/
#include "stm32f411xe.h"
#include "ecGPIO.h"
#include "ecRCC.h"

uint32_t count = 0;

#define LED_PIN 	5

void setup(void);
	
int main(void) { 
	// Initialiization --------------------------------------------------------
	setup();
	TIM_TypeDef* timerx;
	timerx = TIM2;
	RCC->APB1ENR |= RCC_APB1ENR_TIM2EN;
	
	timerx->PSC =	840 - 1; // 83 - 1					        // Timer counter clock: 1MHz(1us)
	timerx->ARR = 100 - 1;	// 1000 - 1						    // Set auto reload register to maximum (count up to 65535)
	timerx->DIER |= 1 << 0;             			       // Enable Interrupt
	timerx->CR1 |= TIM_CR1_CEN;                      // Enable counter
	
	NVIC_SetPriority(TIM2_IRQn, 2);               // TIM2_IRQHandler Set priority as 2
	NVIC_EnableIRQ(TIM2_IRQn);				    				// TIM2_IRQHandler Enable
	
	
	// Inifinite Loop ----------------------------------------------------------
	while(1){}
}

// Initialiization 
void setup(void)
{	
	RCC_PLL_init();                       // System Clock = 84MHz
	GPIO_init(GPIOA, LED_PIN, OUTPUT);    // calls RCC_GPIOA_enable()	
}

void TIM2_IRQHandler(void){
	if((TIM2->SR & TIM_SR_UIF) ==  TIM_SR_UIF    ){ // update interrupt flag
		//Create the code to toggle LED by 1000ms
		count++;
		if (count > 1000){
			LED_Toggle();
			count = 0;
		}
		
		TIM2->SR &=  ~TIM_SR_UIF;                       // clear by writing 0
	}
}