/**
* Functions for setup DATA memory
* (non-zero initialized static variables)
*/

#pragma once

// data
extern unsigned __data_start;
extern unsigned __data_end;
// data load
extern unsigned __data_load;

/** Copy statically defined variables
 */
inline void copy_data() {
    unsigned *src = &__data_load;
    unsigned *dst = &__data_start;
    while (dst < &__data_end) {
        *dst++ = *src++;
    }
}
