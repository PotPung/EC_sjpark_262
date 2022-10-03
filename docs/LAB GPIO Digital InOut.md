# LAB: GPIO Digital InOut

**Date:** 2022-09-00

**Author/Partner: Seongjun Park / Dongmin Kim**

**Github:** repository link

**Demo Video:** Youtube link

**PDF version:** [file link](https://github.com/ykkimhgu/EC-student/blob/main/lab/lab-student/LAB_GPIO_Digital_InOut_LED_BTN.pdf)

# Introduction

In this lab, you are required to create a simple program that toggle multiple LEDs with a push-button input. Create HAL drivers for GPIO digital in and out control and use your library.

You must submit

- 

  LAB Report (*.md & *.pdf)

- 

  Zip source files(main*.c, ecRCC.h, ecGPIO.h etc...).

  - 

    Only the source files. Do not submit project files

## Requirement

### Hardware

- 

  MCU

  - 

    NUCLEO-F401RE

- 

  Actuator/Sensor/Others:

  - 

    LEDs x 3

  - 

    Resistor 330 ohm x 3, breadboard

### Software

- 

  Keil uVision, CMSIS, EC_HAL library

# Problem 1: Create EC_HAL library

## Procedure

Create the library directory `\repos\EC\lib\`.

Save your header library files in this directory. [See here for detail.](https://ykkim.gitbook.io/ec/uvision/adding-my-api-header-in-uvision)

> DO NOT make duplicates of library files under each project folders

List of functions for Digital_In and Out .

[Library file LINK such as github](https://github.com/ykkimhgu/EC-student/)

**ecRCC.h** (provided)

void RCC_HSI_init(void);  

void RCC_GPIOA_enable(void);   

void RCC_GPIOB_enable(void); 

void RCC_GPIOC_enable(void);

**ecGPIO.h** (만들어야 하는 것)

void GPIO_init(GPIO_TypeDef *Port, int pin,  int mode);  

void GPIO_write(GPIO_TypeDef *Port, int pin,  int output);  

int  GPIO_read(GPIO_TypeDef *Port, int pin);  

void GPIO_mode(GPIO_TypeDef* Port, int pin, int mode);  

void GPIO_ospeed(GPIO_TypeDef* Port, int pin,  int speed);  

void GPIO_otype(GPIO_TypeDef* Port, int pin,  int type);  

void GPIO_pupdr(GPIO_TypeDef* Port, int pin,  int pudr);

- 

  Example code

/* ecGPIO.c  */



// Input(00), Output(01), AlterFunc(10), Analog(11)

void GPIO_mode(GPIO_TypeDef *Port, int pin, int mode){

   Port->MODER &= ~(3UL<<(2*pin));     

   Port->MODER |= mode<<(2*pin);    

}

# Problem 2: Toggle LED with Button

## Procedure

1. 1.

   Create a new project under the directory `\repos\EC\LAB\`

- 

  The project name is “**LAB_GPIO_DIO_LED”.**

- 

  Name the source file as “**LAB_GPIO_DIO_LED.c”**



\2. Include your library **ecGPIO.h, ecGPIO.c** in `\repos\EC\lib\`.

> You MUST write your name in the top of the source file, inside the comment section.

\3. Toggle the LED by pushing button.

- 

  Pushing button (LED ON), Pushing Button (LED OFF) and repeat

## Configuration

Button (B1)

LED

Digital In

Digital Out

GPIOC, Pin 13

GPIOA, Pin 5

PULL-UP

Open-Drain, Pull-up, Medium Speed

## Code

Your code goes here: [ADD Code LINK such as github](https://github.com/ykkimhgu/EC-student/)

Explain your source code with necessary comments.

**Sample Code**

\#define LED_PIN 	5

\#define BUTTON_PIN 13



void setup(void);

​	

int main(void) { 

​	// Initialiization

​	setup();

​	

​	// Inifinite Loop 

​	while(1){

​		if(GPIO_read(GPIOC, BUTTON_PIN) == 0)		GPIO_write(GPIOA, LED_PIN, HIGH);

​		else 										GPIO_write(GPIOA, LED_PIN, LOW);

​	}

}





// Initialiization 

void setup(void)

{

​	RCC_HSI_init();	

​	GPIO_init(GPIOC, BUTTON_PIN, INPUT);  // calls RCC_GPIOC_enable()

​	GPIO_init(GPIOA, LED_PIN, OUTPUT);    // calls RCC_GPIOA_enable()

}

## Discussion

1. 1.

   Find out a typical solution for software debouncing and hardware debouncing. 

2. 2.

   What method of debouncing did this NUCLEO board used for the push-button(B1)?



# Problem 3: Toggle LED with Button

## Procedure

1. 1.

   Create a new project under the directory `\repos\EC\LAB\`

- 

  The project name is “**LAB_GPIO_DIO_multiLED”.**

- 

  Name the source file as “**LAB_GPIO_DIO_multiLED.c”**

> You MUST write your name in the top of the source file, inside the comment section.

1. 1.

   Include your library **ecGPIO.h, ecGPIO.c** in `\repos\lib\`.

2. 2.

   Connect 4 LEDs externally with necessary load resistors.

- 

  As Button B1 is Pressed, light one LED at a time, in sequence.

- 

  Example: LED0--> LED1--> …LED3--> …LED0….

## Configuration

Button

LED

Digital In

Digital Out

GPIOC, Pin 13

PA5, PA6, PA7, PB6

PULL-UP

Push-Pull, Pull-up, Medium Speed

## Circuit Diagram

Circuit diagram

> You need to modify the circuit diagram

![img](https://user-images.githubusercontent.com/38373000/191176652-df38f9ad-5190-4c24-8dfc-fee6206555d9.png)

image

## Code

Your code goes here: [ADD Code LINK such as github](https://github.com/ykkimhgu/EC-student/)

Explain your source code with necessary comments.

// YOUR MAIN CODE ONLY

## Results

Experiment images and results

> Show experiment images /results

Add [demo video link](https://github.com/ykkimhgu/course-doc/blob/master/course/lab/link/README.md)

## Discussion

1. 1.

   Find out a typical solution for software debouncing and hardware debouncing. What method of debouncing did this NUCLEO board used for the push-button(B1)?

> Answer discussion questions

# Reference

Complete list of all references used (github, blog, paper, etc)