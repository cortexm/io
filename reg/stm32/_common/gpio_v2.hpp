/**
* Peripheral Definition File
*
* GPIO - second version
*
* MCUs containing this peripheral:
*  - STM32F0xx
*  - STM32F2xx - no BRR register
*  - STM32F3xx
*  - STM32F4xx - no BRR register
*  - STM32F7xx - no BRR register
*  - STM32H7xx - no BRR register
*  - STM32L0xx
*  - STM32L1xx
*  - STM32L4xx - has ACSR register
*/

#pragma once

#include <cstdint>
#include <cstddef>

namespace io {

struct Gpio {
    /** GPIO port mode register
     */
    struct Moder {
        Moder(const uint32_t raw=0) { r = raw; }

        struct Bits {
            uint32_t MODER0 : 2;  // Port configuration bits
            uint32_t MODER1 : 2;
            uint32_t MODER2 : 2;
            uint32_t MODER3 : 2;
            uint32_t MODER4 : 2;
            uint32_t MODER5 : 2;
            uint32_t MODER6 : 2;
            uint32_t MODER7 : 2;
            uint32_t MODER8 : 2;
            uint32_t MODER9 : 2;
            uint32_t MODER10 : 2;
            uint32_t MODER11 : 2;
            uint32_t MODER12 : 2;
            uint32_t MODER13 : 2;
            uint32_t MODER14 : 2;
            uint32_t MODER15 : 2;
        };

        struct Mode {
            static const uint32_t INPUT = 0;  // Input mode
            static const uint32_t OUTPUT = 1;  // Output mode
            static const uint32_t AF = 2;  // Alternate function mode
            static const uint32_t ANALOG = 3;  // Analog mode
        };

        union {
            uint32_t r;
            Bits b;
            uint32_t MODER;
        };

        inline void set(const unsigned pin, const uint16_t mode) volatile {
            r &= ~(3 << (pin << 1));
            r |= (mode & 3) << (pin << 1);
        }

        inline uint32_t get(const unsigned pin) volatile const {
            return 3 & (r >> (pin << 1));
        }
    };

    /** GPIO port output type register
    */
    struct Otyper {
        Otyper(const uint32_t raw=0) { r = raw; }

        struct Bits {
            uint32_t OTYPER0 : 1;  // Port configuration bits
            uint32_t OTYPER1 : 1;
            uint32_t OTYPER2 : 1;
            uint32_t OTYPER3 : 1;
            uint32_t OTYPER4 : 1;
            uint32_t OTYPER5 : 1;
            uint32_t OTYPER6 : 1;
            uint32_t OTYPER7 : 1;
            uint32_t OTYPER8 : 1;
            uint32_t OTYPER9 : 1;
            uint32_t OTYPER10 : 1;
            uint32_t OTYPER11 : 1;
            uint32_t OTYPER12 : 1;
            uint32_t OTYPER13 : 1;
            uint32_t OTYPER14 : 1;
            uint32_t OTYPER15 : 1;
            uint32_t : 16;
        };

        struct Otype {
            static const uint32_t PUSH_PULL = 0;
            static const uint32_t OPEN_DRAIN = 1;
        };

        union {
            uint32_t r;
            Bits b;
            uint32_t OTYPER;
        };

        inline void set(const unsigned pin, const uint32_t otype) volatile {
            if (otype == Otype::PUSH_PULL)
                r &= ~(1 << pin);
            else
                r |= 1 << pin;
        }

        inline uint32_t get(const unsigned pin) volatile const {
            return 1 & (r >> pin);
        }
    };

    /** GPIO port output speed register
     */
    struct Ospeedr {
        Ospeedr(const uint32_t raw=0) { r = raw; }

