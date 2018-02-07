/**
* Peripheral Definition File
*
* DMA - Direct memory access controller
*
* MCUs containing this peripheral:
*  - STM32L0xx
*/

#pragma once

#include <cstdint>
#include <cstddef>

#include "io/reg/stm32/_common/dma_v1.hpp"

namespace io {

namespace base {

static const size_t DMA1 = 0x40026000;
static const size_t DMA2 = 0x40026400;

}

static Dma &DMA1 = *reinterpret_cast<Dma *>(base::DMA1);
static Dma &DMA2 = *reinterpret_cast<Dma *>(base::DMA2);

}
