/**
* Peripheral Definition File
*
* ADC - Analog Digital Converter
*
* MCUs containing this peripheral:
*  - STM32F0xx
*  - STM32L0xx
*/

#pragma once

#include <cstdint>
#include <cstddef>

namespace io {

struct Adc {
    /** Interrupt and status register
     */
    struct Isr {
        Isr() {}
        Isr(uint32_t raw) { r = raw; }
        union {
            uint32_t r;
            struct {
                uint32_t ADRDY : 1;  // ADC ready
                uint32_t EOSMP : 1;  // End of sampling flag
                uint32_t EOC : 1;  // End of conversion flag
                uint32_t EOSEQ : 1;  // End of sequence flag
                uint32_t OVR : 1;  // ADC overrun
                uint32_t : 2;
                uint32_t AWD : 1;  // Analog watchdog flag
                uint32_t : 3;
                uint32_t EOCAL : 1;  // End Of Calibration flag (L0)
                uint32_t : 20;
            } b;
        };
    };

    /** Interrupt enable register
     */
    struct Ier {
        Ier() {}
        Ier(uint32_t raw) { r = raw; }
        union {
            uint32_t r;
            struct {
                uint32_t ADRDYIE : 1;  // ADC ready interrupt enable
                uint32_t EOSMPIE : 1;  // End of sampling flag interrupt enable
                uint32_t EOCIE : 1;  // End of conversion interrupt enable
                uint32_t EOSEQIE : 1;  // End of conversion sequence interrupt enable
                uint32_t OVRIE : 1;  // Overrun interrupt enable
                uint32_t : 2;
                uint32_t AWDIE : 1;  // Analog watchdog interrupt enable
                uint32_t : 3;
                uint32_t EOCALIE : 1;  // End Of Calibration flag interrupt enable (L0)
                uint32_t : 20;
            } b;
        };
    };

    /** Control register
     */
    struct Cr {
        Cr() {}
        Cr(uint32_t raw) { r = raw; }
        union {
            uint32_t r;
            struct {
                uint32_t ADEN : 1;  // ADC enable command
                uint32_t ADDIS : 1;  // ADC disable command
                uint32_t ADSTART : 1;  // ADC start conversion command
                uint32_t : 1;
                uint32_t ADSTP : 1;  // ADC stop conversion command
                uint32_t : 23;
                uint32_t ADVREGEN : 1;  // ADC Voltage Regulator Enable (L0)
                uint32_t : 2;
                uint32_t ADCAL : 1;  // ADC calibration
            } b;
        };
    };

    /** Configuration register 1
     */
    struct Cfgr1 {
        Cfgr1() {}
        Cfgr1(uint32_t raw) { r = raw; }
        union {
            uint32_t r;
            struct {
                uint32_t DMAEN : 1;  // Direct memory access enable
                uint32_t DMACFG : 1;  // Direct memory access configuration
                uint32_t SCANDIR : 1;  // Scan sequence direction
                uint32_t RES : 2;  // Data resolution
                uint32_t ALIGN : 1;  // Data alignment
                uint32_t EXTSEL : 3;  // External trigger selection
                uint32_t : 1;
                uint32_t EXTEN : 2;  // External trigger enable and polarity selection
                uint32_t OVRMOD : 1;  // Overrun management mode
                uint32_t CONT : 1;  // Single / continuous conversion mode
                uint32_t WAIT : 1;  // Wait conversion mode
                uint32_t AUTOFF : 1;  // Auto-off mode
                uint32_t DISCEN : 1;  // Discontinuous mode
                uint32_t : 5;
                uint32_t AWDSGL : 1;  // Enable the watchdog on a single channel or on all channels
                uint32_t AWDEN : 1;  // Analog watchdog enable
                uint32_t : 2;
                uint32_t AWDCH : 5;  // Analog watchdog channel selection
                uint32_t : 1;
            } b;
        };
        struct Res {
            static const uint32_t RES_12 = 0;
            static const uint32_t RES_10 = 1;
            static const uint32_t RES_8 = 2;
            static const uint32_t RES_6 = 3;
        };
    };

    /** Configuration register 2
     */
    struct Cfgr2 {
        Cfgr2() {}
        Cfgr2(uint32_t raw) { r = raw; }
        union {
            uint32_t r;
            struct {
                uint32_t OVSE : 1;  // Oversampler Enable (L0)
                uint32_t : 1;
                uint32_t OVSR : 3;  // Oversampling ratio (L0)
                uint32_t OVSS : 4;  // Oversampling shift (L0)
                uint32_t TOVS : 1;  // Triggered Oversampling (L0)
                uint32_t : 20;
                uint32_t CKMODE : 2;  // ADC clock mode
            } b;
        };
        struct Ovsr {
            static const uint32_t OVS_2 = 0;
            static const uint32_t OVS_4 = 1;
            static const uint32_t OVS_8 = 2;
            static const uint32_t OVS_16 = 3;
            static const uint32_t OVS_32 = 4;
            static const uint32_t OVS_64 = 5;
            static const uint32_t OVS_128 = 6;
            static const uint32_t OVS_256 = 7;
        };
        struct Ckmode {
            static const uint32_t ADCCLK = 0;
            static const uint32_t PCLK_DIV2 = 1;
            static const uint32_t PCLK_DIV4 = 2;
        };
    };

