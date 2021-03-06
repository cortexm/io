/**
* Peripheral Definition File
*
* RTC - Real-time clock
*
* MCUs containing this peripheral:
*  - STM32F0xx
*  - STM32F2xx (partial support)
*  - STM32F3xx
*  - STM32F4xx (partial support)
*  - STM32F46+
*  - STM32F7xx (partial support)
*  - STM32H7xx (partial support)
*  - STM32L0xx (partial support)
*  - STM32L1xx (partial support)
*  - STM32L4xx (partial support)
*/

#pragma once

#include <cstdint>
#include <cstddef>

namespace io {

struct Rtc {
    /** Time register
     */
    struct Tr {
        Tr(const uint32_t raw=0) { r = raw; }

        struct Bits {
            uint32_t SU : 4;  // Second units in BCD format
            uint32_t ST : 3;  // Second tens in BCD format
            uint32_t : 1;
            uint32_t MNU : 4;  // Minute units in BCD format
            uint32_t MNT : 3;  // Minute tens in BCD format
            uint32_t : 1;
            uint32_t HU : 4;  // Hour units in BCD format
            uint32_t HT : 2;  // Hour tens in BCD format
            uint32_t PM : 1;  // AM/PM notation
            uint32_t : 9;
        };

        union {
            uint32_t r;
            Bits b;
        };
    };

    /** Date register
     */
    struct Dr {
        Dr(const uint32_t raw=0) { r = raw; }

        struct Bits {
            uint32_t DU : 4;  // Date units in BCD format
            uint32_t DT : 2;  // Date tens in BCD format
            uint32_t : 2;
            uint32_t MU : 4;  // Month units in BCD format
            uint32_t MT : 1;  // Month tens in BCD format
            uint32_t WDU : 3;  // Week day units
            uint32_t YU : 4;  // Year units in BCD format
            uint32_t YT : 4;  // Year tens in BCD format
            uint32_t : 8;
        };

        union {
            uint32_t r;
            Bits b;
        };
    };

    /** Control register
     */
    struct Cr {
        Cr(const uint32_t raw=0) { r = raw; }

        struct Bits {
            uint32_t WUCKSEL : 3;  // Wakeup clock selection
            uint32_t TSEDGE : 1;  // Time-stamp event active edge
            uint32_t REFCKON : 1;  // RTC_REFIN reference clock detection enable
            uint32_t BYPSHAD : 1;  // Bypass the shadow register (F0, F3, F4, F7, H7, L0, L1, L4)
            uint32_t FMT : 1;  // Hour format
            uint32_t DCE : 1;  // Coarse digital calibration enable (F2, F4, L1)
            uint32_t ALRAE : 1;  // Alarm A enable
            uint32_t ALRBE : 1;  // Alarm B enable (F2, F3, F4, F7, H7, L0, L1, L4)
            uint32_t WUTE : 1;  // Wakeup timer enable
            uint32_t TSE : 1;  // Time-stamp enable
            uint32_t ALRAIE : 1;  // Alarm A interrupt enable
            uint32_t ALRBIE : 1;  // Alarm B interrupt enable (F2, F3, F4, F7, H7, L0, L1, L4)
            uint32_t WUTIE : 1;  // Wakeup timer interrupt enable
            uint32_t TSIE : 1;  // Time-stamp interrupt enable
            uint32_t ADD1H : 1;  // Add one hour
            uint32_t SUB1H : 1;  // Subtract 1 hour
            uint32_t BKP : 1;  // Backup
            uint32_t COSEL : 1;  // Calibration output selection (F0, F4, F7, H7, L0, L1, L4)
            uint32_t POL : 1;  // Output polarity
            uint32_t OSEL : 2;  // Output selection
            uint32_t COE : 1;  // Calibration output enable
            uint32_t ITSE : 1;  // Time-stamp on internal event enable (F7, H7, L4)
            uint32_t : 7;
        };

