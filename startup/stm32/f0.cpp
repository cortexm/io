/**
 * Start-up code
 */

#include "io/startup/_common/data.hpp"
#include "io/startup/_common/bss.hpp"
#include "io/startup/_common/heap.hpp"
#include "io/startup/_common/arrays.hpp"

extern void main_app();

void RESET_handler() {
    copy_data();
    zero_bss();
    fill_heap();
    call_preinit_array();
    call_init_array();
    // run application
    main_app();
    // call destructors for static instances
    call_fini_array();
    // stop
    while (true);
}
