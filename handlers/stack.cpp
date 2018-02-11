/**
 * Stack setup
 */

// top of stack
extern unsigned _stacktop;

// put top of stack into ".stack" section
__attribute__((section(".stack"), used)) unsigned *stack_init = &_stacktop;
