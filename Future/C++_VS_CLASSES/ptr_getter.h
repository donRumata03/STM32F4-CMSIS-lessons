#pragma once

#include "all_include.h"

class ptr_getter
{
private:
	const uint32_t* known_ptr;
	const uint32_t known_ptr_value;
public:
	constexpr ptr_getter(const uint32_t* _known_ptr, const uint32_t _known_ptr_value)
		: known_ptr_value(_known_ptr_value)
		, known_ptr(_known_ptr) {}
	constexpr uint32_t* to_ptr(const uint32_t target_addr) const {
		return const_cast<uint32_t*> (known_ptr - (known_ptr_value >> 2) + (target_addr >> 2));	
	}
};
