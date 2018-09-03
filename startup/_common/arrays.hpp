/**
* Functions for setup static objects
*/

#pragma once

typedef void (*array_func_t)();

// pre-constructors array
extern void (*__preinit_array_start[])() __attribute__((weak));
extern void (*__preinit_array_end[])() __attribute__((weak));

/** call pre-constructors for static objects
 */
inline void call_preinit_array() {
    int count = __preinit_array_end - __preinit_array_start;
    for (int i = 0; i < count; i++) {
        __preinit_array_start[i]();
    }
}

// constructors array
extern void (*__init_array_start[])() __attribute__((weak));
extern void (*__init_array_end[])() __attribute__((weak));

/** call constructors for static objects
 */
inline void call_init_array() {
    int count = __init_array_end - __init_array_start;
    for (int i = 0; i < count; i++) {
        __init_array_start[i]();
    }
}

// destructors array
extern void (*__fini_array_start[])() __attribute__((weak));
extern void (*__fini_array_end[])() __attribute__((weak));

/** call destructors for static objects
 */
inline void call_fini_array() {
    int count = __fini_array_end - __fini_array_start;
    for (int i = 0; i < count; i++) {
        __fini_array_start[i]();
    }
}
