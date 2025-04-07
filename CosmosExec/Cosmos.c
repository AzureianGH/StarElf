#include "Cosmos.h"

/// ############################# READ THIS FUCKING NOTE ############################ ///
/// Before you add your own function, for the love of god please know that            ///
/// C# uses UTF-16 encoding for strings. This means that if you pass a string         ///
/// to a function, it will be in UTF-16 encoding. If you want to use ASCII,           ///
/// you need to convert it to UTF-16 first. Also note that function args are          ///
/// passed in reverse order than what you would expect.                               ///
/// ############################# READ THIS FUCKING NOTE ############################ ///

void*** funcTable = 0;

unsigned int framebufferWidth = 0;
unsigned int framebufferHeight = 0;
unsigned int* framebuffer = 0;

char lastEncoding = 0; // 0 = None, 1 = ASCII, 2 = UTF-16
__cdecl void Cosmos_RegisterFunctionTable(void*** table) {
    funcTable = table;
}

/// CLASS 0 (Console)

// INDEX 0
__cdecl void Console_WriteLine16(char* str) 
{
    #ifdef PREVENT_ENCODING_MANGLING
    if (lastEncoding == 0) lastEncoding = 2;
    else if (lastEncoding == 1) {
        Console_WriteLineA("");
    }
    #endif
    void (*print)(char*) = (void (*)(char*)) funcTable[0][0];

    print(str);
}

// INDEX 1
__cdecl void Console_Write16(char* str) 
{
    #ifdef PREVENT_ENCODING_MANGLING
    if (lastEncoding == 0) lastEncoding = 2;
    else if (lastEncoding == 1) {
        Console_WriteLineA("");
    }
    #endif
    void (*print)(char*) = (void (*)(char*)) funcTable[0][1];

    print(str);
}

// INDEX 2
__cdecl char* Console_ReadLine16(void) 
{
    #ifdef PREVENT_ENCODING_MANGLING
    if (lastEncoding == 0) lastEncoding = 2;
    else if (lastEncoding == 1) {
        Console_WriteLineA("");
    }
    #endif
    char* (*read)(void) = (char* (*)(void)) funcTable[0][2];

    return read();
}

// INDEX 3
__cdecl void Console_WriteLineInt32(int num) 
{
    #ifdef PREVENT_ENCODING_MANGLING
    if (lastEncoding == 0) lastEncoding = 2;
    else if (lastEncoding == 1) {
        Console_WriteLineA("");
    }
    #endif
    void (*print)(int) = (void (*)(int)) funcTable[0][3];

    print(num);
}

// INDEX 4
__cdecl void Console_WriteInt32(int num) 
{
    #ifdef PREVENT_ENCODING_MANGLING
    if (lastEncoding == 0) lastEncoding = 2;
    else if (lastEncoding == 1) {
        Console_WriteLineA("");
    }
    #endif
    void (*print)(int) = (void (*)(int)) funcTable[0][4];

    print(num);
}

// INDEX 5
__cdecl void Console_WriteLineUInt32(unsigned int num) 
{
    #ifdef PREVENT_ENCODING_MANGLING
    if (lastEncoding == 0) lastEncoding = 2;
    else if (lastEncoding == 1) {
        Console_WriteLineA("");
    }
    #endif
    void (*print)(unsigned int) = (void (*)(unsigned int)) funcTable[0][5];

    print(num);
}

// INDEX 6
__cdecl void Console_WriteUInt32(unsigned int num) 
{
    #ifdef PREVENT_ENCODING_MANGLING
    if (lastEncoding == 0) lastEncoding = 2;
    else if (lastEncoding == 1) {
        Console_WriteLineA("");
    }
    #endif
    void (*print)(unsigned int) = (void (*)(unsigned int)) funcTable[0][6];

    print(num);
}

// INDEX 7
__cdecl void Console_WriteLineInt64(long long num) 
{
    #ifdef PREVENT_ENCODING_MANGLING
    if (lastEncoding == 0) lastEncoding = 2;
    else if (lastEncoding == 1) {
        Console_WriteLineA("");
    }
    #endif
    void (*print)(long long) = (void (*)(long long)) funcTable[0][7];

    print(num);
}

// INDEX 8
__cdecl void Console_WriteInt64(long long num) 
{
    #ifdef PREVENT_ENCODING_MANGLING
    if (lastEncoding == 0) lastEncoding = 2;
    else if (lastEncoding == 1) {
        Console_WriteLineA("");
    }
    #endif
    void (*print)(long long) = (void (*)(long long)) funcTable[0][8];

    print(num);
}

