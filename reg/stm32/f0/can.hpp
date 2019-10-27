/**
* Peripheral Definition File
*
* CAN - Control area network
*
* MCUs containing this peripheral:
*  - STM32F0xx
*/

#pragma once

#include <cstdint>
#include <cstddef>

namespace io {

struct Can {
    /** Master control register
     */
    struct Mcr {
        struct Bits {
            uint32_t INRQ : 1;  // Initialization request
            uint32_t SLEEP : 1;  // Sleep mode request
            uint32_t TXFP : 1;  // TX FIFO priority
            uint32_t RFLM : 1;  // Receiver FIFO locked mode
            uint32_t NART : 1;  // No automatic retransmission
            uint32_t AWUM : 1;  // Automatic wake-up mode
            uint32_t ABOM : 1;  // Automatic bus-off management
            uint32_t TTCM : 1;  // Time triggered communication mode
            uint32_t : 7;
            uint32_t RESET : 1;  // Software master reset
            uint32_t DBF : 1;  // Debug freeze
            uint32_t : 15;
        };

        union {
            uint32_t r;
            Bits b;
        };
    };

    /** Master status register
     */
    struct Msr {
        struct Bits {
            const uint32_t INAK : 1;  // initialization acknowledge
            const uint32_t SLAK : 1;  // sleep acknowledge
            uint32_t ERRI : 1;  // error interrupt
            uint32_t WKUI : 1;  // wakeup interrupt
            uint32_t SLAKI : 1;  // sleep acknowledge interrupt
            uint32_t : 3;
            const uint32_t TXM : 1;  // transmit mode
            const uint32_t RXM : 1;  // receive mode
            const uint32_t SAMP : 1;  // Last sample point
            const uint32_t RX : 1;  // CAN RX signal
            uint32_t : 20;
        };

        union {
            uint32_t r;
            Bits b;
        };
    };

    /** Transmit status register
     */
    struct Tsr {
        struct Bits {
            uint32_t RQCP0 : 1;  // Request completed mailbox 0
            uint32_t TXOK0 : 1;  // Transmission OK for mailbox 0
            uint32_t ALST0 : 1;  // Arbitration lost for mailbox 0
            uint32_t TERR0 : 1;  // Transmission error for mailbox 0
            uint32_t : 3;
            uint32_t ABRQ0 : 1;  // Abort request for mailbox 0
            uint32_t RQCP1 : 1;  // Request completed mailbox 1
            uint32_t TXOK1 : 1;  // Transmission OK for mailbox 1
            uint32_t ALST1 : 1;  // Arbitration lost for mailbox 1
            uint32_t TERR1 : 1;  // Transmission error for mailbox 1
            uint32_t : 3;
            uint32_t ABRQ1 : 1;  // Abort request for mailbox 1
            uint32_t RQCP2 : 1;  // Request completed mailbox 2
            uint32_t TXOK2 : 1;  // Transmission OK for mailbox 2
            uint32_t ALST2 : 1;  // Arbitration lost for mailbox 2
            uint32_t TERR2 : 1;  // Transmission error for mailbox 2
            uint32_t : 3;
            uint32_t ABRQ2 : 1;  // Abort request for mailbox 2
            const uint32_t CODE : 2;  // Mailbox code
            const uint32_t TME0 : 1;  // Transmit mailbox 0 empty
            const uint32_t TME1 : 1;  // Transmit mailbox 1 empty
            const uint32_t TME2 : 1;  // Transmit mailbox 2 empty
            const uint32_t LOW0 : 1;  // Lowest priority flag for mailbox 0
            const uint32_t LOW1 : 1;  // Lowest priority flag for mailbox 1
            const uint32_t LOW2 : 1;  // Lowest priority flag for mailbox 2
        };

        union {
            uint32_t r;
            Bits b;
        };
    };

