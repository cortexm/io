/**
* Peripheral Definition File
*
* RCC - Reset and clock control
*
* MCUs containing this peripheral:
*  - STM32F0xx
*/

#pragma once

#include <cstdint>
#include <cstddef>

namespace io {

struct Rcc {
    /** Clock control register
     */
    struct Cr {
        Cr() {}
        Cr(uint32_t raw) { r = raw; }
        union {
            uint32_t r;
            struct {
                uint32_t HSION : 1;  // HSI clock enable
                const uint32_t HSIRDY : 1;  // HSI clock ready flag
                uint32_t : 1;
                uint32_t HSITRIM : 5;  // HSI clock trimming
                const uint32_t HSICAL : 8;  // HSI clock calibration
                uint32_t HSEON : 1;  // HSE clock enable
                const uint32_t HSERDY : 1;  // HSE clock ready flag
                uint32_t HSEBYP : 1;  // HSE crystal oscillator bypass
                uint32_t CSSON : 1;  // Clock security system enable
                uint32_t : 4;
                uint32_t PLLON : 1;  // PLL enable
                const uint32_t PLLRDY : 1;  // PLL clock ready flag
                uint32_t : 6;
            } b;
        };
    };

    /** Clock configuration register
     */
    struct Cfgr {
        Cfgr() {}
        Cfgr(uint32_t raw) { r = raw; }
        union {
            uint32_t r;
            struct {
                uint32_t SW : 2;  // System clock switch
                uint32_t SWS : 2;  // System clock switch status
                uint32_t HPRE : 4;  // HLCK prescaler
                uint32_t PPRE : 3;  // PCLK prescaler
                uint32_t : 3;
                uint32_t ADCPRE : 1;  // ADC prescaler
                uint32_t PLLSRC : 2;  // PLL input clock source
                uint32_t PLLXTPRE : 1;  // HSE divider for PLL input clock
                uint32_t PLLMUL : 4;  // PLL multiplication factor
                uint32_t : 2;
                uint32_t MCO : 4;  // Microcontroller clock output
                uint32_t MCOPRE : 3;  // Microcontroller Clock Output Prescaler
                uint32_t PLLNODIV : 1;  // PLL clock not divided for MCO
            } b;
        };

        struct Sw {
            static const uint32_t HSI = 0;
            static const uint32_t HSE = 1;
            static const uint32_t PLL = 2;
            static const uint32_t HSI48 = 3;  // (F0x1, F0x2, F0x8)
        };

        struct Hpre {
            static const uint32_t DIV_1 = 0;
            static const uint32_t DIV_2 = 0x8;
            static const uint32_t DIV_4 = 0x9;
            static const uint32_t DIV_8 = 0xa;
            static const uint32_t DIV_16 = 0xb;
            static const uint32_t DIV_64 = 0xc;
            static const uint32_t DIV_128 = 0xd;
            static const uint32_t DIV_256 = 0xe;
            static const uint32_t DIV_512 = 0xf;
        };

        struct Ppre {
            static const uint32_t DIV_1 = 0;
            static const uint32_t DIV_2 = 0x4;
            static const uint32_t DIV_4 = 0x5;
            static const uint32_t DIV_8 = 0x6;
            static const uint32_t DIV_16 = 0x7;
        };

        struct Pllsrc {
            static const uint32_t HSI_DIV_2 = 0;
            static const uint32_t HSI_PREDIV = 1;  // (F0x1, F0x2, F0x8)
            static const uint32_t HSE_PREDIV = 2;
            static const uint32_t HSI48_PREDIV = 3;  // (F0x1, F0x2, F0x8)
        };

        struct Pllmul {
            static const uint32_t MUL_2 = 0x0;
            static const uint32_t MUL_3 = 0x1;
            static const uint32_t MUL_4 = 0x2;
            static const uint32_t MUL_5 = 0x3;
            static const uint32_t MUL_6 = 0x4;
            static const uint32_t MUL_7 = 0x5;
            static const uint32_t MUL_8 = 0x6;
            static const uint32_t MUL_9 = 0x7;
            static const uint32_t MUL_10 = 0x8;
            static const uint32_t MUL_11 = 0x9;
            static const uint32_t MUL_12 = 0xa;
            static const uint32_t MUL_13 = 0xb;
            static const uint32_t MUL_14 = 0xc;
            static const uint32_t MUL_15 = 0xd;
            static const uint32_t MUL_16 = 0xe;
        };

        struct Mco {
            static const uint32_t NOCLOCK = 0x0;
            static const uint32_t HSI14 = 0x1;
            static const uint32_t LSI = 0x2;
            static const uint32_t LSE = 0x3;
            static const uint32_t SYSCLK = 0x4;
            static const uint32_t HSI = 0x5;
            static const uint32_t HSE = 0x6;
            static const uint32_t PLLCLK = 0x7;
            static const uint32_t HSI48 = 0x8;  // (F0x1, F0x2, F0x8)
        };

