#include "TIM.h"

long long counter = 0;
long num_tick = 0;
double period = 0;


void TIM_ini(void){ // TIM2
	RCC->APB1ENR |= RCC_APB1ENR_TIM2EN;
	
	// Freq = 10 MHZ
	
	// It should become 1 Hz
	// ARR * PSC = 10 000 000
	// ARR = 1000
	// PSC = 10 000
	
	TIM2->ARR = 1000;
	TIM2->PSC = 10000 - 1;
	
	TIM2->DIER |= TIM_DIER_UIE;
	NVIC_EnableIRQ(TIM2_IRQn);
	TIM2->CR1 |= TIM_CR1_CEN;
}


void TIM2_IRQHandler(){
	if(TIM2->SR & TIM_SR_UIF){
		TIM2->SR &= ~TIM_SR_UIF;
		TOGGLE_RED;
		num_tick += 1;
		period = ((double)counter) / ((double)num_tick);
	}
}