        struct Bits {
            uint32_t OSPEEDR0 : 2;  // Port configuration bits
            uint32_t OSPEEDR1 : 2;
            uint32_t OSPEEDR2 : 2;
            uint32_t OSPEEDR3 : 2;
            uint32_t OSPEEDR4 : 2;
            uint32_t OSPEEDR5 : 2;
            uint32_t OSPEEDR6 : 2;
            uint32_t OSPEEDR7 : 2;
            uint32_t OSPEEDR8 : 2;
            uint32_t OSPEEDR9 : 2;
            uint32_t OSPEEDR10 : 2;
            uint32_t OSPEEDR11 : 2;
            uint32_t OSPEEDR12 : 2;
            uint32_t OSPEEDR13 : 2;
            uint32_t OSPEEDR14 : 2;
            uint32_t OSPEEDR15 : 2;
        };

        struct Ospeed {
            static const uint32_t LOW = 0;
            static const uint32_t MEDIUM = 1;
            static const uint32_t FAST = 2;
            static const uint32_t HIGH = 3;
        };

        union {
            uint32_t r;
            Bits b;
            uint32_t OSPEEDR;
        };

        inline void set(const unsigned pin, const uint32_t ospeed) volatile {
            r &= ~(3 << (pin << 1));
            r |= (ospeed & 3) << (pin << 1);
        }

        inline uint32_t get(const unsigned pin) volatile const {
            return 3 & (r >> (pin << 1));
        }
    };

    /** GPIO port pull-up/pull-down register
     */
    struct Pupdr {
        Pupdr(const uint32_t raw=0) { r = raw; }

        struct Bits {
            uint32_t PUPDR0 : 2;  // Port configuration bits
            uint32_t PUPDR1 : 2;
            uint32_t PUPDR2 : 2;
            uint32_t PUPDR3 : 2;
            uint32_t PUPDR4 : 2;
            uint32_t PUPDR5 : 2;
            uint32_t PUPDR6 : 2;
            uint32_t PUPDR7 : 2;
            uint32_t PUPDR8 : 2;
            uint32_t PUPDR9 : 2;
            uint32_t PUPDR10 : 2;
            uint32_t PUPDR11 : 2;
            uint32_t PUPDR12 : 2;
            uint32_t PUPDR13 : 2;
            uint32_t PUPDR14 : 2;
            uint32_t PUPDR15 : 2;
        };

        struct Pupd {
            static const uint32_t OFF = 0;
            static const uint32_t PULL_UP = 1;
            static const uint32_t PULL_DOWN = 2;
        };

        union {
            uint32_t r;
            Bits b;
            uint32_t PUPDR;
        };

        inline void set(const unsigned pin, const uint32_t pupd) volatile {
            r &= ~(3 << (pin << 1));
            r |= (pupd & 3) << (pin << 1);
        }

        inline uint32_t get(const unsigned pin) volatile const {
            return 3 & (r >> (pin << 1));
        }
    };

    /** GPIO port input data register
     */
    struct Idr {
        Idr(const uint32_t raw=0) { r = raw; }

        struct Bits {
            const uint32_t IDR0 : 1;  // Port input data bits
            const uint32_t IDR1 : 1;
            const uint32_t IDR2 : 1;
            const uint32_t IDR3 : 1;
            const uint32_t IDR4 : 1;
            const uint32_t IDR5 : 1;
            const uint32_t IDR6 : 1;
            const uint32_t IDR7 : 1;
            const uint32_t IDR8 : 1;
            const uint32_t IDR9 : 1;
            const uint32_t IDR10 : 1;
            const uint32_t IDR11 : 1;
            const uint32_t IDR12 : 1;
            const uint32_t IDR13 : 1;
            const uint32_t IDR14 : 1;
            const uint32_t IDR15 : 1;
            uint32_t : 16;
        };

        union {
            uint32_t r;
            Bits b;
            uint32_t IDR;
        };

        inline bool get(const unsigned pin) volatile const {
            return 1 & (r >> pin);
        }
    };

    /** GPIO port output data register
     */
    struct Odr {
        Odr(const uint32_t raw=0) { r = raw; }

