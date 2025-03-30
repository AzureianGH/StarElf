#pragma once
#include "Stellar.h"
#define PREVENT_ENCODING_MANGLING
#define main __stdcall _start

/// @brief Register the function table for the kernel to call
/// @param funcTable The function table to register
void Cosmos_RegisterFunctionTable(void*** table);

/// @brief Uses UTF-16 Encoding
/// @param str The string to print
void Console_WriteLine16(char* str);

/// @brief Uses UTF-16 Encoding
/// @param str The string to print
void Console_Write16(char* str);

/// @brief Uses UTF-16 Encoding
/// @return The string captured from the console
char* Console_ReadLine16(void);

/// @brief Uses ASCII Encoding
/// @param str The string to print
void Console_WriteLineA(char* str);

/// @brief Uses ASCII Encoding
/// @param str The string to print
void Console_WriteA(char* str);

/// @brief Uses ASCII Encoding
/// @return The string captured from the console
char* Console_ReadLineA(void);

/// @brief Passes a 32-bit integer to the Console
/// @param num The number to print
void Console_WriteLineInt32(int num);

/// @brief Passes a 32-bit integer to the Console
/// @param num The number to print
void Console_WriteInt32(int num);

/// @brief Passes a 32-bit unsigned integer to the Console
/// @param num The number to print
void Console_WriteLineUInt32(unsigned int num);

/// @brief Passes a 32-bit unsigned integer to the Console
/// @param num The number to print
void Console_WriteUInt32(unsigned int num);

/// @brief Passes a 64-bit integer to the Console
/// @param num The number to print
void Console_WriteLineInt64(long long num);

/// @brief Passes a 64-bit integer to the Console
/// @param num The number to print
void Console_WriteInt64(long long num);

/// @brief Passes a 64-bit unsigned integer to the Console
/// @param num The number to print
void Console_WriteLineUInt64(unsigned long long num);

/// @brief Passes a 64-bit unsigned integer to the Console
/// @param num The number to print
void Console_WriteUInt64(unsigned long long num);

/// @brief Passes a float to the Console
/// @param num The number to print
void Console_WriteLineFloat(float num);

/// @brief Passes a float to the Console
/// @param num The number to print
void Console_WriteFloat(float num);

/// @brief Passes a double to the Console
/// @param num The number to print
void Console_WriteLineDouble(double num);

/// @brief Passes a double to the Console
/// @param num The number to print
void Console_WriteDouble(double num);

/// @brief Clear the console screen
void Console_Clear(void);

/// @brief Set the cursor position in the console
/// @param x The x coordinate of the cursor
/// @param y The y coordinate of the cursor
void Console_SetCursorPosition(int x, int y);

/// @brief Allocate memory from the heap
/// @param size The size of the memory to allocate
/// @return A pointer to the allocated memory
void* Heap_Alloc(unsigned int size);

/// @brief Free memory allocated from the heap
/// @param ptr The pointer to the memory to free
void Heap_Free(void* ptr);