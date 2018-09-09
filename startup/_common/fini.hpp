/**
* Functions for setup static objects
*/

#pragma once

#include "io/lib/io_def.hpp"

// destructors array
extern ptr_func_t __fini_array_start[];
extern ptr_func_t __fini_array_end[];

/** call destructors for static objects
 */
inline void call_fini_array() {
    auto array = __fini_array_start;
    while (array < __fini_array_end) {
        (*array)();
        array++;
    }
}
