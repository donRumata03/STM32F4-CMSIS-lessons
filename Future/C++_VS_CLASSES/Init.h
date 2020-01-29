#pragma once

#include "ptr_getter.h"
#include "GPIO.h"

// Magic for hacking **cking C++
static uint32_t j = 0;
constexpr const uint32_t* addr0 = &j;  // 0x2000001c


// Objectg for getting adresses
constexpr ptr_getter p(addr0, 0x2000001c);

#include "GPIO_maker.h"

