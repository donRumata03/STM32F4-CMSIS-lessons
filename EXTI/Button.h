#ifndef BUTTON_H
#define BUTTON_H


#include "stm32f4xx.h"


#define Button_Read ((GPIOA->IDR) & 1)
#define BUTTON_BOUNCE_MAX_TIME 20

void Button_Init(void);



#endif