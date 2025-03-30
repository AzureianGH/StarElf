#include "Cosmos.h"
void*** funcTable = 0;
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