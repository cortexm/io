/**
* Peripheral Definition File
*
* SPI - Serial peripheral interface / inter-IC sound
*
* MCUs containing this peripheral:
*  - STM32L0xx
*/

#pragma once

#include <cstdint>
#include <cstddef>

#include "io/reg/stm32/_common/spi_v2.hpp"

namespace io {

namespace base {

static const size_t SPI1 = 0x40013000;
static const size_t SPI2 = 0x40003800;

}

static Spi &SPI1 = *reinterpret_cast<Spi *>(base::SPI1);
static Spi &SPI2 = *reinterpret_cast<Spi *>(base::SPI2);

}
