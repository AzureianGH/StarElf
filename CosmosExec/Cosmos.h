#pragma once
#include "Stellar.h"
#define PREVENT_ENCODING_MANGLING
#define main __stdcall _start
#define COSMOS_INIT() debug_serial_init(); Cosmos_RegisterFunctionTable(funcTable);

#define COLOR_DEPTH_32 32
#define COLOR_DEPTH_24 24
#define COLOR_DEPTH_16 16
#define COLOR_DEPTH_8 8

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

/// @brief Open a file for reading or writing
/// @param filename The name of the file to open
/// @param mode The mode to open the file in (e.g., "r", "w")
/// @return A pointer to the opened file
FILE* File_Open(char* filename, char* mode);

/// @brief Close a file
/// @param file The file to close
/// @return 0 on success, fault otherwise
int File_Close(FILE* file);

/// @brief Reads from a file
/// @param buffer The buffer to read data into
/// @param size The size of each element to read
/// @param nmemb The number of elements to read
/// @param stream The file to read from
/// @return The number of elements read
int File_Read(void* buffer, unsigned int size, unsigned int nmemb, FILE* stream);

/// @brief Write to a file
/// @param buffer The buffer to write data from
/// @param size The size of each element to write
/// @param nmemb The number of elements to write
/// @param stream The file to write to
/// @return The number of elements written
int File_Write(void* buffer, unsigned int size, unsigned int nmemb, FILE* stream);

/// @brief Seek to a position in a file
/// @param stream The file to seek in
/// @param offset The offset to seek to
/// @param whence The reference point for the offset (e.g., SEEK_SET, SEEK_CUR, SEEK_END)
/// @return 0 on success, fault otherwise
int File_Seek(FILE* stream, int offset, int whence);

/// @brief Get the current position in a file
/// @param stream The file to get the position from
/// @return The current position in the file
int File_Tell(FILE* stream);

/// @brief Flush the file buffer
/// @param stream The file to flush
/// @return 0 on success, fault otherwise
int File_Flush(FILE* stream);

/// @brief Create a canvas for graphics
/// @param width The width of the canvas
/// @param height The height of the canvas
/// @param colordepth The color depth of the canvas
void Graphics_Create_Canvas(int width, int height, char colordepth);

/// @brief Resize the canvas
/// @param width The new width of the canvas
/// @param height The new height of the canvas
void Graphics_Resize_Canvas(int width, int height);

/// @brief Retrieve the framebuffer
/// @param framebuffer The pointer to the framebuffer to fill
void Graphics_Retrieve_Framebuffer(unsigned int** framebuffer);

/// @brief Display the graphics on the screen
void Graphics_Display(void);