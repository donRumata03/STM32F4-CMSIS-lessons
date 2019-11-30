#include "stm32f4xx.h"



int main(){
	RCC->AHB1ENR |= RCC_AHB1ENR_GPIODEN;
	
	GPIOD->MODER |= GPIO_MODER_MODER12_0;
	

	
	while(1){
		GPIOD->ODR ^= (1 << 12);
		for(int i = 0; i < 2000000; i++){}
	}
}
