/**
 * Start-up code
 */

#include "io/startup/_common/data.hpp"
#include "io/startup/_common/bss.hpp"
#include "io/startup/_common/heap.hpp"
#include "io/startup/_common/cdtors.hpp"

extern void main_app();

void RESET_handler() {
    copy_data();
    zero_bss();
    fill_heap();
    call_ctors();
    // run application
    main_app();
    // call destructors for static instances
    call_dtors();
    // stop
    while (true);
}
