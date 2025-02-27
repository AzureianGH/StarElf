#define VIDEO_MEMORY 0xb8000
#define SCREEN_WIDTH 80
#define SCREEN_HEIGHT 25

void clear_screen() {
    char* video_memory = (char*) VIDEO_MEMORY;
    for (int i = 0; i < SCREEN_WIDTH * SCREEN_HEIGHT; i++) {
        *video_memory = ' ';
        video_memory++;
        *video_memory = 0x0f;
        video_memory++;
    }
}

void print_char(char c, int col, int row) {
    char* video_memory = (char*) VIDEO_MEMORY;
    video_memory += 2 * (row * SCREEN_WIDTH + col);
    *video_memory = c;
    video_memory++;
    *video_memory = 0x0f;
}

void print_string(const char* str, int col, int row) {
    //use printchar
    for (int i = 0; str[i] != '\0'; i++) {
        print_char(str[i], col + i, row);
    }
}

void print_string_length(const char* str, int col, int row, int length) {
    //use printchar
    for (int i = 0; i < length; i++) {
        print_char(str[i], col + i, row);
    }
}

int strlen(const char* str) {
    int len = 0;
    while (*str) {
        len++;
        str++;
    }
    return len;
}

void _start() {
    clear_screen();
    while (1);
}