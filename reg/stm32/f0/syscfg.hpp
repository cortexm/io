/**
* Peripheral Definition File
*
* SYSCFG - System configuration controller
*
* MCUs containing this peripheral:
*  - STM32F0xx
*/

#pragma once

#include <cstdint>
#include <cstddef>

namespace io {

struct Syscfg {
    /** configuration register 1
     */
    struct Cfgr1 {
        Cfgr1(const uint32_t raw=0) { r = raw; }

        struct Bits {
            uint32_t MEM_MODE : 2;  // Memory mapping selection bits
            uint32_t : 2;
            uint32_t PA11_PA12_RMP : 1;  // remap PA11 an PA12
            uint32_t : 3;
            uint32_t ADC_DMA_RMP : 1;  // remap ADC DMA
            uint32_t USART1_TX_DMA_RMP : 1;  // remap USART1 TX DMA
            uint32_t USART1_RX_DMA_RMP : 1;  // remap USART1 RX DMA
            uint32_t TIM16_DMA_RMP : 1;  // remap TIM16 DMA
            uint32_t TIM17_DMA_RMP : 1;  // remap TIM17 DMA
            uint32_t TIM16_DMA_RMP2 : 1;  // alternate remap TIM16 DMA
            uint32_t TIM17_DMA_RMP2 : 1;  // alternate remap TIM17 DMA
            uint32_t : 1;
            uint32_t I2C_PB6_FMP : 1;  // enable fast mode plus on I2C PA6
            uint32_t I2C_PB7_FMP : 1;  // enable fast mode plus on I2C PA7
            uint32_t I2C_PB8_FMP : 1;  // enable fast mode plus on I2C PA8
            uint32_t I2C_PB9_FMP : 1;  // enable fast mode plus on I2C PA9
            uint32_t I2C1_FMP : 1;  // enable fast mode plus on I2C1
            uint32_t I2C2_FMP : 1;  // enable fast mode plus on I2C2
            uint32_t I2C_PA9_FMP : 1;  // enable fast mode plus on I2C PA9
            uint32_t I2C_PA10_FMP : 1;  // enable fast mode plus on I2C PA10
            uint32_t SPI2_DMA_RMP : 1;  // remap SPI2 DMA
            uint32_t USART2_DMA_RMP : 1;  // remap USART2 DMA
            uint32_t USART3_DMA_RMP : 1;  // remap USART3 DMA
            uint32_t I2C1_DMA_RMP : 1;  // remap I2C1 DMA
            uint32_t TIM1_DMA_RMP : 1;  // remap TIM1 DMA
            uint32_t TIM2_DMA_RMP : 1;  // remap TIM2 DMA
            uint32_t TIM3_DMA_RMP : 1;  // remap TIM3 DMA
            uint32_t : 1;
        };

        struct Memmode {
            static const uint32_t FLASH = 0;
            static const uint32_t SYSTEM = 1;
            static const uint32_t SRAM = 3;
        };

        union {
            uint32_t r;
            Bits b;
        };
    };

    /** external interrupt configuration register 1
     */
    struct Exticr {
        Afr() {
            for (int i = 0; i < 4) {
                r[i] = 0;
            }
        }

        Afr(Acr &acr) {
            for (int i = 0; i < 4) {
                r[i] = acr.r[i];
            }
        }

        struct Bits {
            uint16_t EXTI0 : 4;  // select EXTI source
            uint16_t EXTI1 : 4;
            uint16_t EXTI2 : 4;
            uint16_t EXTI3 : 4;
            uint16_t : 16;
            uint16_t EXTI4 : 4;
            uint16_t EXTI5 : 4;
            uint16_t EXTI6 : 4;
            uint16_t EXTI7 : 4;
            uint16_t : 16;
            uint16_t EXTI8 : 4;
            uint16_t EXTI9 : 4;
            uint16_t EXTI10 : 4;
            uint16_t EXTI11 : 4;
            uint16_t : 16;
            uint16_t EXTI12 : 4;
            uint16_t EXTI13 : 4;
            uint16_t EXTI14 : 4;
            uint16_t EXTI15 : 4;
            uint16_t : 16;
        };

        struct Exti {
            static const uint32_t GPIOA = 0;
            static const uint32_t GPIOB = 1;
            static const uint32_t GPIOC = 2;
            static const uint32_t GPIOD = 3;
            static const uint32_t GPIOE = 4;
            static const uint32_t GPIOF = 5;
        };

        union {
            uint32_t r[4];
            Bits b;
        };
    };

