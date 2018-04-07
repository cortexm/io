/**
* Peripheral Definition File
*
* IWDG - Independent watchdog
*
* MCUs containing this peripheral:
*  - STM32F1xx
*  - STM32F2xx
*  - STM32F4xx
*  - STM32L1xx
*/

#pragma once

#include <cstdint>
#include <cstddef>

namespace io {

struct Iwdg {
    /** Key register
     */
    struct Kr {
        Kr(const uint32_t raw=0) { r = raw; }

        static const uint32_t WRITE_ACCESS = 0x00005555;
        static const uint32_t REFRESH = 0x0000aaaa;
        static const uint32_t START = 0x0000cccc;

        union {
            uint32_t r;
            uint32_t KEY;  // Key value
            uint16_t KEY16;  // 16 bit access
        };
    };

    /** Prescaler register
     */
    struct Pr {
        Pr(const uint32_t raw=0) { r = raw; }

        struct Bits {
            uint32_t PRE : 3;  // prescaler divider
            uint32_t : 29;
        };

        struct Pre {
            static const uint32_t DIV_4 = 0;
            static const uint32_t DIV_8 = 1;
            static const uint32_t DIV_16 = 2;
            static const uint32_t DIV_32 = 3;
            static const uint32_t DIV_64 = 4;
            static const uint32_t DIV_128 = 5;
            static const uint32_t DIV_256 = 6;
        };

        union {
            uint32_t r;
            uint32_t PRE;  // 32 bit access
            uint16_t PRE16;  // 16 bit access
            Bits b;
        };
    };

    /** Reload register
     */
    struct Rlr {
        Rlr(const uint32_t raw=0) { r = raw; }

        struct Bits {
            uint32_t RL : 12;  // Watchdog counter reload value
            uint32_t : 20;
        };

        union {
            uint32_t r;
            uint32_t RL;  // 32 bit access
            uint16_t RL16;  // 16 bit access
            Bits b;
        };
    };

    /** Status register
     */
    struct Sr {
        Sr(const uint32_t raw=0) { r = raw; }

        struct Bits {
            const uint32_t PVU : 1;  // Watchdog prescaler value update
            const uint32_t RVU : 1;  // Watchdog counter reload value update
            uint32_t : 30;
        };

        union {
            uint32_t r;
            Bits b;
        };
    };

    volatile Kr KR;  // Key register
    volatile Pr PR;  // Prescaler register
    volatile Rlr RLR;  // Reload register
    volatile Sr SR;  // Status register
};

}
