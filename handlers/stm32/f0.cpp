
/**
 * Handlers setup code for STM32F0xxxx MCUs.
 */

#include "io/lib/io_def.hpp"

// Undefined handler is pointing to this function, this stop MCU.
// This function name must by not mangled, so must be C,
// because alias("..") is working only with C code
extern "C" void __stop_stm32() { while (true); }

// Handlers for Cortex-M core.
// These handler are with attribute 'weak' and can be overwritten
// by non-week function, default is __stop() function
__attribute__((weak, alias("__stop_stm32"))) void WWDG_handler();
__attribute__((weak, alias("__stop_stm32"))) void PVD_handler();
__attribute__((weak, alias("__stop_stm32"))) void RTC_handler();
__attribute__((weak, alias("__stop_stm32"))) void FLASH_handler();
__attribute__((weak, alias("__stop_stm32"))) void RCC_CRS_handler();
__attribute__((weak, alias("__stop_stm32"))) void EXTI0_1_handler();
__attribute__((weak, alias("__stop_stm32"))) void EXTI2_3_handler();
__attribute__((weak, alias("__stop_stm32"))) void EXTI4_15_handler();
__attribute__((weak, alias("__stop_stm32"))) void TSC_handler();
__attribute__((weak, alias("__stop_stm32"))) void DMA1_CH1_handler();
__attribute__((weak, alias("__stop_stm32"))) void DMA1_CH2_3_DMA2_CH1_2_handler();
__attribute__((weak, alias("__stop_stm32"))) void DMA1_CH4_5_6_7_DMA2_CH3_4_5_handler();
__attribute__((weak, alias("__stop_stm32"))) void ADC_COMP_handler();
__attribute__((weak, alias("__stop_stm32"))) void TIM1_BRK_UP_TRG_COM_handler();
__attribute__((weak, alias("__stop_stm32"))) void TIM1_CC_handler();
__attribute__((weak, alias("__stop_stm32"))) void TIM2_handler();
__attribute__((weak, alias("__stop_stm32"))) void TIM3_handler();
__attribute__((weak, alias("__stop_stm32"))) void TIM6_DAC_handler();
__attribute__((weak, alias("__stop_stm32"))) void TIM7_handler();
__attribute__((weak, alias("__stop_stm32"))) void TIM14_handler();
__attribute__((weak, alias("__stop_stm32"))) void TIM15_handler();
__attribute__((weak, alias("__stop_stm32"))) void TIM16_handler();
__attribute__((weak, alias("__stop_stm32"))) void TIM17_handler();
__attribute__((weak, alias("__stop_stm32"))) void I2C1_handler();
__attribute__((weak, alias("__stop_stm32"))) void I2C2_handler();
__attribute__((weak, alias("__stop_stm32"))) void SPI1_handler();
__attribute__((weak, alias("__stop_stm32"))) void SPI2_handler();
__attribute__((weak, alias("__stop_stm32"))) void USART1_handler();
__attribute__((weak, alias("__stop_stm32"))) void USART2_handler();
__attribute__((weak, alias("__stop_stm32"))) void USART3_4_5_6_7_8_handler();
__attribute__((weak, alias("__stop_stm32"))) void CEC_CAN_handler();
__attribute__((weak, alias("__stop_stm32"))) void USB_handler();

// Dummy handler (for unused vectors)
extern void DUMMY_handler();

// Vector table for handlers
// This array will be placed in ".vectors" section defined in linker script.
__attribute__((section(".vectors_stm32"), used)) ptr_func_t __isr_vectors_stm32[] = {
    WWDG_handler,
    PVD_handler,
    RTC_handler,
    FLASH_handler,
    RCC_CRS_handler,
    EXTI0_1_handler,
    EXTI2_3_handler,
    EXTI4_15_handler,
    TSC_handler,
    DMA1_CH1_handler,
    DMA1_CH2_3_DMA2_CH1_2_handler,
    DMA1_CH4_5_6_7_DMA2_CH3_4_5_handler,
    ADC_COMP_handler,
    TIM1_BRK_UP_TRG_COM_handler,
    TIM1_CC_handler,
    TIM2_handler,
    TIM3_handler,
    TIM6_DAC_handler,
    TIM7_handler,
    TIM14_handler,
    TIM15_handler,
    TIM16_handler,
    TIM17_handler,
    I2C1_handler,
    I2C2_handler,
    SPI1_handler,
    SPI2_handler,
    USART1_handler,
    USART2_handler,
    USART3_4_5_6_7_8_handler,
    CEC_CAN_handler,
    USB_handler,
};