    /** configuration register 2
     */
    struct Cfgr2 {
        Cfgr2(const uint32_t raw=0) { r = raw; }

        struct Bits {
            uint32_t LOCKUP_LOCK : 1;  // Cortex-M0 LOCKUP bit enable bit
            uint32_t SRAM_PARITY_LOCK : 1;  // SRAM parity lock bit
            uint32_t PVD_LOCK : 1;  // PVD lock enable bit
            uint32_t : 5;
            uint32_t SRAM_PEF : 1;  // SRAM parity error flag
            uint32_t : 23;
        };

        union {
            uint32_t r;
            Bits b;
        };
    };

    /** Interrupt line 0 status register
     */
    struct Itline0 {
        Itline0(const uint32_t raw=0) { r = raw; }

        struct Bits {
            const uint32_t WWDG : 1;  // WWDG Interrupt request pending
            uint32_t : 31;
        };

        union {
            uint32_t r;
            Bits b;
        };
    };

    /** Interrupt line 1 status register
     */
    struct Itline1 {
        Itline1(const uint32_t raw=0) { r = raw; }

        struct Bits {
            const uint32_t PVDOUT : 1;  // PVDOUT Interrupt request pending
            const uint32_t VDDIO2 : 1;  // VDDIO2 Interrupt request pending
            uint32_t : 30;
        };

        union {
            uint32_t r;
            Bits b;
        };
    };

    /** Interrupt line 2 status register
     */
    struct Itline2 {
        Itline2(const uint32_t raw=0) { r = raw; }

        struct Bits {
            const uint32_t RTC_WAKEUP : 1;  // RTC_WAKEUP Interrupt request pending
            const uint32_t RTC_TSTAMP : 1;  // RTC_TSTAMP Interrupt request pending
            const uint32_t RTC_ALRA : 1;  // RTC_ALRA Interrupt request pending
            uint32_t : 29;
        };

        union {
            uint32_t r;
            Bits b;
        };
    };

    /** Interrupt line 3 status register
     */
    struct Itline3 {
        Itline3(const uint32_t raw=0) { r = raw; }

        struct Bits {
            const uint32_t FLASH_ITF : 1;  // FLASH_ITF Interrupt request pending
            uint32_t : 31;
        };

        union {
            uint32_t r;
            Bits b;
        };
    };

    /** Interrupt line 4 status register
     */
    struct Itline4 {
        Itline4(const uint32_t raw=0) { r = raw; }

        struct Bits {
            const uint32_t RCC : 1;  // RCC Interrupt request pending
            const uint32_t CRS : 1;  // CRS Interrupt request pending
            uint32_t : 30;
        };

        union {
            uint32_t r;
            Bits b;
        };
    };

    /** Interrupt line 5 status register
     */
    struct Itline5 {
        Itline5(const uint32_t raw=0) { r = raw; }

        struct Bits {
            const uint32_t EXTI0 : 1;  // EXTI0 Interrupt request pending
            const uint32_t EXTI1 : 1;  // EXTI1 Interrupt request pending
            uint32_t : 30;
        };

        union {
            uint32_t r;
            Bits b;
        };
    };

    /** Interrupt line 6 status register
     */
    struct Itline6 {
        Itline6(const uint32_t raw=0) { r = raw; }

        struct Bits {
            const uint32_t EXTI2 : 1;  // EXTI2 Interrupt request pending
            const uint32_t EXTI3 : 1;  // EXTI3 Interrupt request pending
            uint32_t : 30;
        };

        union {
            uint32_t r;
            Bits b;
        };
    };

    /** Interrupt line 7 status register
     */
    struct Itline7 {
        Itline7(const uint32_t raw=0) { r = raw; }

        struct Bits {
            const uint32_t EXTI4 : 1;  // EXTI0 Interrupt request pending
            const uint32_t EXTI5 : 1;  // EXTI1 Interrupt request pending
            const uint32_t EXTI6 : 1;  // EXTI0 Interrupt request pending
            const uint32_t EXTI7 : 1;  // EXTI1 Interrupt request pending
            const uint32_t EXTI8 : 1;  // EXTI0 Interrupt request pending
            const uint32_t EXTI9 : 1;  // EXTI1 Interrupt request pending
            const uint32_t EXTI10 : 1;  // EXTI0 Interrupt request pending
            const uint32_t EXTI11 : 1;  // EXTI1 Interrupt request pending
            const uint32_t EXTI12 : 1;  // EXTI0 Interrupt request pending
            const uint32_t EXTI13 : 1;  // EXTI1 Interrupt request pending
            const uint32_t EXTI14 : 1;  // EXTI0 Interrupt request pending
            const uint32_t EXTI15 : 1;  // EXTI1 Interrupt request pending
            uint32_t : 20;
        };

