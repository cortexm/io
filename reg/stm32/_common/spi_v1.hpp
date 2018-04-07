/**
* Peripheral Definition File
*
* SPI - Serial peripheral interface / inter-IC sound
*
* MCUs containing this peripheral:
*  - STM32F1xx
*  - STM32F2xx
*  - STM32F4xx
*  - STM32L0xx
*  - STM32L1xx
*/

#pragma once

#include <cstdint>
#include <cstddef>

namespace io {

struct Spi {
    /** Control register 1
     */
    struct Cr1 {
        Cr1(const uint32_t raw=0) { r = raw; }

        struct Bits {
            uint32_t CPHA : 1;  // Clock Phase
            uint32_t CPOL  : 1;  // Clock Polarity
            uint32_t MSTR : 1;  // Master enable
            uint32_t BR : 3;  // Baud Rate control
            uint32_t SPE : 1;  // SPI Enable
            uint32_t LSBFIRST : 1;  // LSB First frame format
            uint32_t SSI : 1;  // Internal Slave Select
            uint32_t SSM : 1;  // Software Slave Management enable
            uint32_t RXONLY : 1;  // Receiver Only mode enable
            uint32_t DFF : 1;  // Data frame format (0: 8 bit, 1: 16 bit)
            uint32_t CRCNEXT : 1;  // Transmit CRC Next
            uint32_t CRCEN : 1;  // CRC enable
            uint32_t BIDIOE : 1;  // Output Enable in Bidirectional Mode
            uint32_t BIDIMODE : 1;  // Bidirectional data Mode enabled
            uint32_t : 16;
        };

        struct Br {
            static const uint32_t DIV_2 = 0;
            static const uint32_t DIV_4 = 1;
            static const uint32_t DIV_8 = 2;
            static const uint32_t DIV_16 = 3;
            static const uint32_t DIV_32 = 4;
            static const uint32_t DIV_64 = 5;
            static const uint32_t DIV_128 = 6;
            static const uint32_t DIV_256 = 7;
        };

        union {
            uint32_t r;
            Bits b;
        };
    };

    /** Control register 2
     */
    struct Cr2 {
        Cr2(const uint32_t raw=0) { r = raw; }

        struct Bits {
            uint32_t RXDMAEN : 1;  // RX buffer DMA Enable
            uint32_t TXDMAEN  : 1;  // TX buffer DMA Enable
            uint32_t SSOE  : 1;  // Slave Select Output Enable
            uint32_t NSSP  : 1;  // NSS Pulse management enable
            uint32_t FRF : 1;  // Frame Format mode (0: Motorola, 1: TI)
            uint32_t ERRIE  : 1;  // Error Interrupt Enable
            uint32_t RXNEIE : 1;  // RX buffer Not Empty Interrupt Enable
            uint32_t TXEIE : 1;  // TX buffer Empty Interrupt Enable
            uint32_t DS : 4;  // Data Size
            uint32_t FRXTH : 1;  // FiFo Reception Threshold
            uint32_t LDMA_RX : 1;  // Last DMA transfer for Reception
            uint32_t LDMA_TX : 1;  // Last DMA transfer for transmission
            uint32_t : 17;
        };

        struct Ds {
            static const uint32_t DS_4 = 3;
            static const uint32_t DS_5 = 4;
            static const uint32_t DS_6 = 5;
            static const uint32_t DS_7 = 6;
            static const uint32_t DS_8 = 7;
            static const uint32_t DS_9 = 8;
            static const uint32_t DS_10 = 9;
            static const uint32_t DS_11 = 10;
            static const uint32_t DS_12 = 11;
            static const uint32_t DS_13 = 12;
            static const uint32_t DS_14 = 13;
            static const uint32_t DS_15 = 14;
            static const uint32_t DS_16 = 15;
        };

        union {
            uint32_t r;
            Bits b;
        };
    };

    /** Status register
     */
    struct Sr {
        Sr(const uint32_t raw=0) { r = raw; }

