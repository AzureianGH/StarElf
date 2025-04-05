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

    Graphics_Create_Canvas(800, 600, COLOR_DEPTH_32);

    unsigned int* fb;
    Graphics_Retrieve_Framebuffer(&fb);

    for (int y = 0; y < 600; y++) {
        for (int x = 0; x < 800; x++) {
            fb[y * 800 + x] = 0xFFFFFFFF; // White ARGB: full alpha, R, G, B
        }
    }
    

    return;
}