    /** Sampling time register
     */
    struct Smpr {
        Smpr() {}
        Smpr(uint32_t raw) { r = raw; }
        union {
            uint32_t r;
            struct {
                uint32_t SMP : 3;  // Sampling time selection
                uint32_t : 29;
            } b;
        };
        struct Smp {
            static const uint32_t SMP_1_5 = 0;
            static const uint32_t SMP_7_5 = 1;
            static const uint32_t SMP_13_5 = 2;
            static const uint32_t SMP_28_5 = 3;
            static const uint32_t SMP_41_5 = 4;
            static const uint32_t SMP_55_5 = 5;
            static const uint32_t SMP_71_5 = 6;
            static const uint32_t SMP_239_5 = 7;
        };
    };

    /** Watchdog threshold register
     */
    struct Tr {
        Tr() {}
        Tr(uint32_t raw) { r = raw; }
        union {
            uint32_t r;
            struct {
                uint32_t LT : 12;  // Analog watchdog lower threshold
                uint32_t : 4;
                uint32_t HT : 12;  // Analog watchdog higher threshold
                uint32_t : 4;
            } b;
        };
    };

    /** Channel selection register
     */
    struct Chselr {
        Chselr() {}
        Chselr(uint32_t raw) { r = raw; }
        union {
            uint32_t r;
            struct {
                uint32_t CHSEL0 : 1;  // Channel selection
                uint32_t CHSEL1 : 1;
                uint32_t CHSEL2 : 1;
                uint32_t CHSEL3 : 1;
                uint32_t CHSEL4 : 1;
                uint32_t CHSEL5 : 1;
                uint32_t CHSEL6 : 1;
                uint32_t CHSEL7 : 1;
                uint32_t CHSEL8 : 1;
                uint32_t CHSEL9 : 1;
                uint32_t CHSEL10 : 1;
                uint32_t CHSEL11 : 1;
                uint32_t CHSEL12 : 1;
                uint32_t CHSEL13 : 1;
                uint32_t CHSEL14 : 1;
                uint32_t CHSEL15 : 1;
                uint32_t CHSEL16 : 1;
                uint32_t CHSEL17 : 1;
                uint32_t CHSEL18 : 1;
                uint32_t : 13;
            } b;
        };
        inline void set(const uint32_t ch) volatile {
            r |= 1 << ch;
        }
        inline void clr(const uint32_t ch) volatile {
            r &= ~(1 << ch);
        }
    };

    /** Data register
     */
    struct Dr {
        union {
            uint32_t r;
            const uint32_t DATA;  // Converted data
        };
    };

    /** Calibration factor register (L0)
     */
    struct Calfactr {
        Calfactr() {}
        Calfactr(uint32_t raw) { r = raw; }
        union {
            uint32_t r;
            struct {
                uint32_t CALFACT : 7;  // Calibration factor
                uint32_t : 25;
            } b;
        };
    };

    /** Common configuration register
     */
    struct Ccr {
        Ccr() {}
        Ccr(uint32_t raw) { r = raw; }
        union {
            uint32_t r;
            struct {
                uint32_t : 22;
                uint32_t VREFEN : 1;  // VREFINT enable
                uint32_t TSEN : 1;  // Temperature sensor enable
                uint32_t VBATEN : 1;  // VBAT enable
                uint32_t : 7;
            } b;
        };
    };

    volatile Isr ISR;  // Interrupt and status register
    volatile Ier IER;  // Interrupt enable register
    volatile Cr CR;  // Control register
    volatile Cfgr1 CFGR1;  // Configuration register 1
    volatile Cfgr2 CFGR2;  // Configuration register 2
    volatile Smpr SMPR;  // Sampling time register
    uint32_t __res0[2];
    volatile Tr TR;  // Watchdog threshold register
    uint32_t __res1;
    volatile Chselr CHSELR;  // Channel selection register
    uint32_t __res2[5];
    volatile Dr DR;  // Data register
    uint32_t __res3[28];
    volatile Calfactr CALFACTR;  // Calibration factor register (L0)
    uint32_t __res4[148];
    volatile Ccr CCR;  // Commong configuration register
};

}
