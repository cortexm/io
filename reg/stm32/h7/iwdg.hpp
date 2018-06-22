/**
* Peripheral Definition File
*
* IWDG - Independent watchdog
*
* MCUs containing this peripheral:
*  - STM32H7xx
*/

#pragma once

#include <cstdint>
#include <cstddef>

#include "io/reg/stm32/_common/iwdg_v2.hpp"

namespace io {

namespace base {

    static constexpr size_t IWDG = 0x58004800;

}

static Iwdg &IWDG = *reinterpret_cast<Iwdg *>(base::IWDG);

}