        struct Bits {
            uint32_t ODR0 : 1;  // Port output data bits
            uint32_t ODR1 : 1;
            uint32_t ODR2 : 1;
            uint32_t ODR3 : 1;
            uint32_t ODR4 : 1;
            uint32_t ODR5 : 1;
            uint32_t ODR6 : 1;
            uint32_t ODR7 : 1;
            uint32_t ODR8 : 1;
            uint32_t ODR9 : 1;
            uint32_t ODR10 : 1;
            uint32_t ODR11 : 1;
            uint32_t ODR12 : 1;
            uint32_t ODR13 : 1;
            uint32_t ODR14 : 1;
            uint32_t ODR15 : 1;
            uint32_t : 16;
        };

        union {
            uint32_t r;
            Bits b;
            uint32_t ODR;
        };

        inline bool get(const unsigned pin) volatile const {
            return 1 & (r >> pin);
        }
    };

    /** GPIO port bit set/reset register
     */
    struct Bsrr {
        Bsrr(const uint32_t raw=0) { r = raw; }

        struct Bits {
            uint32_t BS0 : 1;  // Port set bits
            uint32_t BS1 : 1;
            uint32_t BS2 : 1;
            uint32_t BS3 : 1;
            uint32_t BS4 : 1;
            uint32_t BS5 : 1;
            uint32_t BS6 : 1;
            uint32_t BS7 : 1;
            uint32_t BS8 : 1;
            uint32_t BS9 : 1;
            uint32_t BS10 : 1;
            uint32_t BS11 : 1;
            uint32_t BS12 : 1;
            uint32_t BS13 : 1;
            uint32_t BS14 : 1;
            uint32_t BS15 : 1;
            uint32_t BR0 : 1;  // Port reset bits
            uint32_t BR1 : 1;
            uint32_t BR2 : 1;
            uint32_t BR3 : 1;
            uint32_t BR4 : 1;
            uint32_t BR5 : 1;
            uint32_t BR6 : 1;
            uint32_t BR7 : 1;
            uint32_t BR8 : 1;
            uint32_t BR9 : 1;
            uint32_t BR10 : 1;
            uint32_t BR11 : 1;
            uint32_t BR12 : 1;
            uint32_t BR13 : 1;
            uint32_t BR14 : 1;
            uint32_t BR15 : 1;
        };

        struct HalfWords {
            uint16_t BS;
            uint16_t BR;
        };

        union {
            uint32_t r;
            Bits b;
            HalfWords h;
        };

        inline void set(const unsigned pin) volatile {
            h.BS = 1 << pin;
        }

        inline void clr(const unsigned pin) volatile {
            h.BR = 1 << pin;
        }
    };

    /** GPIO port configuration lock register
     */
    struct Lckr {
        Lckr(const uint32_t raw=0) { r = raw; }

        struct Bits {
            uint32_t LCK0 : 1;  // Port lock bits
            uint32_t LCK1 : 1;
            uint32_t LCK2 : 1;
            uint32_t LCK3 : 1;
            uint32_t LCK4 : 1;
            uint32_t LCK5 : 1;
            uint32_t LCK6 : 1;
            uint32_t LCK7 : 1;
            uint32_t LCK8 : 1;
            uint32_t LCK9 : 1;
            uint32_t LCK10 : 1;
            uint32_t LCK11 : 1;
            uint32_t LCK12 : 1;
            uint32_t LCK13 : 1;
            uint32_t LCK14 : 1;
            uint32_t LCK15 : 1;
            uint32_t LCKK : 1;  // Lock key
            uint32_t : 15;
        };

        union {
            uint32_t r;
            Bits b;
        };
    };

    /** GPIO alternate function low register
     */
    struct Afr {
        Afr(const uint64_t raw=0) { r64 = raw; }

        struct Bits {
            uint32_t AFR0 : 4;  // Alternate function selection for pin
            uint32_t AFR1 : 4;
            uint32_t AFR2 : 4;
            uint32_t AFR3 : 4;
            uint32_t AFR4 : 4;
            uint32_t AFR5 : 4;
            uint32_t AFR6 : 4;
            uint32_t AFR7 : 4;
            uint32_t AFR8 : 4;
            uint32_t AFR9 : 4;
            uint32_t AFR10 : 4;
            uint32_t AFR11 : 4;
            uint32_t AFR12 : 4;
            uint32_t AFR13 : 4;
            uint32_t AFR14 : 4;
            uint32_t AFR15 : 4;
        };

