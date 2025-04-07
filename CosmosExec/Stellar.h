#pragma once

#include <stdarg.h>


typedef unsigned int size_t;

/// @brief Prevents name mangling for C++ compilers
#ifdef __cplusplus
#define NO_NAME_MANGLE extern "C"
#else
#define NO_NAME_MANGLE
#endif

#define NULL 0


#define __stdcall __attribute__((__stdcall__))
#define __cdecl __attribute__((__cdecl__))
#define __fastcall __attribute__((__fastcall__))
#define __packed __attribute__((__packed__))

typedef struct idt_entry_struct {
    unsigned short base_low;  // lower 16 bits of the base address
    unsigned short selector;   // selector in GDT or LDT
    unsigned char zero;        // unused, set to 0
    unsigned char flags;       // type and attributes
    unsigned short base_high;  // upper 16 bits of the base address
} __packed idt_entry_t;

typedef struct idt_ptr_struct {
    unsigned short limit; // size of the IDT in bytes - 1
    unsigned int base;    // address of the first entry in the IDT
} __packed idt_ptr_t;

typedef struct _iobuf {
    char *_ptr;
    int _cnt;
    char *_base;
    int _flag;
    int _file;
    int _charbuf;
    int _bufsiz;
    char *_tmpfname;
} FILE;

#include "Cosmos.h"

#pragma region FUNCTION DECLARATIONS

char* utf16_to_ascii(const char* utf16);
char* ascii_to_utf16(const char* ascii);

int strlen(char* str);
int strcmp(const char* str1, const char* str2);
char* strncpy(char* dest, const char* src, unsigned int n);
int strcspn(const char* str1, const char* str2);
int strtol(const char* str, char** endptr, int base);
unsigned int strtoul(const char* str, char** endptr, int base);
float strtof(const char* str, char** endptr);
int tolower(int c);
int toupper(int c);
int isdigit(int c);

/// @brief Copies memory from one location to another
/// @param dest The destination to copy to
/// @param src The source to copy from
/// @param n The number of bytes to copy
/// @return A pointer to the destination
void* memcpy(void* dest, const void* src, unsigned int n);

/// @brief Sets a block of memory to a specific value
/// @param dest The destination to set
/// @param c The value to set the memory to
/// @param n The number of bytes to set
/// @return A pointer to the destination
void* memset(void* dest, int c, unsigned int n);

/// @brief Moves a block of memory from one location to another
/// @param dest The destination to move to
/// @param src The source to move from
/// @param n The number of bytes to move
/// @return A pointer to the destination
void* memmove(void* dest, const void* src, unsigned int n);

/// @brief Compares two blocks of memory
/// @param ptr1 The first block of memory to compare
/// @param ptr2 The second block of memory to compare
/// @param n The number of bytes to compare
/// @return 0 if the blocks are equal, a negative number if ptr1 is less than ptr2, and a positive number if ptr1 is greater than ptr2
void* memcmp(const void* ptr1, const void* ptr2, unsigned int n);

/// @brief Searches for a specific value in a block of memory
/// @param ptr The block of memory to search
/// @param c The value to search for
/// @param n The number of bytes to search
/// @return A pointer to the first occurrence of the value, or NULL if not found
void* memchr(const void* ptr, int c, unsigned int n);

/// @brief Write a byte to a specific port
/// @param port The port to write to
/// @param value The byte to write
void stellar_outb(unsigned short port, unsigned char value);

/// @brief Read a byte from a specific port
/// @param port The port to read from
/// @return The byte read
unsigned char stellar_inb(unsigned short port);

/// @brief Read a word from a specific port
/// @param port The port to read from
/// @return The word read
unsigned short stellar_inw(unsigned short port);

/// @brief Write a word to a specific port
/// @param port The port to write to
/// @param value The word to write
void stellar_outw(unsigned short port, unsigned short value);

/// @brief Read a double word from a specific port
/// @param port The port to read from
/// @return The double word read
unsigned int stellar_inl(unsigned short port);

/// @brief Write a double word to a specific port
/// @param port The port to write to
/// @param value The double word to write
/// @return The double word written
void stellar_outl(unsigned short port, unsigned int value);

/// @brief Initialize the serial port (COM1) for debugging
/// @note This function sets the baud rate to 38400, 8 data bits, no parity, and 1 stop bit
void debug_serial_init(void);

/// @brief Write a char out COM1
/// @param c The char to write
/// @return 0 if successful, -1 if failed
int debug_putchar(int c);

/// @brief Read a char from COM1
/// @return The char read, or -1 if failed
char debug_getchar(void);

/// @brief Write a string out COM1
/// @param str The string to write
/// @return 0 if successful, -1 if failed
/// @note The string must be null-terminated
int debug_puts(const char* str);

/// @brief Read a string from COM1
/// @param str The string to read into
/// @param size The size of the string buffer
/// @return 0 if successful, -1 if failed
/// @note The string will be truncated if it exceeds the size of the buffer
int debug_gets(char* str, size_t size);

/// @brief Get the current IDT of the CPU
void get_current_idt(void);

/// @brief Retrieve the IDT
/// @return The IDT of the CPU
idt_ptr_t get_idt(void);

/// @brief Set the IDT of the CPU
/// @param idt The IDT to set
void set_idt(idt_ptr_t idt_ptr);

/// @brief Set IDT Gate
/// @param num The interrupt number
/// @param base The base address of the interrupt handler
/// @param sel The segment selector
/// @param flags The flags for the interrupt gate
void set_idt_gate(unsigned char num, unsigned long base, unsigned short sel, unsigned char flags);

/// @brief Get the base address of an IDT gate
/// @param num The interrupt number
/// @return The base address of the IDT gate
unsigned long get_idt_gate_base(unsigned char num);


/// COSMOS SUPPORT FUNCTIONS

void* malloc(size_t size);
void free(void* ptr);
void* calloc(size_t num, size_t size);
void* realloc(void* ptr, size_t size);

int isspace(int c);

void itoa(int num, char* str, int base);
void ltoa(long num, char* str, int base);
void utoa(unsigned int num, char* str, int base);
void ultoa(unsigned long num, char* str, int base);
void uitoa(unsigned int num, char* str, int base);
void atoi(int num, char* str, int base);

void printf(const char* format, ...);
int sprintf(char* str, const char* format, ...);
int snprintf(char* str, size_t size, const char* format, ...);
void vsnprintf(char *str, size_t size, const char *format, va_list args);
void vsprintf(char* str, const char* format, va_list ap);
void clrscr(void);

void gets(char* str, size_t size);

//scanf functions
int scanf(const char *fmt, ...);
int sscanf(const char* str, const char* format, ...);


#define SEEK_SET 0
#define SEEK_CUR 1
#define SEEK_END 2

//file functions
FILE* fopen(const char* filename, const char* mode);
int fclose(FILE* file);
int fread(void* buffer, unsigned int size, unsigned int nmemb, FILE* stream);
int fwrite(void* buffer, unsigned int size, unsigned int nmemb, FILE* stream);
int fseek(FILE* stream, int offset, int whence);
int ftell(FILE* stream);
int fflush(FILE* stream);


#pragma endregion FUNCTION DECLARATIONS