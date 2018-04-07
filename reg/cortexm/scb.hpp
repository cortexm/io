/**
* Peripheral Definition File
*
* SCB - System Control Block
*
* MCUs containing this peripheral:
*  - Cortex M0
*  - Cortex M0plus
*  - Cortex M3
*  - Cortex M4
*  - Cortex M7
*/

#pragma once

#include <cstdint>
#include <cstddef>

namespace io {

struct Scb {
    /** CPUID Register
     */
    struct Cpuid {
        Cpuid(const uint32_t raw=0) { r = raw; }

        struct Bits {
            const uint32_t REVISION : 4;  // Revision number
            const uint32_t PARTNO : 12;  // Part number of the processor
            const uint32_t ARCHITECTURE : 4;  // Architecture
            const uint32_t VARIANT : 4;  // Part Number
            const uint32_t IMPLEMENTER : 8;  // Revision number
        };

        struct Partno {
            static const uint32_t CORTEX_M0 = 0xc20;
            static const uint32_t CORTEX_M0P = 0xc60;
            static const uint32_t CORTEX_M3 = 0xc23;
            static const uint32_t CORTEX_M4 = 0xc24;
            static const uint32_t CORTEX_M7 = 0xc27;
        };

        struct Architecture {
            static const uint32_t ARMV6M = 0xc;  // M0, M0+
            static const uint32_t ARMV7M = 0xf;  // M3, M4, M7
        };

        struct Implementer {
            static const uint32_t ARM = 0x41;
        };

        union {
            uint32_t r;
            Bits b;
        };
    };

    /** Interrupt control and state register
     */
    struct Icsr {
        Icsr(const uint32_t raw=0) { r = raw; }

        struct Bits {
            uint32_t VECTACTIVE : 9;  // Active vector
            uint32_t : 2;
            const uint32_t RETOBASE : 1;  //  Return to base level (M0+, M3, M4, M7)
            const uint32_t VECTPENDING : 9;  // Pending vector
            uint32_t : 1;
            const uint32_t ISRPENDING : 1;  // Interrupt pending flag
            uint32_t : 2;
            uint32_t PENDSTCLR : 1;  // SysTick exception clear-pending bit
            uint32_t PENDSTSET : 1;  // SysTick exception set-pending bit
            uint32_t PENDSVCLR : 1;  // PendSV clear-pending bit
            uint32_t PENDSVSET : 1;  // PendSV set-pending bit
            uint32_t : 2;
            uint32_t NMIPENDSET : 1;  // NMI set-pending bit
        };

        union {
            uint32_t r;
            Bits b;
        };
    };

    /** Vector Table Offset Register
     */
    struct Vtor {
        union {
            uint32_t r;
            uint32_t TBLOFF;  // Vector table base offset field
        };
    };

    /** Application Interrupt and Reset Control Register
     */
    struct Aircr {
        Aircr(const uint32_t raw=0) { r = raw; }

        struct Bits {
            uint32_t VECTRESET : 1;  // Reserved for Debug use
            uint32_t VECTCLRACTIVE : 1;  // Reserved for Debug use
            uint32_t SYSRESETREQ : 1;  // System reset request
            uint32_t : 5;
            uint32_t PRIGROUP : 3;  // Interrupt priority grouping field (M3, M4, M7)
            uint32_t : 4;
            const uint32_t ENDIANESS : 1;  // Data endianness bit
            uint32_t VECTKEY : 16;  // Register key
        };

        struct Endianess {
            static const uint32_t LITTLE_ENDIAN = 0;
        };

        union {
            uint32_t r;
            Bits b;
        };
    };

    /** System control registe
     */
    struct Scr {
        Scr(const uint32_t raw=0) { r = raw; }

        struct Bits {
            uint32_t : 1;
            uint32_t SLEEPONEXIT : 1;  // Seep on return from interrupt
            uint32_t SLEEPDEEP : 1;  // Use deep sleep mode
            uint32_t : 1;
            uint32_t SEVONPEND : 1;  // Send Event on Pending bit
            uint32_t : 27;
        };

        union {
            uint32_t r;
            Bits b;
        };
    };

    /** Configuration and control register
     */
    struct Ccr {
        Ccr(const uint32_t raw=0) { r = raw; }

        struct Bits {
            uint32_t NONBASETHRDENA : 1;  // Configures how the processor enters Thread mode (M3, M4, M7)
            uint32_t USERSETMPEND : 1;  // Enables unprivileged software access to the STIR (M3, M4, M7)
            uint32_t : 1;
            uint32_t UNALIGN_TRP : 1;  // Enables unaligned access traps
            uint32_t DIV_0_TRP : 1;  // Trap on SDIV or UDIV with a divisor of 0 (M3, M4, M7)
            uint32_t : 3;
            uint32_t BFHFNMIGN : 1;  // Enables handlers with priority -1 or -2 (M3, M4, M7)
            uint32_t STKALIGN : 1;  // Configures stack alignment on exception entry
            uint32_t : 22;
        };

        union {
            uint32_t r;
            Bits b;
        };
    };

    /** System handler priority register
     */
    struct Shpr {
        Shpr(const uint32_t raw0=0, const uint32_t raw1=0, const uint32_t raw2=0) { r[0] = raw0; r[1] = raw1; r[2] = raw2; }

