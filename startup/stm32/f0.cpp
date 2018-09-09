/**
 * Start-up code
 */

#include "io/lib/main_app.hpp"
#include "io/startup/_common/data.hpp"
#include "io/startup/_common/bss.hpp"
#include "io/startup/_common/heap.hpp"
#include "io/startup/_common/init.hpp"
#include "io/startup/_common/fini.hpp"

void RESET_handler() {
    copy_data();
    zero_bss();
    fill_heap();
    call_init_array();
    // run application
    main_app();
    // call destructors for static instances
    call_fini_array();
    // stop
    while (true);
}
