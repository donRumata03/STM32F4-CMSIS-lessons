#include "LEDS.h"

void LEDS_ini(void){
	RCC->AHB1ENR |= RCC_AHB1ENR_GPIODEN;
	
	GPIOD->MODER |= (1 << 24) | (1 << 26) | (1 << 28) | (1 << 30); // PD12, PD13, PD14, PD15 are outputs
}
