/**
* Peripheral Definition File
*
* DMA - Direct Memory Access
*
* MCUs containing this peripheral:
*  - STM32F0xx
*  - STM32F1xx
*  - STM32F3xx
*  - STM32L0xx
*  - STM32L1xx
*  - STM32L4xx
*/

#pragma once

#include <cstdint>
#include <cstddef>

namespace io {

struct Dma {
    /** Interrupt status register
     */
    struct Isr {
        Isr(const uint32_t raw=0) { r = raw; }

        struct Bits {
            const uint32_t GIF1 : 1;  // Global Interrupt Flag
            const uint32_t TCIF1 : 1;  // Transfer Complete Interrupt Flag
            const uint32_t HTIF1 : 1;  // Half Transfer Interrupt Flag
            const uint32_t TEIF1 : 1;  // Transfer Error Interrupt Flag
            const uint32_t GIF2 : 1;
            const uint32_t TCIF2 : 1;
            const uint32_t HTIF2 : 1;
            const uint32_t TEIF2 : 1;
            const uint32_t GIF3 : 1;
            const uint32_t TCIF3 : 1;
            const uint32_t HTIF3 : 1;
            const uint32_t TEIF3 : 1;
            const uint32_t GIF4 : 1;
            const uint32_t TCIF4 : 1;
            const uint32_t HTIF4 : 1;
            const uint32_t TEIF4 : 1;
            const uint32_t GIF5 : 1;
            const uint32_t TCIF5 : 1;
            const uint32_t HTIF5 : 1;
            const uint32_t TEIF5 : 1;
            const uint32_t GIF6 : 1;
            const uint32_t TCIF6 : 1;
            const uint32_t HTIF6 : 1;
            const uint32_t TEIF6 : 1;
            const uint32_t GIF7 : 1;
            const uint32_t TCIF7 : 1;
            const uint32_t HTIF7 : 1;
            const uint32_t TEIF7 : 1;
            uint32_t : 4;
        };

        union {
            uint32_t r;
            Bits b;
        };

        inline bool GIF(const unsigned channel) volatile const {
            return r & 1 << ((channel - 1) << 2);
        }

        inline bool TCIF(const unsigned channel) volatile const {
            return r & 2 << ((channel - 1) << 2);
        }

        inline bool HTIF(const unsigned channel) volatile const {
            return r & 4 << ((channel - 1) << 2);
        }

        inline bool TEIF(const unsigned channel) volatile const {
            return r & 8 << ((channel - 1) << 2);
        }
    };

    /** Interrupt flag clear register
     */
    struct Ifcr {
        Ifcr(const uint32_t raw=0) { r = raw; }

        struct Bits {
            uint32_t CGIF1 : 1;  // Clear Global Interrupt Flag
            uint32_t CTCIF1 : 1;  // Clear Transfer Complete Interrupt Flag
            uint32_t CHTIF1 : 1;  // Clear Half Transfer Interrupt Flag
            uint32_t CTEIF1 : 1;  // Clear Transfer Error Interrupt Flag
            uint32_t CGIF2 : 1;
            uint32_t CTCIF2 : 1;
            uint32_t CHTIF2 : 1;
            uint32_t CTEIF2 : 1;
            uint32_t CGIF3 : 1;
            uint32_t CTCIF3 : 1;
            uint32_t CHTIF3 : 1;
            uint32_t CTEIF3 : 1;
            uint32_t CGIF4 : 1;
            uint32_t CTCIF4 : 1;
            uint32_t CHTIF4 : 1;
            uint32_t CTEIF4 : 1;
            uint32_t CGIF5 : 1;
            uint32_t CTCIF5 : 1;
            uint32_t CHTIF5 : 1;
            uint32_t CTEIF5 : 1;
            uint32_t CGIF6 : 1;
            uint32_t CTCIF6 : 1;
            uint32_t CHTIF6 : 1;
            uint32_t CTEIF6 : 1;
            uint32_t CGIF7 : 1;
            uint32_t CTCIF7 : 1;
            uint32_t CHTIF7 : 1;
            uint32_t CTEIF7 : 1;
            uint32_t : 4;
        };

        static const unsigned GIF = 1;
        static const unsigned TCIF = 2;
        static const unsigned HTIF = 4;
        static const unsigned TEIF = 8;