    /** Receive FIFO register
     */
    struct Rfr {
        struct Bits {
            const uint32_t FMP : 2;  // FIFO messages pending
            uint32_t : 1;
            uint32_t FULL : 1;  // FIFO full
            uint32_t VOVR : 1;  // FIFO overrun
            uint32_t RFOM : 1;  // output mailbox
            uint32_t : 26;
        };

        union {
            uint32_t r;
            Bits b;
        };
    };

    /** Interrupt enable register
     */
    struct Ier {
        struct Bits {
            uint32_t TMEIE : 1;  // Transmit mailbox empty interrupt enable
            uint32_t FMPIE0 : 1;  // FIFO message pending interrupt enable
            uint32_t FFIE0 : 1;  // FIFO full interrupt enable
            uint32_t FOVIE0 : 1;  // FIFO overrun interrupt enable
            uint32_t FMPIE1 : 1;  // FIFO message interrupt enable
            uint32_t FFIE1 : 1;  // FIFO full interrupt enable
            uint32_t FOVIE1 : 1;  // FIFO overrun interrupt enable
            uint32_t : 1;
            uint32_t EWGIE : 1;  // Error warning interrupt enable
            uint32_t EPVIE : 1;  // Error passive interrupt enable
            uint32_t BOFIE : 1;  // Bus-off interrupt enable
            uint32_t LECIE : 1;  // Last error code interrupt enable
            uint32_t : 3;
            uint32_t ERRIE : 1;  // Error interrupt enable
            uint32_t WKUIE : 1;  // Wakeup interrupt enable
            uint32_t SLKIE : 1;  // Sleep interrupt enable
            uint32_t : 14;
        };

        union {
            uint32_t r;
            Bits b;
        };
    };

    /** Error status register
     */
    struct Esr {
        struct Bits {
            const uint32_t EWGF : 1;  // Error warning flag
            const uint32_t EPVF : 1;  // Error passive flag
            const uint32_t BOFF : 1;  // Bus-off flag
            uint32_t : 1;
            uint32_t LEC : 3;  // Last error code
            uint32_t : 9;
            const uint32_t TEC : 8;  // Transmit error counter
            const uint32_t REC : 8;  // Receive error counter
        };

        union {
            uint32_t r;
            Bits b;
        };

        struct Lec {
            static const uint32_t NO_ERROR = 0;  //
            static const uint32_t STUFF_ERROR = 1;  //
            static const uint32_t FORM_ERROR = 2;  //
            static const uint32_t ACK_ERROR = 3;  //
            static const uint32_t BIT_RECESSIVE_ERROR = 4;  //
            static const uint32_t BIT_DOMINANT_ERROR = 5;  //
            static const uint32_t CRC_ERROR = 6;  //
            static const uint32_t SET_BY_SW = 7;  //
        };
    };

    /** Bit timing register
     */
    struct Btr {
        struct Bits {
            uint32_t BRP : 10;  // Baud rate prescaler
            uint32_t : 6;
            uint32_t TS1 : 4;  // Time segment 1
            uint32_t TS2 : 3;  // Time segment 2
            uint32_t : 1;
            uint32_t SJW : 2;  // Resynchronization jump width
            uint32_t : 4;
            uint32_t LBKM : 1;  // Loop back mode
            uint32_t SILM : 1;  // Silent mode
        };

        union {
            uint32_t r;
            Bits b;
        };
    };

    /** CAN transmit mailbox identifier register
     */
    struct Tixr {
        struct Bits {
            uint32_t TXRQ : 1;  // Transmit mailbox request
            uint32_t RTR : 1;  // Remote transmission request
            uint32_t IDE : 1;  // Identifier extension
            uint32_t EXID : 29;  // Extended identifier
        };

        struct Bits1 {
            uint32_t : 21;
            uint32_t STID : 11;  // Standard identifier
        };

        union {
            uint32_t r;
            Bits b;
            Bits1 b1;
        };
    };

    /** CAN mailbox data length control and time stamp register
     */
    struct Tdtxr {
        struct Bits {
            const uint32_t DLC : 4;  // Data length code
            uint32_t : 4;
            const uint32_t TGT : 1;  // Transmit global time
            uint32_t : 7;
            const uint32_t TIME : 16;  // Message time stamp
        };

