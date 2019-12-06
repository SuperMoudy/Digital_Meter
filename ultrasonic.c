#include "ultrasonic.h"

void output_val(int dis){
		
	PA25=((dis%10)<< _7SEG_1);
	PA25=((dis%10)<< _7SEG_1);
	dis/=10;
	PB25=((dis%10)<<_7SEG_2);
	PB25=((dis%10)<<_7SEG_2);
	dis/=10;
	GPIO_PORTE_DATA_R= (dis%10);

}

/*void Ultrasonic_Init(void)
{
	
}*/
void enable_trigger(void)
{
	GPIO_PORTA_DATA_R &= ~(1 << TRIG);
	delay_us(5);
	GPIO_PORTA_DATA_R |= (1 << TRIG);
	delay_us(10);
	GPIO_PORTA_DATA_R &= ~(1 << TRIG);
}

/*uint32_t pulse_duration(void)
{
	
}*/
