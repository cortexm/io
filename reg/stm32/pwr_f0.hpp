/**
* Peripheral Definition File
*
* PWR - Power control
*
* MCUs containing this peripheral:
*  - STM32F0xx
*/

#pragma once

#include <cstdint>
#include <cstddef>

namespace io {

struct Pwr {
    /** Power control register
     */
    struct Cr {
        Cr() {}
        Cr(uint32_t raw) { r = raw; }
        union {
            uint32_t r;
            struct {
                uint32_t LPDS : 1;  // Low power deep sleep
                uint32_t PDDS : 1;  // Power down deep sleep
                uint32_t CWUF : 1;  // Clear wakeup flag
                uint32_t CSBF : 1;  // Clear standby flag
                uint32_t PVDE : 1;  // Power voltage detector enable (F0x1, F0x2, F0x8)
                uint32_t PLS : 3;  // PVD level selection (F0x1, F0x2, F0x8)
                uint32_t DBP : 1;  // Disable RTC domain write protection
                uint32_t : 23;
            } b;
        };

        struct Pls {
            static const uint32_t PVD_2_2 = 0;
            static const uint32_t PVD_2_3 = 1;
            static const uint32_t PVD_2_4 = 2;
            static const uint32_t PVD_2_5 = 3;
            static const uint32_t PVD_2_6 = 4;
            static const uint32_t PVD_2_7 = 5;
            static const uint32_t PVD_2_8 = 6;
            static const uint32_t PVD_2_9 = 7;
        };
    };

    /** Power control status register
     */
    struct Csr {
        Csr() {}
        Csr(uint32_t raw) { r = raw; }
        union {
            uint32_t r;
            struct {
                const uint32_t WUF : 1;  // Wakeup flag
                const uint32_t SBF : 1;  // Standby flag
                const uint32_t PVDO : 1;  // PVD output (F0x1, F0x2, F0x8)
                const uint32_t VREFINTRDY : 1;  // VREFINT reference voltage ready (F0x1, F0x2, F0x8)
                uint32_t : 4;
                uint32_t EWUP1 : 1; // Enable WKUPx pins
                uint32_t EWUP2 : 1;
                uint32_t EWUP3 : 1;
                uint32_t EWUP4 : 1;
                uint32_t EWUP5 : 1;
                uint32_t EWUP6 : 1;
                uint32_t EWUP7 : 1;
                uint32_t EWUP8 : 1;
                uint32_t : 16;
            } b;
        };
    };

    volatile Cr CR;  // Power control register
    volatile Csr CSR;  // Power control status register

    static const size_t BASE = 0x40007000;
};

static Pwr &PWR = *reinterpret_cast<Pwr *>(Pwr::BASE);

}