        struct Mcopre {
            static const uint32_t DIV_1 = 0x0;
            static const uint32_t DIV_2 = 0x1;
            static const uint32_t DIV_4 = 0x2;
            static const uint32_t DIV_8 = 0x3;
            static const uint32_t DIV_16 = 0x4;
            static const uint32_t DIV_32 = 0x5;
            static const uint32_t DIV_64 = 0x6;
            static const uint32_t DIV_128 = 0x7;
        };
    };

    /** Clock interrupt register
     */
    struct Cir {
        Cir() {}
        Cir(uint32_t raw) { r = raw; }
        union {
            uint32_t r;
            struct {
                const uint32_t LSIRDYF : 1;  // LSI ready interrupt flag
                const uint32_t LSERDYF : 1;  // LSE ready interrupt flag
                const uint32_t HSIRDYF : 1;  // HSI ready interrupt flag
                const uint32_t HSERDYF : 1;  // HSE ready interrupt flag
                const uint32_t PLLRDYF : 1;  // PLL ready interrupt flag
                const uint32_t HSI14RDYF : 1;  // HSI14 ready interrupt flag
                const uint32_t HSI48RDYF : 1;  // HSI48 ready interrupt flag (F0x1, F0x2, F0x8)
                const uint32_t CSSF : 1;  // Clock security system interrupt flag
                uint32_t LSIRDYIE : 1;  // LSI ready interrupt enable
                uint32_t LSERDYIE : 1;  // LSE ready interrupt enable
                uint32_t HSIRDYIE : 1;  // HSI ready interrupt enable
                uint32_t HSERDYIE : 1;  // HSE ready interrupt enable
                uint32_t PLLRDYIE : 1;  // PLL ready interrupt enable
                uint32_t HSI14RDYIE : 1;  // HSI14 ready interrupt enable
                uint32_t HSI48RDYIE : 1;  // HSI48 ready interrupt enable (F0x1, F0x2, F0x8)
                uint32_t : 1;
                uint32_t LSIRDYC : 1;  // LSI ready interrupt clear
                uint32_t LSERDYC : 1;  // LSE ready interrupt clear
                uint32_t HSIRDYC : 1;  // HSI ready interrupt clear
                uint32_t HSERDYC : 1;  // HSE ready interrupt clear
                uint32_t PLLRDYC : 1;  // PLL ready interrupt clear
                uint32_t HSI14RDYC : 1;  // HSI14 ready interrupt clear
                uint32_t HSI48RDYC : 1;  // HSI48 Ready Interrupt Clear (F0x1, F0x2, F0x8)
                uint32_t CSSC : 1;  // Clock security system interrupt clear
                uint32_t : 8;
            } b;
        };
    };

    /** AHB peripheral
     * clock enable register
     * reset register
     */
    struct Ahb {
        Ahb() {}
        Ahb(uint32_t raw) { r = raw; }
        union {
            uint32_t r;
            struct {
                uint32_t DMA1 : 1;  // DMA1 (enable)
                uint32_t DMA2 : 1;  // DMA2 (enable) (F0x1, F0x2, F0x8)
                uint32_t SRAM : 1;  // SRAM (enable)
                uint32_t : 1;
                uint32_t FLITF : 1;  // FLITF (enable)
                uint32_t : 1;
                uint32_t CRC : 1;  // CRC (enable)
                uint32_t : 10;
                uint32_t GPIOA : 1;  // I/O port A (enable, reset)
                uint32_t GPIOB : 1;  // I/O port B (enable, reset)
                uint32_t GPIOC : 1;  // I/O port C (enable, reset)
                uint32_t GPIOD : 1;  // I/O port D (enable, reset)
                uint32_t GPIOE : 1;  // I/O port E (enable, reset) (F0x1, F0x2, F0x8)
                uint32_t GPIOF : 1;  // I/O port F (enable, reset)
                uint32_t : 1;
                uint32_t TSC : 1;  // Touch sensing controller (enable, reset) (F0x1, F0x2, F0x8)
                uint32_t : 7;
            } b;
        };
    };

