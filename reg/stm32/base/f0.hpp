/**
* Peripheral Definition File
*
* BASE - BASE peripheral addresses
*
* MCUs containing this peripheral:
*  - STM32F0xx
*/

#pragma once

#include <cstdint>
#include <cstddef>

namespace io {
struct Base {
    static const size_t APB1PERIPH = 0x40000000;
    static const size_t APB2PERIPH = 0x40010000;
    static const size_t AHB1PERIPH = 0x40020000;
    static const size_t AHB2PERIPH = 0x48000000;

    static const size_t ADC = APB2PERIPH + 0x2400;  // 0x40012400
    static const size_t CAN = APB1PERIPH + 0x6400;  // 0x40006400
    static const size_t CEC = APB1PERIPH + 0x7800;  // 0x40007800
    static const size_t DBGMCU = APB2PERIPH + 0x5800;  // 0x40015800
    static const size_t CRC = AHB1PERIPH + 0x3000;  // 0x40023000
    static const size_t CRS = APB1PERIPH + 0x6c00;  // 0x40006c00
    static const size_t DAC = APB1PERIPH + 0x7400;  // 0x40007400
    static const size_t DMA1 = AHB1PERIPH + 0x0000;  // 0x40020000
    static const size_t DMA2 = AHB1PERIPH + 0x0400;  // 0x40020400
    static const size_t EXTI = APB2PERIPH + 0x0400;  // 0x40010400
    static const size_t FLASH = AHB1PERIPH + 0x2000;  // 0x40022000
    static const size_t GPIOA = AHB2PERIPH + 0x0000;  // 0x48000000
    static const size_t GPIOB = AHB2PERIPH + 0x0400;  // 0x48000400
    static const size_t GPIOC = AHB2PERIPH + 0x0800;  // 0x48000800
    static const size_t GPIOD = AHB2PERIPH + 0x0c00;  // 0x48000c00
    static const size_t GPIOE = AHB2PERIPH + 0x1000;  // 0x48001000
    static const size_t GPIOF = AHB2PERIPH + 0x1400;  // 0x48001400
    static const size_t I2C2 = APB1PERIPH + 0x5800;  // 0x40005800
    static const size_t I2C1 = APB1PERIPH + 0x5400;  // 0x40005400
    static const size_t IWDG = APB1PERIPH + 0x3000;  // 0x40003000
    static const size_t PWR = APB1PERIPH + 0x7000;  // 0x40007000
    static const size_t RCC = AHB1PERIPH + 0x1000;  // 0x40021000
    static const size_t RTC = APB1PERIPH + 0x2800;  // 0x40002800
    static const size_t SPI1 = APB2PERIPH + 0x3000;  // 0x40013000
    static const size_t SPI2 = APB1PERIPH + 0x3800;  // 0x40003800
    static const size_t SYSCFG = APB2PERIPH + 0x0000;  // 0x40010000
    static const size_t COMP = APB2PERIPH + 0x0000;  // 0x40010000
    static const size_t TIM1 = APB2PERIPH + 0x2c00;  // 0x40012c00
    static const size_t TIM2 = APB1PERIPH + 0x0000;  // 0x40000000
    static const size_t TIM3 = APB1PERIPH + 0x0400;  // 0x40000400
    static const size_t TIM6 = APB1PERIPH + 0x1000;  // 0x40001000
    static const size_t TIM7 = APB1PERIPH + 0x1400;  // 0x40004000
    static const size_t TIM14 = APB1PERIPH + 0x2000;  // 0x40002000
    static const size_t TIM15 = APB2PERIPH + 0x4000;  // 0x40014000
    static const size_t TIM16 = APB2PERIPH + 0x4400;  // 0x40014400
    static const size_t TIM17 = APB2PERIPH + 0x4800;  // 0x40014800
    static const size_t TSC = AHB1PERIPH + 0x4000;  // 0x40024000
    static const size_t WWDG = APB1PERIPH + 0x2c00;  // 0x40002c00
    static const size_t USART1 = APB2PERIPH + 0x3800;  // 0x40013800
    static const size_t USART2 = APB1PERIPH + 0x4400;  // 0x40004400
    static const size_t USART3 = APB1PERIPH + 0x4800;  // 0x40004800
    static const size_t USART4 = APB1PERIPH + 0x4c00;  // 0x40004c00
    static const size_t USART5 = APB1PERIPH + 0x5000;  // 0x40005000
    static const size_t USART6 = APB2PERIPH + 0x1400;  // 0x40011400
    static const size_t USART7 = APB2PERIPH + 0x1800;  // 0x40011800
    static const size_t USART8 = APB2PERIPH + 0x1c00;  // 0x40011c00
    static const size_t USB = APB1PERIPH + 0x5c00;  // 0x40005c00
    static const size_t USB_SRAM = APB1PERIPH + 0x6000;  // 0x40006000
    static const size_t CAN_SRAM = APB1PERIPH + 0x6000;  // 0x40006000

    static const size_t FLASH_SIZE = 0x1ffff7cc;
    static const size_t UID = 0x1ffff7ac;
};
}
