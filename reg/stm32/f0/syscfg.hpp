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

    volatile Cfgr1 CFGR1;  // configuration register 1
    uint32_t __res0;
    volatile Exticr EXTICR;  // external interrupt configuration register 1
    volatile Cfgr2 CFGR2;  // configuration register 2
};

namespace base {

static constexpr size_t SYSCFG = 0x40010000;

}

static Syscfg &SYSCFG = *reinterpret_cast<Syscfg *>(base::SYSCFG);

}