        union {
            uint32_t r;
            Bits b;
        };
        struct Fmt {
            static const uint32_t HF24 = 0;
            static const uint32_t HF12 = 1;
        };
        struct Wucksel {
            static const uint32_t RTC_16 = 0;
            static const uint32_t RTC_8 = 1;
            static const uint32_t RTC_4 = 2;
            static const uint32_t RTC_2 = 3;
            static const uint32_t CK_SPRE = 4;
            static const uint32_t CK_SPRE_2_16 = 6;
        };
    };

    /** Initialization and status register
     */
    struct Isr {
        Isr(const uint32_t raw=0) { r = raw; }

        struct Bits {
            const uint32_t ALRAWF : 1;  // Alarm A write flag
            const uint32_t ALRBWF : 1;  // Alarm B write flag (F2, F3, F4, F7, H7, L0, L1, L4)
            const uint32_t WUTWF : 1;  // Wakeup timer write flag
            const uint32_t SHPF : 1;  // Shift operation pending (F0, F3, F4, F7, H7, L0, L1, L4)
            const uint32_t INITS : 1;  // Initialization status flag
            uint32_t RSF : 1;  // Registers synchronization flag
            const uint32_t INITF : 1;  // Initialization flag
            uint32_t INIT : 1;  // Initialization mode
            uint32_t ALRAF : 1;  // Alarm A flag
            uint32_t ALRBF : 1;  // Alarm B flag (F2, F3, F4, F7, H7, L0, L1, L4)
            uint32_t WUTF : 1;  // Wakeup timer flag
            uint32_t TSF : 1;  // Time-stamp flag
            uint32_t TSOVF : 1;  // Time-stamp overflow flag
            uint32_t TAMP1F : 1;  // RTC_TAMP1 detection flag
            uint32_t TAMP2F : 1;  // RTC_TAMP2 detection flag (F0, F3, F4, F7, H7, L0, L1, L4)
            uint32_t TAMP3F : 1;  // RTC_TAMP3 detection flag (F0, F3, F4, F7, H7, L0, L1, L4)
            const uint32_t RECALPF : 1;  // Recalibration pending Flag (F0, F3, F4, F7, H7, L0, L1, L4)
            uint32_t ITSF : 1;  // Internal Time-stamp flag (F7, H7, L4)
            uint32_t : 14;
        };

        union {
            uint32_t r;
            Bits b;
        };
    };

    /** Prescaler register
     */
    struct Prer {
        Prer(const uint32_t raw=0) { r = raw; }

        struct Bits {
            uint32_t PREDIV_S : 15;  // Asynchronous prescaler factor
            uint32_t : 1;
            uint32_t PREDIV_A : 7;  // Synchronous prescaler factor
            uint32_t : 9;
        };

        union {
            uint32_t r;
            Bits b;
        };
    };

    /** Wakeup timer register
     */
    struct Wutr {
        Wutr(const uint32_t raw=0) { r = raw; }

        struct Bits {
            uint32_t WUT : 16;  // Wakeup auto-reload value
            uint32_t : 16;
        };

        union {
            uint32_t r;
            uint32_t WUT;
            Bits b;
        };
    };

    /** Calibration register (F2, F4, L1)
     */
    struct Calibr {
        Calibr(const uint32_t raw=0) { r = raw; }

        struct Bits {
            uint32_t DC : 5;  // Digital calibration
            uint32_t : 2;
            uint32_t DCS : 1;  // Digital calibration sign
            uint32_t : 24;
        };

        union {
            uint32_t r;
            Bits b;
        };
    };

     /** Alarm register
     */
    struct Alarmr {
        Alarmr(const uint32_t raw=0) { r = raw; }

