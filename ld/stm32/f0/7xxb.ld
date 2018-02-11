MEMORY {
    FLASH(rx) : ORIGIN = 0x08000000, LENGTH = 128K
    SRAM(rwx) : ORIGIN = 0x20000000, LENGTH = 16K
}

INCLUDE "io/ld/_common/flash.ld"
INCLUDE "io/ld/_common/sram.ld"
