#include "ADC.h"


uint16_t ADC_result = 4096;


void ADC_ini(){


	RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN;
	RCC->APB2ENR |= RCC_APB2ENR_ADC1EN;
	
	GPIOA->MODER |= (1 << 13) | (1 << 12); // PA6 is ANALOG pin
	
	
	
	ADC1->CR1 |= ADC_CR1_EOCIE;
	ADC1->SMPR2 |= ADC_SMPR2_SMP6_1 | ADC_SMPR2_SMP6_0; // Sampling time is 56 cycles
	
	// Length is 1 conversion => change nothing in L bits
	
	ADC1->SQR3 |= ADC_SQR3_SQ1_1 | ADC_SQR3_SQ1_2;
		
	
	ADC1->CR2 |= ADC_CR2_CONT;
	
	NVIC_EnableIRQ(ADC_IRQn);
	
	ADC1->CR2 |= ADC_CR2_ADON;
}



void ADC_IRQHandler(){
	if(ADC1->SR & ADC_SR_EOC){
		ADC1->SR &= ~ADC_SR_EOC;
		ADC_result = ADC1->DR;
	}
}







void ADC_start(void){
	ADC1->CR2 |= ADC_CR2_SWSTART;
}



void ADC_with_tim_ini(void){
	RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN;
	RCC->APB2ENR |= RCC_APB2ENR_ADC1EN;
	
	GPIOA->MODER |= (1 << 13) | (1 << 12); // PA6 is ANALOG pin
	
	
	
	ADC1->CR1 |= ADC_CR1_EOCIE;
	ADC1->SMPR2 |= ADC_SMPR2_SMP6_1 | ADC_SMPR2_SMP6_0; // Sampling time is 56 cycles
	
	// Length is 1 conversion => change nothing in L bits
	
	ADC1->SQR3 |= ADC_SQR3_SQ1_1 | ADC_SQR3_SQ1_2;
		
	
	ADC1->CR2 |= ADC_CR2_CONT;
	
	NVIC_EnableIRQ(ADC_IRQn);
	
	ADC1->CR2 |= ADC_CR2_ADON;
}
