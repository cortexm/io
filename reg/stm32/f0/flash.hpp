/**
* Peripheral Definition File
*
* FLASH - Flash memory controller
*
* MCUs containing this peripheral:
*  - STM32F0xx
*/

#pragma once

#include <cstdint>
#include <cstddef>

namespace io {

struct Flash {
    /** Flash access control register
     */
    struct Acr {
        Acr(const uint32_t raw=0) { r = raw; }

        struct Bits {
            uint32_t LATENCY : 3;  // Latency
            uint32_t : 1;
            uint32_t PRFTBE : 1;  // Prefetch buffer enable
            const uint32_t PRFTBS : 1;  // Prefetch buffer status
            uint32_t : 26;
        };

        union {
            uint32_t r;
            Bits b;
        };
    };

    /** Flash status register
     */
    struct Sr {
        Sr(const uint32_t raw=0) { r = raw; }

        struct Bits {
            const uint32_t BSY : 1;  // Busy
            uint32_t : 1;
            uint32_t PGERR : 1;  // Programming error
            uint32_t : 1;
            uint32_t WRPRTERR : 1;  // Write protection error
            uint32_t EOP : 1;  // End of operation
            uint32_t : 26;
        };

        union {
            uint32_t r;
            Bits b;
        };
    };

    /** Flash control register
     */
    struct Cr {
        Cr(const uint32_t raw=0) { r = raw; }

        struct Bits {
            uint32_t PG : 1;  // Programming
            uint32_t PER : 1;  // Page erase
            uint32_t MER : 1;  // Mass erase
            uint32_t : 1;
            uint32_t OPTPG : 1;  // Option byte programming
            uint32_t OPTER : 1;  // Option byte erase
            uint32_t STRT : 1;  // Start
            uint32_t LOCK : 1;  // Lock
            uint32_t : 1;
            uint32_t OPTWRE : 1;  // Option byte write enable
            uint32_t ERRIE : 1;  // Error interrupt enable
            uint32_t : 1;
            uint32_t EOPIE : 1;  // End of operation interrupt enable
            uint32_t OBL_LAUNCH : 1;  // Force option byte loading
            uint32_t : 18;
        };

        union {
            uint32_t r;
            Bits b;
        };
    };

    /** Flash option byte register
     */
    struct Obr {
        Obr(const uint32_t raw=0) { r = raw; }

        struct Bits {
            const uint32_t OPTERR : 1;  // Option byte error
            const uint32_t RDPRT : 2;  // Read protection level status
            uint32_t : 5;
            const uint32_t WDG_SW : 1;
            const uint32_t RST_STOP : 1;
            const uint32_t RST_STDBY : 1;
            const uint32_t BOOT0 : 1;
            const uint32_t BOOT1 : 1;
            const uint32_t VDDA_MONITOR : 1;
            const uint32_t RAM_PARITY_CHECK : 1;
            const uint32_t BOOT_SEL : 1;
            const uint32_t DATA0 : 8;
            const uint32_t DATA1 : 8;
        };

        union {
            uint32_t r;
            Bits b;
        };
    };

    volatile Acr ACR;  // Flash access control register
    volatile uint32_t KEYR;  // Flash key register
    volatile uint32_t OPTKEYR;  // Flash option key register
    volatile Sr SR;  // Flash status register
    volatile Cr CR;  // Flash control register
    volatile uint32_t AR;  // Flash address register
    uint32_t __res0;
    volatile Obr OBR;  // Flash option byte register
    volatile uint32_t WRPR;  // Write protection register

    static const size_t BASE = 0x40022000;
};

static Flash &FLASH = *reinterpret_cast<Flash *>(Flash::BASE);

}
