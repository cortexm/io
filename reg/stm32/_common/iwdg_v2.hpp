/**
* Peripheral Definition File
*
* IWDG - Independent watchdog
*
* MCUs containing this peripheral:
*  - STM32F0xx
*  - STM32F3xx
*  - STM32L0xx
*  - STM32F7xx
*  - STM32L4xx
*  - STM32H7xx
*/

#pragma once

#include <cstdint>
#include <cstddef>

namespace io {

struct Iwdg {
    /** Key register
     */
    struct Kr {
        Kr() {}
        Kr(uint32_t raw) { r = raw; }
        union {
            uint32_t r;
            uint32_t KEY;  // Key value
            uint16_t KEY16;  // 16 bit access
        };
        static const uint32_t WRITE_ACCESS = 0x00005555;
        static const uint32_t REFRESH = 0x0000aaaa;
        static const uint32_t START = 0x0000cccc;
    };

    /** Prescaler register
     */
    struct Pr {
        Pr() {}
        Pr(uint32_t raw) { r = raw; }
        union {
            uint32_t r;
            uint32_t PRE;  // 32 bit access
            uint32_t PRE16;  // 16 bit access
            struct {
                uint32_t PRE : 3;  // prescaler divider
                uint32_t : 29;
            } b;
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
    };

    /** Reload register
     */
    struct Rlr {
        Rlr() {}
        Rlr(uint32_t raw) { r = raw; }
        union {
            uint32_t r;
            uint32_t RL;  // 32 bit access
            uint32_t RL16;  // 16 bit access
            struct {
                uint32_t RL : 12;  // Watchdog counter reload value
                uint32_t : 20;
            } b;
        };
    };

    /** Status register
     */
    struct Sr {
        Sr() {}
        Sr(uint32_t raw) { r = raw; }
        union {
            uint32_t r;
            struct {
                const uint32_t PVU : 1;  // Watchdog prescaler value update
                const uint32_t RVU : 1;  // Watchdog counter reload value update
                const uint32_t WVU : 1;  // Watchdog counter window value update
                uint32_t : 29;
            } b;
        };
    };

    /** Window register
     */
    struct Winr {
        Winr() {}
        Winr(uint32_t raw) { r = raw; }
        union {
            uint32_t r;
            uint32_t WIN;  // Key value
            uint16_t WIN16;  // 16 bit access
        };
    };

    volatile Kr KR;  // Key register
    volatile Pr PR;  // Prescaler register
    volatile Rlr RLR;  // Reload register
    volatile Sr SR;  // Status register
    volatile Winr WINR;  // Window register
};

}
