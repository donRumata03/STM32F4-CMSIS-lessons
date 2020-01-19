#ifndef HARD_PWM_H
#define HARD_PWM_H

#include "stm32f4xx.h"
#include "SPLs.h"
#include "TIM.h"

void Hard_PWM(uint16_t period, uint16_t pulse);
void plav_vkl(double t_ms, uint16_t max_volt);

#endif
