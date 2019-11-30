#ifndef LEDS_H
#define LEDS_H

#include "stm32f4xx.h"


#define GREEN_ON (GPIOD->ODR |= (1 << 12))
#define GREEN_OFF (GPIOD->ODR &= ~(1 << 12))
#define GREEN_TOGGLE (GPIOD->ODR ^= (1 << 12))



#define ORANGE_ON (GPIOD->ODR |= (1 << 13))
#define ORANGE_OFF (GPIOD->ODR &= ~(1 << 13))
#define ORANGE_TOGGLE (GPIOD->ODR ^= (1 << 13))


#define RED_ON (GPIOD->ODR |= (1 << 14))
#define RED_OFF (GPIOD->ODR &= ~(1 << 14))
#define RED_TOGGLE (GPIOD->ODR ^= (1 << 14))


#define BLUE_ON (GPIOD->ODR |= (1 << 15))
#define BLUE_OFF (GPIOD->ODR &= ~(1 << 15))
#define BLUE_TOGGLE (GPIOD->ODR ^= (1 << 15))

void LEDs_Init(void);

#endif
