/**
* Peripheral Definition File
*
* I2C - Inter-integrated circuit interface
*
* MCUs containing this peripheral:
*  - STM32F0xx
*  - STM32F3xx
*  - STM32F7xx
*  - STM32H7xx
*  - STM32L0xx
*  - STM32L4xx
*/

#pragma once

#include <cstdint>
#include <cstddef>

namespace io {

struct I2c {
    /** Control register 1
     */
    struct Cr1 {
        Cr1() {}
        Cr1(uint32_t raw) { r = raw; }
        union {
            uint32_t r;
            struct {
                uint32_t PE : 1;  // Peripheral enable
                uint32_t TXIE : 1;  // TX Interrupt enable
                uint32_t RXIE : 1;  // RX Interrupt enable
                uint32_t ADDRIE : 1;  // Address match Interrupt enable (slave only)
                uint32_t NACKIE : 1;  // Not acknowledge received Interrupt enable
                uint32_t STOPIE : 1;  // STOP detection Interrupt enable
                uint32_t TCIE : 1;  // Transfer Complete interrupt enable
                uint32_t ERRIE : 1;  // Error interrupts enable
                uint32_t DNF : 4;  // Digital noise filter
                uint32_t ANF : 1;  // Analog noise filter OFF
                uint32_t : 1;
                uint32_t TXDMAEN : 1;  // DMA transmission requests enable
                uint32_t RXDMAEN : 1;  // DMA reception requests enable
                uint32_t SBC : 1;  // Slave byte control
                uint32_t NOSTRETCH : 1; // Clock stretching disable
                uint32_t WUPEN : 1;  // Wakeup from Stop mode enable  // F0, F3, H7, L0, L4
                uint32_t GCEN : 1;  // General call enable
                uint32_t SMBHEN : 1;  // SMBus Host address enable
                uint32_t SMBDEN : 1;  // SMBus Device Default address enable
                uint32_t ALERTEN : 1;  // SMBus alert enable
                uint32_t PECEN : 1;  // PEC enable
                uint32_t : 8;
            } b;
        };
    };

    /** Control register 2
     */
    struct Cr2 {
        Cr2() {}
        Cr2(uint32_t raw) { r = raw; }
        union {
            uint32_t r;
            struct {
                uint32_t SADD : 10;  // Slave address
                uint32_t RD_WRN : 1;  // Transfer direction (master mode)
                uint32_t ADD10 : 1;  // 10-bit addressing mode (master mode)
                uint32_t HEAD10R : 1;  // 10-bit address header only read direction (master receiver mode)
                uint32_t START : 1;  // Start generation
                uint32_t STOP : 1;  // Stop generation (master mode)
                uint32_t NACK : 1;  // NACK generation (slave mode)
                uint32_t NBYTES : 8;  // Number of bytes
                uint32_t RELOAD : 1;  // NBYTES reload mode
                uint32_t AUTOEND : 1;  // Automatic end mode (master mode)
                uint32_t PECBYTE : 1;  // Packet error checking byte
                uint32_t : 5;
            } b;
        };
    };

    /** Own address 1 register
     */
    struct Oar1 {
        Oar1() {}
        Oar1(uint32_t raw) { r = raw; }
        union {
            uint32_t r;
            struct {
                uint32_t OA1 : 10;  // Interface address
                uint32_t OA1MODE : 1;  // Own Address 1 10-bit mode
                uint32_t : 4;
                uint32_t OA1EN : 1;  // Own Address 1 enable
                uint32_t : 16;
            } b;
        };
    };

    /** Own address 2 register
     */
    struct Oar2 {
        Oar2() {}
        Oar2(uint32_t raw) { r = raw; }
        union {
            uint32_t r;
            struct {
                uint32_t : 1;
                uint32_t OA2 : 7;  // Interface address
                uint32_t OA2MASK : 3;  // Own Address 2 masks
                uint32_t : 4;
                uint32_t OA2EN : 1;  // Own Address 2 enable
                uint32_t : 16;
            } b;
        };
    };

    /** Timing register
     */
    struct Timingr {
        Timingr() {}
        Timingr(uint32_t raw) { r = raw; }
        union {
            uint32_t r;
            struct {
                uint32_t SCLL : 8;  // SCL low period (master mode)
                uint32_t SCLH : 8;  // SCL high period (master mode)
                uint32_t SDADEL : 4;  // Data hold time
                uint32_t SCLDEL : 4; // Data setup time
                uint32_t : 4;
                uint32_t PRESC : 4;  // Timing prescaler
            } b;
        };
    };