        union {
            uint32_t r;
            Bits b;
        };
    };

    /** CAN receive mailbox identifier register
     */
    struct Rixr {
        struct Bits {
            uint32_t : 1;
            const uint32_t RTR : 1;  // Remote transmission request
            const uint32_t IDE : 1;  // Identifier extension
            const uint32_t EXID : 29;  // Extended identifier
        };

        struct Bits1 {
            uint32_t : 21;
            const uint32_t STID : 11;  // Standard identifier
        };

        union {
            uint32_t r;
            Bits b;
            Bits1 b1;
        };
    };

    /** CAN mailbox data length control and time stamp register
     */
    struct Rdtxr {
        struct Bits {
            uint32_t DLC : 4;  // Data length code
            uint32_t : 4;
            uint32_t FMI : 8;  // Filter match index
            uint32_t TIME : 16;  // Message time stamp
        };

        union {
            uint32_t r;
            Bits b;
        };
    };

    /** CAN mailbox data low register
     */
    struct Dlxr {
        struct Bits {
            uint32_t DATA0 : 8;  // Data bytes of message
            uint32_t DATA1 : 8;
            uint32_t DATA2 : 8;
            uint32_t DATA3 : 8;
        };

        union {
            uint32_t r;
            Bits b;
        };
    };

    /** CAN mailbox data high register
     */
    struct Dhxr {
        struct Bits {
            uint32_t DATA4 : 8;  // Data bytes of message
            uint32_t DATA5 : 8;
            uint32_t DATA6 : 8;
            uint32_t DATA7 : 8;
        };

        union {
            uint32_t r;
            Bits b;
        };
    };

    /** CAN filter master register
     */
    struct Fmr {
        struct Bits {
            uint32_t FINIT : 1;  // Filter initialization mode
            uint32_t : 31;
        };

        union {
            uint32_t r;
            Bits b;
            FINIT;  // direct access
        };
    };

    /** CAN filter mode register
     */
    struct Fm1r {
        struct Bits {
            uint32_t FBM0 : 1;  // Filter mode
            uint32_t FBM1 : 1;
            uint32_t FBM2 : 1;
            uint32_t FBM3 : 1;
            uint32_t FBM4 : 1;
            uint32_t FBM5 : 1;
            uint32_t FBM6 : 1;
            uint32_t FBM7 : 1;
            uint32_t FBM8 : 1;
            uint32_t FBM9 : 1;
            uint32_t FBM10 : 1;
            uint32_t FBM11 : 1;
            uint32_t FBM12 : 1;
            uint32_t FBM13 : 1;
            uint32_t : 18;
        };

        union {
            uint32_t r;
            Bits b;
            uint32_t FBM;  // direct access
        };
    };

    /** CAN filter scale register
     */
    struct Fs1r {
        struct Bits {
            uint32_t FSC0 : 1;  // Filter scale configuration
            uint32_t FSC1 : 1;
            uint32_t FSC2 : 1;
            uint32_t FSC3 : 1;
            uint32_t FSC4 : 1;
            uint32_t FSC5 : 1;
            uint32_t FSC6 : 1;
            uint32_t FSC7 : 1;
            uint32_t FSC8 : 1;
            uint32_t FSC9 : 1;
            uint32_t FSC10 : 1;
            uint32_t FSC11 : 1;
            uint32_t FSC12 : 1;
            uint32_t FSC13 : 1;
            uint32_t : 18;
        };

        union {
            uint32_t r;
            Bits b;
            uint32_t FSC;  // direct access
        };
    };

    /** CAN filter FIFO assignment register
     */
    struct Ffa1r {
        struct Bits {
            uint32_t FFA0 : 1;  // Filter FIFO assignment for filter x
            uint32_t FFA1 : 1;
            uint32_t FFA2 : 1;
            uint32_t FFA3 : 1;
            uint32_t FFA4 : 1;
            uint32_t FFA5 : 1;
            uint32_t FFA6 : 1;
            uint32_t FFA7 : 1;
            uint32_t FFA8 : 1;
            uint32_t FFA9 : 1;
            uint32_t FFA10 : 1;
            uint32_t FFA11 : 1;
            uint32_t FFA12 : 1;
            uint32_t FFA13 : 1;
            uint32_t : 18;
        };

