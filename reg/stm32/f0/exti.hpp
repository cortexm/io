/**
* Peripheral Definition File
*
* EXTI
*
* MCUs containing this peripheral:
*  - STM32F0xx
*/

#pragma once

#include <cstdint>
#include <cstddef>

#include "io/reg/stm32/_common/exti.hpp"

namespace io {

namespace base {

static const size_t EXTI = 0x40010400;

}

static Exti &EXTI = *reinterpret_cast<Exti *>(base::EXTI);

}
