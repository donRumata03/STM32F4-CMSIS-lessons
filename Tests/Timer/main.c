#include "main.h"

extern long long counter;
extern uint16_t ADC_result;
extern long num_tick;
long delay_couter = 0;


void SysTick_Handler(){
	if (delay_couter > 0){
		delay_couter--;
	}
	counter++;
}


void delay_ms(long ms){
	delay_couter = ms;
	while(delay_couter > 0){}
}



int main(void){
	
	SystemCoreClockUpdate();
	
	SysTick_Config(SystemCoreClock/1000);
	
	__enable_irq();
	ADC_ini();
	
	
	

	
	
	
	LEDS_ini();
	GREEN_ON;
	TIM_ini();
	
	while(1){
		TOGGLE_BLUE;
		delay_ms(1000);
	}
}

