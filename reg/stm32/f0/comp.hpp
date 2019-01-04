/**
* Peripheral Definition File
*
* COMP - Comparator
*
* MCUs containing this peripheral:
*  - STM32F0xx
*/

#pragma once

#include <cstdint>
#include <cstddef>

namespace io {

struct Comp {
    /** Control and status register
     */
    struct Csr {
        struct Bits {
            uint32_t COMP1EN : 1;  // Comparator 1 enable
            uint32_t COMP1SW1 : 1;  // Comparator 1 non inverting input DAC switch
            uint32_t COMP1MODE : 2;  // Comparator 1 mode
            uint32_t COMP1INSEL : 3;  // Comparator 1 inverting input selection
            uint32_t : 1;
            uint32_t COMP1OUTSEL : 3;  // Comparator 1 output selection
            uint32_t COMP1POL : 1;  // Comparator 1 output polarity
            uint32_t COMP1HYST : 2;  // Comparator 1 hysteresis
            const uint32_t COMP1OUT : 1;  // Comparator 1 output
            uint32_t COMP1LOCK : 1;  // Comparator 1 lock
            uint32_t COMP2EN : 1;  // Comparator 2 enable
            uint32_t : 1;
            uint32_t COMP2MODE : 2;  // Comparator 2 mode
            uint32_t COMP2INSEL : 3;  // Comparator 2 inverting input selection
            uint32_t WNDWEN : 1;  // Window mode enable
            uint32_t COMP2OUTSEL : 3;  // Comparator 2 output selection
            uint32_t COMP2POL : 1;  // Comparator 2 output polarity
            uint32_t COMP2HYST : 2;  // Comparator 2 hysteresis
            const uint32_t COMP2OUT : 1;  // Comparator 2 output
            uint32_t COMP2LOCK : 1;  // Comparator 2 lock
        };

        union {
            uint32_t r;
            Bits b;
        };

        struct Compmode {
            static const uint32_t HIGH_SPEED = 0;  // full power
            static const uint32_t MEDIUM_SPEED = 1;  // mediaum power
            static const uint32_t LOW_SPEED = 2;  // low power
            static const uint32_t VERY_LOW_SPEED = 3;  // ultra-low power
        };

        struct Compoutsel {
            static const uint32_t NO_SELECTION = 0;  // No selection
            static const uint32_t TIM1_BREAK = 1;  // Timer 1 break input
            static const uint32_t TIM1_INPUT_CAPTURE1 = 2;  // Timer 1 input capture 1
            static const uint32_t TIM1_OC_REF_CLEAR = 3;  // Timer 1  OC ref clear input
            static const uint32_t TIM2_INPUT_CAPTURE4 = 4;  // Timer 2 input capture 4
            static const uint32_t TIM2_OC_REF_CLEAR = 5;  // Timer 2  OC ref clear input
            static const uint32_t TIM3_INPUT_CAPTURE1 = 6;  // Timer 3 input capture 1
            static const uint32_t TIM3_OC_REF_CLEAR = 7;  // Timer 3  OC ref clear input
        };

        struct Comphyst {
            static const uint32_t NO_HYSTERESIS = 0;  // No hysteresis
            static const uint32_t LOW_HYSTERESIS = 1;  // Low hysteresis
            static const uint32_t MEDIUM_HYSTERESIS = 2;  // Medium hysteresis
            static const uint32_t HIGH_HYSTERESIS = 3;  // High hysteresis
        };

        struct Comp1insel {
            static const uint32_t VREF_1_4 = 0;  // 1/4 Vrefint
            static const uint32_t VREF_1_2 = 1;  // 1/2 Vrefint
            static const uint32_t VREF_3_4 = 2;  // 3/4 Vrefint
            static const uint32_t VREF = 3;  // Vrefint
            static const uint32_t PA4 = 4;  // PA4 (DAC_OUT1)
            static const uint32_t PA5 = 5;  // PA5 (DAC_OUT2)
            static const uint32_t PA0 = 6;  // PA0
        };

        struct Comp2insel {
            static const uint32_t VREF_1_4 = 0;  // 1/4 Vrefint
            static const uint32_t VREF_1_2 = 1;  // 1/2 Vrefint
            static const uint32_t VREF_3_4 = 2;  // 3/4 Vrefint
            static const uint32_t VREF = 3;  // Vrefint
            static const uint32_t PA4 = 4;  // PA4 (DAC_OUT1)
            static const uint32_t PA5 = 5;  // PA5 (DAC_OUT2)
            static const uint32_t PA2 = 6;  // PA2
        };
    };

    volatile Csr CSR;  // Control and status register
};

namespace base {

static constexpr size_t COMP = 0x40010000;

}

static Comp &COMP = *reinterpret_cast<Comp *>(base::COMP);

}