        union {
            uint32_t r;
            Bits b;
        };
    };

    /** Interrupt line 8 status register
     */
    struct Itline8 {
        Itline8(const uint32_t raw=0) { r = raw; }

        struct Bits {
            const uint32_t TCS_MCE : 1;  // TCS_MCE Interrupt request pending
            const uint32_t TCS_EOA : 1;  // TCS_EOA Interrupt request pending
            uint32_t : 30;
        };

        union {
            uint32_t r;
            Bits b;
        };
    };

    /** Interrupt line 9 status register
     */
    struct Itline9 {
        Itline9(const uint32_t raw=0) { r = raw; }

        struct Bits {
            const uint32_t DMA1_CH1 : 1;  // DMA1_CH1 Interrupt request pending
            uint32_t : 31;
        };

        union {
            uint32_t r;
            Bits b;
        };
    };

    /** Interrupt line 10 status register
     */
    struct Itline10 {
        Itline10(const uint32_t raw=0) { r = raw; }

        struct Bits {
            const uint32_t DMA1_CH2 : 1;  // DMA1_CH2 Interrupt request pending
            const uint32_t DMA1_CH3 : 1;  // DMA1_CH3 Interrupt request pending
            const uint32_t DMA2_CH1 : 1;  // DMA2_CH1 Interrupt request pending
            const uint32_t DMA2_CH2 : 1;  // DMA2_CH2 Interrupt request pending
            uint32_t : 28;
        };

        union {
            uint32_t r;
            Bits b;
        };
    };

    /** Interrupt line 11 status register
     */
    struct Itline11 {
        Itline11(const uint32_t raw=0) { r = raw; }

        struct Bits {
            const uint32_t DMA1_CH4 : 1;  // DMA1_CH4 Interrupt request pending
            const uint32_t DMA1_CH5 : 1;  // DMA1_CH5 Interrupt request pending
            const uint32_t DMA1_CH6 : 1;  // DMA1_CH6 Interrupt request pending
            const uint32_t DMA1_CH7 : 1;  // DMA1_CH7 Interrupt request pending
            const uint32_t DMA2_CH1 : 1;  // DMA2_CH1 Interrupt request pending
            const uint32_t DMA2_CH2 : 1;  // DMA2_CH2 Interrupt request pending
            const uint32_t DMA2_CH2 : 1;  // DMA2_CH2 Interrupt request pending
            uint32_t : 25;
        };

        union {
            uint32_t r;
            Bits b;
        };
    };

    /** Interrupt line 12 status register
     */
    struct Itline12 {
        Itline12(const uint32_t raw=0) { r = raw; }

        struct Bits {
            const uint32_t ADC : 1;  // ADC Interrupt request pending
            const uint32_t COMP1 : 1;  // COMP1 Interrupt request pending
            const uint32_t COMP2 : 1;  // COMP2 Interrupt request pending
            uint32_t : 29;
        };

        union {
            uint32_t r;
            Bits b;
        };
    };

    /** Interrupt line 13 status register
     */
    struct Itline13 {
        Itline13(const uint32_t raw=0) { r = raw; }

        struct Bits {
            const uint32_t TIM1_CCU : 1;  // TIM1_CCU Interrupt request pending
            const uint32_t TIM1_TRG : 1;  // TIM1_TRG Interrupt request pending
            const uint32_t TIM1_UPD : 1;  // TIM1_UPD Interrupt request pending
            const uint32_t TIM1_BRK : 1;  // TIM1_BRK Interrupt request pending
            uint32_t : 28;
        };

        union {
            uint32_t r;
            Bits b;
        };
    };

    /** Interrupt line 14 status register
     */
    struct Itline14 {
        Itline14(const uint32_t raw=0) { r = raw; }

        struct Bits {
            const uint32_t TIM1_CC : 1;  // TIM1_CC Interrupt request pending
            uint32_t : 31;
        };

        union {
            uint32_t r;
            Bits b;
        };
    };

    /** Interrupt line 15 status register
     */
    struct Itline15 {
        Itline15(const uint32_t raw=0) { r = raw; }

        struct Bits {
            const uint32_t TIM2 : 1;  // TIM2 Interrupt request pending
            uint32_t : 31;
        };

        union {
            uint32_t r;
            Bits b;
        };
    };