    /** APB2 peripheral
     * clock enable register
     * reset register
     */
    struct Apb2 {
        Apb2() {}
        Apb2(uint32_t raw) { r = raw; }
        union {
            uint32_t r;
            struct {
                uint32_t SYSCFGCOMP : 1;  // SYSCFGCOMP (enable, reset)
                uint32_t : 4;
                uint32_t USART6 : 1;  // USART6 (enable, reset)
                uint32_t USART7 : 1;  // USART7 (enable, reset)
                uint32_t USART8 : 1;  // USART8 (enable, reset)
                uint32_t : 1;
                uint32_t ADC : 1;  // ADC (enable, reset)
                uint32_t : 1;
                uint32_t TIM1 : 1;  // TIM1 (enable, reset)
                uint32_t SPI1 : 1;  // SPI1 (enable, reset)
                uint32_t : 1;
                uint32_t USART1 : 1;  // USART1 (enable, reset)
                uint32_t : 1;
                uint32_t TIM15 : 1;  // TIM15 (enable, reset)
                uint32_t TIM16 : 1;  // TIM16 (enable, reset)
                uint32_t TIM17 : 1;  // TIM17 (enable, reset)
                uint32_t : 3;
                uint32_t DBGMCU : 1;  // DBGMCU (enable, reset)
                uint32_t : 9;
            } b;
        };
    };

    /** APB1 peripheral
     * clock enable register
     * reset register
     */
    struct Apb1 {
        Apb1() {}
        Apb1(uint32_t raw) { r = raw; }
        union {
            uint32_t r;
            struct {
                uint32_t TIM2 : 1;  // TIM2 (enable, reset) (F0x1, F0x2, F0x8)
                uint32_t TIM3 : 1;  // TIM3 (enable, reset)
                uint32_t : 2;
                uint32_t TIM6 : 1;  // TIM6 (enable, reset)
                uint32_t TIM7 : 1;  // TIM7 (enable, reset)
                uint32_t : 2;
                uint32_t TIM14 : 1;  // TIM14 (enable, reset)
                uint32_t : 2;
                uint32_t WWDG : 1;  // WWDG (enable, reset)
                uint32_t : 2;
                uint32_t SPI2 : 1;  // SPI2 (enable, reset)
                uint32_t : 2;
                uint32_t USART2 : 1;  // USART2 (enable, reset)
                uint32_t USART3 : 1;  // USART3 (enable, reset)
                uint32_t USART4 : 1;  // USART4 (enable, reset)
                uint32_t USART5 : 1;  // USART5 (enable, reset)
                uint32_t I2C1 : 1;  // I2C1 (enable, reset)
                uint32_t I2C2 : 1;  // I2C2 (enable, reset)
                uint32_t USB : 1;  // USB (enable, reset)
                uint32_t : 1;
                uint32_t CAN : 1;  // CAN (enable, reset) (F0x1, F0x2, F0x8)
                uint32_t : 1;
                uint32_t CRS : 1;  // CRS (enable, reset) (F0x1, F0x2, F0x8)
                uint32_t PWR : 1;  // PWR (enable, reset)
                uint32_t DAC : 1;  // DAC (enable, reset) (F0x1, F0x2, F0x8)
                uint32_t CEC : 1;  // CEC (enable, reset) (F0x1, F0x2, F0x8)
                uint32_t : 1;
            } b;
        };
    };

    /** RTC domain control register
     */
    struct Bdcr {
        Bdcr() {}
        Bdcr(uint32_t raw) { r = raw; }
        union {
            uint32_t r;
            struct {
                uint32_t LSEON : 1;  // LSE oscillator enable
                const uint32_t LSERDY : 1;  // LSE oscillator ready
                uint32_t LSEBYP : 1;  // LSE oscillator bypass
                uint32_t LSEDRV : 2;  // LSE oscillator drive capability
                uint32_t : 3;
                uint32_t RTCSEL : 2;  // RTC clock source selection
                uint32_t : 5;
                uint32_t RTCEN : 1;  // RTC clock enable
                uint32_t BDRST : 1;  // RTC domain software reset
                uint32_t : 15;
            } b;
        };

        struct Rtcsel {
            static const uint32_t NOCLOCK = 0;
            static const uint32_t LSE = 1;
            static const uint32_t LSI = 2;
            static const uint32_t HSE = 3;
        };
    };

    /** Control/status register
     */
    struct Csr {
        Csr() {}
        Csr(uint32_t raw) { r = raw; }
        union {
            uint32_t r;
            struct {
                uint32_t LSION : 1;  // LSI oscillator enable
                const uint32_t LSIRDY : 1;  // LSI oscillator ready
                uint32_t : 21;
                const uint32_t V18PWRRSTF : 1;  // Reset flag of the 1.8 V domain
                uint32_t RMVF : 1;  // Remove reset flag
                const uint32_t OBLRSTF : 1;  // Option byte loader reset flag
                const uint32_t PINRSTF : 1;  // PIN reset flag
                const uint32_t PORRSTF : 1;  // POR/PDR reset flag
                const uint32_t SFTRSTF : 1;  // Software reset flag
                const uint32_t IWDGRSTF : 1;  // Independent watchdog reset flag
                const uint32_t WWDGRSTF : 1;  // Window watchdog reset flag
                const uint32_t LPWRRSTF : 1;  // Low-power reset flag
            } b;
        };
    };

