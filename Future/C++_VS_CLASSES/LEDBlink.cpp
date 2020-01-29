#include "all_include.h"

#include "stm32f4xx.h"
#include "GPIO.h"
#include "ptr_getter.h"

int main() {
#include "Init.h"
		
	RCC->AHB1ENR |= RCC_AHB1ENR_GPIODEN;
	GPIOD->MODER |= GPIO_MODER_MODER12_0;
	

	
	while (1) {
		gpiod.pin_toggle(12);
		for (int i = 0; i < 2000000; i++) {}
	}
}
