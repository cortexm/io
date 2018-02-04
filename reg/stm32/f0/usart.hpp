/**
* Peripheral Definition File
*
* USART - Universal synchronous asynchronous receiver transmitter
*
* MCUs containing this peripheral:
*  - STM32F0xx
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
static const size_t USART4 = 0x40004c00;
static const size_t USART5 = 0x40005000;
static const size_t USART6 = 0x40011400;
static const size_t USART7 = 0x40011800;
static const size_t USART8 = 0x40011c00;

}

static Usart &USART1 = *reinterpret_cast<Usart *>(base::USART1);
static Usart &USART2 = *reinterpret_cast<Usart *>(base::USART2);
static Usart &USART3 = *reinterpret_cast<Usart *>(base::USART3);
static Usart &USART4 = *reinterpret_cast<Usart *>(base::USART4);
static Usart &USART5 = *reinterpret_cast<Usart *>(base::USART5);
static Usart &USART6 = *reinterpret_cast<Usart *>(base::USART6);
static Usart &USART7 = *reinterpret_cast<Usart *>(base::USART7);
static Usart &USART8 = *reinterpret_cast<Usart *>(base::USART8);

}
