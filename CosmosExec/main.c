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

void print_string(const char* str, int col, int row) {
    char* video_memory = (char*) VIDEO_MEMORY;
    video_memory += 2 * (row * SCREEN_WIDTH + col);
    while (*str) {
        *video_memory = *str;
        video_memory++;
        *video_memory = 0x0f;
        video_memory++;
        str++;
    }
}

void delay() {
    for (volatile int i = 0; i < 100000; i++) for (volatile int j = 0; j < 1000; j++);
}

int _start(void* print_func) {
    clear_screen();
    
    int col = 0, row = 0;
    int col_dir = 1, row_dir = 1;
    const char* message = "Hello, World!";
    int message_length = 13; // Length of "Hello, World!"

    while (1) {
        clear_screen();
        print_string(message, col, row);
        
        col += col_dir;
        row += row_dir;

        if (col == 0 || col == SCREEN_WIDTH - message_length) {
            col_dir = -col_dir;
        }
        if (row == 0 || row == SCREEN_HEIGHT - 1) {
            row_dir = -row_dir;
        }

        delay();
    }
}