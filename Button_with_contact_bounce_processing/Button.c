#include "Button.h"



void Button_Init(){
	RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN;
	GPIOA->MODER &= ~(3 << 0);
}

