/**
* Peripheral Definition File
*
* DAC - Digital-to-analog converter
*
* MCUs containing this peripheral:
*  - STM32F05x (single channel)
*  - STM32F07x (dual channel)
*  - STM32F09x (dual channel)
*/

#pragma once

#include <cstdint>
#include <cstddef>

namespace io {

struct Dac {
    /** Control register
     */
    struct Cr {
        Cr(const uint32_t raw=0) { r = raw; }

        struct Bits {
            uint32_t EN1 : 1;  // DAC channel 1 enable
            uint32_t BOFF1 : 1;  // DAC channel 1 output buffer disable
            uint32_t TEN1 : 1;  // DAC channel 1 trigger enable
            uint32_t TSEL1 : 3;  // DAC channel 1 trigger selection
            uint32_t WAVE1 : 2;  // DAC channel 1 noise / triangle wave generation enable
            uint32_t MAMP1 : 4;  // DAC channel 1 mask / amplitude selector
            uint32_t DMAEN1 : 1;  // DAC channel 1 DMAenable
            uint32_t DMAUDRIE1 : 1;  // DAC channel 1 DMA Under run Interrupt enable
            uint32_t : 2;
            uint32_t EN2 : 1;  // DAC channel 2 enable
            uint32_t BOFF2 : 1;  // DAC channel 2 output buffer disable
            uint32_t TEN2 : 1;  // DAC channel 2 trigger enable
            uint32_t TSEL2 : 3;  // DAC channel 2 trigger selection
            uint32_t WAVE2 : 2;  // DAC channel 2 noise / triangle wave generation enable
            uint32_t MAMP2 : 4;  // DAC channel 2 mask / amplitude selector
            uint32_t DMAEN2 : 1;  // DAC channel 2 DMAenable
            uint32_t DMAUDRIE2 : 1;  // DAC channel 2 DMA Under run Interrupt enable
            uint32_t : 2;
        };

        struct Tsel {
            static const uint32_t TIMER_3 = 0;  //
            static const uint32_t TIMER_6 = 1;  //
            static const uint32_t TIMER_7 = 2;  //
            static const uint32_t TIMER_15 = 3;  //
            static const uint32_t TIMER_2 = 4;  //
            static const uint32_t EXTI = 6;  //
            static const uint32_t SW = 7;  //
        };

        struct Wave {
            static const uint32_t DISABLED = 0;  // bit order not affected
            static const uint32_t NOISE = 1;  // Bit reversal done by word
            static const uint32_t TRIANGLE = 2;  // Bit reversal done by half-word
        };

        struct Mamp {
            static const uint32_t AMP_1 = 0;  // Unmask bit 0 of LFSR / triangle amplitude equal to 1
            static const uint32_t AMP_3 = 1;  // Unmask bits [1:0] of LFSR / triangle amplitude equal to 3
            static const uint32_t AMP_7 = 2;  // Unmask bits [2:0] of LFSR / triangle amplitude equal to 7
            static const uint32_t AMP_15 = 3;  // Unmask bits [3:0] of LFSR / triangle amplitude equal to 15
            static const uint32_t AMP_31 = 4;  // Unmask bits [4:0] of LFSR / triangle amplitude equal to 31
            static const uint32_t AMP_63 = 5;  // Unmask bits [5:0] of LFSR / triangle amplitude equal to 63
            static const uint32_t AMP_127 = 6;  // Unmask bits [6:0] of LFSR / triangle amplitude equal to 127
            static const uint32_t AMP_255 = 7;  // Unmask bits [7:0] of LFSR / triangle amplitude equal to 255
            static const uint32_t AMP_511 = 8;  // Unmask bits [8:0] of LFSR / triangle amplitude equal to 511
            static const uint32_t AMP_1023 = 9;  // Unmask bits [9:0] of LFSR / triangle amplitude equal to 1023
            static const uint32_t AMP_2047 = 10;  // Unmask bits [10:0] of LFSR / triangle amplitude equal to 2047
            static const uint32_t AMP_4095 = 11;  // Unmask bits [11:0] of LFSR / triangle amplitude equal to 4095
        };

        union {
            uint32_t r;
            Bits b;
        };
    };

    /** DAC software trigger register
     */
    struct Swtrigr {
        Swtrigr(const uint32_t raw=0) { r = raw; }

        struct Bits {
            uint32_t SWTRIG1 : 1;  // DAC channel 1 software trigger
            uint32_t SWTRIG2 : 1;  // DAC channel 1 software trigger
            uint32_t : 30;
        };

        union {
            uint32_t r;
            Bits b;
        };
    };

    /** DAC channel 1 12-bit right-aligned data holding register
     */
    struct Dhr12r1 {
        Dhr12r1(const uint32_t raw=0) { r = raw; }

        union {
            uint32_t r;
            uint32_t DACC1DHR;  // DAC channel 1 12-bit right-aligned data
        };

        void set(uint16_t val1) volatile {
            DACC1DHR = static_cast<uint32_t>(val1);
        }
    };

    /** DAC channel 1 12-bit left-aligned data holding register
     */
    struct Dhr12l1 {
        Dhr12l1(const uint32_t raw=0) { r = raw; }

        union {
            uint32_t r;
            uint32_t DACC1DHR;  // DAC channel 1 12-bit left-aligned data
        };

        void set(uint16_t val1) volatile {
            DACC1DHR = static_cast<uint32_t>(val1);
        }
    };

    /** DAC channel 1 8-bit right-aligned data holding register
     */
    struct Dhr8r1 {
        Dhr8r1(const uint32_t raw=0) { r = raw; }

        union {
            uint32_t r;
            uint32_t DACC1DHR;  // DAC channel 1 8-bit right-aligned data
        };

