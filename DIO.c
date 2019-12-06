#include "DIO.h"

void Port_Init(char c){ 
	volatile unsigned long delay;
	switch(c)
	{
		case ('A'):
	SYSCTL_RCGC2_R |= PORTA;          // 1) A clock
  delay = SYSCTL_RCGC2_R;           // delay   
  GPIO_PORTA_LOCK_R = LOCK;         // 2) unlock PortF PA0  
  GPIO_PORTA_CR_R = PORT_A;         // allow changes to PA7-2       
  GPIO_PORTA_AMSEL_R = 0x00;        // 3) disable analog function
  GPIO_PORTA_PCTL_R = 0x00000000;   // 4) GPIO clear bit PCTL  
  GPIO_PORTA_DIR_R |= 0x7C;         // 5) PA7 input, PA6-2 output   
  GPIO_PORTA_AFSEL_R = 0x00;        // 6) no alternate function
  GPIO_PORTA_PUR_R = 0x00;          // enable pullup resistors        
  GPIO_PORTA_DEN_R = PORT_A;        // 7) enable digital pins PA7-PA2 
		break;
		case ('B'):
	SYSCTL_RCGC2_R |= PORTB;          // 1) B clock
  delay = SYSCTL_RCGC2_R;           // delay   
  GPIO_PORTB_LOCK_R = LOCK;         // 2) unlock PortF PB0  
  GPIO_PORTB_CR_R = PORT_B;         // allow changes to PB5-2       
  GPIO_PORTB_AMSEL_R = 0x00;        // 3) disable analog function
  GPIO_PORTB_PCTL_R = 0x00000000;   // 4) GPIO clear bit PCTL  
  GPIO_PORTB_DIR_R |= 0x3C;         // 5) PB5-2 output   
  GPIO_PORTB_AFSEL_R = 0x00;        // 6) no alternate function
  GPIO_PORTB_PUR_R = 0x00;          // enable pullup resistors        
  GPIO_PORTB_DEN_R = PORT_B;        // 7) enable digital pins PB5-PB2 
		break;
		case ('E'):
	SYSCTL_RCGC2_R |= PORTE;          // 1) C clock
  delay = SYSCTL_RCGC2_R;           // delay   
  GPIO_PORTE_LOCK_R = LOCK;         // 2) unlock PortE PE0  
  GPIO_PORTE_CR_R = PORT_E;         // allow changes to PC7-4       
  GPIO_PORTE_AMSEL_R = 0x00;        // 3) disable analog function
  GPIO_PORTE_PCTL_R = 0x00000000;   // 4) GPIO clear bit PCTL  
	GPIO_PORTE_DIR_R |= PORT_E;         // 5) PC4:PC7 output   
  GPIO_PORTE_AFSEL_R = 0x00;        // 6) no alternate function
  GPIO_PORTE_PUR_R = 0x00;          // disable pullup resistors        
  GPIO_PORTE_DEN_R = PORT_E;        // 7) enable digital pins PE 
		break;
		case ('F'):
  SYSCTL_RCGC2_R |= PORTF;          // 1) F clock
  delay = SYSCTL_RCGC2_R;           // delay   
  GPIO_PORTF_LOCK_R = LOCK;         // 2) unlock PortF PF0  
  GPIO_PORTF_CR_R = PORT_F;         // allow changes to PF4-0       
  GPIO_PORTF_AMSEL_R = 0x00;        // 3) disable analog function
  GPIO_PORTF_PCTL_R = 0x00000000;   // 4) GPIO clear bit PCTL  
  GPIO_PORTF_DIR_R |= 0x0E;         // 5) PF4,PF0 input, PF3,PF2,PF1 output   
  GPIO_PORTF_AFSEL_R = 0x00;        // 6) no alternate function
  GPIO_PORTF_PUR_R = 0x11;          // enable pullup resistors on PF4,PF0       
  GPIO_PORTF_DEN_R = PORT_F;        // 7) enable digital pins PF4-PF0   
    break;		
	}
	}


	
// READ 
unsigned long GPIO_read(unsigned long port,unsigned long mask){
 
	return port&mask;
}

// write
void GPIO_write(unsigned long port,unsigned long mask,int state){
 if (state==1)
	 port|= mask;
 else 
	 port&= ~mask;
}
