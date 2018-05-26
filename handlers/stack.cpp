/**
 * Stack setup
 */

// top of stack
extern unsigned __stacktop;

// put top of stack into ".stack" section
__attribute__((section(".stack"), used)) unsigned *__stack_init = &__stacktop;
