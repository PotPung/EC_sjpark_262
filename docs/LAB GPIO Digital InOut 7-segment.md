# LAB: GPIO Digital InOut 7-segment



**Date:** 2022-09-26

**Author/Partner:**

**Github:** repository link

**Demo Video:** Youtube link

**PDF version:**

# Introduction

In this lab, you are required to create a simple program to control a 7-segment display to show a decimal number (0~9) that increases by pressing a push-button.

You must submit

- LAB Report (*.md & *.pdf)
- Zip source files(main*.c, ecRCC.h, ecGPIO.h etc...).
  - Only the source files. Do not submit project files

## Requirement

### Hardware

- 

  MCU

  - 

    NUCLEO-F401RE

- 

  Actuator/Sensor/Others:

  - 

    7-segment display(5101ASR)

  - 

    Array resistor (330 ohm)

  - 

    breadboard

### Software

- 

  Keil uVision, CMSIS, EC_HAL library

# Problem 1: Connecting 7-Segment

## Procedure

Review 7-segment Decoder and Display from Digital Logic lecture.

- 

  Read here: [7-segment BCD tutorial](https://www.electronics-tutorials.ws/combination/comb_6.html)

The popular BCD 7-segment decoder chips are **74LS47 and CD4511**.

Instead of using the decoder chip, we are going to make the 7-segment decoder with the MCU programming.

![img](https://user-images.githubusercontent.com/38373000/192133325-a4844100-ab1c-445b-8832-837c8f988f35.png)

image

Connect the common anode 7-segment with the given array resistors.

Apply VCC and GND to the 7-segment display.

Apply 'H' to any 7-segment pin 'a'~'g' and observe if that LED is turned on or off

- 

  example: Set 'H' on PA5 of MCU and connect to 'a' of the 7-segment.

## Connection Diagram

Circuit diagram

> You need to include the circuit diagram

![img](https://user-images.githubusercontent.com/38373000/192134563-72f68b29-4127-42ac-b064-2eda95a9a52a.png)

image

## Discussion

1. 1.

   Draw the truth table for the BCD 7-segment decoder with the 4-bit input.

> Answer discussion questions

** YOUR Truth-table  goes here**

1. 1.

   What are the common cathode and common anode of 7-segment display?

> Answer discussion questions

1. 1.

   Does the LED of a 7-segment display (common anode) pin turn ON when 'HIGH' is given to the LED pin from the MCU?

> Answer discussion questions

# Problem 2: Display 0~9 with button press

## Procedure

1. 1.

   Create a new project under the directory `\repos\EC\LAB\LAB_GPIO_7segment`

- 

  The project name is “**LAB_GPIO_7segment”.**

- 

  Create a new source file named as “**LAB_GPIO_7segment.c”**

- 

  Refer to the [sample code](https://github.com/ykkimhgu/course-doc/blob/master/course/lab/code/README.md)

> You MUST write your name on the source file inside the comment section.

\2. Include your updated library in `\repos\EC\lib\` to your project.

- 

  **ecGPIO.h, ecGPIO.c**

- 

  **ecRCC.h, ecRCC.c**

1. 1.

   Declare and Define the following functions in your library

   - 

     You can refer to [an example code of 7-segment control](https://os.mbed.com/users/ShingyoujiPai/code/7SegmentDisplay/file/463ff11d33fa/main.cpp/)

   **ecGPIO.h**

void sevensegment_init(void); 

void sevensegment_decoder(uint8  num);

1. 1.

   First, check if every number, 0 to 9, can be displayed properly

2. 2.

   Then, create a code to display the number from 0 to 9 with each button press. After the number '9', it should start from '0' again.

## Configuration

Digital In for Button (B1)

Digital Out for 7-Segment

Digital In

Digital Out

PC13

PA5, PA6, PA7, PB6, PC7, PA9, PA8, PB10 ('a'~'h', respectively)

PULL-UP

Push-Pull, No Pull-up-Pull-down, Medium Speed

## Exercise

Fill in the table

| Port/Pin       | Description                  | Register setting            |
| -------------- | ---------------------------- | --------------------------- |
| Port A Pin 5   | Clear Pin5 mode              | GPIOA->MODER &=~(3<<(5*2))  |
| Port A Pin 5   | Set Pin5 mode = Output       | GPIOA->MODER \|= (1<<(5*2)) |
| Port A Pin 6   | Clear Pin6 mode              | GPIOA->MODER &=~(3<<(6*2))  |
| Port A Pin 6   | Set Pin6 mode = Output       | GPIOA->MODER \|= (1<<(6*2)) |
| Port A Pin Y   | Clear PinY mode              | GPIOA->MODER &=~            |
| Port A Pin Y   | Set PinY mode = Output       | GPIOA->MODER \|=            |
| Port A Pin 5~9 | Clear Pin5~9 mode            | GPIOA->MODER &=~            |
|                | Set Pin5~9 mode = Output     | GPIOA->MODER \|=            |
| Port X Pin Y   | Clear Pin Y mode             | GPIOX->MODER &=~            |
|                | Set Pin Y mode = Output      | GPIOX->MODER \|=            |
| Port A Pin 6   | Set Pin5 otype=push-pull     | GPIOA->OTYPER =             |
| Port A Pin Y   | Set PinY otype=push-pull     | GPIOA-> OTYPER =            |
| Port A Pin 5   | Set Pin5 ospeed=Fast         | GPIOA->OSPEEDR =            |
| Port A Pin Y   | Set PinY ospeed=Fast         | GPIOA-> OSPEEDR =           |
| Port A Pin 5   | Set Pin5 PUPD=no pullup/down | GPIOA->OTYPER =             |
| Port A Pin Y   | Set PinY PUPD=no pullup/down | GPIOA-> OTYPER =            |



## Code

[**Sample Code**](https://ykkim.gitbook.io/ec/stm32-m4-programming/example-code#seven-segment).

\#include "stm32f4xx.h"

\#include "ecGPIO.h"

\#include "ecRCC.h"



\#define LED_PIN 	5

\#define BUTTON_PIN 13



void setup(void);

​	

int main(void) { 

​	// Initialiization --------------------------------------------------------

​	setup();

​	unsigned int cnt = 0;

​	

​	// Inifinite Loop ----------------------------------------------------------

​	while(1){

​		sevensegment_decode(cnt % 10);

​		if(GPIO_read(GPIOC, BUTTON_PIN) == 0) cnt++; 

​		if (cnt > 9) cnt = 0;

​		for(int i = 0; i < 500000;i++){}

​	}

}





// Initialiization 

void setup(void)

{

​	RCC_HSI_init();	

​	GPIO_init(GPIOC, BUTTON_PIN, INPUT);  // calls RCC_GPIOC_enable()

​	sevensegment_init();

}

Your code goes here: [ADD Code LINK such as github](https://github.com/ykkimhgu/EC-student/)

Explain your source code with necessary comments.

// YOUR MAIN CODE ONLY

// YOUR CODE

## Results

Experiment images and results

> Show experiment images /results

Add [demo video link](https://github.com/ykkimhgu/course-doc/blob/master/course/lab/link/README.md)

# Reference

Complete list of all references used (github, blog, paper, etc)



# Troubleshooting

(Option) You can write Troubleshooting section