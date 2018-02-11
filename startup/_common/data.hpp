/**
* Functions for setup DATA memory
* (non-zero initialized static variables)
*/

#pragma once

// data
extern unsigned _data_start;
extern unsigned _data_end;
// data load
extern unsigned _data_load;

/** Copy statically defined variables
 */
inline void copy_data() {
    unsigned *src = &_data_load;
    unsigned *dst = &_data_start;
    while (dst < &_data_end) {
        *dst++ = *src++;
    }
}
