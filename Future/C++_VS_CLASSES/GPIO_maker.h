#include "all_include.h"
#include "GPIO.h"
#include "ptr_getter.h"

// Make GPIOA
constexpr Gpio _gpioa(gpioa_base, p);
Gpio& gpioa = (Gpio)(_gpioa);

// Make GPIOB
constexpr Gpio _gpiob(gpiob_base, p);
Gpio& gpiob = (Gpio)(_gpiob);

// GPIOC
constexpr Gpio _gpioc(gpioc_base, p);
Gpio& gpioc = (Gpio)(_gpioc);

// GPIOD
constexpr Gpio _gpiod(gpiod_base, p);
Gpio& gpiod = (Gpio)(_gpiod);

// GPIOE
constexpr Gpio _gpioe(gpioe_base, p);
Gpio& gpioe = (Gpio)(_gpioe);

// GPIOF
constexpr Gpio _gpiof(gpiof_base, p);
Gpio& gpiof = (Gpio)(_gpiof);

// GPIOG
constexpr Gpio _gpiog(gpiog_base, p);
Gpio& gpiog = (Gpio)(_gpiog);

// GPIOH
constexpr Gpio _gpioh(gpioh_base, p);
Gpio& gpioh = (Gpio)(_gpioh);

// GPIOI
constexpr Gpio _gpioi(gpioi_base, p);
Gpio& gpioi = (Gpio)(_gpioi);

