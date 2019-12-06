#include "delay.h"


void Systick_Init(void)
{
	NVIC_ST_CTRL_R = 0;
	NVIC_ST_CTRL_R |= (1 << ENABLE) | (1 << CLK_SRC);
}

void Systick_Stop(void)
{
	NVIC_ST_CTRL_R = 0;
}

void Systick_Set_Reload(uint32_t reload_val)
{
	NVIC_ST_RELOAD_R = reload_val - 1;
	NVIC_ST_CURRENT_R = 0;
}

uint32_t Systick_Get_Reload(void)
{
	return NVIC_ST_RELOAD_R;
}

void Systick_Trace_Time(void)
{
	Systick_Set_Reload(MAX_RELOAD);
}

uint32_t Systick_Get_Elapsed_Time(void)
{
	uint32_t last = Systick_Get_Reload();
	uint32_t now = NVIC_ST_CURRENT_R;
	return (((last - now)&0x00FFFFFF) / 16); //value in microseconds
}

void Systick_Wait(uint32_t reload_val)
{
	NVIC_ST_RELOAD_R = reload_val - 1;
	NVIC_ST_CURRENT_R = 0;
	while(!(NVIC_ST_CTRL_R & (1 << COUNT)));
}

void delay_ms(uint32_t delay_val)
{
	//int i;
	for(uint32_t i = 0; i < delay_val; i++)
	{
		Systick_Wait(16000);
	}
}

void delay_us(uint32_t delay_val)
{
	//int i;
	//for(uint32_t i = 0; i < delay_val; i++)
	//{
	Systick_Wait(delay_val * 16);
	//}
}