        void set(uint8_t val1) volatile {
            DACC1DHR = static_cast<uint8_t>(val1);
        }
    };

    /** DAC channel 2 12-bit right-aligned data holding register
     */
    struct Dhr12r2 {
        Dhr12r2(const uint32_t raw=0) { r = raw; }

        union {
            uint32_t r;
            uint32_t DACC2DHR;  // DAC channel 2 12-bit right-aligned data
        };

        void set(uint16_t val2) volatile {
            DACC2DHR = static_cast<uint32_t>(val2);
        }
    };

    /** DAC channel 2 12-bit left-aligned data holding register
     */
    struct Dhr12l2 {
        Dhr12l2(const uint32_t raw=0) { r = raw; }

        union {
            uint32_t r;
            uint32_t DACC2DHR;  // DAC channel 2 12-bit left-aligned data
        };

        void set(uint16_t val2) volatile {
            DACC2DHR = static_cast<uint32_t>(val2);
        }
    };

    /** DAC channel 2 8-bit right-aligned data holding register
     */
    struct Dhr8r2 {
        Dhr8r2(const uint32_t raw=0) { r = raw; }

        union {
            uint32_t r;
            uint32_t DACC2DHR;  // DAC channel 2 8-bit right-aligned data
        };

        void set(uint8_t val2) volatile {
            DACC2DHR = static_cast<uint32_t>(val2);
        }
    };

    /** Dual DAC 12-bit right-aligned data holding register
     */
    struct Dhr12rd {
        Dhr12rd(const uint32_t raw=0) { r = raw; }

        struct Bits {
            uint32_t DACC1DHR : 16;  // DAC channel 1 right-aligned data
            uint32_t DACC2DHR : 16;  // DAC channel 2 right-aligned data
        };

        union {
            uint32_t r;
            Bits b;
        };

        void set(uint16_t val1, uint16_t val2) volatile {
            Dhr12rd reg(0);
            reg.b.DACC1DHR = val1;
            reg.b.DACC2DHR = val2;
            r = reg.r;
        }
    };

    /** Dual DAC 12-bit left-aligned data holding register
     */
    struct Dhr12ld {
        Dhr12ld(const uint32_t raw=0) { r = raw; }

        struct Bits {
            uint32_t DACC1DHR : 16;  // DAC channel 1 left-aligned data
            uint32_t DACC2DHR : 16;  // DAC channel 2 left-aligned data
        };

        union {
            uint32_t r;
            Bits b;
        };

        void set(uint16_t val1, uint16_t val2) volatile {
            Dhr12ld reg(0);
            reg.b.DACC1DHR = val1;
            reg.b.DACC2DHR = val2;
            r = reg.r;
        }
    };

    /** Dual DAC 8-bit right-aligned data holding register
     */
    struct Dhr8rd {
        Dhr8rd(const uint32_t raw=0) { r = raw; }

        struct Bits {
            uint32_t DACC1DHR : 8;  // DAC channel 1 right-aligned data
            uint32_t DACC2DHR : 8;  // DAC channel 2 right-aligned data
            uint32_t : 16;
        };

        union {
            uint32_t r;
            Bits b;
        };

        void set(uint8_t val1, uint8_t val2) volatile {
            Dhr8rd reg(0);
            reg.b.DACC1DHR = val1;
            reg.b.DACC2DHR = val2;
            r = reg.r;
        }
    };

    /** DAC Channel 1 data output register
     */
    struct Dhrdor1 {
        struct Bits {
            const uint32_t DACC1DOR : 16;  // DAC channel 1 data output
            uint32_t : 16;
        };

        union {
            uint32_t r;
            Bits b;
        };
    };

    /** DAC Channel 2 data output register
     */
    struct Dhrdor2 {
        struct Bits {
            const uint32_t DACC2DOR : 16;  // DAC channel 2 data output
            uint32_t : 16;
        };

        union {
            uint32_t r;
            Bits b;
        };
    };

    /** DAC status register
     */
    struct Sr {
        struct Bits {
            uint32_t : 13;
            const uint32_t DMAUDR1 : 1;  // DAC channel 2 data output
            uint32_t : 15;
            const uint32_t DMAUDR2 : 1;  // DAC channel 2 data output
            uint32_t : 2;
        };

        union {
            uint32_t r;
            Bits b;
        };
    };

    volatile Cr CR;  // Control register
    volatile Swtrigr SWTRIGR;  // DAC software trigger register
    volatile Dhr12r1 DHR12R1;  // DAC channel 1 12-bit right-aligned data holding register
    volatile Dhr12l1 DHR12L1;  // DAC channel 1 12-bit left-aligned data holding register
    volatile Dhr8r1 DHR8R1;  // DAC channel 1 8-bit right-aligned data holding register
    volatile Dhr12r2 DHR12R2;  // DAC channel 2 12-bit right-aligned data holding register
    volatile Dhr12l2 DHR12L2;  // DAC channel 2 12-bit left-aligned data holding register
    volatile Dhr8r2 DHR8R2;  // DAC channel 2 8-bit right-aligned data holding register
    volatile Dhr12rd DHR12RD;  // Dual DAC 12-bit right-aligned data holding register
    volatile Dhr12ld DHR12LD;  // Dual DAC 12-bit left-aligned data holding register
    volatile Dhr8rd DHR8RD;  // Dual DAC 8-bit right-aligned data holding register
    volatile Dhrdor1 DHRDOR1;  // DAC Channel 1 data output register
    volatile Dhrdor2 DHRDOR2;  // DAC Channel 2 data output register
    volatile Sr SR;  // DAC status register
};

namespace base {

static constexpr size_t DAC = 0x40007400;

}

static Dac &DAC = *reinterpret_cast<Dac *>(base::DAC);

}
