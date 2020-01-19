#ifndef LEDS_H
#define LEDS_H

#include "stm32f4xx.h"


#define GREEN_ON GPIOD->ODR |= (1 << 12)
#define ORANGE_ON GPIOD->ODR |= (1 << 13)
#define RED_ON GPIOD->ODR |= (1 << 14)
#define BLUE_ON GPIOD->ODR |= (1 << 15)


#define GREEN_OFF GPIOD->ODR &= ~(1 << 12)
#define ORANGE_OFF GPIOD->ODR &= ~(1 << 13)
#define RED_OFF GPIOD->ODR &= ~(1 << 14)
#define BLUE_OFF GPIOD->ODR &= ~(1 << 15)


#define TOGGLE_GREEN GPIOD->ODR ^= (1 << 12)
#define TOGGLE_ORANGE GPIOD->ODR ^= (1 << 13)
#define TOGGLE_RED GPIOD->ODR ^= (1 << 14)
#define TOGGLE_BLUE GPIOD->ODR ^= (1 << 15)


void LEDS_ini(void);

#endif
