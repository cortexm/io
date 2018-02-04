/**
* Peripheral Definition File
*
* TIMER - Timers
*
* MCUs containing this peripheral:
*  - STM32F0xx
*  - STM32F1xx
*  - STM32F2xx
*  - STM32F4xx
*  - STM32L0xx
*  - STM32L1xx
*
*  author:
*    Pavel Revak
*/

#pragma once

#include <cstdint>
#include <cstddef>

namespace io {

struct Timer {
    /** Control register 1
     */
    struct Cr1 {
        Cr1() {}
        Cr1(uint32_t raw) { r = raw; }
        union {
            uint32_t r;
            struct {
                uint32_t CEN : 1;  // Counter enable
                uint32_t UDIS : 1;  // Update disable
                uint32_t URS : 1;  // Update request source
                uint32_t OPM : 1;  // One pulse mode
                uint32_t DIR : 1;  // Direction
                uint32_t CMS : 2;  // Center-aligned mode selection
                uint32_t ARPE : 1;  // Auto-reload preload enable
                uint32_t CKD : 2;  // Clock division
                uint32_t : 22;
            } b;
        };
    };

    /** Control register 2
     */
    struct Cr2 {
        Cr2() {}
        Cr2(uint32_t raw) { r = raw; }
        union {
            uint32_t r;
            struct {
                uint32_t CCPC : 1;  // Capture/compare preloaded control
                uint32_t : 1;
                uint32_t CCUS : 1;  // Capture/compare control update selection
                uint32_t CCDS : 1;  // Capture/compare DMA selection
                uint32_t MMS : 3;  // Master mode selection
                uint32_t TI1S : 1;  // TI1 selection
                uint32_t OIS1 : 1;  // Output Idle state 1 (OC1 output)
                uint32_t OIS1N : 1;  // Output Idle state 1 (OC1N output)
                uint32_t OIS2 : 1;  // Output Idle state 2 (OC2 output)
                uint32_t OIS2N : 1;  // Output Idle state 2 (OC2N output)
                uint32_t OIS3 : 1;  // Output Idle state 3 (OC3 output)
                uint32_t OIS3N : 1;  // Output Idle state 3 (OC3N output)
                uint32_t OIS4 : 1;  // Output Idle state 4 (OC4 output)
                uint32_t : 17;
            } b;
        };
    };

    /** Slave mode control register
     */
    struct Smcr {
        Smcr() {}
        Smcr(uint32_t raw) { r = raw; }
        union {
            uint32_t r;
            struct {
                uint32_t SMS : 3;  // Slave mode selection
                uint32_t OCCS : 1;  // OCREF clear selection
                uint32_t TS : 3;  // Trigger selection
                uint32_t MSM : 1;  // Master/slave mode
                uint32_t ETF : 4;  // External trigger filter
                uint32_t ETPS : 2;  // External trigger prescaler
                uint32_t ECE : 1;  // External clock enable
                uint32_t ETP : 1;  // External trigger polarity
                uint32_t : 16;
            } b;
        };
    };

    /** DMA/interrupt enable register
     */
    struct Dier {
        Dier() {}
        Dier(uint32_t raw) { r = raw; }
        union {
            uint32_t r;
            struct {
                uint32_t UIE : 1;  // Update interrupt enable
                uint32_t CC1IE : 1;  // Capture/Compare 1 interrupt enable
                uint32_t CC2IE : 1;  // Capture/Compare 2 interrupt enable
                uint32_t CC3IE : 1;  // Capture/Compare 3 interrupt enable
                uint32_t CC4IE : 1;  // Capture/Compare 4 interrupt enable
                uint32_t COMIE : 1;  // COM interrupt enable
                uint32_t TIE : 1;  // Trigger interrupt enable
                uint32_t BIE : 1;  // Break interrupt enable
                uint32_t UDE : 1;  // Update DMA request enable
                uint32_t CC1DE : 1;  // Capture/Compare 1 DMA request enable
                uint32_t CC2DE : 1;  // Capture/Compare 2 DMA request enable
                uint32_t CC3DE : 1;  // Capture/Compare 3 DMA request enable
                uint32_t CC4DE : 1;  // Capture/Compare 4 DMA request enable
                uint32_t COMDE : 1;  // COM DMA request enable
                uint32_t TDE : 1;  // Trigger DMA request enable
                uint32_t : 17;
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
                uint32_t UIF : 1;  // Update interrupt flag
                uint32_t CC1IF : 1;  // Capture/Compare 1 interrupt flag
                uint32_t CC2IF : 1;  // Capture/Compare 2 interrupt flag
                uint32_t CC3IF : 1;  // Capture/Compare 3 interrupt flag
                uint32_t CC4IF : 1;  // Capture/Compare 4 interrupt flag
                uint32_t COMIF : 1;  // COM interrupt flag
                uint32_t TIF : 1;  // Trigger interrupt flag
                uint32_t BIF : 1;  // Break interrupt flag
                uint32_t : 1;
                uint32_t CC1OF : 1;  // Capture/Compare 1 overcapture flag
                uint32_t CC2OF : 1;  // Capture/Compare 2 overcapture flag
                uint32_t CC3OF : 1;  // Capture/Compare 3 overcapture flag
                uint32_t CC4OF : 1;  // Capture/Compare 4 overcapture flag
                uint32_t : 19;
            } b;
        };
    };

