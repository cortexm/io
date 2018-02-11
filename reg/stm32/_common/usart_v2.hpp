/**
* Peripheral Definition File
*
* USART - Universal synchronous asynchronous receiver transmitter
*
* MCUs containing this peripheral:
*  - STM32F0xx
*  - STM32F3xx
*  - STM32F7xx
*  - STM32L0xx
*  - STM32L4xx
*/

#pragma once

#include <cstdint>
#include <cstddef>

namespace io {

struct Usart {
    /** Control register 1
     */
    struct Cr1 {
        Cr1() {}
        Cr1(uint32_t raw) { r = raw; }
        union {
            uint32_t r;
            struct {
                uint32_t UE : 1;  // USART enable
                uint32_t UESM : 1;  // USART enable in Stop mode
                uint32_t RE : 1;  // Receiver enable
                uint32_t TE : 1;  // Transmitter enable
                uint32_t IDLEIE : 1;  // IDLE interrupt enable
                uint32_t RXNEIE : 1;  // RXNE interrupt enable
                uint32_t TCIE : 1;  // Transmission complete interrupt enable
                uint32_t TXEIE : 1;  // interrupt enable
                uint32_t PEIE : 1;  // PE interrupt enable
                uint32_t PS : 1;  // Parity selection
                uint32_t PCE : 1;  // Parity control enable
                uint32_t WAKE : 1;  // Receiver wakeup method
                uint32_t M0 : 1;  // Word length 0
                uint32_t MME : 1;  // Mute mode enable
                uint32_t CMIE : 1;  // Character match interrupt enable
                uint32_t OVER8 : 1;  // Oversampling mode
                uint32_t DEDT : 5;  // Driver Enable de-assertion time
                uint32_t DEAT : 5;  // Driver Enable assertion time
                uint32_t RTOIE : 1;  // Receiver timeout interrupt enable
                uint32_t EOBIE : 1;  // End of Block interrupt enable
                uint32_t M1 : 1;  // Word length 1
                uint32_t : 3;
            } b;
        };
    };

    struct Cr2 {
        /** Control register 2
         */
        Cr2() {}
        Cr2(uint32_t raw) { r = raw; }
        union {
            uint32_t r;
            struct {
                uint32_t : 4;
                uint32_t ADDM7 : 1;  // 7-bit Address Detection/4-bit Address Detection
                uint32_t LBDL : 1;  // LIN break detection length
                uint32_t LBDIE : 1;  // LIN break detection interrupt enable
                uint32_t : 1;
                uint32_t LBCL : 1;  // Last bit clock pulse
                uint32_t CPHA : 1;  // Clock phase
                uint32_t CPOL : 1;  // Clock polarity
                uint32_t CLKEN : 1;  // Clock enable
                uint32_t STOP: 2;  // STOP bits
                uint32_t LINEN : 1;  // LIN mode enable
                uint32_t SWAP : 1;  // Swap TX/RX pins
                uint32_t RXINV : 1;  // RX pin active level inversion
                uint32_t TXINV : 1;  // TX pin active level inversion
                uint32_t DATAINV : 1;  // Binary data inversion
                uint32_t MSBFIRST : 1;  // Most significant bit first
                uint32_t ABREN : 1;  // Auto baud rate enable
                uint32_t ABRMOD : 2;  // Auto baud rate mode
                uint32_t RTOEN : 1;  // Receiver timeout enable
                uint32_t ADD : 8;  // Address of the USART node
            } b;
        };
    };

    struct Cr3 {
        /** Control register 1
         */
        Cr3() {}
        Cr3(uint32_t raw) { r = raw; }
        union {
            uint32_t r;
            struct {
                uint32_t EIE : 1;  // Error interrupt enable
                uint32_t IREN : 1;  // IrDA mode enable
                uint32_t IRLP : 1;  // IrDA low-power
                uint32_t HDSEL : 1;  // Half-duplex selection
                uint32_t NACK : 1;  // Smartcard NACK enable
                uint32_t SCEN : 1;  // Smartcard mode enable
                uint32_t DMAR : 1;  // DMA enable receiver
                uint32_t DMAT : 1;  // DMA enable transmitter
                uint32_t RTSE : 1;  // RTS enable
                uint32_t CTSE : 1;  // CTS enable
                uint32_t CTSIE : 1;  // CTS interrupt enable
                uint32_t ONEBIT : 1;  // One sample bit method enable
                uint32_t OVRDIS : 1;  // Overrun Disable
                uint32_t DDRE : 1;  // DMA Disable on Reception Erro
                uint32_t DEM : 1;  // Driver enable mode
                uint32_t DEP : 1;  // Driver enable polarity selection
                uint32_t : 1;
                uint32_t SCARCNT : 3;  // Smartcard auto-retry count
                uint32_t WUS : 2;  // Wakeup from Stop mode interrupt flag selection (F0, L0)
                uint32_t WUFIE : 1;  // Wakeup from Stop mode interrupt enable (F0, L0)
                uint32_t UCESM : 1;  // USART Clock Enable in Stop mode  (L0)
                uint32_t TCBGTIE : 1;  // Transmission complete before guard time interrupt enable (L4)
                uint32_t : 7;
            } b;
        };
    };

