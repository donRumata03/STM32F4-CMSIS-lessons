#include "Hard_PWM.h"

double PWM_point = 0;
double inc;
double dinc;


void Hard_PWM(uint16_t period, uint16_t pulse){
	// Init clocks
	RCC->APB1ENR |= RCC_APB1ENR_TIM4EN;
	RCC->AHB1ENR |= RCC_AHB1ENR_GPIODEN;
	
	// TIM Base Init
	
	TIM4->ARR = period;
	TIM4->PSC = 0;
	
	// GPIO Init
	
	GPIOD->MODER &= ~((uint32_t)1 << 30);
	GPIOD->MODER |= ((uint32_t)1 << 31); // Type: AF
	GPIOD->OTYPER &= ~((uint16_t)1 << 15); // Push-Pull
	GPIOD->OSPEEDR |= ((uint32_t)1 << 31) | ((uint32_t)1 << 30); // Max speed (100 MHz)
	GPIOD->PUPDR &= ~(((uint32_t)1 << 31) | ((uint32_t)1 << 30)); // No pull
	
	GPIOD->AFR[1] |= GPIO_AFRH_AFSEL15_1;
	
	//Timer PWM Init
	TIM4->CCMR2 = (1 << 13) | (1 << 14); // Output compare 1 mode is PWM1
	TIM4->CCR4 = pulse; // Value of PWM
	TIM4->CCER = TIM_CCER_CC4E; // Muliplex CR4 to PD15
	
	
	// Start PWM
	TIM4->CR1 = TIM_CR1_CEN;
}


void plav_vkl(double t_ms, uint16_t max_volt){
	TIM_ini();
	
	inc = 2 * ((double)max_volt) / t_ms;
	dinc = inc / (double)t_ms;
	PWM_point = 0;
}