    /** Event generation register
     */
    struct Egr {
        Egr() {}
        Egr(uint32_t raw) { r = raw; }
        union {
            uint32_t r;
            struct {
                uint32_t UG : 1;  // Update generation
                uint32_t CC1G : 1;  // Capture/Compare 1 generation
                uint32_t CC2G : 1;  // Capture/Compare 2 generation
                uint32_t CC3G : 1;  // Capture/Compare 3 generation
                uint32_t CC4G : 1;  // Capture/Compare 4 generation
                uint32_t COMG : 1;  // Capture/Compare control update generation
                uint32_t TG : 1;  // Trigger generation
                uint32_t BG : 1;  // Break generation
                uint32_t : 24;
            } b;
        };
    };

    /** Capture/compare mode register
     */
    struct Ccmr {
        Ccmr() {}
        union {
            uint32_t r[2];
            struct {
                uint32_t CC1S : 2;  // Capture/Compare 1 selection
                uint32_t OC1FE : 1;  // Output Compare 1 fast enable
                uint32_t OC1PE : 1;  // Output Compare 1 preload enable
                uint32_t OC1M : 3;  // Output Compare 1 mode
                uint32_t OC1CE : 1;  // Output Compare 1 clear enable
                uint32_t CC2S : 2;  // Capture/Compare 2 selection
                uint32_t OC2FE : 1;  // Output Compare 2 fast enable
                uint32_t OC2PE : 1;  // Output Compare 2 preload enable
                uint32_t OC2M : 3;  // Output Compare 2 mode
                uint32_t OC2CE : 1;  // Output Compare 2 clear enable
                uint32_t : 16;
                uint32_t CC3S : 2;  // Capture/Compare 3 selection
                uint32_t OC3FE : 1;  // Output Compare 3 fast enable
                uint32_t OC3PE : 1;  // Output Compare 3 preload enable
                uint32_t OC3M : 3;  // Output Compare 3 mode
                uint32_t OC3CE : 1;  // Output Compare 3 clear enable
                uint32_t CC4S : 2;  // Capture/Compare 4 selection
                uint32_t OC4FE : 1;  // Output Compare 4 fast enable
                uint32_t OC4PE : 1;  // Output Compare 4 preload enable
                uint32_t OC4M : 3;  // Output Compare 4 mode
                uint32_t OC4CE : 1;  // Output Compare 4 clear enable
                uint32_t : 16;
            } b;
            struct {
                uint32_t : 2;
                uint32_t IC1PSC : 2;  // Input capture 1 prescaler
                uint32_t IC1F : 4;  // Input capture 1 filter
                uint32_t : 2;
                uint32_t IC2PSC : 2;  // Input capture 2 prescaler
                uint32_t IC2F : 4;  // Input capture 2 filter
                uint32_t : 16;
                uint32_t : 2;
                uint32_t IC3PSC : 2;  // Input capture 3 prescaler
                uint32_t IC3F : 4;  // Input capture 3 filter
                uint32_t : 2;
                uint32_t IC4PSC : 2;  // Input capture 4 prescaler
                uint32_t IC4F : 4;  // Input capture 4 filter
                uint32_t : 16;
            } b1;
        };
    };

