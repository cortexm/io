/**
* Peripheral Definition File
*
* WWDG - Window watchdog
*
* MCUs containing this peripheral:
*  - STM32F0xx
*  - STM32F1xx
*  - STM32F2xx
*  - STM32F3xx
*  - STM32F4xx
*  - STM32F7xx
*  - STM32L0xx
*  - STM32L1xx
*  - STM32L4xx
*/

#pragma once

#include <cstdint>
#include <cstddef>

namespace io {

struct Wwdg {
    /** Control register
     */
    struct Cr {
        Cr(const uint32_t raw=0) { r = raw; }

        struct Bits {
            uint32_t T : 7;  // 7-bit counter (MSB to LSB)
            uint32_t WDGA : 1;  // Activation bit
            uint32_t : 24;
        };

        union {
            uint32_t r;
            Bits b;
        };
    };

    /** Configuration register
     */
    struct Cfr {
        Cfr(const uint32_t raw=0) { r = raw; }

        struct Bits {
            uint32_t T : 7;  // 7-bit window value
            uint32_t WDGTB : 2;  // Timer base
            uint32_t EWI : 1;  // Early wakeup interrupt
            uint32_t : 22;
        };

        struct Wdgtb {
            static const uint32_t DIV_1 = 0;
            static const uint32_t DIV_2 = 1;
            static const uint32_t DIV_4 = 2;
            static const uint32_t DIV_8 = 3;
        };

        union {
            uint32_t r;
            Bits b;
        };
    };

    /** Status register
     */
    struct Sr {
        Sr(const uint32_t raw=0) { r = raw; }

        struct Bits {
            uint32_t EWIF : 1;  // Early wakeup interrupt flag
            uint32_t : 31;
        };

        union {
            uint32_t r;
            Bits b;
        };
    };

    volatile Cr CR;  // Control register
    volatile Cfr CFR;  // Configuration register
    volatile Sr SR;  // Status register
};

}
