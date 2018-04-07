/**
* Peripheral Definition File
*
* NVIC - Nested Vector Interrupt Controller
*
* MCUs containing this peripheral:
*  - Cortex-M0
*  - Cortex-M0plus
*  - Cortex-M3
*  - Cortex-M4
*  - Cortex-M7
*/

#pragma once

#include <cstdint>
#include <cstddef>

namespace io {

struct Nvic {
    /** Software trigger interrupt register
     * This register is on Cortex-M3, M4 and M7
     */
    struct Stir {
        Stir(const uint32_t raw=0) { r = raw; }

        struct Bits {
            uint32_t INTID : 9;  // Software generated interrupt ID
            uint32_t : 23;
        };

        union {
            uint32_t r;
            Bits b;
            uint32_t INTID;  // direct 32 bit access to INTID
        };
    };

    volatile uint32_t ISER[8];  // Interrupt set-enable registers
    uint32_t __res0[24];
    volatile uint32_t ICER[8];  // Interrupt clear-enable registers
    uint32_t __res1[24];
    volatile uint32_t ISPR[8];  // Interrupt set-pending registers
    uint32_t __res2[24];
    volatile uint32_t ICPR[8];  // Interrupt clear-pending registers
    uint32_t __res3[24];
    volatile const uint32_t IABR[8];  // Interrupt active bit registers (M3, M4, M7)
    uint32_t __res4[56];
    volatile uint8_t IPR[240];  // Interrupt priority registers
    uint32_t __res5[644];
    volatile Stir STIR;  // Software trigger interrupt register (M3, M4, M7)

    /** Enable interrupt
     * @param isr interrupt ID
     */
    inline void iser(uint32_t isr) {
        ISER[isr >> 5] = 1 << (isr & 0x1f);
    }

    /** Disable interrupt
     * @param isr interrupt ID
     */
    inline void icer(uint32_t isr) {
        ICER[isr >> 5] = 1 << (isr & 0x1f);
    }

    /** Is interrupt enabled
     * @param isr interrupt ID
     * @return True if interrupt is enabled
     */
    inline bool ier(uint32_t isr) const {
        return ISER[isr >> 5] & 1 << (isr & 0x1f);
    }

    /** Enable pending interrupt
     * @param isr interrupt ID
     */
    inline void ispr(uint32_t isr) {
        ISPR[isr >> 5] = 1 << (isr & 0x1f);
    }

    /** Disable pending interrupt
     * @param isr interrupt ID
     */
    inline void icpr(uint32_t isr) {
        ICPR[isr >> 5] = 1 << (isr & 0x1f);
    }

    /** Is pending interrupt
     * @param isr interrupt ID
     * @return True if interrupt is enabled
     */
    inline bool ipr(uint32_t isr) const {
        return ISPR[isr >> 5] & 1 << (isr & 0x1f);
    }

    /** Is interrupt active
     * @param isr interrupt ID
     * @return True if interrupt is active
     */
    inline bool iabr(uint32_t isr) const {
        return IABR[isr >> 5] & 1 << (isr & 0x1f);
    }

    /** Enable global interrupt
     */
    static inline void isr_enable() {
        __asm volatile ("cpsie i" : : : "memory");
    }

    /**
     * disable global interrupt
     */
    static inline void isr_disable() {
        __asm volatile ("cpsid i" : : : "memory");
    }

    static const size_t BASE = 0xe000e100;
};

static Nvic &NVIC = *reinterpret_cast<Nvic *>(Nvic::BASE);

}