        struct Bits {
            uint8_t PRI_4;  // MEMMANAGE handler priority (M3, M4, M7)
            uint8_t PRI_5;  // BUSFAULT handler priority (M3, M4, M7)
            uint8_t PRI_6;  // USAGEFAULT handler priority (M3, M4, M7)
            uint8_t __res7;
            uint8_t __res8;
            uint8_t __res9;
            uint8_t __res10;
            uint8_t PRI_11;  // SVCALL handler priority
            uint8_t __res12;  // DEBUGMONITOR handler priority
            uint8_t __res13;
            uint8_t PRI_14;  // PENDSV handler priority
            uint8_t PRI_15;  // SYSTICK handler priority
        };

        union {
            uint32_t r[3];
            Bits b;
        };
    };

    /** System handler control and state register (M3, M4, M7)
     */
    struct Shcsr {
        Shcsr(const uint32_t raw=0) { r = raw; }

        struct Bits {
            uint32_t MEMFAULTACT : 1;  // Memory management fault exception active bit
            uint32_t BUSFAULTACT : 1;  //  Bus fault exception active bit
            uint32_t : 1;
            uint32_t USGFAULTACT : 1;  // Usage fault exception active bit
            uint32_t : 3;
            uint32_t SVCALLACT : 1;  // SVC call active bit
            uint32_t MONITORACT : 1;  // Debug monitor active bit
            uint32_t : 1;
            uint32_t PENDSVACT : 1;  // PendSV exception active bit
            uint32_t SYSTICKACT : 1;  // SysTick exception active bit
            uint32_t USGFAULTPENDED : 1;  // Usage fault exception pending bit
            uint32_t MEMFAULTPENDED : 1;  // Memory management fault exception pending bit
            uint32_t BUSFAULTPENDED : 1;  // Bus fault exception pending bit
            uint32_t SVCALLPENDED : 1;  // SVC call pending bit
            uint32_t MEMFAULTENA : 1;  // Memory management fault enable bit
            uint32_t BUSFAULTENA : 1;  // Bus fault enable bit
            uint32_t USGFAULTENA : 1;  // Usage fault enable bit
            uint32_t : 13;
        };

        union {
            uint32_t r;
            Bits b;
        };
    };

    /** Configurable fault status register (M3, M4, M7)
     */
    struct Cfsr {
        Cfsr(const uint32_t raw=0) { r = raw; }

        struct Bits {
            uint32_t IACCVIOL : 1;  // Instruction access violation flag
            uint32_t DACCVIOL : 1;  // Data access violation flag
            uint32_t : 1;
            uint32_t MUNSTKERR : 1;  // Memory manager fault on unstacking for a return from exception
            uint32_t MSTKERR : 1;  // Memory manager fault on stacking for exception entry
            uint32_t MLSPERR : 1;  // MemManage fault occurred during floating-point lazy state (M4, M7)
            uint32_t : 1;
            uint32_t MMARVALID : 1;  // Memory Management Fault Address Register (MMAR) valid flag
            uint32_t IBUSERR : 1;  // Instruction bus error
            uint32_t PRECISERR : 1;  // Precise data bus error
            uint32_t IMPRECISERR : 1;  // Imprecise data bus error
            uint32_t UNSTKERR : 1;  // Bus fault on unstacking for a return from exception
            uint32_t STKERR : 1;  // Bus fault on stacking for exception entry
            uint32_t LSPERR : 1;  // Bus fault on floating-point lazy state preservation (M4, M7)
            uint32_t : 1;
            uint32_t BFARVALID : 1;  // Bus Fault Address Register (BFAR) valid flag
            uint32_t UNDEFINSTR : 1;  // Undefined instruction usage fault
            uint32_t INVSTATE : 1;  // Invalid state usage fault
            uint32_t INVPC : 1;  // Invalid PC load usage fault
            uint32_t NOCP : 1;  // No coprocessor usage fault
            uint32_t : 4;
            uint32_t UNALIGNED : 1;  // Unaligned access usage fault
            uint32_t DIVBYZERO : 1;  // Divide by zero usage fault
            uint32_t : 6;
        };

        union {
            uint32_t r;
            Bits b;
        };
    };

    /** HardFault status register (M3, M4, M7)
     */
    struct Hfsr {
        Hfsr(const uint32_t raw=0) { r = raw; }

        struct Bits {
            uint32_t : 1;
            uint32_t VECTTBL : 1;  // Vector table hard fault
            uint32_t : 4;
            uint32_t FORCED : 1;  // Forced hard fault
            uint32_t DEBUG_VT : 1;  // Reserved for Debug use
            uint32_t : 24;
        };

        union {
            uint32_t r;
            Bits b;
        };
    };

    volatile Cpuid CPUID;  // CPUID base register
    volatile Icsr ICSR;  // Interrupt control and state register
    volatile Vtor VTOR;  // Vector Table Offset Register (M3, M4, M7)
    volatile Aircr AIRCR;  // Application Interrupt and Reset Control Register
    volatile Scr SCR;  // System control registe
    volatile Ccr CCR;  // Configuration and control register
    volatile Shpr SHPR;  // System handler priority registers
    volatile Shcsr SHCSR;  // ystem handler control and state register (M3, M4, M7)
    volatile Cfsr CFSR;  // Configurable fault status register (M3, M4, M7)
    volatile Hfsr HFSR;  // HardFault status register (M3, M4, M7)
    volatile uint32_t MMFAR;  // Memory management fault address register (M3, M4, M7)
    volatile uint32_t BFAR;  // Bus fault address register  (M3, M4, M7)
    volatile uint32_t AFSR;  // Auxiliary fault status register  (M4, M7)

    static const size_t BASE = 0xe000ed00;
};

static Scb &SCB = *reinterpret_cast<Scb *>(Scb::BASE);

}