    /** Interrupt line 16 status register
     */
    struct Itline16 {
        Itline16(const uint32_t raw=0) { r = raw; }

        struct Bits {
            const uint32_t TIM3 : 1;  // TIM3 Interrupt request pending
            uint32_t : 31;
        };

        union {
            uint32_t r;
            Bits b;
        };
    };

    /** Interrupt line 17 status register
     */
    struct Itline17 {
        Itline17(const uint32_t raw=0) { r = raw; }

        struct Bits {
            const uint32_t TIM6 : 1;  // TIM6 Interrupt request pending
            const uint32_t DAC : 1;  // DAC Interrupt request pending
            uint32_t : 30;
        };

        union {
            uint32_t r;
            Bits b;
        };
    };

    /** Interrupt line 18 status register
     */
    struct Itline18 {
        Itline18(const uint32_t raw=0) { r = raw; }

        struct Bits {
            const uint32_t TIM7 : 1;  // TIM7 Interrupt request pending
            uint32_t : 31;
        };

        union {
            uint32_t r;
            Bits b;
        };
    };

    /** Interrupt line 19 status register
     */
    struct Itline19 {
        Itline19(const uint32_t raw=0) { r = raw; }

        struct Bits {
            const uint32_t TIM14 : 1;  // TIM14 Interrupt request pending
            uint32_t : 31;
        };

        union {
            uint32_t r;
            Bits b;
        };
    };

    /** Interrupt line 20 status register
     */
    struct Itline20 {
        Itline20(const uint32_t raw=0) { r = raw; }

        struct Bits {
            const uint32_t TIM15 : 1;  // TIM15 Interrupt request pending
            uint32_t : 31;
        };

        union {
            uint32_t r;
            Bits b;
        };
    };

    /** Interrupt line 21 status register
     */
    struct Itline21 {
        Itline21(const uint32_t raw=0) { r = raw; }

        struct Bits {
            const uint32_t TIM16 : 1;  // TIM16 Interrupt request pending
            uint32_t : 31;
        };

        union {
            uint32_t r;
            Bits b;
        };
    };

    /** Interrupt line 22 status register
     */
    struct Itline22 {
        Itline22(const uint32_t raw=0) { r = raw; }

        struct Bits {
            const uint32_t TIM17 : 1;  // TIM17 Interrupt request pending
            uint32_t : 31;
        };

        union {
            uint32_t r;
            Bits b;
        };
    };

    /** Interrupt line 23 status register
     */
    struct Itline23 {
        Itline23(const uint32_t raw=0) { r = raw; }

        struct Bits {
            const uint32_t I2C1 : 1;  // I2C1 Interrupt request pending
            uint32_t : 31;
        };

        union {
            uint32_t r;
            Bits b;
        };
    };

    /** Interrupt line 24 status register
     */
    struct Itline24 {
        Itline24(const uint32_t raw=0) { r = raw; }

        struct Bits {
            const uint32_t I2C2 : 1;  // I2C2 Interrupt request pending
            uint32_t : 31;
        };

        union {
            uint32_t r;
            Bits b;
        };
    };

    /** Interrupt line 25 status register
     */
    struct Itline25 {
        Itline25(const uint32_t raw=0) { r = raw; }

        struct Bits {
            const uint32_t SPI1 : 1;  // SPI1 Interrupt request pending
            uint32_t : 31;
        };

        union {
            uint32_t r;
            Bits b;
        };
    };

    /** Interrupt line 26 status register
     */
    struct Itline26 {
        Itline26(const uint32_t raw=0) { r = raw; }

        struct Bits {
            const uint32_t SPI2 : 1;  // SPI2 Interrupt request pending
            uint32_t : 31;
        };

        union {
            uint32_t r;
            Bits b;
        };
    };

    /** Interrupt line 27 status register
     */
    struct Itline27 {
        Itline27(const uint32_t raw=0) { r = raw; }

        struct Bits {
            const uint32_t USART1 : 1;  // USART1 Interrupt request pending
            uint32_t : 31;
        };

        union {
            uint32_t r;
            Bits b;
        };
    };

    /** Interrupt line 28 status register
     */
    struct Itline28 {
        Itline28(const uint32_t raw=0) { r = raw; }

        struct Bits {
            const uint32_t USART2 : 1;  // USART2 Interrupt request pending
            uint32_t : 31;
        };

        union {
            uint32_t r;
            Bits b;
        };
    };

    /** Interrupt line 29 status register
     */
    struct Itline29 {
        Itline29(const uint32_t raw=0) { r = raw; }

