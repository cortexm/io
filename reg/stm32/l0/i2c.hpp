/**
* Peripheral Definition File
*
* I2C - Inter-integrated circuit interface
*
* MCUs containing this peripheral:
*  - STM32F0xx
*/

#pragma once

#include <cstdint>
#include <cstddef>

#include "io/reg/stm32/_common/i2c_v2.hpp"

namespace io {

namespace base {

static const size_t I2C1 = 0x40005400;
static const size_t I2C2 = 0x40005800;
static const size_t I2C3 = 0x40007800;

}

static I2c &I2C1 = *reinterpret_cast<I2c *>(base::I2C1);
static I2c &I2C2 = *reinterpret_cast<I2c *>(base::I2C2);
static I2c &I2C3 = *reinterpret_cast<I2c *>(base::I2C3);

}
