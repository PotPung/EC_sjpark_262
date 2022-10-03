/*----------------------------------------------------------------\
@ Embedded Controller by Young-Keun Kim - Handong Global University
Author           : SSS LAB
Created          : 05-03-2021
Modified         : 09-20-2022
Language/ver     : C++ in Keil uVision

Description      : Distributed to Students for LAB_GPIO
/----------------------------------------------------------------*/



#include "stm32f4xx.h"
#include "stm32f411xe.h"
#include "ecGPIO.h"
#define LED_PIN_0 5 //PA5
#define LED_PIN_1	6 //PA6
#define LED_PIN_2 7 //PA7
#define LED_PIN_3	6	//PB6
int ledPin[4][4] ={{1,0,0,0},{0,1,0,0},{0,0,1,0},{0,0,0,1}};

void GPIO_init(GPIO_TypeDef *Port, int pin, int mode){     
	// mode  : Input(0), Output(1), AlterFunc(2), Analog(3)   
	if (Port == GPIOA)
		RCC_GPIOA_enable();
	if (Port == GPIOB)
		RCC_GPIOB_enable();
	if (Port == GPIOC)
		RCC_GPIOC_enable();
	
	//[TO-DO] YOUR CODE GOES HERE
	// Make it for GPIOB, GPIOD..GPIOH

	// You can also make a more general function of
	// void RCC_GPIO_enable(GPIO_TypeDef *Port); 

	GPIO_mode(Port, pin, mode);
	
}


// GPIO Mode          : Input(00), Output(01), AlterFunc(10), Analog(11)
void GPIO_mode(GPIO_TypeDef *Port, int pin, int mode){
   Port->MODER &= ~(3UL<<(2*pin));  
   Port->MODER |= (unsigned)mode<<(2*pin);    
}


// GPIO Speed          : Low speed (00), Medium speed (01), Fast speed (10), High speed (11)
void GPIO_ospeed(GPIO_TypeDef *Port, int pin, int speed){
	Port->OSPEEDR &= ~(3UL<<(2*pin));
	Port->OSPEEDR |= (unsigned)speed<<(2*pin);
}

// GPIO Output Type: Output push-pull (0, reset), Output open drain (1)
void GPIO_otype(GPIO_TypeDef *Port, int pin, int type){
  Port->OTYPER &= ~((unsigned)type<<pin);	
	//[TO-DO] YOUR CODE GOES HERE
}

// GPIO Push-Pull    : No pull-up, pull-down (00), Pull-up (01), Pull-down (10), Reserved (11)
void GPIO_pupd(GPIO_TypeDef *Port, int pin, int pupd){
		Port->PUPDR  &= ~(3UL<<(2*pin));											// 00: none
		Port->PUPDR	|=((unsigned)pupd<<(pin*2));
}

int GPIO_read(GPIO_TypeDef *Port, int pin){
		int bitVal = ((Port->IDR) >> pin) & 1;
	//[TO-DO] YOUR CODE GOES HERE
	return bitVal;    	//[TO-DO] YOUR CODE GOES HERE	
}

void GPIO_write(GPIO_TypeDef *Port, int pin, int Output){
		Port->ODR &= ~(1<<pin);
		Port->ODR |= (unsigned)Output <<pin;
}

void sevensegment_init(void){
	GPIO_init(GPIOA, 8, OUTPUT); //a
	GPIO_otype(GPIOA, 8, 0);
	GPIO_pupd(GPIOA, 8, 0);
	GPIO_ospeed(GPIOA, 8, 1);
	
	GPIO_init(GPIOB, 10, OUTPUT); //b
	GPIO_otype(GPIOB, 10, 0);
	GPIO_pupd(GPIOB, 10, 0);
	GPIO_ospeed(GPIOB, 10, 1);
	
	GPIO_init(GPIOA, 7, OUTPUT); //c
	GPIO_otype(GPIOA, 7, 0);
	GPIO_pupd(GPIOA, 7, 0);
	GPIO_ospeed(GPIOA, 7, 1);
	
	GPIO_init(GPIOA, 6, OUTPUT); //d
	GPIO_otype(GPIOA, 6, 0);
	GPIO_pupd(GPIOA, 6, 0);
	GPIO_ospeed(GPIOA, 6, 1);
	
	GPIO_init(GPIOA, 5, OUTPUT); //e
	GPIO_otype(GPIOA, 5, 0);
	GPIO_pupd(GPIOA, 5, 0);
	GPIO_ospeed(GPIOA, 5, 1);
	
	GPIO_init(GPIOA, 9, OUTPUT); //f
	GPIO_otype(GPIOA, 9, 0);
	GPIO_pupd(GPIOA, 9, 0);
	GPIO_ospeed(GPIOA, 9, 1);
	
	GPIO_init(GPIOC, 7, OUTPUT); //g
	GPIO_otype(GPIOC, 7, 0);
	GPIO_pupd(GPIOC, 7, 0);
	GPIO_ospeed(GPIOC, 7, 1);

}


void sevensegment_decode (uint8_t num){
	int number[10][7]={                         //{a,b,c,d,e,f,g}
                    {0,0,0,0,0,0,1},          //zero
                    {1,0,0,1,1,1,1},          //one
                    {0,0,1,0,0,1,0},          //two
                    {0,0,0,0,1,1,0},          //three
                    {1,0,0,1,1,0,0},          //four
                    {0,1,0,0,1,0,0},          //five
                    {0,1,0,0,0,0,0},          //six
                    {0,0,0,1,1,0,1},          //seven
                    {0,0,0,0,0,0,0},          //eight
                    {0,0,0,0,1,0,0},          //nine
                  };
	GPIO_write(GPIOA, 8, number[num][0]); //a
	GPIO_write(GPIOB, 10, number[num][1]); //b
	GPIO_write(GPIOA, 7, number[num][2]); //c
	GPIO_write(GPIOA, 6, number[num][3]); //d
	GPIO_write(GPIOA, 5, number[num][4]); //e
	GPIO_write(GPIOA, 9, number[num][5]); //f
	GPIO_write(GPIOC, 7, number[num][6]); //g
}

void led_select(int _num){
	GPIO_write(GPIOA, LED_PIN_0, ledPin[_num][0]);
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