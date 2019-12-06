#ifndef _DELAY_H_
#define _DELAY_H_

#include "tm4c123gh6pm.h"
#include <stdint.h>

// CPU Frequency
#define F_CPU 16000000UL

// Systick Timer Registers

// Systick Control and Status Register
#define ENABLE 	 0
#define CLK_SRC  2
#define COUNT 	16

// Systick Reload Register
#define MAX_RELOAD 0x00FFFFFF

//	Useful Macros
#define HIGH 1
#define LOW  0

//========================================



void Systick_Init(void);

void Systick_Stop(void);

void Systick_Set_Reload(uint32_t reload_val);

uint32_t Systick_Get_Reload(void);

void Systick_Trace_Time(void);

uint32_t Systick_Get_Elapsed_Time(void);


void Systick_Wait(uint32_t reload_val);

void delay_ms(uint32_t delay_val);

void delay_us(uint32_t delay_val);

//uint8_t get_delay();

//void delay_s(unsigned long delay_val);

#endif // _DELAY_H_