        union {
            uint32_t r[2];
            uint64_t r64;
            Bits b;
            uint64_t AFR;
        };

        inline void set(const unsigned pin, const unsigned af) volatile {
            uint32_t tmp = r[pin >> 3];
            tmp &= ~ (0x0f << ((pin & 7) << 2));
            tmp |= (af & 0xf) << ((pin & 7) << 2);
            r[pin >> 3] = tmp;
        }

        inline unsigned get(const unsigned pin) volatile const {
            return 0xf & (r[pin >> 3] >> ((pin & 7) << 2));
        }
    };

    /** GPIO port bit reset register
     */
    struct Brr {
        Brr(const uint32_t raw=0) { r = raw; }

        struct Bits {
            uint32_t BR0 : 1;  // Port reset bits
            uint32_t BR1 : 1;
            uint32_t BR2 : 1;
            uint32_t BR3 : 1;
            uint32_t BR4 : 1;
            uint32_t BR5 : 1;
            uint32_t BR6 : 1;
            uint32_t BR7 : 1;
            uint32_t BR8 : 1;
            uint32_t BR9 : 1;
            uint32_t BR10 : 1;
            uint32_t BR11 : 1;
            uint32_t BR12 : 1;
            uint32_t BR13 : 1;
            uint32_t BR14 : 1;
            uint32_t BR15 : 1;
            uint32_t : 16;
        };

        union {
            uint32_t r;
            Bits b;
            uint16_t BR;
        };

        inline void clr(const unsigned pin) volatile {
            BR = 1 << pin;
        }
    };

    /** GPIO port analog switch control register
    */
    struct Acsr {
        Acsr(const uint32_t raw=0) { r = raw; }

        struct Bits {
            uint32_t ACS0 : 1;  // Port configuration bits
            uint32_t ACS1 : 1;
            uint32_t ACS2 : 1;
            uint32_t ACS3 : 1;
            uint32_t ACS4 : 1;
            uint32_t ACS5 : 1;
            uint32_t ACS6 : 1;
            uint32_t ACS7 : 1;
            uint32_t ACS8 : 1;
            uint32_t ACS9 : 1;
            uint32_t ACS10 : 1;
            uint32_t ACS11 : 1;
            uint32_t ACS12 : 1;
            uint32_t ACS13 : 1;
            uint32_t ACS14 : 1;
            uint32_t ACS15 : 1;
            uint32_t : 16;
        };

        struct Acs {
            static const uint32_t DISCONNECTED = 0;
            static const uint32_t CONNECTED = 1;
        };

        union {
            uint32_t r;
            Bits b;
            uint32_t ACS;
        };

        inline void set(const unsigned pin, const uint32_t acs) volatile {
            if (acs == Acs::CONNECTED)
                r &= ~(1 << pin);
            else
                r |= 1 << pin;
        }

        inline uint32_t get(const unsigned pin) volatile const {
            return 1 & (r >> pin);
        }
    };
    volatile Moder MODER;  // GPIO port mode register
    volatile Otyper OTYPER;  // GPIO port output type register
    volatile Ospeedr OSPEEDR;  // GPIO port output speed register
    volatile Pupdr PUPDR;  // GPIO port pull-up/pull-down register
    volatile Idr IDR;  // GPIO port input data register
    volatile Odr ODR;  // GPIO port output data register
    volatile Bsrr BSRR;  // GPIO port bit set/reset register
    volatile Lckr LCKR;  // GPIO port configuration lock register
    volatile Afr AFR;  // GPIO alternate function low register
    volatile Brr BRR;  // GPIO port bit reset register (F0, F3, L0, L1, L4)
    volatile Acsr ACSR;  // GPIO port analog switch control register (L4)
};

static inline constexpr Gpio &GPIO(const size_t base) {
    return *reinterpret_cast<Gpio *>(base);
}

}
