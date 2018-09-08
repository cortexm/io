/**
* Functions for setup HEAP memory
*/

#pragma once

// heap start
extern unsigned __heap_start;

/** Clear/fill with pattern content of HEAP memory
 */
inline void fill_heap(unsigned fill=0x45455246) {
    unsigned *dst = &__heap_start;
    unsigned *msp_reg;
    __asm__("mrs %0, msp\n" : "=r" (msp_reg) );
    while (dst < msp_reg) {
        *dst++ = fill;
    }
}
