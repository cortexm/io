/**
* Peripheral Definition File
*
* IWDG - Independent watchdog
*
* MCUs containing this peripheral:
*  - STM32F7xx
*/

#pragma once

#include <cstdint>
#include <cstddef>

#include "io/reg/stm32/_common/iwdg_v2.hpp"

namespace io {

namespace base {

    static constexpr size_t IWDG = 0x40003000;

}

static Iwdg &IWDG = *reinterpret_cast<Iwdg *>(base::IWDG);

}
