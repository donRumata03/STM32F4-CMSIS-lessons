#include "ADC.h"


uint16_t ADC_result = 4096;
uint16_t ADC_in[50];
long ADC_summ = 0;
uint32_t fla;


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
		TOGGLE_RED;
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
		
	
	// ADC1->CR2 |= ADC_CR2_CONT;
	
	NVIC_EnableIRQ(ADC_IRQn);
	
	
	ADC1->CR2 |= 0x08000000 | 0x10000000;
	
	// TIM2
	
	RCC->APB1ENR |= RCC_APB1ENR_TIM3EN;
	
	// Freq = 10 MHZ
	
	// It should become 1 Hz
	// ARR * PSC = 10 000 000
	// ARR = 1000
	// PSC = 10 000
	
	TIM3->ARR = 1000;
	TIM3->PSC = 10000 - 1;
	

	TIM3->CR1 |= TIM_CR1_CEN;
	
	TIM3->CR2 |= 0x0020;
	
	ADC1->CR2 |= ADC_CR2_ADON;
}


void ADC_DMA_ini(){
	

	RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN;
	RCC->APB2ENR |= RCC_APB2ENR_ADC1EN;
	RCC->AHB1ENR |= RCC_AHB1ENR_DMA2EN; 
	
	
	GPIOA->MODER |= (1 << 13) | (1 << 12); // PA6 is ANALOG pin
	ADC1->SMPR2 |= ADC_SMPR2_SMP6_1 | ADC_SMPR2_SMP6_0; // Sampling time is 56 cycles
	
	// Length is 1 conversion => change nothing in L bits
	
	ADC1->SQR3 |= ADC_SQR3_SQ1_1 | ADC_SQR3_SQ1_2;
	ADC1->CR2 |= ADC_CR2_CONT;
	
	
	// DMA2 Stream0 Channel_0 is ADC1
	// DMA2_Stream0->CR: Channel_0 => all zeros in CHSEL[2:0]
	
	DMA2_Stream0->CR |= DMA_SxCR_PL_0; // Mediom priority
	DMA2_Stream0->CR |= DMA_SxCR_MSIZE_0; // 16 bit size by 1 iteration
	DMA2_Stream0->CR |= DMA_SxCR_PSIZE_0; // 16 bit size by 1 iteration
	DMA2_Stream0->CR |= DMA_SxCR_MINC; // Memory inclrement Enable
	
	DMA2_Stream0->CR |= DMA_SxCR_CIRC; // Circular mode
	// DIR : Periph to Mem => 00
	DMA2_Stream0->CR |= DMA_SxCR_TCIE; // Enable interrupt
	DMA2_Stream0->NDTR = sizeof(ADC_in)/sizeof(uint16_t);
	DMA2_Stream0->PAR |= ((uint32_t)(&ADC1->DR));
	DMA2_Stream0->M0AR |= ((uint32_t)(ADC_in));
	
	
	ADC1->CR2 |= ADC_CR2_DMA;
	ADC1->CR2 |= ADC_CR2_DDS;
	
	
	NVIC_EnableIRQ(DMA2_Stream0_IRQn);
	
	
	DMA2_Stream0->CR |= DMA_SxCR_EN;
	ADC1->CR2 |= ADC_CR2_ADON;
}


void DMA2_Stream0_IRQHandler(void){
	if(DMA2->LISR & DMA_LISR_TCIF0){
		DMA2->LIFCR |= DMA_LIFCR_CTCIF0;
		ADC_summ = 0;
		for(int i = 0; i < (sizeof(ADC_in) / sizeof(uint16_t)); i++){
			ADC_summ += ADC_in[i];
		}
		DMA2_Stream0->CR |= DMA_SxCR_EN;
		fla = DMA2_Stream0->CR & DMA_SxCR_EN;
	}
}

