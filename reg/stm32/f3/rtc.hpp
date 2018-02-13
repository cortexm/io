/**
* Peripheral Definition File
*
* RTC - Real-time clock
*
* MCUs containing this peripheral:
*  - STM32F3xx
*/

#pragma once

#include <cstdint>
#include <cstddef>

#include "io/reg/stm32/_common/rtc_v2.hpp"

namespace io {

namespace base {

static const size_t RTC = 0x40002800;

}

static Rtc &RTC = *reinterpret_cast<Rtc *>(base::RTC);

}
