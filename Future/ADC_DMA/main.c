#include "main.h"

__IO long delay_couter = 0;
extern uint16_t ADC_result;
long ms_counter = 0;
uint16_t max_volt = 1000;


void SysTick_Handler(){
	if (delay_couter > 0){
		delay_couter--;
	}
	ms_counter++;
}


void delay_ms(long ms){
	delay_couter = ms;
	while(delay_couter > 0){}
}



int main(void){
	
	SystemCoreClockUpdate();
	
	SysTick_Config(SystemCoreClock/1000);
	
	__enable_irq();
	
	
	LEDS_ini();
	GREEN_ON;
	
	ADC_DMA_ini();
	ADC1->CR2 |= ADC_CR2_SWSTART;
	
	while(1){
		
	}
}