// INDEX 9
__cdecl void Console_WriteLineUInt64(unsigned long long num) 
{
    #ifdef PREVENT_ENCODING_MANGLING
    if (lastEncoding == 0) lastEncoding = 2;
    else if (lastEncoding == 1) {
        Console_WriteLineA("");
    }
    #endif
    void (*print)(unsigned long long) = (void (*)(unsigned long long)) funcTable[0][9];

    print(num);
}

// INDEX 10
__cdecl void Console_WriteUInt64(unsigned long long num) 
{
    #ifdef PREVENT_ENCODING_MANGLING
    if (lastEncoding == 0) lastEncoding = 2;
    else if (lastEncoding == 1) {
        Console_WriteLineA("");
    }
    #endif
    void (*print)(unsigned long long) = (void (*)(unsigned long long)) funcTable[0][10];

    print(num);
}

// INDEX 11 (float)
__cdecl void Console_WriteLineFloat(float num) 
{
    #ifdef PREVENT_ENCODING_MANGLING
    if (lastEncoding == 0) lastEncoding = 2;
    else if (lastEncoding == 1) {
        Console_WriteLineA("");
    }
    #endif
    void (*print)(float) = (void (*)(float)) funcTable[0][11];

    print(num);
}

// INDEX 12 (float)
__cdecl void Console_WriteFloat(float num) 
{
    #ifdef PREVENT_ENCODING_MANGLING
    if (lastEncoding == 0) lastEncoding = 2;
    else if (lastEncoding == 1) {
        Console_WriteLineA("");
    }
    #endif
    void (*print)(float) = (void (*)(float)) funcTable[0][12];

    print(num);
}

// INDEX 13 (double)
__cdecl void Console_WriteLineDouble(double num) 
{
    #ifdef PREVENT_ENCODING_MANGLING
    if (lastEncoding == 0) lastEncoding = 2;
    else if (lastEncoding == 1) {
        Console_WriteLineA("");
    }
    #endif
    void (*print)(double) = (void (*)(double)) funcTable[0][13];

    print(num);
}

// INDEX 14 (double)
__cdecl void Console_WriteDouble(double num) 
{
    #ifdef PREVENT_ENCODING_MANGLING
    if (lastEncoding == 0) lastEncoding = 2;
    else if (lastEncoding == 1) {
        Console_WriteLineA("");
    }
    #endif
    void (*print)(double) = (void (*)(double)) funcTable[0][14];

    print(num);
}

// INDEX 15
__cdecl void Console_Clear(void) 
{
    #ifdef PREVENT_ENCODING_MANGLING
    if (lastEncoding == 0) lastEncoding = 2;
    else if (lastEncoding == 1) {
        Console_WriteLineA("");
    }
    #endif
    void (*clear)(void) = (void (*)(void)) funcTable[0][15];

    clear();
}

// INDEX 16
__cdecl void Console_SetCursorPosition(int x, int y) 
{
    void (*setCursor)(int, int) = (void (*)(int, int)) funcTable[0][16];

    setCursor(x, y);
}

/// END CLASS 0 (Console)

// CLASS 1 (Heap)

// INDEX 0
__cdecl void* Heap_Alloc(unsigned int size) 
{
    void* (*alloc)(unsigned int) = (void* (*)(unsigned int)) funcTable[1][0];

    return alloc(size);
}

// INDEX 1
__cdecl void Heap_Free(void* ptr) 
{
    void (*free)(void*) = (void (*)(void*)) funcTable[1][1];

    free(ptr);
}

/// END CLASS 1 (Heap)

// CLASS 2 (File)

// INDEX 0
__cdecl FILE* File_Open(char* filename, char* mode) 
{
    FILE* (*open)(char*, char*) = (FILE* (*)(char*, char*)) funcTable[2][0];

    char* utf16 = ascii_to_utf16(filename);
    char* utf16mode = ascii_to_utf16(mode);

    return open(utf16mode, utf16);
}

// INDEX 1
__cdecl int File_Close(FILE* file) 
{
    int (*close)(FILE*) = (int (*)(FILE*)) funcTable[2][1];

    return close(file);
}

// INDEX 2
__cdecl int File_Read(void* buffer, unsigned int size, unsigned int nmemb, FILE* stream) 
{
    int (*read)(void*, unsigned int, unsigned int, FILE*) = (int (*)(void*, unsigned int, unsigned int, FILE*)) funcTable[2][2];
    return read(stream, nmemb, size, buffer);
}

