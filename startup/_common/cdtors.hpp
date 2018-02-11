/**
* Functions for setup static objects
*/

#pragma once

// constructors array
extern unsigned _init_array_start;
extern unsigned _init_array_end;

/** call constructors for static objects
 */
inline void call_ctors() {
    unsigned *tbl = &_init_array_start;
    while (tbl < &_init_array_end) {
        ((void (*)())*tbl++)();
    }
}

// destructors array
extern unsigned _fini_array_start;
extern unsigned _fini_array_end;

/** call destructors for static objects
 */
inline void call_dtors() {
    unsigned *tbl = &_fini_array_start;
    while (tbl < &_fini_array_end) {
        ((void (*)())*tbl++)();
    }
}
