#include "TIM.h"

extern long ms_counter;
long per;
extern double PWM_point;
extern uint16_t max_volt;
extern double inc;
extern double dinc;
uint8_t flag = 0;
long time;
extern long ms_counter;

void TIM_ini(void){ // TIM2
	RCC->APB1ENR |= RCC_APB1ENR_TIM2EN;
	
	// Freq = 10 MHZ
	
	// It should become 1 Hz
	// ARR * PSC = 10 000 000
	// ARR = 1000
	// PSC = 10 000
	
	TIM2->ARR = 1000;
	TIM2->PSC = 20 - 1;
	
	TIM2->DIER |= TIM_DIER_UIE;
	NVIC_EnableIRQ(TIM2_IRQn);
	TIM2->CR1 |= TIM_CR1_CEN;
}


void TIM2_IRQHandler(){
	if(TIM2->SR & TIM_SR_UIF){
		TIM2->SR &= ~TIM_SR_UIF;
		if(PWM_point < max_volt){
			TIM4->CCR4 = (uint16_t)PWM_point;
			PWM_point += inc;
			inc -= dinc;
		}
		else{
			if(flag == 0){
				flag = 1;
				time = ms_counter;
			}
			PWM_point = max_volt;
			GPIOD->ODR |= (1 << 14);
		}
		
	}
}

