/**
* Peripheral Definition File
*
* CRS - Clock recovery system
*
* MCUs containing this peripheral:
*  - STM32F04x
*  - STM32F07x
*  - STM32F09x
*/

#pragma once

#include <cstdint>
#include <cstddef>

namespace io {

struct Crs {
    /** Control register
     */
    struct Cr {
        Cr(const uint32_t raw=0) { r = raw; }

        struct Bits {
            uint32_t SYNCOKIE : 1;  // SYNC event OK interrupt enable
            uint32_t SYNCWARNIE: 1;  // SYNC warning interrupt enable
            uint32_t ERRIE : 1;  // Synchronization or trimming error interrupt enable
            uint32_t ESYNCIE: 1;  // Expected SYNC interrupt enable
            uint32_t : 1;
            uint32_t CEN : 1;  // Frequency error counter enable
            uint32_t AUTOTRIMEN : 1;  // Automatic trimming enable
            uint32_t SWSYNC : 1;  // Generate software SYNC event
            uint32_t TRIM : 6;  // HSI48 oscillator smooth trimming
            uint32_t : 18;
        };

        union {
            uint32_t r;
            Bits b;
        };
    };

    /** Configuration register
     */
    struct Cfgr {
        Cfgr(const uint32_t raw=0) { r = raw; }

        struct Bits {
            uint32_t RELOAD : 16;  // Counter reload value
            uint32_t FELIM: 8;  // Frequency error limit
            uint32_t SYNCDIV : 3;  // SYNC divider
            uint32_t : 1;
            uint32_t SYNCSRC : 2;  // SYNC signal source selection
            uint32_t : 1;
            uint32_t SYNCPOL: 1;  // SYNC polarity selection
        };

        union {
            uint32_t r;
            Bits b;
        };
    };

    /** Interrupt and status register
     */
    struct Isr {
        Isr(const uint32_t raw=0) { r = raw; }

        struct Bits {
            const uint32_t SYNCOKF : 1;  // SYNC event OK flag
            const uint32_t SYNCWARNF : 1;  // SYNC warning flag
            const uint32_t ERRF : 1;  // Error flag
            const uint32_t ESYNCF : 1;  // SYNC flag
            const uint32_t : 4;
            const uint32_t SYNCERR : 1;  // SYNC error
            const uint32_t SYNCMISS : 1;  // SYNC missed
            const uint32_t TRIMOVF : 1;  // Trimming overflow or underflow
            const uint32_t : 4;
            const uint32_t FEDIR : 1;  // Frequency error direction
            const uint32_t FECAP : 16;  // Frequency error capture
        };

        union {
            uint32_t r;
            Bits b;
        };
    };

    /** Interrupt flag clear register
     */
    struct Icr {
        Icr(const uint32_t raw=0) { r = raw; }

        struct Bits {
            const uint32_t SYNCOKC : 1;  // SYNC event OK clear flag
            const uint32_t SYNCWARNC : 1;  // SYNC warning clear flag
            const uint32_t ERRC : 1;  // Error clear flag
            const uint32_t ESYNCC : 1;  // SYNC clear flag
            const uint32_t : 28;
        };

        union {
            uint32_t r;
            Bits b;
        };
    };

    volatile Cr CR;  // Control register
    volatile Cfgr CFGR;  // Configuration register
    volatile Isr ISR;  // Interrupt and status register
    volatile Icr ICR;  // Interrupt flag clear register
};

namespace base {

static constexpr size_t CRS = 0x40006c00;

}

static Crs &CRS = *reinterpret_cast<Crs *>(base::CRS);

}