        union {
            uint32_t r;
            Bits b;
        };

        inline void clear_flags(const unsigned channel, unsigned val=GIF | TCIF | HTIF | TEIF) volatile {
            r = val << ((channel - 1) << 2);
        }

        inline void CGIF(const unsigned channel) volatile {
            clear_flags(channel, GIF);
        }

        inline void CTCIF(const unsigned channel) volatile {
            clear_flags(channel, TCIF);
        }

        inline void CHTIF(const unsigned channel) volatile {
            clear_flags(channel, HTIF);
        }

        inline void CTEIF(const unsigned channel) volatile {
            clear_flags(channel, TEIF);
        }
    };

    /** Channel registers
     */
    struct Channel {
        /** Configuration register
         */
        struct Ccr {
            Ccr(const uint32_t raw=0) { r = raw; }

            struct Bits {
                uint32_t EN : 1;  // Channel Enable
                uint32_t TCIE : 1;  // Transfer Complete Interrupt Enable
                uint32_t HTIE : 1;  // Half Transfer Interrupt Enable
                uint32_t TEIE : 1;  // Transfer Error Interrupt Enable
                uint32_t DIR : 1;  // Direction (0: from peripheral, 1: from memory)
                uint32_t CIRC : 1;  // Circular mode enable
                uint32_t PINC : 1;  // Peripheral Increment mode enable
                uint32_t MINC : 1;  // Memory Increment mode enable
                uint32_t PSIZE : 2;  // Peripheral Size
                uint32_t MSIZE : 2;  // Memory Size
                uint32_t PL : 2;  // Channel Priority (0 - 3 : low - high)
                uint32_t MEM2MEM : 1;  // Memory to Memory mode enable
                uint32_t : 17;
            };

            struct Size {
                static const uint32_t SIZE_8 = 0;
                static const uint32_t SIZE_16 = 1;
                static const uint32_t SIZE_32 = 2;
            };

            struct Pl {
                static const uint32_t LOW = 0;
                static const uint32_t MEDIUM = 1;
                static const uint32_t HIGH = 2;
                static const uint32_t VERY_HIGH = 3;
            };

            union {
                uint32_t r;
                Bits b;
            };
        };

        /** Number of data register
         */
        struct Cndtr {
            union {
                uint32_t r;
                uint32_t NDT;  // Number of Data to Transfer
            };
        };

        /** Peripheral address register
         */
        struct Cpar {
            union {
                uint32_t r;
                size_t PAR;  // Peripheral Address
            };
        };

        /** Memory address register
         */
        struct Cmar {
            union {
                uint32_t r;
                size_t MAR;  // Memory Adress
            };
        };

        volatile Ccr CCR;  // Configuration register
        volatile Cndtr CNDTR;  // Number of data register
        volatile Cpar CPAR;  // Peripheral address register
        volatile Cmar CMAR;  // Memory address register
        uint32_t __res0;
    };

    /** Selection Register
     */
    struct Cselr {
        Cselr(const uint32_t raw=0) { r = raw; }

        struct Bits {
            uint32_t C1S : 4;
            uint32_t C2S : 4;
            uint32_t C3S : 4;
            uint32_t C4S : 4;
            uint32_t C5S : 4;
            uint32_t C6S : 4;
            uint32_t C7S : 4;
            uint32_t : 4;
        };

        union {
            uint32_t r;
            Bits b;
        };

        inline void set(const unsigned channel, const unsigned request) volatile {
            r &= ~(0x0f << (channel << 2));
            r |= (request & 0x0f) << (channel << 2);
        }

        inline unsigned get(const unsigned channel) volatile const {
            return 0x0f & (r >> (channel << 2));
        }
    };

    volatile Isr ISR;  // Interrupt status register
    volatile Ifcr IFCR;  // Interrupt flag clear register
    Channel _CHANNEL[7];  // Channel registers
    uint32_t __res1[20];
    volatile Cselr CSELR;  // Selection Register

    Channel &CHANNEL(const unsigned channel) {
        return _CHANNEL[channel - 1];
    }
};

static inline constexpr Dma &DMA(const size_t base) {
    return *reinterpret_cast<Dma *>(base);
}

}