        struct Bits {
            uint32_t SU : 4;  // Second units in BCD format
            uint32_t ST : 3;  // Second tens in BCD format
            uint32_t MSK1 : 1;  // Alarm A seconds mask
            uint32_t MNU : 4;  // Minute units in BCD format
            uint32_t MNT : 3;  // Minute tens in BCD format
            uint32_t MSK2 : 1;  // Alarm A minutes mask
            uint32_t HU : 4;  // Hour units in BCD format
            uint32_t HT : 2;  // Hour tens in BCD format
            uint32_t PM : 1;  // AM/PM notation
            uint32_t MSK3 : 1;  // Alarm A hour mask
            uint32_t DU : 4;  // Date units in BCD format
            uint32_t DT : 2;  // Date tens in BCD format
            uint32_t WDSEL : 1;  // Week day selection
            uint32_t MSK4 : 1;  // Alarm A date mask
        };

        union {
            uint32_t r;
            Bits b;
        };
    };

    /** Write protection register
     */
    struct Wpr {
        Wpr(const uint32_t raw=0) { r = raw; }

        struct Bits {
            uint32_t KEY : 8;  // Write protection key
            uint32_t : 24;
        };

        union {
            uint32_t r;
            uint32_t KEY;
            Bits b;
        };
    };

    /** Sub second register (F0, F3, F4, F7, H7, L0, L1, L4)
     */
    struct Ssr {
        Ssr(const uint32_t raw=0) { r = raw; }

        struct Bits {
            const uint32_t SS : 16;  // sub seconds
            uint32_t : 16;
        };

        union {
            uint32_t r;
            Bits b;
        };
    };

    /** Shift control register (F0, F3, F4, F7, H7, L0, L1, L4)
     */
    struct Shiftr {
        Shiftr(const uint32_t raw=0) { r = raw; }

        struct Bits {
            uint32_t SUBFS : 15;  // Subtract a fraction of a second
            uint32_t : 16;
            uint32_t ADD1S : 1;  // Add one second
        };

        union {
            uint32_t r;
            Bits b;
        };
    };

    /** Time-stamp time register
     */
    struct Tstr {
        Tstr(const uint32_t raw=0) { r = raw; }

        struct Bits {
            const uint32_t SU : 4;  // Second units in BCD format
            const uint32_t ST : 3;  // Second tens in BCD format
            uint32_t : 1;
            const uint32_t MNU : 4;  // Minute units in BCD format
            const uint32_t MNT : 3;  // Minute tens in BCD format
            uint32_t : 1;
            const uint32_t HU : 4;  // Hour units in BCD format
            const uint32_t HT : 2;  // Hour tens in BCD format
            const uint32_t PM : 1;  // AM/PM notation
            uint32_t : 9;
        };

        union {
            uint32_t r;
            Bits b;
        };
    };

    /** Time-stamp date register
     */
    struct Tsdr {
        Tsdr(const uint32_t raw=0) { r = raw; }

        struct Bits {
            const uint32_t DU : 4;  // Date units in BCD format
            const uint32_t DT : 2;  // Date tens in BCD format
            uint32_t : 2;
            const uint32_t MU : 4;  // Month units in BCD format
            const uint32_t MT : 1;  // Month tens in BCD format
            const uint32_t WDU : 3;  // Week day units
            uint32_t : 16;
        };

        union {
            uint32_t r;
            Bits b;
        };
    };

    /** Time-stamp sub second register (F0, F3, F4, F7, H7, L0, L1, L4)
     */
    struct Tsssr {
        Tsssr(const uint32_t raw=0) { r = raw; }

        struct Bits {
            const uint32_t SS : 16;  // sub seconds
            uint32_t : 16;
        };

        union {
            uint32_t r;
            Bits b;
        };
    };

    /** Calibration register (F0, F3, F4, F7, H7, L0, L1, L4)
     */
    struct Calr {
        Calr(const uint32_t raw=0) { r = raw; }

        struct Bits {
            uint32_t CALM : 9;  // calibration minus
            uint32_t : 4;
            uint32_t CALW16 : 1;  // Use a 16-second calibration cycle period
            uint32_t CALW8 : 1;  // Use an 8-second calibration cycle period
            uint32_t CALP : 1;  // Increase frequency of RTC by 488.5 ppm
            uint32_t : 16;
        };

