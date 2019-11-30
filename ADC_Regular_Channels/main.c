#include "main.h"

uint32_t delay_counter = 0;





void SysTick_Handler(){
	if(delay_counter){
		delay_counter--;
	}
	EXTI_SysTick();
}



void delay(uint32_t ms){
	delay_counter = ms;
	while(delay_counter){}
}


int main(){
	LEDs_Init();
	SystemCoreClockUpdate();
	SysTick_Config((uint32_t)(SystemCoreClock/1000));
	
	ADC_Init();
	
	ADC1->CR2 |= ADC_CR2_SWSTART;

	while(1){
		
	}
}
