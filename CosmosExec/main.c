#include "Cosmos.h"

int get_file_size(FILE* file) {
    int current_pos = ftell(file);
    fseek(file, 0, SEEK_END);
    int size = ftell(file);
    fseek(file, current_pos, SEEK_SET);
    return size;
}

NO_NAME_MANGLE void main(void*** funcTable) {
    COSMOS_INIT();

    clrscr();

    Graphics_Create_Canvas(800, 600);

    Graphics_Clear(0xFF0000); // Red background

    Graphics_Display();

    return;
}