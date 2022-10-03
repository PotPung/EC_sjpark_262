LAB: GPIO Digtal InOUt

**Date:** 2022/10/03

**Author/Partner:** Seongjun Park / Dongmin Kim

**Github:** https://github.com/PotPung/EC_sjpark_262

**Demo Video:** https://youtu.be/ipuXnO2wPJw

**PDF version: **1.7(Acrobat 8.x)



# Introduction

  In this Lab, we will control the operation of the LED with Button. There are two problems. In problem 1, one LED toggles as the button is pressed. When the button is pressed, the LED is switched ON/OFF, and when the button is released, it remains switched until the button is pressed again. In problem 2, a total of four LEDs are turned on alternately each time the button is pressed. For example, when LED1 is ON, pressing button turns LED1 off and LED2 lights on. If pressed one more time, LED2 is turned off and LED3 is turned on. Through this lab, it is possible to define and control the relationship between button input and led output.



# Requirement

### Hardware

- MCU
  - NUCLEO-F401RE
- Actuator/Sensor/Others:
  - LEDs x 4
  - Resistor 330 ohm x 3, breadboard

### Software

- Keil uVision, CMSIS, EC_HAL library



# Problem 1: Create EC_HAL library

## Procedure

Create the library directory `\repos\EC\lib\`.

-> https://github.com/PotPung/EC_sjpark_262/tree/main/lib



# Problem 2: Toggle LED with Button

## Procedure

1. Create a new project under the directory `\repos\EC\LAB\`

- The project name is “**LAB_GPIO_DIO_LED”.**

- Name the source file as “**LAB_GPIO_DIO_LED.c”**

  -> https://github.com/PotPung/EC_sjpark_262/tree/main/lab

  

2. include your library **ecGPIO.h, ecGPIO.c** in `\repos\EC\lib\`.

> -> https://github.com/PotPung/EC_sjpark_262/tree/main/lib
>
> 

3. LED toggles when the button **B1** is pressed.

​	: LED ON 

​	-> Pushing button -> LED OFF 

​	-> Pushing button -> LED ON



## Configuration

| Button (B1)   | LED                               |
| ------------- | --------------------------------- |
| Digital In    | Digital Out                       |
| GPIOC, Pin 13 | GPIOA, Pin 5                      |
| PULL-UP       | Open-Drain, Pull-up, Medium Speed |



# Problem 3: Toggle LED with Button

## Procedure

1. Create a new project under the directory `\repos\EC\LAB\`

- The project name is “**LAB_GPIO_DIO_multiLED”.**

- Name the source file as “**LAB_GPIO_DIO_multiLED.c”**

  ->-> https://github.com/PotPung/EC_sjpark_262/tree/main/lab

  

2. Include your library **ecGPIO.h, ecGPIO.c** in `\repos\lib\`.

   -> https://github.com/PotPung/EC_sjpark_262/tree/main/lib

   

3. Connect 4 LEDs externally with necessary load resistors.

   - 4 LEDs toggles when the button **B1** is pressed.

   ​	: LED1 ON -> Pushing button -> LED1 OFF / LED2 ON

   ​	-> Pushing button -> LED2 OFF / LED3 ON 

   ​	-> Pushing button -> LED3 OFF / LED4 ON

   ​	-> Pushing button -> LED4 OFF / LED1 ON



## Configuration

| Button (B1)   | LED                              |
| ------------- | -------------------------------- |
| Digital In    | Digital Out                      |
| GPIOC, Pin 13 | PA5, PA6, PA7, PB6               |
| PULL-UP       | Push-Pull, Pull-up, Medium Speed |



## Circuit Diagram

External circuit diagram that connects MCU pins to 4 LEDs

< K>![image](https://user-images.githubusercontent.com/114110842/193488657-ef42a3a8-7e9f-4544-9809-97f810598863.png)

# Algorithm

## Overview

**<Problem 1> LED Toggle**

![image-20221003111903566](C:\Users\user\AppData\Roaming\Typora\typora-user-images\image-20221003111903566.png)

**<Problem 2> LEDs Toggle**

![img](https://user-images.githubusercontent.com/114110842/193490252-044c5bb4-0c48-4e77-9416-2aa029d4c8b7.png)



## Description with Code

- **Lab source code <problem 2>**: [https://github.com/PotPung/EC_sjpark_262/blob/main/lab/LAB_GPIO_DIO_LED/LAB_GPIO_DIO_LED.c
- Using 2D-array, 'num' was increased as the button was pressed, and each led state defined in 2D-arrya was input according to num.
- **LED_Toggle main**

```c
int main(void) { 
	// Initialiization --------------------------------------------------------
	setup();
	// Inifinite Loop ----------------------------------------------------------
	while(1){
		LED_Toggle(); // LED toggle function
		for (int i =0; i<300000; i++){ //Delay for debouncing
		}
	}
}

```

- **LED_Toggle function**

```c
void LED_Toggle(void){
	if(GPIO_read(GPIOC, BUTTON_PIN) == LOW){ // pushing Button
		if(GPIO_read(GPIOA, LED_PIN) == LOW){ // toggle
			GPIO_write(GPIOA, LED_PIN, HIGH);
		}
		else{
			GPIO_write(GPIOA, LED_PIN, LOW);
		}
	}
	else{ // non - pushing Button
		if(GPIO_read(GPIOA, LED_PIN) == LOW){ // staying in state
			GPIO_write(GPIOA, LED_PIN, LOW);
		}
		else{
			GPIO_write(GPIOA, LED_PIN, HIGH);
		}
	}
}

