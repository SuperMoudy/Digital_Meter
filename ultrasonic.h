#ifndef _ULTRASONIC_H_
#define _ULTRASONIC_H_

#include "config.h"
#include "delay.h"
#include "DIO.h"

//void Ultrasonic_Init(void);
void enable_trigger(void);

uint32_t pulse_duration(void);
void output_val(int dis);

#endif // _ULTRASONIC_H_
