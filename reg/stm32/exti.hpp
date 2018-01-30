/**
* Peripheral Definition File
*
* EXTI - External Interrupt
*
* MCUs containing this peripheral:
*  - STM32F0xx
*  - STM32F1xx
*  - STM32F2xx
*  - STM32F3xx
*  - STM32F4xx
*  - STM32F7xx
*  - STM32L0xx
*  - STM32L1xx
*  - STM32L4xx - has two EXTI units, see data-sheet
*/

#pragma once

#include <cstdint>
#include <cstddef>

namespace io {

struct Exti {
    struct Mr {
        Mr() {}
        Mr(uint32_t raw) { r = raw; }
        union {
            uint32_t r;
            struct {
                uint32_t MR0 : 1;  // Interrupt or Event mask on external/internal line
                uint32_t MR1 : 1;
                uint32_t MR2 : 1;
                uint32_t MR3 : 1;
                uint32_t MR4 : 1;
                uint32_t MR5 : 1;
                uint32_t MR6 : 1;
                uint32_t MR7 : 1;
                uint32_t MR8 : 1;
                uint32_t MR9 : 1;
                uint32_t MR10 : 1;
                uint32_t MR11 : 1;
                uint32_t MR12 : 1;
                uint32_t MR13 : 1;
                uint32_t MR14 : 1;
                uint32_t MR15 : 1;
                uint32_t MR16 : 1;
                uint32_t MR17 : 1;
                uint32_t MR18 : 1;
                uint32_t MR19 : 1;
                uint32_t MR20 : 1;
                uint32_t MR21 : 1;
                uint32_t MR22 : 1;
                uint32_t MR23 : 1;
                uint32_t MR24 : 1;
                uint32_t MR25 : 1;
                uint32_t MR26 : 1;
                uint32_t MR27 : 1;
                uint32_t MR28 : 1;
                uint32_t MR29 : 1;
                uint32_t MR30 : 1;
                uint32_t MR31 : 1;
            } b;
            uint32_t MR;
        };

        inline void set(const unsigned bit) volatile {
            r |= 1 << bit;
        }

        inline void clr(const unsigned bit) volatile {
            r &= ~(1 << bit);
        }

        inline void set(const unsigned bit, const bool val) volatile {
            if (val) set(bit);
            else clr(bit);
        }
    };

    struct Tr {
        Tr() {}
        Tr(uint32_t raw) { r = raw; }
        union {
            uint32_t r;
            struct {
                uint32_t TR0 : 1;  // Trigger event configuration bit of line
                uint32_t TR1 : 1;
                uint32_t TR2 : 1;
                uint32_t TR3 : 1;
                uint32_t TR4 : 1;
                uint32_t TR5 : 1;
                uint32_t TR6 : 1;
                uint32_t TR7 : 1;
                uint32_t TR8 : 1;
                uint32_t TR9 : 1;
                uint32_t TR10 : 1;
                uint32_t TR11 : 1;
                uint32_t TR12 : 1;
                uint32_t TR13 : 1;
                uint32_t TR14 : 1;
                uint32_t TR15 : 1;
                uint32_t TR16 : 1;
                uint32_t TR17 : 1;
                uint32_t TR18 : 1;
                uint32_t TR19 : 1;
                uint32_t TR20 : 1;
                uint32_t TR21 : 1;
                uint32_t TR22 : 1;
                uint32_t TR23 : 1;
                uint32_t TR24 : 1;
                uint32_t TR25 : 1;
                uint32_t TR26 : 1;
                uint32_t TR27 : 1;
                uint32_t TR28 : 1;
                uint32_t TR29 : 1;
                uint32_t TR30 : 1;
                uint32_t TR31 : 1;
            } b;
        };

        inline void set(const unsigned bit) volatile {
            r |= 1 << bit;
        }

        inline void clr(const unsigned bit) volatile {
            r &= ~(1 << bit);
        }

