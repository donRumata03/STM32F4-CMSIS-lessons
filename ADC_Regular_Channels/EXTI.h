#ifndef EXTI_H
#define EXTI_H

#include "stm32f4xx.h"
#include "main.h"

#define MAX_BOUNCE_TIME 20

void EXTI_Init();
void EXTI_SysTick();


#endif