    /** Clock configuration register 2
     */
    struct Cfgr2 {
        Cfgr2() {}
        Cfgr2(uint32_t raw) { r = raw; }
        union {
            uint32_t r;
            struct {
                uint32_t PREDIV: 4;  // PREDIV division factor
                uint32_t : 28;
            } b;
        };

        struct Prediv {
            static const uint32_t DIV_1 = 0x0;
            static const uint32_t DIV_2 = 0x1;
            static const uint32_t DIV_3 = 0x2;
            static const uint32_t DIV_4 = 0x3;
            static const uint32_t DIV_5 = 0x4;
            static const uint32_t DIV_6 = 0x5;
            static const uint32_t DIV_7 = 0x6;
            static const uint32_t DIV_8 = 0x7;
            static const uint32_t DIV_9 = 0x8;
            static const uint32_t DIV_10 = 0x9;
            static const uint32_t DIV_11 = 0xa;
            static const uint32_t DIV_12 = 0xb;
            static const uint32_t DIV_13 = 0xc;
            static const uint32_t DIV_14 = 0xd;
            static const uint32_t DIV_15 = 0xe;
            static const uint32_t DIV_16 = 0xf;
        };
    };

    /** Clock configuration register 3
     */
    struct Cfgr3 {
        Cfgr3() {}
        Cfgr3(uint32_t raw) { r = raw; }
        union {
            uint32_t r;
            struct {
                uint32_t USART1SW: 2;  // USART1 clock source selection
                uint32_t : 2;
                uint32_t I2C1: 1;  // I2C1 clock source selection
                uint32_t : 1;
                uint32_t CEC: 1;  // HDMI CEC clock source selection (F0x1, F0x2, F0x8)
                uint32_t USB: 1;  // USB clock source selection
                uint32_t ADC: 1;  // ADC clock source selection
                uint32_t : 7;
                uint32_t USART2SW: 2;  // USART2 clock source selection (F0x1, F0x2, F0x8)
                uint32_t USART3SW: 2;  // USART3 clock source selection (F0x1, F0x2, F0x8)
                uint32_t : 12;
            } b;
        };

        struct USARTSW {
            static const uint32_t PCLK = 0;
            static const uint32_t SYSCLK = 1;
            static const uint32_t LSE = 2;
            static const uint32_t HSI = 3;
        };
    };

    /** Clock control register 2
     */
    struct Cr2 {
        Cr2() {}
        Cr2(uint32_t raw) { r = raw; }
        union {
            uint32_t r;
            struct {
                uint32_t HSI14ON : 1;  // HSI14 clock enable
                const uint32_t HSI14RDY : 1;  // HSI14 clock ready flag
                uint32_t HSI14DIS : 1;  // HSI14 clock request from ADC disable
                uint32_t HSI14TRIM : 5;  // HSI14 clock trimming
                const uint32_t HSI14CAL : 8;  // HSI14 clock calibration
                uint32_t HSI48ON : 1;  // HSI48 clock enable (F0x1, F0x2, F0x8)
                const uint32_t HSI48RDY : 1;  // HSI48 clock ready flag (F0x1, F0x2, F0x8)
                uint32_t : 6;
                const uint32_t HSI48CAL : 8;  // HSI48 factory clock calibration (F0x1, F0x2, F0x8)
            } b;
        };
    };

    volatile Cr CR;  // Clock control register
    volatile Cfgr CFGR;  // Clock configuration register
    volatile Cir CIR;  // Clock interrupt register
    volatile Apb2 APB2RSTR;  // APB2 peripheral reset register
    volatile Apb1 APB1RSTR;  // APB1 peripheral reset register
    volatile Ahb AHBENR;  // AHB peripheral clock enable register
    volatile Apb2 APB2ENR;  // APB2 peripheral clock enable register
    volatile Apb1 APB1ENR;  // APB1 peripheral clock enable register
    volatile Bdcr BDCR;  // RTC domain control register
    volatile Csr CSR;  // Control/status register
    volatile Ahb AHBRSTR;  // AHB peripheral reset register
    volatile Cfgr2 CFGR2;  // Clock configuration register 2
    volatile Cfgr3 CFGR3;  // Clock configuration register 3
    volatile Cr2 CR2;  // Clock control register 2

    static constexpr size_t BASE = 0x40021000;
};

static Rcc &RCC = *reinterpret_cast<Rcc *>(Rcc::BASE);

}