        inline void set(const unsigned bit, const bool val) volatile {
            if (val) set(bit);
            else clr(bit);
        }
    };

    struct Swier {
        Swier() {}
        Swier(uint32_t raw) { r = raw; }
        union {
            uint32_t r;
            struct {
                uint32_t SWIER0 : 1;  // Software interrupt on line
                uint32_t SWIER1 : 1;
                uint32_t SWIER2 : 1;
                uint32_t SWIER3 : 1;
                uint32_t SWIER4 : 1;
                uint32_t SWIER5 : 1;
                uint32_t SWIER6 : 1;
                uint32_t SWIER7 : 1;
                uint32_t SWIER8 : 1;
                uint32_t SWIER9 : 1;
                uint32_t SWIER10 : 1;
                uint32_t SWIER11 : 1;
                uint32_t SWIER12 : 1;
                uint32_t SWIER13 : 1;
                uint32_t SWIER14 : 1;
                uint32_t SWIER15 : 1;
                uint32_t SWIER16 : 1;
                uint32_t SWIER17 : 1;
                uint32_t SWIER18 : 1;
                uint32_t SWIER19 : 1;
                uint32_t SWIER20 : 1;
                uint32_t SWIER21 : 1;
                uint32_t SWIER22 : 1;
                uint32_t SWIER23 : 1;
                uint32_t SWIER24 : 1;
                uint32_t SWIER25 : 1;
                uint32_t SWIER26 : 1;
                uint32_t SWIER27 : 1;
                uint32_t SWIER28 : 1;
                uint32_t SWIER29 : 1;
                uint32_t SWIER30 : 1;
                uint32_t SWIER31 : 1;
            } b;
        };

        inline void set(const unsigned bit) volatile {
            r |= 1 << bit;
        }

        inline void clr(const unsigned bit) volatile {
            r &= ~(1 << bit);
        }

        inline void set(const unsigned bit, const bool val) volatile {
            if (val) set(bit);
            else clr(bit);
        }
    };

    struct Pr {
        Pr() {}
        Pr(uint32_t raw) { r = raw; }
        union {
            uint32_t r;
            struct {
                uint32_t PR0 : 1;  // Pending bit on line
                uint32_t PR1 : 1;
                uint32_t PR2 : 1;
                uint32_t PR3 : 1;
                uint32_t PR4 : 1;
                uint32_t PR5 : 1;
                uint32_t PR6 : 1;
                uint32_t PR7 : 1;
                uint32_t PR8 : 1;
                uint32_t PR9 : 1;
                uint32_t PR10 : 1;
                uint32_t PR11 : 1;
                uint32_t PR12 : 1;
                uint32_t PR13 : 1;
                uint32_t PR14 : 1;
                uint32_t PR15 : 1;
                uint32_t PR16 : 1;
                uint32_t PR17 : 1;
                uint32_t PR18 : 1;
                uint32_t PR19 : 1;
                uint32_t PR20 : 1;
                uint32_t PR21 : 1;
                uint32_t PR22 : 1;
                uint32_t PR23 : 1;
                uint32_t PR24 : 1;
                uint32_t PR25 : 1;
                uint32_t PR26 : 1;
                uint32_t PR27 : 1;
                uint32_t PR28 : 1;
                uint32_t PR29 : 1;
                uint32_t PR30 : 1;
                uint32_t PR31 : 1;
            } b;
        };

        inline void clr(const unsigned bit) volatile {
            r = 1 << bit;
        }

        inline bool get(const unsigned pin) volatile const {
            return 1 & (r >> pin);
        }
    };

    volatile Mr IMR;
    volatile Mr EMR;
    volatile Tr RTSR;
    volatile Tr FTSR;
    volatile Swier SWIER;
    volatile Pr PR;
};

static inline constexpr Exti &EXTI(const size_t base) {
    return *reinterpret_cast<Exti *>(base);
}

}
