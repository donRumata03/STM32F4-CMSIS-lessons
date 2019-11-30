#include "ADC.h"

uint16_t ADC_data = 4096;

void ADC_Init(){
	// ADC1 PA1 Channel: 1
	
	RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN;
	RCC->APB2ENR |= RCC_APB2ENR_ADC1EN;
	
	GPIOA->MODER |= (0b11 << 2);
	GPIOA->OSPEEDR |= (0b11 << 2);
	
	
	ADC1->SQR3 |= 1;
	ADC1->SMPR2 |= (0b011 << 3); // 56 Cycles
	
	ADC1->CR2 |= ADC_CR2_CONT;
	
	
	ADC1->CR1 |= ADC_CR1_EOCIE;
	NVIC_EnableIRQ(ADC_IRQn);
	
	ADC1->CR2 |= ADC_CR2_ADON;
}

uint16_t ADC_Get_Data(){
	return (uint16_t)(ADC1->DR);
}


void ADC_IRQHandler(){
	if(ADC1->SR & ADC_SR_EOC){
		ADC1->SR &= ~ADC_SR_EOC;
		ADC_data = ADC_Get_Data();
	}
}