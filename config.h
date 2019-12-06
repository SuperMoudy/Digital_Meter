#ifndef _CONFIG_H_
#define _CONFIG_H_
#include "tm4c123gh6pm.h"
#define PORTA 0X01
#define PORTB 0X02
#define PORTE 0X10
#define PORTF 0X20
#define PORT_A 0XFC
#define PORT_B 0X3C
#define PORT_E 0X3F
#define PORT_F 0X01F
#define LOCK   0x4C4F434B 
#define PA25   (*((volatile unsigned long *)0x400040f0))
#define PE03   (*((volatile unsigned long *)0x400243C0))	
#define PB25   (*((volatile unsigned long *)0x400050f0))
#define _7SEG_1 2
#define _7SEG_2 2
#define _7SEG_3 4
#define HIGH	1
#define LOW 	0
#define TRIG 6
#define ECHO 7

#endif //_CONFIG_H_