        union {
            uint32_t r;
            Bits b;
        };
    };

    /** Tamper and alternate function configuration register (F0, F3, F46+, )
     */
    struct Tafcr {
        Tafcr(const uint32_t raw=0) { r = raw; }

        struct Bits {
            uint32_t TAMP1E : 1;  // RTC_TAMP1 input detection enable
            uint32_t TAMP1TRG : 1;  // Active level for RTC_TAMP1 input
            uint32_t TAMPIE : 1;  // Tamper interrupt enable
            uint32_t TAMP2E : 1;  // RTC_TAMP2 input detection enable
            uint32_t TAMP2TRG : 1;  // Active level for RTC_TAMP2 input
            uint32_t TAMP3E : 1;  // RTC_TAMP3 detection enable
            uint32_t TAMP3TRG : 1;  // Active level for RTC_TAMP3 input
            uint32_t TAMPTS : 1;  // Activate time-stamp on tamper detection event
            uint32_t TAMPFREQ : 3;  // Tamper sampling frequency
            uint32_t TAMPFLT : 2;  // RTC_TAMPx filter count
            uint32_t TAMPPRCH : 2;  // RTC_TAMPx precharge duration
            uint32_t TAMPPUDIS : 1;  // RTC_TAMPx pull-up disable
            uint32_t : 2;
            uint32_t PC13VALUE : 1;  // RTC_ALARM output type/PC13 value
            uint32_t PC13MODE : 1;  // PC13 mode
            uint32_t PC14VALUE : 1;  // PC14 value
            uint32_t PC14MODE : 1;  // PC14 mode
            uint32_t PC15VALUE : 1;  // PC15 value
            uint32_t PC15MODE : 1;  // PC15 mode
            uint32_t : 8;
        };

        union {
            uint32_t r;
            Bits b;
        };
    };

    /** Alarm A sSub second register
     */
    struct Alrmssr {
        Alrmssr(const uint32_t raw=0) { r = raw; }

        struct Bits {
            const uint32_t SS : 15;  // sub seconds
            uint32_t : 9;
            uint32_t MASKSS : 4;  // Mask the most-significant bits starting at this bit
            uint32_t : 4;
        };

        union {
            uint32_t r;
            Bits b;
        };
    };

    volatile Tr TR;  // Time register
    volatile Dr DR;  // Date register
    volatile Cr CR;  // Control register
    volatile Isr ISR;  // Initialization and status register
    volatile Prer PRER;  // Prescaler register
    volatile Wutr WUTR;  // Wakeup timer register
    volatile Calibr CALIBR;  // Calibration register (F2, F4, L1)
    volatile Alarmr ALARMAR;  // Alarm A register
    volatile Alarmr ALARMBR;  // Alarm B register (F2, F3, F4, F7, H7, L0, L1, L4)
    volatile Wpr WPR;  // Write protection register
    volatile Ssr SSR;  // Sub second register (F0, F3, F4, F7, H7, L0, L1, L4)
    volatile Shiftr SHIFTR;  // Shift control register (F0, F3, F4, F7, H7, L0, L1, L4)
    volatile Tstr TSTR;  // Time-stamp time register
    volatile Tsdr TSDR;  // Time-stamp date register
    volatile Tsssr TSSSR;  // Time-stamp sub second register (F0, F3, F4, F7, H7, L0, L1, L4)
    volatile Calr CALR;  // Calibration register (F0, F3, F4, F7, H7, L0, L1, L4)
    volatile Tafcr TAFCR;  // Tamper and alternate function configuration register
    volatile Alrmssr ALRMASSR;  // Alarm A sSub second register
    volatile Alrmssr ALRMBSSR;  // Alarm A sSub second register
    uint32_t __res1;
    volatile uint32_t BKP[32];  // (F0:5, F2:20, F3:32, F4:20, F7:32, L0:5, L1:32, L4:32, H7:32)
};

}
