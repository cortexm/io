/**
* Peripheral Definition File
*
* CRC - Cyclic redundancy check calculation unit
*
* MCUs containing this peripheral:
*  - STM32F0xx
*/

#pragma once

#include <cstdint>
#include <cstddef>

namespace io {

struct Crc {
    /** Data register
     */
    struct Dr {
        union {
            uint32_t r;
            uint32_t DR;  // Data register (32-bit)
            uint32_t DR32;  // Data register (32-bit)
            uint16_t DR16;  // Data register (16-bit)
            uint8_t DR8;  // Data register (8-bit)
        };
    };

    /** Independent data register
     */
    struct Idr {
        struct Bits {
            uint32_t IDR : 8;  // General-purpose 8-bit data register bits
            uint32_t : 24;
        };

        union {
            uint32_t r;
            Bits b;
            uint32_t IDR;  // Data register
        };
    };

    /** Control register
     */
    struct Cr {
        Cr(const uint32_t raw=0) { r = raw; }

        struct Bits {
            uint32_t RESET : 1;  // RESET bit
            uint32_t : 2;
            uint32_t POLYSIZE: 2;  // Polynomial size (STM32F07x and STM32F09x)
            uint32_t REVIN : 2;  // Reverse input data
            uint32_t REVOUT: 1;  // Reverse output data
        };

        struct Polysize {
            static const uint32_t POLY_7 = 0;  // 7-bit polynomial
            static const uint32_t POLY_8 = 1;  // 8-bit polynomial
            static const uint32_t POLY_16 = 2;  // 16-bit polynomial
            static const uint32_t POLY_32 = 3;  // 32-bit polynomial
        };

        struct Revin {
            static const uint32_t NO = 0;  // bit order not affected
            static const uint32_t REV_8 = 1;  // Bit reversal done by word
            static const uint32_t REV_16 = 2;  // Bit reversal done by half-word
            static const uint32_t REV_32 = 3;  // Bit reversal done by word
        };

        struct Revout {
            static const uint32_t NO = 0;  // 7-bit polynomial
            static const uint32_t REVERSE = 1;  // Bit-reversed output format
        };

        union {
            uint32_t r;
            Bits b;
        };
    };

    /** Initial CRC value
     */
    struct Init {
        union {
            uint32_t r;
            uint32_t INIT;  // Programmable initial CRC value
        };
    };

    /** CRC polynomial
     */
    struct Pol {
        union {
            uint32_t r;
            uint32_t POL;  // Programmable polynomial (RW for: STM32F07x and STM32F09x)
        };
    };

    volatile Dr DR;  // Data register
    volatile Idr IDR;  // Independent data register
    volatile Cr CR;  // Control register
    volatile Init INIT;  // Initial CRC value
    volatile Pol POL;  // CRC polynomial
};

namespace base {

static constexpr size_t CRC = 0x40023000;

}

static Crc &CRC = *reinterpret_cast<Crc *>(base::CRC);

}