```





- **Lab source code <problem 3>**: https://github.com/PotPung/EC_sjpark_262/blob/main/lab/LAB_GPIO_DIO_multiLED/LAB_GPIO_DIO_multiLED.c

- **LEDs_Toggle main**

```c
int main(void) { 
	// Initialiization --------------------------------------------------------
	setup();
	int num = 0; // num_init
		// Inifinite Loop ----------------------------------------------------------
	while(1){
		led_select (num % 4); //led select function 
		if(GPIO_read(GPIOC, BUTTON_PIN) == LOW) num++;
		if(num>3) num = 0;
		for (int i =0; i<300000; i++){ // Delay for debouncing
		}
	}
}

```

- **led_select function**

```c
int ledPin[4][4] ={{1,0,0,0},{0,1,0,0},{0,0,1,0},{0,0,0,1}}; // 2D-array for each leds on/off

void led_select(int _num){
	GPIO_write(GPIOA, LED_PIN_0,ledPin[_num][0]); //led 1
	GPIO_write(GPIOA, LED_PIN_1, ledPin[_num][1]);  //led 2
	GPIO_write(GPIOA, LED_PIN_2, ledPin[_num][2]);  //led 3
	GPIO_write(GPIOB, LED_PIN_3, ledPin[_num][3]);  //led 4
	
}

```



# Results

## Results

**<Problem 1> LED OFF**
[![image](https://user-images.githubusercontent.com/114110842/193491730-2763ba46-0a92-41f6-a586-84f38fc236e9.png)](https://user-images.githubusercontent.com/114110842/193491730-2763ba46-0a92-41f6-a586-84f38fc236e9.png)

**<Problem 1> LED ON**
[![image](https://user-images.githubusercontent.com/114110842/193491744-fd2803a6-3dfa-4abb-aa01-d847667ef36b.png)](https://user-images.githubusercontent.com/114110842/193491744-fd2803a6-3dfa-4abb-aa01-d847667ef36b.png)

**<Problem 2> LED1 ON**
[![image](https://user-images.githubusercontent.com/114110842/193491761-45962eac-3c76-4c76-8f78-c22eb3e5a139.png)](https://user-images.githubusercontent.com/114110842/193491761-45962eac-3c76-4c76-8f78-c22eb3e5a139.png)

**<Problem 2> LED2 ON**
[![image](https://user-images.githubusercontent.com/114110842/193491771-97d6dffa-e187-42e1-98cf-e78f16b5573b.png)](https://user-images.githubusercontent.com/114110842/193491771-97d6dffa-e187-42e1-98cf-e78f16b5573b.png)

**<Problem 2> LED3 ON**
[![image](https://user-images.githubusercontent.com/114110842/193491786-cf828175-2853-43f1-b653-dd78dcc99106.png)](https://user-images.githubusercontent.com/114110842/193491786-cf828175-2853-43f1-b653-dd78dcc99106.png)

**<Problem 2> LED4 ON**
[![image](https://user-images.githubusercontent.com/114110842/193491802-026ec4b4-dbd3-489a-966e-b47d06b9cb2a.png)](https://user-images.githubusercontent.com/114110842/193491802-026ec4b4-dbd3-489a-966e-b47d06b9cb2a.png)

https://youtu.be/ipuXnO2wPJw

It was confirmed that the LED was toggled every time Button **B1** was pressed. When there was no debounce, the LED output value was very unstable, and it was not easy to control the whole thing. The debounce process observed that the output power according to the input was stable, and it could be seen how important the role of debounce is.



## Discussion

1. Find out a typical solution for software debouncing and hardware debouncing. 

   ![image](https://user-images.githubusercontent.com/114110842/193492703-82499522-d32d-4e91-a232-f4e58e9e170e.png)

    First, if you look into the cause of bouncing through the picture above, you can see that the signal pops quickly in the process of turning the switch on and off. Accordingly, the mechanical device causes unstable results. This can be solved in each aspect of software and hardware.

    The solution to this in hardware is to add capacitors in parallel at the switch end. The capacitor may perform a role of reducing noise. However, as a disadvantage, it can occupy a lot of space and costs a capacitor.

    A way to solve this problem in software can give a certain amount of delay after detecting the first pulse. Then, delay occurs during the end of the unstable section and normal results can occur. However, the disadvantage is that these minor delays can gather and slow down the processing of the entire project.

   

2. What method of debouncing did this NUCLEO board used for the push-button(B1)?

   In this NUCLEO board, delay, a software debouncement solution, was used as a solution to bouncing.

   

# Reference

Young-Keun Kim. *Gitbook*. https://github.com/ykkimhgu/EC-student/blob/main/lab/lab-student/LAB_GPIO_DIO_LED_student.c  [2022, September 21].

North American Editors.  *Digi-Key.* https://www.digikey.com/en/articles/how-to-implement-hardware-debounce-for-switches-and-relays [2021, February 9]

Mike Murray. *The GEEK PUB.* https://www.thegeekpub.com/246471/debouncing-a-switch-in-hardware-or-software/ [n. d.]

 