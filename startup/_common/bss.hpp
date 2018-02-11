/**
* Functions for setup BSS memory
* (zero and uninitialized static variables)
*/

#pragma once

// bss
extern unsigned _bss_start;
extern unsigned _bss_end;

/** Zero static variables with zero or undefined value
 */
inline void zero_bss() {
    unsigned *dst = &_bss_start;
    while (dst < &_bss_end) {
        *dst++ = 0;
    }
}
