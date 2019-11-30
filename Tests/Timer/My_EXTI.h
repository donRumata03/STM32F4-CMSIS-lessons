#ifndef My_EXTI_H
#define My_EXTI_H

#include "stm32f4xx.h"
#include "main.h"

#define DELAY_DREB 50 // Ms

void EXTI_ini(void);
void My_EXTI_SysTick(void);


#endif
