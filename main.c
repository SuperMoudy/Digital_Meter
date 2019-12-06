// Main File of Digital Meter Project
// Date : 30 / 3 / 2018
// Authors : Mahmoud Hamdy & Mohamed Mohamed El Morsy
//
// Description : Digital Meter that uses ultrasonic waves to measure distance
// 
// Main Components : 
// - 1 TivaC LaunchPad (TM4C123GH6PM Microcontroller)
// - 3 7-segment displays (common cathode)
// - 3 7448 (BCD to 7-segment decoders)
// - 1 HC-SR04 (ultrasonic sensor module)
// - 6 Resistors 330 ohm
// - Jumper wires
//////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////

// Included Libraries and Modules

#include "tm4c123gh6pm.h"
#include <stdint.h>
#include "delay.h"
#include "config.h"
#include "DIO.h"
#include "ultrasonic.h"

// System Initialization Code

void SystemInit(void){}

// Main Function

int main(void)
{
	
	//Peripherals Initialization
	
	Systick_Init();
	Port_Init('A');
	Port_Init('B');
	Port_Init('E');
	
	uint32_t duration; // duration of the pulse in the air
	float distance; // distance from the ultrasonic to the target
	
	while(1)
	{

		enable_trigger(); //send a 10us pulse through the trig pin of the sensor
		
		while((GPIO_PORTA_DATA_R & (1 << ECHO)) == 0); //wait for the echo to get ready to receive pulse
		
		Systick_Trace_Time(); //Trace the time from when the echo pin is ready to receive the pulse
		
		while((GPIO_PORTA_DATA_R & (1 << ECHO)) != 0); //wait for the echo to receive the pulse
		
		duration = Systick_Get_Elapsed_Time(); //get the elapsed time of the pulse in the air
		
		distance = ((float)duration * 0.034)/ 2.0; //distance(m) = time(s) x velocity(m/s)
		
		output_val((uint32_t)((distance + 0.5)*1.021)); //Divide the value on the 3 seven segments
		
		delay_ms(100); //delay between each pair of measurements
	}
}

