#include "EXTI.h"


int EXTI_button_counter = 0;


void EXTI_Init(){
	RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN;
	
	GPIOA->OSPEEDR |= (0b11);
	
	
	EXTI->IMR |= 1;
	EXTI->RTSR |= 1;
	EXTI->FTSR |= 1;
	
	NVIC_EnableIRQ(EXTI0_IRQn);
}


void EXTI0_IRQHandler(){
	if(EXTI->PR & 1){
		EXTI->PR |= 1;
		EXTI_button_counter = MAX_BOUNCE_TIME;
		NVIC_DisableIRQ(EXTI0_IRQn);
	}
}


void EXTI_SysTick(){
	if(EXTI_button_counter == 1){
		if(Button_Read){
			RED_TOGGLE;
		}
		NVIC_EnableIRQ(EXTI0_IRQn);
	}
	if(EXTI_button_counter){
		EXTI_button_counter--;
	}
}
