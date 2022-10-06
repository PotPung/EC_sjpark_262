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

## Explain the problem in detail





# Problem 2: Toggle LED with Button

## Procedure

LED toggles when the button **B1** is pressed.

​	: LED ON 

​	-> Pushing button -> LED OFF 

​	-> Pushing button -> LED ON



## Configuration

| Button (B1)   | LED                               |
| ------------- | --------------------------------- |
| Digital In    | Digital Out                       |
| GPIOC, Pin 13 | GPIOA, Pin 5                      |
| PULL-UP       | Open-Drain, Pull-up, Medium Speed |



## Discussion

1. Find out a typical solution for software debouncing and hardware debouncing. 

   ![image](https://user-images.githubusercontent.com/114110842/193492703-82499522-d32d-4e91-a232-f4e58e9e170e.png)

   먼저 위 사진을 통해 Debouncing의 원인을 들여다 보면, 스위치를 ON, OFF 하는 과정에서 순간적으로 신호가 빠르게 튀는 것을 확인할 수 있다. 이에 따라 기계 장치는 불안정한 결과를 야기한다. 이를  software와 hardware 각각의 측면에서 해결할 수 있다.

   

2. What method of debouncing did this NUCLEO board used for the push-button(B1)?

   : 

# Problem 3: Toggle LED with Button

## Procedure

4 LEDs toggles when the button **B1** is pressed.

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

- Lab source code <problem 2>: [https://github.com/PotPung/EC_sjpark_262/blob/main/lab/LAB_GPIO_DIO_LED/LAB_GPIO_DIO_LED.c

Explain your source code with necessary comments

- Description 1

// CODE Snippet or Segments

// Don't show the whole code. Only necessary segments

- Description 2

// CODE Snippet or Segments







- Lab source code <problem 3>: https://github.com/PotPung/EC_sjpark_262/blob/main/lab/LAB_GPIO_DIO_multiLED/LAB_GPIO_DIO_multiLED.c

Explain your source code with necessary comments

- Description 1

// CODE Snippet or Segments

// Don't show the whole code. Only necessary segments

- Description 2

// CODE Snippet or Segments



# Results and Analysis

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

It was confirmed that the LED was toggled every time Button **B1** was pressed.

# Discussion





# Reference

Young-Keun Kim. *Gitbook*. https://github.com/ykkimhgu/EC-student/blob/main/lab/lab-student/LAB_GPIO_DIO_LED_student.c  [2022, September 21].

North American Editors.  *Digi-Key.* https://www.digikey.com/en/articles/how-to-implement-hardware-debounce-for-switches-and-relays [2021, February 9]

# Troubleshooting

(Option) You can write Troubleshooting section