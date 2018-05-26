/**
* Functions for setup BSS memory
* (zero and uninitialized static variables)
*/

#pragma once

// bss
extern unsigned __bss_start;
extern unsigned __bss_end;

/** Zero static variables with zero or undefined value
 */
inline void zero_bss() {
    unsigned *dst = &__bss_start;
    while (dst < &__bss_end) {
        *dst++ = 0;
    }
}
