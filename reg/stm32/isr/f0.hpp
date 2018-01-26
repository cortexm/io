/**
* Peripheral Definition File
*
* ISR - ISR numbers
*
* MCUs containing this peripheral:
*  - STM32F0xx
*/

#pragma once

#include <cstdint>

namespace io {
struct Isr {
    static const uint32_t WWDG_isr = 0;
    static const uint32_t PVD_isr = 1;
    static const uint32_t RTC_isr = 2;
    static const uint32_t FLASH_isr = 3;
    static const uint32_t RCC_CRS_isr = 4;
    static const uint32_t EXTI0_1_isr = 5;
    static const uint32_t EXTI2_3_isr = 6;
    static const uint32_t EXTI4_15_isr = 7;
    static const uint32_t TSC_isr = 8;
    static const uint32_t DMA1_CH1_isr = 9;
    static const uint32_t DMA1_CH2_3_DMA2_CH1_2_isr = 10;
    static const uint32_t DMA1_CH4_5_6_7_DMA2_CH3_4_5_isr = 11;
    static const uint32_t ADC_COMP_isr = 12;
    static const uint32_t TIM1_BRK_UP_TRG_COM_isr = 13;
    static const uint32_t TIM1_CC_isr = 14;
    static const uint32_t TIM2_isr = 15;
    static const uint32_t TIM3_isr = 16;
    static const uint32_t TIM6_DAC_isr = 17;
    static const uint32_t TIM7_isr = 18;
    static const uint32_t TIM14_isr = 19;
    static const uint32_t TIM15_isr = 20;
    static const uint32_t TIM16_isr = 21;
    static const uint32_t TIM17_isr = 22;
    static const uint32_t I2C1_isr = 23;
    static const uint32_t I2C2_isr = 24;
    static const uint32_t SPI1_isr = 25;
    static const uint32_t SPI2_isr = 26;
    static const uint32_t USART1_isr = 27;
    static const uint32_t USART2_isr = 28;
    static const uint32_t USART3_4_5_6_7_8_isr = 29;
    static const uint32_t CEC_CAN_isr = 30;
    static const uint32_t USB_isr = 31;
};
}
