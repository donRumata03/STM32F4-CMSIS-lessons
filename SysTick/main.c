#include "stm32f4xx.h"

uint32_t delay_counter = 0;



void SysTick_Handler(){
	if(delay_counter){
		delay_counter--;
	}
}



void delay(uint32_t ms){
	delay_counter = ms;
	while(delay_counter){}
}



int main(){
	RCC->AHB1ENR |= RCC_AHB1ENR_GPIODEN;
	
	GPIOD->MODER |= GPIO_MODER_MODER12_0;
	
	SystemCoreClockUpdate();
	
	
	SysTick_Config((uint32_t)(SystemCoreClock/1000));
	
	
	while(1){
		GPIOD->ODR ^= (1 << 12);
		delay(1000);
	}
}