    /** Capture/compare enable register
     */
    struct Ccer {
        Ccer() {}
        Ccer(uint32_t raw) { r = raw; }
        union {
            uint32_t r;
            struct {
                uint32_t CC1E : 1;  // Capture/Compare 1 output enable
                uint32_t CC1P : 1;  // Capture/Compare 1 output polarity
                uint32_t CC1NE : 1;  // Capture/Compare 1 complementary output enable
                uint32_t CC1NP : 1;  // Capture/Compare 1 complementary output polarity
                uint32_t CC2E : 1;  // Capture/Compare 2 output enable
                uint32_t CC2P : 1;  // Capture/Compare 2 output polarity
                uint32_t CC2NE : 1;  // Capture/Compare 2 complementary output enable
                uint32_t CC2NP : 1;  // Capture/Compare 2 complementary output polarity
                uint32_t CC3E : 1;  // Capture/Compare 3 output enable
                uint32_t CC3P : 1;  // Capture/Compare 3 output polarity
                uint32_t CC3NE : 1;  // Capture/Compare 3 complementary output enable
                uint32_t CC3NP : 1;  // Capture/Compare 3 complementary output polarity
                uint32_t CC4E : 1;  // Capture/Compare 4 output enable
                uint32_t CC4P : 1;  // Capture/Compare 4 output polarity
                uint32_t : 18;
            } b;
        };
    };

    /** Counter value
     */
    struct Cnt {
        union {
            uint32_t r;
            uint32_t CNT;  // 32 bit access
            uint16_t CNT16;  // 16 bit access
        };
    };

    /** Prescaler value
     */
    struct Psc {
        union {
            uint32_t r;
            uint32_t PSC;  // 32 bit access
            uint16_t PSC16;  // 16 bit access
        };
    };

    /** Auto-reload value
     */
    struct Arr {
        union {
            uint32_t r;
            uint32_t ARR;  // 32 bit access
            uint16_t ARR16;  // 16 bit access
        };
    };

    /** Repetition counter value
     */
    struct Rcr {
        union {
            uint32_t r;
            uint32_t RCR;  // 32 bit access
            uint16_t RCR16;  // 16 bit access
        };
    };

    /** Capture/compare register
     */
    struct Ccr {
        union {
            uint32_t r[4];
            struct {
                uint32_t CCR1;  // Capture/Compare 1 value
                uint32_t CCR2;  // Capture/Compare 2 value
                uint32_t CCR3;  // Capture/Compare 3 value
                uint32_t CCR4;  // Capture/Compare 4 value
            } b;
        };
    };

    /** Break and dead-time register
     */
    struct Bdtr {
        Bdtr() {}
        Bdtr(uint32_t raw) { r = raw; }
        union {
            uint32_t r;
            struct {
                uint32_t DTG : 8;  // Dead-time generator setup
                uint32_t LOCK : 2;  // Lock configuration
                uint32_t OSSI : 1;  // Off-state selection for Idle mode
                uint32_t OSSR : 1;  // Off-state selection for Run mode
                uint32_t BKE : 1;  // Break enable
                uint32_t BKP : 1;  // Break polarity
                uint32_t AOE : 1;  // Automatic output enable
                uint32_t MOE : 1;  // Main output enable
                uint32_t : 16;
            } b;
        };
    };

    /** DMA control register
     */
    struct Dcr {
        Dcr() {}
        Dcr(uint32_t raw) { r = raw; }
        union {
            uint32_t r;
            struct {
                uint32_t DBA : 5;  // DMA base address
                uint32_t : 3;
                uint32_t DBL : 5;  // DMA burst length
                uint32_t : 19;
            } b;
        };
    };

    /** DMA address for full transfer
     */
    struct Dmar {
        union {
            uint32_t r;
            uint32_t DMAB;  // DMA register for burst accesses
            uint16_t DMAB16;  // 16 bit access
        };
    };

    volatile Cr1 CR1;  // Control register 1
    volatile Cr2 CR2;  // Control register 2
    volatile Smcr SMCR;  // Slave mode control register
    volatile Dier DIER;  // DMA/interrupt enable register
    volatile Sr SR;  // Status register
    volatile Egr EGR;  // Event generation register
    volatile Ccmr CCMR;  // Capture/compare mode register
    volatile Ccer CCER;  // Capture/compare enable register
    volatile Cnt CNT;  // Counter value
    volatile Psc PSC;  // Prescaler value
    volatile Arr ARR;  // Auto-reload value
    volatile Rcr RCR;  // Repetition counter value
    volatile Ccr CCR;  // Capture/compare register
    volatile Bdtr BDTR;  // Break and dead-time register
    volatile Dcr DCR;  // DMA control register
    volatile Dmar DMAR;  // DMA address for full transfer
};

static inline constexpr Timer &TIMER(const size_t base) {
    return *reinterpret_cast<Timer *>(base);
}

}
