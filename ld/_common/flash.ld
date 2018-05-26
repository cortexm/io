SECTIONS {
    . = ORIGIN(FLASH);
    .stack : {
        KEEP(*(.stack))
    } >FLASH

    .vectors : {
        KEEP(*(.vectors))
        KEEP(*(.vectors*))
    } >FLASH

    .text ALIGN(4) : {
        KEEP(*(.text))
        *(.text*)
    } >FLASH

    .rodata ALIGN(4) : {
        KEEP(*(.rodata))
        *(.rodata*)
        . = ALIGN(4);
    } >FLASH

    .preinit_array ALIGN(4): {
        __preinit_array_start = .;
        KEEP(*(.preinit_array))
        __preinit_array_end = .;
    } >FLASH

    .init_array ALIGN(4): {
        __init_array_start = .;
        KEEP(*(.init_array))
        __init_array_end = .;
    } >FLASH

    .fini_array ALIGN(4): {
        __fini_array_start = .;
        KEEP(*(.fini_array))
        __fini_array_end = .;
    } >FLASH

    /DISCARD/ : {
        *(.ARM.exidx*)
        *(.gnu.linkonce.armexidx.*)
        *(.ARM.attributes)
        *(.debug_frame)
        *(.comment)
    }
}