        union {
            uint32_t r;
            Bits b;
            uint32_t FFA;  // direct access
        };
    };

    /** CAN filter activation register
     */
    struct Fa1r {
        struct Bits {
            uint32_t FACT0 : 1;  // Filter active
            uint32_t FACT1 : 1;
            uint32_t FACT2 : 1;
            uint32_t FACT3 : 1;
            uint32_t FACT4 : 1;
            uint32_t FACT5 : 1;
            uint32_t FACT6 : 1;
            uint32_t FACT7 : 1;
            uint32_t FACT8 : 1;
            uint32_t FACT9 : 1;
            uint32_t FACT10 : 1;
            uint32_t FACT11 : 1;
            uint32_t FACT12 : 1;
            uint32_t FACT13 : 1;
            uint32_t : 18;
        };

        union {
            uint32_t r;
            Bits b;
            uint32_t FACT;  // direct access
        };
    };

    volatile Mcr MCR;  // Master control register
    volatile Msr MSR;  // Master status register
    volatile Tsr TSR;  // Transmit status register
    volatile Rfr RF0R;  // Receive FIFO 0 register
    volatile Rfr RF1R;  // Receive FIFO 1 register
    volatile Ier IER;  // Interrupt enable register
    volatile Esr ESR;  // Error status register
    volatile Btr BTR;  // Bit timing register
    uint32_t __res1[88];  // offset to 0x180
    volatile Tixr TI0R;  // CAN transmit mailbox 0 identifier register
    volatile Tdtxr TDT0R;  // CAN mailbox 0 data length control register
    volatile TDlxr DL0R;  // Data bytes of message
    volatile Dhxr TDH0R;  // Data bytes of message
    volatile Tixr TI1R;  // CAN transmit mailbox 1 identifier register
    volatile Tdtxr TDT1R;  // CAN mailbox 1 data length control register
    volatile Dlxr TDL1R;  // Data bytes of message
    volatile Dhxr TDH1R;  // Data bytes of message
    volatile Tixr TI2R;  // CAN transmit mailbox 2 identifier register
    volatile Tdtxr TDT2R;  // CAN mailbox 2 data length control register
    volatile Dlxr TDL2R;  // Data bytes of message
    volatile Dhxr TDH2R;  // Data bytes of message
    const volatile Rixr RI0R;  // CAN receive mailbox 0 identifier register
    const volatile Rdtxr RDT0R;  // CAN mailbox 0 data length control register
    const volatile Dlxr RDL0R;  // Data bytes of message
    const volatile Dhxr RDH0R;  // Data bytes of message
    const volatile Rixr RI1R;  // CAN receive mailbox 1 identifier register
    const volatile Rdtxr RDT1R;  // CAN mailbox 1 data length control register
    const volatile Dlxr RDL1R;  // Data bytes of message
    const volatile Dhxr RDH1R;  // Data bytes of message
    uint32_t __res2[12];  // offset to 0x200
    volatile Fmr FMR;  // CAN filter master register
    volatile Fm1r FM1R;  // CAN filter mode register
    uint32_t __res3;
    volatile Fs1r FS1R;  // CAN filter scale register
    uint32_t __res4;
    volatile Ffa1r FFA1R;  // CAN filter FIFO assignment register
    uint32_t __res5;
    volatile Fa1r FA1R;  // CAN filter activation register
    uint32_t __res6[8];  // offset to 0x240
    uint32_t FR[28][2];  // Filters: 28 banks: 2 registers
};

namespace base {

static constexpr size_t CAN = 0x40006400;

}

static Can &CAN = *reinterpret_cast<Can *>(base::CAN);

}  // namespace io
