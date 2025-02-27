/* linker.ld - Minimal freestanding linker script for x86 (32-bit) with Position-Independent Code (PIC) */

/* Set the entry point to _start, this is where execution begins */
ENTRY(_start)

/* Define the memory layout */
SECTIONS {
    /* Start the program at address 0x10000 (can be changed if needed) */
    . = 0x10000;

    /* The .text section for the code (position-independent code) */
    .text : {
        *(.text)    /* Include all code in .text sections */
        *(.text*)   /* Include any additional .text* sections */
    }

    /* The .data section for initialized global/static variables (like strings) */
    .data : {
        *(.data)    /* Include all initialized data */
        *(.data*)   /* Include any other .data* sections */
    }

    /* The .bss section for uninitialized global/static variables */
    .bss : {
        *(.bss)     /* Include all uninitialized data */
        *(.bss*)    /* Include any other .bss* sections */
        *(COMMON)   /* Include common symbols */
    }
}
