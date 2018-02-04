/**
* Peripheral Definition File
*
* TIMER - Timers
*
* MCUs containing this peripheral:
*  - STM32F0xx
*/

#pragma once

#include <cstdint>
#include <cstddef>

#include "io/reg/stm32/_common/timer.hpp"

namespace io {

namespace base {

static const size_t TIM1 = 0x40012c00;
static const size_t TIM2 = 0x40000000;
static const size_t TIM3 = 0x40000400;
static const size_t TIM6 = 0x40001000;
static const size_t TIM7 = 0x40001400;
static const size_t TIM14 = 0x40002000;
static const size_t TIM15 = 0x40014000;
static const size_t TIM16 = 0x40014400;
static const size_t TIM17 = 0x40014800;

}

static Timer &TIM1 = *reinterpret_cast<Timer *>(base::TIM1);
static Timer &TIM2 = *reinterpret_cast<Timer *>(base::TIM2);
static Timer &TIM3 = *reinterpret_cast<Timer *>(base::TIM3);
static Timer &TIM6 = *reinterpret_cast<Timer *>(base::TIM6);
static Timer &TIM7 = *reinterpret_cast<Timer *>(base::TIM7);
static Timer &TIM14 = *reinterpret_cast<Timer *>(base::TIM14);
static Timer &TIM15 = *reinterpret_cast<Timer *>(base::TIM15);
static Timer &TIM16 = *reinterpret_cast<Timer *>(base::TIM16);
static Timer &TIM17 = *reinterpret_cast<Timer *>(base::TIM17);

}
