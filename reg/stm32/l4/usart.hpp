/**
* Peripheral Definition File
*
* USART - Universal synchronous asynchronous receiver transmitter
*
* MCUs containing this peripheral:
*  - STM32F3xx
*/

#pragma once

#include <cstdint>
#include <cstddef>

#include "io/reg/stm32/_common/usart_v2.hpp"

namespace io {

namespace base {

static const size_t USART1 = 0x40013800;
static const size_t USART2 = 0x40004400;
static const size_t USART3 = 0x40004800;
static const size_t UART4 = 0x40004c00;
static const size_t UART5 = 0x40005000;

}

static Usart &USART1 = *reinterpret_cast<Usart *>(base::USART1);
static Usart &USART2 = *reinterpret_cast<Usart *>(base::USART2);
static Usart &USART3 = *reinterpret_cast<Usart *>(base::USART3);
static Usart &UART4 = *reinterpret_cast<Usart *>(base::UART4);
static Usart &UART5 = *reinterpret_cast<Usart *>(base::UART5);

}