        struct Bits {
            const uint32_t RXNE : 1;  // RX buffer not empty
            const uint32_t TXE : 1;  // TX buffer empty
            const uint32_t CHSIDE : 1;  // I2S Channel side (0: left, 1: right)
            const uint32_t UDR : 1;  // I2S Under run flag
            uint32_t CRCERR : 1;  // CRC Error flag
            const uint32_t MODF : 1;  // Mode Fault
            const uint32_t OVR : 1;  // Overrun Flag
            const uint32_t BSY : 1;  // Busy Flag
            const uint32_t FRE : 1;  // Frame format Error
            const uint32_t FRLVL : 2;  // FiFo Reception Level
            const uint32_t FTLVL : 2;  // FiFo Transmission Level
            uint32_t : 19;
        };

        union {
            uint32_t r;
            Bits b;
        };
        struct Flvl {
            static const uint32_t EMPTY = 0;
            static const uint32_t QUART = 1;
            static const uint32_t HALF = 2;
            static const uint32_t FULL = 3;
        };
    };

    /** data register
     */
    struct Dr {
        union {
            uint32_t r;
            uint32_t DR;  // Data Register 16 bit access (using 32 bits)
            uint16_t DR16;  // Data Register 16 bit access
            uint8_t DR8;  // Data Register 8 bit access
        };
    };

    /** CRC polynomial register
     */
    struct Crcpr {
        union {
            uint32_t r;
            uint16_t CRCPOLY;  // CRC Polynomial
        };
    };

    /** Rx CRC register
     */
    struct Rxcrcr {
        union {
            uint32_t r;
            const uint16_t RXCRC;  // RX CRC 16 bit
        };
    };

    /** Tx CRC register
     */
    struct Txcrcr {
        union {
            uint32_t r;
            const uint16_t TXCRC;  // TX CRC 16 bit
        };
    };

    /** I2S configuration register
     */
    struct I2scfgr {
        I2scfgr(const uint32_t raw=0) { r = raw; }

        struct Bits {
            uint32_t CHLEN : 1;  // Channel Length (0: 16 bit, 1: 32 bit)
            uint32_t DATLEN : 2;  // Data Length
            uint32_t CKPOL : 1;  // steady state Clock Polarity
            uint32_t I2SSTD : 2;  // I2S Standard selection
            uint32_t : 1;
            uint32_t PCMSYNC : 1;  // PCM frame Synchronization
            uint32_t I2SCFG : 2;  // I2S Configuration mode
            uint32_t I2SE : 1;  // I2S Enable
            uint32_t I2SMOD : 1;  // I2S Mode selected
            uint32_t : 20;
        };

        struct Datalen {
            static const uint32_t DATALEN_16 = 0;
            static const uint32_t DATALEN_24 = 1;
            static const uint32_t DATALEN_32 = 2;
        };

        struct I2sstd {
            static const uint32_t I2S_PHILLIPS = 0;
            static const uint32_t MSB_JUSTIFIED = 1;
            static const uint32_t LSB_JUSTIFIED = 2;
            static const uint32_t PCM_STANDARD = 3;
        };

        struct I2scfg {
            static const uint32_t SLAVE_TX = 0;
            static const uint32_t SLAVE_RX = 1;
            static const uint32_t MASTER_TX = 2;
            static const uint32_t MASTER_RX = 3;
        };

        union {
            uint32_t r;
            Bits b;
        };
    };

    /** I2S prescaler register
     */
    struct I2spr {
        I2spr(const uint32_t raw=0) { r = raw; }

        struct Bits {
            uint32_t I2SDIV : 8;  // I2S linear prescaler
            uint32_t ODD : 1;  // Odd factor for the prescaler
            uint32_t MCKOE : 1;  // Master Clock Output Enable
            uint32_t : 22;
        };

        union {
            uint32_t r;
            Bits b;
        };
    };

    volatile Cr1 CR1;  // Control register 1
    volatile Cr2 CR2;  // Control register 2
    volatile Sr SR;  // Status register
    volatile Dr DR;  // data register
    volatile Crcpr CRCPR;  // CRC polynomial register
    volatile Rxcrcr RXCRCR;  // Rx CRC register
    volatile Txcrcr TXCRCR;  // Tx CRC register
    volatile I2scfgr I2SCFGR;  // I2S configuration register
    volatile I2spr I2SPR;  // I2S prescaler register
};

static inline constexpr Spi &SPI(const size_t base) {
    return *reinterpret_cast<Spi *>(base);
}

}
