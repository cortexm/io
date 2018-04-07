/**
* Peripheral Definition File
*
* SYSMEM - System memory
*
* MCUs containing this peripheral:
*  - STM32F0xx
*/

#pragma once

#include <cstdint>
#include <cstddef>

#include "io/reg/stm32/_common/adc_v2.hpp"

namespace io {

struct Sysmem {

    /** Unique device ID
     */
    struct Uid {
        struct Bits {
            const uint16_t X;  // x-coordinate
            const uint16_t Y;  // y-coordinate
            const uint8_t WAF;  // Wafer number
            const uint8_t LOT[7];  // Lot number
        };

        union {
            uint32_t r[3];
            Bits b;
        };
    };

    volatile const Uid UID;  // Unique device ID (0x1ffff7ac)
    volatile const uint16_t TEMP30_CAL;  // Temperature sensor ADC raw data at 30 degree C (0x1ffff7b8)
    volatile const uint16_t VREFINT_CAL;  // Voltage reference ADC raw data at 30 degree C (0x1ffff7ba)
    uint16_t __res0[3];
    volatile const uint16_t TEMP110_CAL;  // Temperature sensor ADC raw data at 110 degree C (0x1ffff7c2)
    uint16_t __res1[4];
    volatile const uint16_t FLASH_SIZE;  // Flash memory size in KB (0x1ffff7cc)

};

}

namespace io {

namespace base {

static const size_t SYSMEM = 0x1ffff7ac;

}

static Sysmem &SYSMEM = *reinterpret_cast<Sysmem *>(base::SYSMEM);

}
