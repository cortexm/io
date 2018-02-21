/**
* Peripheral Definition File
*
* WWDG - Independent watchdog
*
* MCUs containing this peripheral:
*  - STM32L4xx
*/

#pragma once

#include <cstdint>
#include <cstddef>

#include "io/reg/stm32/_common/wwdg.hpp"

namespace io {

namespace base {

    static constexpr size_t WWDG = 0x40002c00;

}

static Wwdg &WWDG = *reinterpret_cast<Wwdg *>(base::WWDG);

}