    /** Baud rate register
     */
    struct Brr {
        Brr() {}
        Brr(uint32_t raw) { r = raw; }
        union {
            uint32_t r;
            struct {
                uint32_t DIV_FRACTION : 4;
                uint32_t DIV_MANTIS : 12;
                uint32_t : 16;
            } b;
        };
    };

    /** Guard time and prescaler register
     */
    struct Gtpr {
        Gtpr() {}
        Gtpr(uint32_t raw) { r = raw; }
        union {
            uint32_t r;
            struct {
                uint32_t PSC : 8;  // Prescaler value
                uint32_t GT : 8;  // Guard time value
                uint32_t : 16;
            } b;
        };
    };

    /** Receiver timeout register
     */
    struct Rtor {
        Rtor() {}
        Rtor(uint32_t raw) { r = raw; }
        union {
            uint32_t r;
            struct {
                uint32_t RTO : 24;  // Receiver timeout value
                uint32_t BLEN : 8;  // Block Length
            } b;
        };
    };

    /** Request register
     */
    struct Rqr {
        Rqr() {}
        Rqr(uint32_t raw) { r = raw; }
        union {
            uint32_t r;
            struct {
                uint32_t ABRRQ : 1;  // Auto baud rate reques
                uint32_t SBKRQ : 1;  // Send break request
                uint32_t MMRQ : 1;  // Mute mode request
                uint32_t RXFRQ : 1;  // Receive data flush request
                uint32_t TXFRQ : 1;  // Transmit data flush request
                uint32_t : 27;
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
                const uint32_t PE : 1;  // Parity error
                const uint32_t FE : 1;  // Framing error
                const uint32_t NF : 1;  // START bit Noise detection flag
                const uint32_t ORE : 1;  // Overrun error
                const uint32_t IDLE : 1;  // Idle line detected
                const uint32_t RXNE : 1;  // Read data register not empty
                const uint32_t TC : 1;  // Transmission complete
                const uint32_t TXE : 1;  // Transmit data register empty
                const uint32_t LBDF : 1;  // LIN break detection flag
                const uint32_t CTSIF : 1;  // CTS interrupt flag
                const uint32_t CTS : 1;  // CTS flag
                const uint32_t RTOF : 1;  // Receiver timeout
                const uint32_t EOBF : 1;  // End of block flag
                uint32_t : 1;
                const uint32_t ABRE : 1;  // Auto baud rate error
                const uint32_t ABRF : 1;  // Auto baud rate flag
                const uint32_t BUSY : 1;  // Busy flag
                const uint32_t CMF : 1;  // Character match flag
                const uint32_t SBKF : 1;  // Send break flag
                const uint32_t RWU : 1;  // Receiver wakeup from Mute mode
                const uint32_t WUF : 1;  // Wakeup from Stop mode flag (F0, L0)
                const uint32_t TEACK : 1;  // Transmit enable acknowledge flag
                const uint32_t REACK : 1;  // Receive enable acknowledge flag (F0, L0)
                uint32_t : 2;
                const uint32_t TCBGT : 1;  // Transmission complete before guard time completion (L4)
                uint32_t : 6;
            } b;
        };
    };

    /** Interrupt flag clear register
     */
    struct Icr {
        Icr() {}
        Icr(uint32_t raw) { r = raw; }
        union {
            uint32_t r;
            struct {
                uint32_t PECF : 1;  // Parity error clear flag
                uint32_t FECF : 1;  // Framing error clear flag
                uint32_t NCF : 1;  // Noise detected clear flag
                uint32_t ORECF : 1;  // Overrun error clear flag
                uint32_t IDLECF : 1;  // Idle line detected clear flag
                uint32_t : 1;
                uint32_t TCCF : 1;  // Transmission complete clear flag
                uint32_t : 1;
                uint32_t LBDFCF : 1;  // LIN break detection clear flag
                uint32_t CTSCF : 1;  // CTS clear flag
                uint32_t : 1;
                uint32_t RTOCF : 1;  // Receiver timeout clear flag
                uint32_t EOBFCF : 1;  // End of block clear flag
                uint32_t : 4;
                uint32_t CMCF : 1;  // Character match clear flag
                uint32_t : 2;
                uint32_t WUCF : 1;  // Wakeup from Stop mode clear flag (F0, L0)
                uint32_t : 11;
            } b;
        };
    };

    /** data register
     */
    struct Dr {
        union {
            uint32_t r;
            uint32_t DR;  // Data register
            uint16_t DR16;  // 16 bit access
        };
    };

    volatile Cr1 CR1;  // Control register 1
    volatile Cr2 CR2;  // Control register 2
    volatile Cr3 CR3;  // Control register 1
    volatile Brr BRR;  // Baud rate register
    volatile Gtpr GTPR;  // Guard time and prescaler register
    volatile Rtor RTOR;  // Receiver timeout register
    volatile Rqr RQR;  // Request register
    volatile Isr ISR;  // Interrupt and status register
    volatile Icr ICR;  // Interrupt flag clear register
    volatile Dr RDR;  // Receiver data register
    volatile Dr TDR;  // Transceiver data register
};

static inline constexpr Usart &USART(const size_t base) {
    return *reinterpret_cast<Usart *>(base);
}

}
