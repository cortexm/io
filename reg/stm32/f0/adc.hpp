/**
* Peripheral Definition File
*
* ADC - Analog Digital Converter
*
* MCUs containing this peripheral:
*  - STM32F0xx
*/

#pragma once

#include <cstdint>
#include <cstddef>

#include "io/reg/stm32/_common/adc_v2.hpp"

namespace io {

namespace base {

static const size_t ADC = 0x40012400;

}

static Adc &ADC = *reinterpret_cast<Adc *>(base::ADC);

}
