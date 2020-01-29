#pragma once
#include "all_include.h"
#include  "ptr_getter.h"



// GPIO base adresses
constexpr uint32_t gpio_base = 0x40020000;


constexpr uint32_t gpioa_base = gpio_base + 0x0000;
constexpr uint32_t gpiob_base = gpio_base + 0x0400;
constexpr uint32_t gpioc_base = gpio_base + 0x0800;
constexpr uint32_t gpiod_base = gpio_base + 0x0C00;
constexpr uint32_t gpioe_base = gpio_base + 0x1000;
constexpr uint32_t gpiof_base = gpio_base + 0x1400;
constexpr uint32_t gpiog_base = gpio_base + 0x1800;
constexpr uint32_t gpioh_base = gpio_base + 0x1C00;
constexpr uint32_t gpioi_base = gpio_base + 0x2000;




/*
constexpr uint32_t* get_ptr(const uint32_t target_addr, const uint32_t* ptr, const uint32_t ptr_value) {
	return const_cast<uint32_t*> (ptr - (ptr_value >> 2) + (target_addr >> 2));	
}
*/

class Gpio {
public:
	uint32_t base;
	uint32_t* odr, *moder, *idr, *otyper, *ospeedr, *pupdr;
	constexpr Gpio(uint32_t _base, const ptr_getter &p) : 
		odr(p.to_ptr(_base + 0x14)), base(_base), moder(p.to_ptr(_base)), idr(), otyper(), ospeedr(), pupdr(){}
	template<class T>
	void pin_on(T pin_index) const {
		*(this->odr) |= (1 << static_cast<uint32_t>(pin_index));
	}
	
	template<class T> void pin_off(T pin_index) const {
		*(this->odr) &= ~(1 << static_cast<uint32_t>(pin_index));
	}
	
	template<class T> void pin_toggle(T pin_index) const {
		(*this->odr) ^= (1 << static_cast<uint32_t>(pin_index));
	}
};



