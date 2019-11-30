#include "main.h"

uint32_t delay_counter = 0;


// Button
uint8_t button_pressed = 0;
uint16_t button_counter = 0;


void SysTick_Handler(){
	if(delay_counter){
		delay_counter--;
	}
	if(button_counter == 1){
		RED_TOGGLE;
	}
	if(button_counter){
		button_counter--;
	}
}



void delay(uint32_t ms){
	delay_counter = ms;
	while(delay_counter){}
}




int main(){
	LEDs_Init();
	Button_Init();
	SystemCoreClockUpdate();
	SysTick_Config((uint32_t)(SystemCoreClock/1000));
	
	
	
	while(1){
		if(Button_Read){
			if(button_pressed){
				
			}
			else{
				button_counter = BUTTON_BOUNCE_MAX_TIME;
			}
		}
		else{
			if(button_pressed){
				button_counter = BUTTON_BOUNCE_MAX_TIME;
			}
		}
	}
}
