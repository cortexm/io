/**
* Peripheral Definition File
*
* GPIO - General purpose and alternate function I/Os
*
* MCUs containing this peripheral:
*  - STM32L0xx
*/

#pragma once

#include <cstdint>
#include <cstddef>

#include "io/reg/stm32/_common/gpio_v2.hpp"

namespace io {

namespace base {

static const size_t GPIOA = 0x50000000;
static const size_t GPIOB = 0x50000400;
static const size_t GPIOC = 0x50000800;
static const size_t GPIOD = 0x50000c00;
static const size_t GPIOE = 0x50001000;
static const size_t GPIOH = 0x50001c00;

}

static Gpio &GPIOA = *reinterpret_cast<Gpio *>(base::GPIOA);
static Gpio &GPIOB = *reinterpret_cast<Gpio *>(base::GPIOB);
static Gpio &GPIOC = *reinterpret_cast<Gpio *>(base::GPIOC);
static Gpio &GPIOD = *reinterpret_cast<Gpio *>(base::GPIOD);
static Gpio &GPIOE = *reinterpret_cast<Gpio *>(base::GPIOE);
static Gpio &GPIOH = *reinterpret_cast<Gpio *>(base::GPIOH);

}
