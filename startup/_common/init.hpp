/**
* Functions for setup static objects
*/

#pragma once

#include "io/lib/io_def.hpp"

// constructors array
extern ptr_func_t __preinit_array_start[];
extern ptr_func_t __preinit_array_end[];
extern ptr_func_t __init_array_start[];
extern ptr_func_t __init_array_end[];

/** call constructors for static objects
 */
inline void call_init_array() {
    auto array = __preinit_array_start;
    while (array < __preinit_array_end) {
        (*array)();
        array++;
    }

    array = __init_array_start;
    while (array < __init_array_end) {
        (*array)();
        array++;
    }
}
