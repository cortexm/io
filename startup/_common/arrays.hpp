/**
* Functions for setup static objects
*/

#pragma once

// pre-constructors array
extern unsigned __preinit_array_start;
extern unsigned __preinit_array_end;

/** call pre-constructors for static objects
 */
inline void call_preinit_array() {
    unsigned *tbl = &__preinit_array_start;
    while (tbl < &__preinit_array_end) {
        ((void (*)())*tbl++)();
    }
}

// constructors array
extern unsigned __init_array_start;
extern unsigned __init_array_end;

/** call constructors for static objects
 */
inline void call_init_array() {
    unsigned *tbl = &__init_array_start;
    while (tbl < &__init_array_end) {
        ((void (*)())*tbl++)();
    }
}

// destructors array
extern unsigned __fini_array_start;
extern unsigned __fini_array_end;

/** call destructors for static objects
 */
inline void call_fini_array() {
    unsigned *tbl = &__fini_array_start;
    while (tbl < &__fini_array_end) {
        ((void (*)())*tbl++)();
    }
}