// INDEX 3
__cdecl int File_Write(void* buffer, unsigned int size, unsigned int nmemb, FILE* stream) 
{
    int (*write)(void*, unsigned int, unsigned int, FILE*) = (int (*)(void*, unsigned int, unsigned int, FILE*)) funcTable[2][3];
    return write(stream, nmemb, size, buffer);
}

// INDEX 4
__cdecl int File_Seek(FILE* stream, int offset, int whence) 
{
    int (*seek)(int, int, FILE*) = (int (*)(int, int, FILE*)) funcTable[2][4];
    return seek(whence, offset, stream);
}

// INDEX 5
__cdecl int File_Tell(FILE* stream) 
{
    int (*tell)(FILE*) = (int (*)(FILE*)) funcTable[2][5];
    return tell(stream);
}

// INDEX 6
__cdecl int File_Flush(FILE* stream) 
{
    int (*flush)(FILE*) = (int (*)(FILE*)) funcTable[2][6];
    return flush(stream);
}

// CLASS 3 (Graphics)

// INDEX 0
__cdecl void Graphics_Create_Canvas(int width, int height)
{
    void (*createCanvas)(int, int) = (void (*)(int, int)) funcTable[3][0];

    framebufferWidth = width;
    framebufferHeight = height;
    createCanvas(height, width);

    framebuffer = (unsigned int*)malloc(width * height * sizeof(unsigned int));
}

// INDEX 1
__cdecl void Graphics_Resize_Canvas(int width, int height)
{
    void (*resizeCanvas)(int, int) = (void (*)(int, int)) funcTable[3][1];

    resizeCanvas(height, width);

    framebufferWidth = width;
    framebufferHeight = height;
    framebuffer = (unsigned int*)realloc(framebuffer, width * height * sizeof(unsigned int));
}

// INDEX 2
__cdecl void Graphics_Retrieve_Framebuffer(unsigned int** framebuffer)
{
    
    void (*retrieveFramebuffer)(unsigned int**) = (void (*)(unsigned int**)) funcTable[3][2];

    retrieveFramebuffer(framebuffer);
}

// INDEX 3
__cdecl void Graphics_Display()
{
    void (*display)(void) = (void (*)(void)) funcTable[3][3];

    display();
}

// INDEX 4
__cdecl void Graphics_Flatten(unsigned int* framebuffer)
{
    void (*flatten)(unsigned int*) = (void (*)(unsigned int*)) funcTable[3][4];

    flatten(framebuffer);
}

/// NO CLASS FUNCS

__cdecl void Console_WriteLineA(char* str)
{
    #ifdef PREVENT_ENCODING_MANGLING
    if (lastEncoding == 0) lastEncoding = 1;
    else if (lastEncoding == 2) {
        Console_WriteLineA("");
    }
    #endif
    char* utf16 = ascii_to_utf16(str);
    Console_WriteLine16(utf16);
    Heap_Free(utf16);
    return;
}

__cdecl void Console_WriteA(char* str)
{
    #ifdef PREVENT_ENCODING_MANGLING
    if (lastEncoding == 0) lastEncoding = 1;
    else if (lastEncoding == 2) {
        Console_WriteLineA("");
    }
    #endif
    char* utf16 = ascii_to_utf16(str);
    Console_Write16(utf16);
    Heap_Free(utf16);
    return;
}

__cdecl char* Console_ReadLineA(void) 
{
    #ifdef PREVENT_ENCODING_MANGLING
    if (lastEncoding == 0) lastEncoding = 1;
    else if (lastEncoding == 2) {
        Console_WriteLineA("");
    }
    #endif
    char* utf16 = Console_ReadLine16();
    return utf16_to_ascii(utf16);
}

__cdecl void Graphics_Draw_Pixel(int x, int y, unsigned int color) 
{
    if (x >= 0 && x < framebufferWidth && y >= 0 && y < framebufferHeight) {
        framebuffer[y * framebufferWidth + x] = color;
    }
}
__cdecl void Graphics_Draw_Rectangle(int x, int y, int width, int height, unsigned int color) 
{
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            Graphics_Draw_Pixel(x + j, y + i, color);
        }
    }
}  
__cdecl void Graphics_Clear(unsigned int color) 
{
    for (int i = 0; i < framebufferHeight; i++) {
        for (int j = 0; j < framebufferWidth; j++) {
            framebuffer[i * framebufferWidth + j] = color;
        }
    }
}