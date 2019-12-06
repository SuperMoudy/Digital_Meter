#ifndef _DIO_H_
#define _DIO_H_

#include "config.h"

void Port_Init(char c);
unsigned long GPIO_read(unsigned long port,unsigned long mask);
void GPIO_write(unsigned long port,unsigned long mask,int state);

#endif // _DIO_H_
