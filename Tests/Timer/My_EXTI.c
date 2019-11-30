#include "My_EXTI.h"

__IO uint8_t dreb_counter = 0;
__IO uint8_t obr_begun = RESET;
int presses = 0;
int true_presses = 0;

void EXTI_ini(){
	RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN;
	RCC->APB2ENR |= 0x00004000;
	RCC->APB2ENR |= RCC_APB2ENR_SYSCFGEN;
	
	// PA0 is input
	GPIOA->MODER &= ~(1 << 0);
	GPIOA->MODER &= ~(1 << 1);
	
	// Multiplexser selects, that EXTI0 is PA0
	SYSCFG->EXTICR[0] &= ~SYSCFG_EXTICR1_EXTI0;
	
	// Allow interrupts
	
	EXTI->IMR |= EXTI_IMR_MR0;
	EXTI->EMR |= EXTI_IMR_MR0;
	
	// Rising edge
	
	EXTI->RTSR |= EXTI_RTSR_TR0; 
	
	// Enable handling events
	
	NVIC_EnableIRQ(EXTI0_IRQn);
}

void EXTI0_IRQHandler(){
	if((1 << 0) & EXTI->PR){
		EXTI->PR |= (1 << 0);
		presses++;
		
		if(obr_begun == SET && dreb_counter == 0 && (GPIOA->IDR & (1 << 0))){
			TOGGLE_GREEN;
			obr_begun = RESET;
			true_presses++;
		}
		else if (obr_begun == RESET){
			dreb_counter = DELAY_DREB;
			obr_begun = SET;
		}
	}
}


void My_EXTI_SysTick(void){
	if(dreb_counter > 0){
		dreb_counter--;
	}
	if(obr_begun == SET && dreb_counter == 0 && (GPIOA->IDR & (1 << 0))){
			TOGGLE_GREEN;
			obr_begun = RESET;
			true_presses++;
		}
}

