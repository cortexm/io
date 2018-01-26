/**
* Peripheral Definition File
*
* SYSTICK - SysTick Timer
*
* MCUs containing this peripheral:
*  - Cortex M0
*  - Cortex M0plus
*  - Cortex M3
*  - Cortex M4
*  - Cortex M7
*/

#pragma once

#include <cstdint>
#include <cstddef>

namespace io {

struct Systick {
    /** SysTick control and status register
     */
    struct Csr {
        Csr() {}
        Csr(uint32_t raw) { r = raw; }
        union {
            uint32_t r;
            struct {
                uint32_t ENABLE : 1;  // Counter enable
                uint32_t TICKINT : 1;  // SysTick exception request enable
                uint32_t CLKSOURCE : 1;  // Clock source selection
                uint32_t : 13;
                uint32_t COUNTFLAG : 1;  // Returns 1 if timer counted to 0 since last time this was read.
                uint32_t : 15;
            } b;
        };

        struct Clksource {
            static const uint32_t EXTERNAL = 0;
            static const uint32_t PROCESSOR = 1;
        };
    };

    /** SysTick reload value register
     */
    struct Load {
        union {
            uint32_t r;
            struct {
                uint32_t RELOAD : 24;  // reload value
                uint32_t : 8;
            } b;
            uint32_t RELOAD;  // direct 32 bit access to RELOAD
        };
    };

    /** SysTick current value register
     */
    struct Val {
        union {
            uint32_t r;
            struct {
                uint32_t CURRENT : 24;  // current counter value
                uint32_t : 8;
            } b;
            uint32_t CURRENT;  // direct 32 bit access to COUNTER
        };
    };

    /** SysTick calibration value register
     */
    struct Calib {
        Calib() {}
        Calib(uint32_t raw) { r = raw; }
        union {
            uint32_t r;
            struct {
                const uint32_t TENMS : 24;  // Calibration value
                uint32_t : 6;
                const uint32_t SKEW : 1;  // Indicates whether the TENMS value is exact
                const uint32_t NOREF : 1;  // No reference clock to the processor
            } b;
        };
    };

    volatile Csr CSR;  // SysTick control and status register
    volatile Load LOAD;  // SysTick reload value register
    volatile Val VAL;  // SysTick reload value register
    volatile Calib CALIB;  // SysTick calibration value register

    static constexpr size_t BASE = 0xe000e010;
};

static Systick &SYSTICK = *reinterpret_cast<Systick *>(Systick::BASE);

}
