#ifndef ADC_H
#define ADC_H

#include "stm32f4xx.h"

void ADC_ini(void);
void ADC_start(void);
uint16_t ADC_Get_Data(void);
void ADC_with_tim_ini(void);

#endif