    /** Timeout register
     */
    struct Timeoutr {
        Timeoutr() {}
        Timeoutr(uint32_t raw) { r = raw; }
        union {
            uint32_t r;
            struct {
                uint32_t TIMEOUTA : 12;  // Bus Timeout A
                uint32_t TIDLE : 1;  // Idle clock timeout detection
                uint32_t : 2;
                uint32_t TIMEOUTEN : 1;  // Clock timeout enable
                uint32_t TIMEOUTB : 12;  // Bus timeout B
                uint32_t : 3;
                uint32_t TEXTEN : 1;  // Extended clock timeout enable
            } b;
        };
    };

    /** Interrupt and status register
     */
    struct Isr {
        Isr() {}
        Isr(uint32_t raw) { r = raw; }
        union {
            uint32_t r;
            struct {
                uint32_t TXE : 1;  // Transmit data register empty (transmitters)
                uint32_t TXIS : 1;  // Transmit interrupt status (transmitters)
                const uint32_t RXNE : 1;  // Receive data register not empty (receivers)
                const uint32_t ADDR : 1;  // Address matched (slave mode)
                const uint32_t NACKF : 1;  // Not Acknowledge received flag
                const uint32_t STOPF : 1;  // Stop detection flag
                const uint32_t TC : 1;  // Transfer Complete (master mode)
                const uint32_t TCR : 1;  // Transfer Complete Reload
                const uint32_t BERR : 1;  // Bus error
                const uint32_t ARLO : 1;  // Arbitration lost
                const uint32_t OVR : 1;  // Overrun/Underrun (slave mode)
                const uint32_t PECERR : 1;  // PEC Error in reception
                const uint32_t TIMEOUT : 1;  // Timeout or tLOW detection flag
                const uint32_t ALERT : 1;  // SMBus alert
                const uint32_t : 1;
                const uint32_t BUSY : 1;  // Bus busy
                const uint32_t DIR : 1;  // Transfer direction (Slave mode)
                const uint32_t ADDCODE : 7;  // Address match code (Slave mode)
                uint32_t : 8;
            } b;
        };
    };

    /** Interrupt clear register
     */
    struct Icr {
        Icr() {}
        Icr(uint32_t raw) { r = raw; }
        union {
            uint32_t r;
            struct {
                uint32_t : 3;
                uint32_t ADDRCF : 1;  // Address Matched flag clear
                uint32_t NACKCF : 1;  // Not Acknowledge flag clear
                uint32_t STOPCF : 1;  // Stop detection flag clear
                uint32_t : 2;
                uint32_t BERRCF : 1;  // Bus error flag clear
                uint32_t ARLOCF : 1;  // Arbitration Lost flag clea
                uint32_t OVRCF : 1;  // Overrun/Underrun flag clear
                uint32_t PECCF : 1;  // PEC Error flag clear
                uint32_t TIMOUTCF : 1;  // Timeout detection flag clear
                uint32_t ALERTCF : 1;  // Alert flag clear
                uint32_t : 18;
            } b;
        };
    };

    /** Packet error checking register
     */
    struct Pecr {
        union {
            uint32_t r;
            uint32_t PEC;  // Packet error checking register (8-bit used)
        };
    };

    /** Receive data register
     */
    struct Rxdr {
        union {
            uint32_t r;
            uint32_t RXDATA;  // 8-bit receive data
        };
    };

    /** Transmit data register
     */
    struct Txdr {
        union {
            uint32_t r;
            uint32_t TXDATA;  // 8-bit transmit data
        };
    };

    volatile Cr1 CR1;  // Control register 1
    volatile Cr2 CR2;  // Control register 2
    volatile Oar1 OAR1;  // Own address 1 register
    volatile Oar2 OAR2;  // Own address 2 register
    volatile Timingr TIMINGR;  // Timing register
    volatile Timeoutr TIMEOUTR;  // Timeout register
    volatile Isr ISR;  // Interrupt and status register
    volatile Icr ICR;  // Interrupt clear register
    volatile Pecr PECR;  // Packet error checking register
    volatile Rxdr RXDR;  // Receive data register
    volatile Txdr TXDR;  // Transmit data register
};

static inline constexpr I2c &I2C(const size_t base) {
    return *reinterpret_cast<I2c *>(base);
}

}
