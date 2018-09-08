/**
* Functions for setup static objects
*/

#pragma once

typedef void (*array_func_t)();

// pre-constructors array
extern array_func_t __preinit_array_start[];
extern array_func_t __preinit_array_end[];

/** call pre-constructors for static objects
 */
inline void call_preinit_array() {
    auto array = __preinit_array_start;
    while (array < __preinit_array_end) {
        (*array)();
        array++;
    }
}

// constructors array
extern array_func_t __init_array_start[];
extern array_func_t __init_array_end[];

/** call constructors for static objects
 */
inline void call_init_array() {
    auto array = __init_array_start;
    while (array < __init_array_end) {
        (*array)();
        array++;
    }
}

// destructors array
extern array_func_t __fini_array_start[];
extern array_func_t __fini_array_end[];

/** call destructors for static objects
 */
inline void call_fini_array() {
    auto array = __fini_array_start;
    while (array < __fini_array_end) {
        (*array)();
        array++;
    }
}
