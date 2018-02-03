/**
* Peripheral Definition File
*
* GPIO - General purpose and alternate function I/Os
*
* MCUs containing this peripheral:
*  - STM32F0xx
*/

#pragma once

#include <cstdint>
#include <cstddef>

#include "io/reg/stm32/_common/gpio_v2.hpp"

namespace io {

namespace base {

static const size_t GPIOA = 0x48000000;
static const size_t GPIOB = 0x48000400;
static const size_t GPIOC = 0x48000800;
static const size_t GPIOD = 0x48000c00;
static const size_t GPIOE = 0x48001000;
static const size_t GPIOF = 0x48001400;

}

static Gpio &GPIOA = *reinterpret_cast<Gpio *>(base::GPIOA);
static Gpio &GPIOB = *reinterpret_cast<Gpio *>(base::GPIOB);
static Gpio &GPIOC = *reinterpret_cast<Gpio *>(base::GPIOC);
static Gpio &GPIOD = *reinterpret_cast<Gpio *>(base::GPIOD);
static Gpio &GPIOE = *reinterpret_cast<Gpio *>(base::GPIOE);
static Gpio &GPIOF = *reinterpret_cast<Gpio *>(base::GPIOF);

}
