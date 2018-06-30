/**
* Peripheral Definition File
*
* IWDG - Independent watchdog
*
* MCUs containing this peripheral:
*  - STM32F0xx
*  - STM32F3xx
*  - STM32F7xx
*  - STM32H7xx
*  - STM32L0xx
*  - STM32L4xx
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

        struct Rl {
            static const uint32_t MAX = 0x00000fff;
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
            const uint32_t WVU : 1;  // Watchdog counter window value update
            uint32_t : 29;
        };

        union {
            uint32_t r;
            Bits b;
        };
    };

    /** Window register
     */
    struct Winr {
        Winr(const uint32_t raw=0) { r = raw; }

        struct Bits {
            uint32_t WIN : 12;  // Watchdog counter reload value
            uint32_t : 20;
        };

        union {
            uint32_t r;
            uint32_t WIN;  // Key value
            uint16_t WIN16;  // 16 bit access
            Bits b;
        };
    };

    volatile Kr KR;  // Key register
    volatile Pr PR;  // Prescaler register
    volatile Rlr RLR;  // Reload register
    volatile Sr SR;  // Status register
    volatile Winr WINR;  // Window register
};

}
