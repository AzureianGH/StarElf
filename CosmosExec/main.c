#include "Cosmos.h"
void example_IDT_GATE(void) {
    printf("Interrupt Called!\n");
}

NO_NAME_MANGLE void main(void*** funcTable) {
    debug_serial_init();
    Cosmos_RegisterFunctionTable(funcTable);

    clrscr();

    get_current_idt();
    idt_ptr_t idt = get_idt();
    set_idt_gate(0x80, (int)example_IDT_GATE, 0x08, 0x8E);
    set_idt(idt);

    printf("IDT: 0x%p\n", &idt);

    asm volatile("int $0x80");

    return;
}