        struct Bits {
            const uint32_t USART3 : 1;  // USART3 Interrupt request pending
            const uint32_t USART4 : 1;  // USART4 Interrupt request pending
            const uint32_t USART5 : 1;  // USART5 Interrupt request pending
            const uint32_t USART6 : 1;  // USART6 Interrupt request pending
            const uint32_t USART7 : 1;  // USART7 Interrupt request pending
            const uint32_t USART8 : 1;  // USART8 Interrupt request pending
            uint32_t : 26;
        };

        union {
            uint32_t r;
            Bits b;
        };
    };

    /** Interrupt line 30 status register
     */
    struct Itline30 {
        Itline30(const uint32_t raw=0) { r = raw; }

        struct Bits {
            const uint32_t CEC : 1;  // CEC Interrupt request pending
            const uint32_t CAN : 1;  // CAN Interrupt request pending
            uint32_t : 30;
        };

        union {
            uint32_t r;
            Bits b;
        };
    };

    /** Interrupt line 31 status register
     */
    struct Itline31 {
        Itline31(const uint32_t raw=0) { r = raw; }

        struct Bits {
            const uint32_t USB : 1;  // USB Interrupt request pending
            uint32_t : 31;
        };

        union {
            uint32_t r;
            Bits b;
        };
    };

    volatile Cfgr1 CFGR1;  // configuration register 1
    uint32_t __res0;
    volatile Exticr EXTICR;  // external interrupt configuration register 1
    volatile Cfgr2 CFGR2;  // configuration register 2
    uint32_t __res1[25];
    volatile Itline0 ITLINE0;  // Interrupt line 0 status register (F09x)
    volatile Itline1 ITLINE1;  // Interrupt line 1 status register (F09x)
    volatile Itline2 ITLINE2;  // Interrupt line 2 status register (F09x)
    volatile Itline3 ITLINE3;  // Interrupt line 3 status register (F09x)
    volatile Itline4 ITLINE4;  // Interrupt line 4 status register (F09x)
    volatile Itline5 ITLINE5;  // Interrupt line 5 status register (F09x)
    volatile Itline6 ITLINE6;  // Interrupt line 6 status register (F09x)
    volatile Itline7 ITLINE7;  // Interrupt line 7 status register (F09x)
    volatile Itline8 ITLINE8;  // Interrupt line 8 status register (F09x)
    volatile Itline9 ITLINE9;  // Interrupt line 9 status register (F09x)
    volatile Itline10 ITLINE10;  // Interrupt line 10 status register (F09x)
    volatile Itline11 ITLINE11;  // Interrupt line 11 status register (F09x)
    volatile Itline12 ITLINE12;  // Interrupt line 12 status register (F09x)
    volatile Itline13 ITLINE13;  // Interrupt line 13 status register (F09x)
    volatile Itline14 ITLINE14;  // Interrupt line 14 status register (F09x)
    volatile Itline15 ITLINE15;  // Interrupt line 15 status register (F09x)
    volatile Itline16 ITLINE16;  // Interrupt line 16 status register (F09x)
    volatile Itline17 ITLINE17;  // Interrupt line 17 status register (F09x)
    volatile Itline18 ITLINE18;  // Interrupt line 18 status register (F09x)
    volatile Itline19 ITLINE19;  // Interrupt line 19 status register (F09x)
    volatile Itline20 ITLINE20;  // Interrupt line 20 status register (F09x)
    volatile Itline21 ITLINE21;  // Interrupt line 21 status register (F09x)
    volatile Itline22 ITLINE22;  // Interrupt line 22 status register (F09x)
    volatile Itline23 ITLINE23;  // Interrupt line 23 status register (F09x)
    volatile Itline24 ITLINE24;  // Interrupt line 24 status register (F09x)
    volatile Itline25 ITLINE25;  // Interrupt line 25 status register (F09x)
    volatile Itline26 ITLINE26;  // Interrupt line 26 status register (F09x)
    volatile Itline27 ITLINE27;  // Interrupt line 27 status register (F09x)
    volatile Itline28 ITLINE28;  // Interrupt line 28 status register (F09x)
    volatile Itline29 ITLINE29;  // Interrupt line 29 status register (F09x)
    volatile Itline30 ITLINE30;  // Interrupt line 30 status register (F09x)
    volatile Itline31 ITLINE31;  // Interrupt line 31 status register (F09x)
};

namespace base {

static constexpr size_t SYSCFG = 0x40010000;

}

static Syscfg &SYSCFG = *reinterpret_cast<Syscfg *>(base::SYSCFG);

}
