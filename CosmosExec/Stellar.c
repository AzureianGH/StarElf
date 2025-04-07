#include "Stellar.h"

idt_entry_t idt[256] = {0};
idt_ptr_t idt_ptr = {0};

int strlen(char* str) {
    int i = 0;
    while (str[i] != 0) {
        i++;
    }
    return i;
}

int strcmp(const char* str1, const char* str2) {
    while (*str1 && (*str1 == *str2)) {
        str1++;
        str2++;
    }
    return *(unsigned char*)str1 - *(unsigned char*)str2;
}

char* strncpy(char* dest, const char* src, unsigned int n) {
    char* d = dest;
    const char* s = src;
    while (n && *s) {
        *d++ = *s++;
        n--;
    }
    while (n) {
        *d++ = 0;
        n--;
    }
    return dest;
}

int strcspn(const char* str1, const char* str2) {
    int count = 0;
    while (*str1) {
        const char* s = str2;
        while (*s) {
            if (*str1 == *s) {
                return count; // Return the length of the initial segment
            }
            s++;
        }
        count++;
        str1++;
    }
    return count; // Return the length of the entire string if no match found
}

int strtol(const char* str, char** endptr, int base) {
    int result = 0;
    int sign = 1;
    if (*str == '-') {
        sign = -1;
        str++;
    } else if (*str == '+') {
        str++;
    }
    while (*str) {
        int digit = *str - '0';
        if (digit >= 10) {
            digit = *str - 'a' + 10;
        }
        if (digit >= base) {
            break;
        }
        result = result * base + digit;
        str++;
    }
    if (endptr) {
        *endptr = (char*)str;
    }
    return result * sign;
}

float strtof(const char* str, char** endptr) {
    float result = 0.0f;
    int sign = 1;
    if (*str == '-') {
        sign = -1;
        str++;
    } else if (*str == '+') {
        str++;
    }
    while (*str >= '0' && *str <= '9') {
        result = result * 10.0f + (*str - '0');
        str++;
    }
    if (*str == '.') {
        str++;
        float decimal_place = 0.1f;
        while (*str >= '0' && *str <= '9') {
            result += decimal_place * (*str - '0');
            decimal_place *= 0.1f;
            str++;
        }
    }
    if (endptr) {
        *endptr = (char*)str;
    }
    return result * sign;
}

unsigned int strtoul(const char* str, char** endptr, int base) {
    unsigned int result = 0;
    while (*str) {
        int digit = *str - '0';
        if (digit >= 10) {
            digit = *str - 'a' + 10;
        }
        if (digit >= base) {
            break;
        }
        result = result * base + digit;
        str++;
    }
    if (endptr) {
        *endptr = (char*)str;
    }
    return result;
}

int tolower(int c) {
    if (c >= 'A' && c <= 'Z') {
        return c + 32; // Convert uppercase to lowercase
    }
    return c;
}

int toupper(int c) {
    if (c >= 'a' && c <= 'z') {
        return c - 32; // Convert lowercase to uppercase
    }
    return c;
}

int isdigit(int c) {
    return (c >= '0' && c <= '9'); // Check if the character is a digit
}

void* memcpy(void* dest, const void* src, unsigned int n) {
    char* d = (char*)dest;
    const char* s = (const char*)src;
    for (unsigned int i = 0; i < n; i++) {
        d[i] = s[i];
    }
    return dest;
}

void* memset(void* dest, int c, unsigned int n) {
    char* d = (char*)dest;
    for (unsigned int i = 0; i < n; i++) {
        d[i] = (char)c;
    }
    return dest;
}

void* memmove(void* dest, const void* src, unsigned int n) {
    char* d = (char*)dest;
    const char* s = (const char*)src;
    if (d < s) {
        for (unsigned int i = 0; i < n; i++) {
            d[i] = s[i];
        }
    } else {
        for (unsigned int i = n; i > 0; i--) {
            d[i - 1] = s[i - 1];
        }
    }
    return dest;
}

void* memcmp(const void* ptr1, const void* ptr2, unsigned int n) {
    const char* p1 = (const char*)ptr1;
    const char* p2 = (const char*)ptr2;
    for (unsigned int i = 0; i < n; i++) {
        if (p1[i] != p2[i]) {
            return (void*)(p1[i] - p2[i]);
        }
    }
    return 0;
}

void* memchr(const void* ptr, int c, unsigned int n) {
    const char* p = (const char*)ptr;
    for (unsigned int i = 0; i < n; i++) {
        if (p[i] == (char)c) {
            return (void*)&p[i];
        }
    }
    return 0;
}

char* utf16_to_ascii(const char* utf16) {
    int len = 0;
    while (utf16[len * 2] || utf16[len * 2 + 1]) {
        len++;
    }
    char* ascii = (char*)Heap_Alloc(len + 1);
    for (int i = 0; i < len; i++) {
        ascii[i] = utf16[i * 2];
    }
    ascii[len] = 0;
    return ascii;
}

char* ascii_to_utf16(const char* ascii) {
    int len = 0;
    while (ascii[len]) {
        len++;
    }
    char* utf16 = (char*)Heap_Alloc((len + 1) * 2);
    for (int i = 0; i < len; i++) {
        utf16[i * 2] = ascii[i];
        utf16[i * 2 + 1] = 0;
    }
    utf16[len * 2] = 0;
    utf16[len * 2 + 1] = 0;
    return utf16;
}



unsigned char stellar_inb(unsigned short port) {
    unsigned char ret;
    __asm__ __volatile__ ("inb %1, %0" : "=a"(ret) : "Nd"(port));
    return ret;
}

unsigned short stellar_inw(unsigned short port) {
    unsigned short ret;
    __asm__ __volatile__ ("inw %1, %0" : "=a"(ret) : "Nd"(port));
    return ret;
}

unsigned int stellar_inl(unsigned short port) {
    unsigned int ret;
    __asm__ __volatile__ ("inl %1, %0" : "=a"(ret) : "Nd"(port));
    return ret;
}

void stellar_outb(unsigned short port, unsigned char value) {
    __asm__ __volatile__ ("outb %0, %1" : : "a"(value), "Nd"(port));
}

void stellar_outw(unsigned short port, unsigned short value) {
    __asm__ __volatile__ ("outw %0, %1" : : "a"(value), "Nd"(port));
}

void stellar_outl(unsigned short port, unsigned int value) {
    __asm__ __volatile__ ("outl %0, %1" : : "a"(value), "Nd"(port));
}
void debug_serial_init(void) {
    stellar_outb(0x3F8 + 1, 0x00); // Disable all interrupts
    stellar_outb(0x3F8 + 3, 0x80); // Enable DLAB (set baud rate divisor)
    stellar_outb(0x3F8 + 0, 0x01); // Set divisor to 1 (lo byte) 115200 baud for QEMU
    stellar_outb(0x3F8 + 1, 0x00); //                  (hi byte)
    stellar_outb(0x3F8 + 3, 0x03); // 8 bits, no parity, one stop bit
    stellar_outb(0x3F8 + 2, 0xC7); // Enable FIFO, clear them, with 14-byte threshold
    stellar_outb(0x3F8 + 4, 0x0B); // IRQs enabled, RTS/DSR set
}

int debug_putchar(int c) {
    while ((stellar_inb(0x3F8 + 5) & 0x20) == 0); // Wait for the transmit buffer to be empty
    stellar_outb(0x3F8, c); // Send the character
    return c;
}

char debug_getchar(void) {
    while ((stellar_inb(0x3F8 + 5) & 1) == 0); // Wait for data to be available
    return stellar_inb(0x3F8); // Read the character
}

int debug_puts(const char* str) {
    while (*str) {
        debug_putchar(*str++); // Send each character
    }
    debug_putchar('\n'); // Add a newline for QEMU compatibility
    return 0; // Success
}

int debug_gets(char* str, size_t size) {
    size_t i = 0;
    char c;
    while (i < size - 1) { // Leave space for null terminator
        c = debug_getchar();
        debug_putchar(c); // Print the character as it is typed
        if (c == '\n' || c == '\r') {
            break; // End of line
        }
        str[i++] = c; // Store the character
    }
    str[i] = '\0'; // Null-terminate the string
    return i; // Return the number of characters read
}

void get_current_idt(void)
{
    __asm__ __volatile__ ("sidt %0" : "=m"(idt_ptr)); // Store the IDT register in idt_ptr
    // Ensure the IDT array is not overwritten by reinitializing it if necessary
    memcpy(idt, (idt_entry_t*)idt_ptr.base, idt_ptr.limit + 1);
}

idt_ptr_t get_idt(void) {
    idt_ptr.limit = sizeof(idt_entry_t) * 256 - 1;
    idt_ptr.base = (unsigned int)idt; // Ensure the base points to the actual IDT array
    return idt_ptr;
}

void set_idt(idt_ptr_t idt_ptr) {
    __asm__ __volatile__ ("lidt %0" : : "m"(idt_ptr));
    // Ensure the IDT array is not overwritten by reinitializing it if necessary
    memcpy(idt, (idt_entry_t*)idt_ptr.base, idt_ptr.limit + 1);
}

void set_idt_gate(unsigned char num, unsigned long base, unsigned short sel, unsigned char flags)
{
    idt[num].base_low = base & 0xFFFF;
    idt[num].base_high = (base >> 16) & 0xFFFF;
    idt[num].selector = sel;
    idt[num].zero = 0;
    idt[num].flags = flags | 0x60; // Present and interrupt gate
}
unsigned long get_idt_gate_base(unsigned char num)
{
    if (num >= 256) {
        return 0; // Return 0 for invalid IDT entry numbers
    }
    return ((unsigned long)idt[num].base_high << 16) | (unsigned long)idt[num].base_low; // Combine high and low parts of the base address
}


/// COSMOS SUPPORT FUNCTIONS

void* malloc(size_t size) {
    return Heap_Alloc(size); // Use the Heap_Alloc function from the Cosmos library
}
void free(void* ptr) {
    Heap_Free(ptr); // Use the Heap_Free function from the Cosmos library
}
void* calloc(size_t num, size_t size) {
    void* ptr = malloc(num * size); // Allocate memory for num elements of size bytes each
    if (ptr) {
        memset(ptr, 0, num * size); // Initialize the allocated memory to zero
    }
    return ptr;
}
void* realloc(void* ptr, size_t size) {
    if (ptr == NULL) {
        return malloc(size); // If ptr is NULL, allocate new memory
    }
    if (size == 0) {
        free(ptr); // If size is 0, free the memory and return NULL
        return NULL;
    }
    void* new_ptr = malloc(size); // Allocate new memory of the requested size
    if (new_ptr) {
        memcpy(new_ptr, ptr, size); // Copy the old data to the new memory location
        free(ptr); // Free the old memory
    }
    return new_ptr; // Return the pointer to the new memory location
}

int isspace(int c) {
    return (c == ' ' || c == '\t' || c == '\n' || c == '\r' || c == '\f' || c == '\v'); // Check if the character is a whitespace character
}

void itoa(int num, char* str, int base) {
    int i = 0;
    int isNegative = 0;
    if (num < 0 && base == 10) {
        isNegative = 1; // Handle negative numbers for base 10
        num = -num;
    }
    do {
        int rem = num % base;
        str[i++] = (rem > 9) ? (rem - 10) + 'a' : rem + '0'; // Convert to character
        num /= base;
    } while (num != 0);
    if (isNegative) {
        str[i++] = '-'; // Add negative sign if needed
    }
    str[i] = '\0'; // Null-terminate the string
}

void ltoa(long num, char* str, int base) {
    int i = 0;
    int isNegative = 0;
    if (num < 0 && base == 10) {
        isNegative = 1; // Handle negative numbers for base 10
        num = -num;
    }
    do {
        int rem = num % base;
        str[i++] = (rem > 9) ? (rem - 10) + 'a' : rem + '0'; // Convert to character
        num /= base;
    } while (num != 0);
    if (isNegative) {
        str[i++] = '-'; // Add negative sign if needed
    }
    str[i] = '\0'; // Null-terminate the string
}

void utoa(unsigned int num, char* str, int base) {
    int i = 0;
    do {
        int rem = num % base;
        str[i++] = (rem > 9) ? (rem - 10) + 'a' : rem + '0'; // Convert to character
        num /= base;
    } while (num != 0);
    str[i] = '\0'; // Null-terminate the string
}

void ultoa(unsigned long num, char* str, int base) {
    int i = 0;
    do {
        int rem = num % base;
        str[i++] = (rem > 9) ? (rem - 10) + 'a' : rem + '0'; // Convert to character
        num /= base;
    } while (num != 0);
    str[i] = '\0'; // Null-terminate the string
}

void uitoa(unsigned int num, char* str, int base) {
    int i = 0;
    do {
        int rem = num % base;
        str[i++] = (rem > 9) ? (rem - 10) + 'a' : rem + '0'; // Convert to character
        num /= base;
    } while (num != 0);
    str[i] = '\0'; // Null-terminate the string
}

void atoi(int num, char* str, int base) {
    int i = 0;
    do {
        int rem = num % base;
        str[i++] = (rem > 9) ? (rem - 10) + 'a' : rem + '0'; // Convert to character
        num /= base;
    } while (num != 0);
    str[i] = '\0'; // Null-terminate the string
}

void printf(const char* format, ...) {
    va_list args;
    va_start(args, format);
    char buffer[256]; // Buffer for formatted string
    vsnprintf(buffer, sizeof(buffer), format, args); // Format the string
    Console_WriteA(buffer); // Print the formatted string to the console
    va_end(args);
}

int sprintf(char* str, const char* format, ...) {
    va_list args;
    va_start(args, format);
    vsnprintf(str, 256, format, args); // Format the string into str
    va_end(args);
    return strlen(str); // Return the length of the formatted string
}

int snprintf(char* str, size_t size, const char* format, ...) {
    va_list args;
    va_start(args, format);
    vsnprintf(str, size, format, args); // Format the string into str with size limit
    va_end(args);
    return strlen(str); // Return the length of the formatted string
}

void vsnprintf(char *str, size_t size, const char *format, va_list args)
{
    char *buffer = str;
    const char *end = str + size;
    const char *fmt = format;
    while (*fmt != '\0')
    {
        if (*fmt == '%')
        {
            fmt++;
            switch (*fmt)
            {
            case 's':
            {
                const char *s = va_arg(args, const char *);
                while (*s != '\0' && buffer < end)
                {
                    *buffer = *s;
                    buffer++;
                    s++;
                }
                break;
            }
            case 'c':
            {
                char c = va_arg(args, int);
                *buffer = c;
                buffer++;
                break;
            }
            case 'd':
            {
                int i = va_arg(args, int);
                char buf[32];
                itoa(i, buf, 10);

                // Reverse the string
                int len = strlen(buf);
                for (int j = 0; j < len / 2; j++) {
                    char temp = buf[j];
                    buf[j] = buf[len - j - 1];
                    buf[len - j - 1] = temp;
                }

                const char *s = buf;
                while (*s != '\0' && buffer < end)
                {
                    *buffer = *s;
                    buffer++;
                    s++;
                }
                break;
            }
            case 'x':
            {
                int i = va_arg(args, int);
                char buf[32];
                itoa(i, buf, 16);

                // Reverse the string
                int len = strlen(buf);
                for (int j = 0; j < len / 2; j++) {
                    char temp = buf[j];
                    buf[j] = buf[len - j - 1];
                    buf[len - j - 1] = temp;
                }

                const char *s = buf;
                while (*s != '\0' && buffer < end)
                {
                    *buffer = *s;
                    buffer++;
                    s++;
                }
                break;
            }
            case 'p': // can return negative values
            {
                void *p = va_arg(args, void *);
                char buf[32];
                itoa(*(int*)p, buf, 16);
                const char *s = buf;
                while (*s != '\0' && buffer < end)
                {
                    *buffer = *s;
                    buffer++;
                    s++;
                }
                break;
            }
            case 'n': // cannot, but uses hex
            {
                void *p = va_arg(args, void *);
                char buf[32];
                uitoa(*(unsigned int*)p, buf, 16);
                const char *s = buf;
                while (*s != '\0' && buffer < end)
                {
                    *buffer = *s;
                    buffer++;
                    s++;
                }
                break;
            }
            //u is like x but unsigned
            case 'u':
            {
                unsigned int i = va_arg(args, unsigned int);
                char buf[32];
                uitoa(i, buf, 10);
                const char *s = buf;
                while (*s != '\0' && buffer < end)
                {
                    *buffer = *s;
                    buffer++;
                    s++;
                }
                break;
            }
            case 'l':
            {
                unsigned long i = va_arg(args, unsigned long); // Get the unsigned long argument
                char buf[32]; // Buffer to hold the converted value
                ultoa(i, buf, 16); // Convert the unsigned long to a string in hexadecimal (base 16)
                
                const char *s = buf; // Pointer to the start of the string
                while (*s != '\0' && buffer < end) // Loop until the string ends or buffer is full
                {
                    *buffer = *s; // Copy the character to the buffer
                    buffer++; // Move to the next position in the buffer
                    s++; // Move to the next character in the string
                }
                break;
            }
            case 'i':
            {
                //like l but all the ulongs are padded with 0s
                unsigned long i = va_arg(args, unsigned long); // Get the unsigned long argument
                char buf[32]; // Buffer to hold the converted value
                ultoa(i, buf, 16); // Convert the unsigned long to a string in hexadecimal (base 16)

                // Pad the string with 0s
                int len = strlen(buf); // Get the length of the string
                for (int i = 0; i < 16 - len; i++) // Loop until the string is 16 characters long
                {
                    *buffer = '0'; // Add a 0 to the buffer
                    buffer++; // Move to the next position in the buffer
                }

                const char *s = buf; // Pointer to the start of the string
                while (*s != '\0' && buffer < end) // Loop until the string ends or buffer is full
                {
                    *buffer = *s; // Copy the character to the buffer
                    buffer++; // Move to the next position in the buffer
                    s++; // Move to the next character in the string
                }
                break;
            }
            case '%':
            {
                *buffer = '%'; // Print the % character
                buffer++;
                break;
            }
            }
        }
        else
        {
            *buffer = *fmt;
            buffer++;
        }
        fmt++;
    }
    *buffer = '\0';
}

void vsprintf(char* str, const char* format, va_list ap) {
    // add %d, %u, %x, %s, %c support
    char* p = str;
    while (*format) {
        if (*format == '%') {
            format++;
            switch (*format) {
                case 'd': {
                    int num = va_arg(ap, int);
                    p += sprintf(p, "%d", num); // Format integer as decimal
                    break;
                }
                case 'u': {
                    unsigned int num = va_arg(ap, unsigned int);
                    p += sprintf(p, "%u", num); // Format unsigned integer as decimal
                    break;
                }
                case 'x': {
                    unsigned int num = va_arg(ap, unsigned int);
                    p += sprintf(p, "%x", num); // Format unsigned integer as hexadecimal
                    break;
                }
                case 's': {
                    char* str_arg = va_arg(ap, char*);
                    p += sprintf(p, "%s", str_arg); // Format string
                    break;
                }
                case 'c': {
                    char c = (char)va_arg(ap, int);
                    *p++ = c; // Add character to output
                    break;
                }
                default:
                    *p++ = *format; // Copy unknown format specifier as is
            }
        } else {
            *p++ = *format; // Copy regular character to output
        }
        format++;
    }
    *p = '\0'; // Null-terminate the string
    str = p; // Update the pointer to the end of the formatted string
}

void clrscr(void) {
    Console_Clear(); // Clear the console screen
}

void gets(char* str, size_t size)
{
    //use Console_ReadLineA and return the string
    char* input = Console_ReadLineA(); // Read a line from the console
    if (input) {
        strncpy(str, input, size); // Copy the input string to the provided buffer
        str[size - 1] = '\0'; // Ensure null termination
    } else {
        str[0] = '\0'; // If no input, set the string to empty
    }
    free(input); // Free the memory allocated for the input string
}

int scanf(const char *fmt, ...) {
    va_list args;
    va_start(args, fmt);
    char buffer[256]; // Buffer for formatted string
    gets(buffer, sizeof(buffer)); // Read input from the console
    
    int count = 0;
    const char* p = fmt;
    char* input = buffer;
    
    while (*p != '\0') {
        if (*p == '%') {
            p++;
            // Skip leading spaces in input
            while (isspace((unsigned char)*input)) {
                input++;
            }
            switch (*p) {
                case 'd': { // read integer
                    int* dest = va_arg(args, int*);
                    char temp[32];
                    int i = 0;
                    int sign = 1;
                    if (*input == '-') {
                        sign = -1;
                        input++;
                    }
                    while (isdigit((unsigned char)*input) && i < (int)(sizeof(temp) - 1)) {
                        temp[i++] = *input++;
                    }
                    temp[i] = '\0';

                    *dest = sign * strtol(temp, NULL, 10);
                    count++;
                    break;
                }
                case 'u': { // read unsigned integer
                    unsigned int* dest = va_arg(args, unsigned int*);
                    char temp[32];
                    int i = 0;
                    while (isdigit((unsigned char)*input) && i < (int)(sizeof(temp) - 1)) {
                        temp[i++] = *input++;
                    }
                    temp[i] = '\0';
                    *dest = (unsigned int)strtoul(temp, NULL, 10);
                    count++;
                    break;
                }
                case 'x': { // read hexadecimal
                    unsigned int* dest = va_arg(args, unsigned int*);
                    char temp[32];
                    int i = 0;
                    while (((*input >= '0' && *input <= '9') ||
                            (*input >= 'a' && *input <= 'f') ||
                            (*input >= 'A' && *input <= 'F')) && i < (int)(sizeof(temp) - 1)) {
                        temp[i++] = *input++;
                    }
                    temp[i] = '\0';
                    *dest = (unsigned int)strtoul(temp, NULL, 16);
                    count++;
                    break;
                }
                case 's': { // read string
                    char* dest = va_arg(args, char*);
                    while (*input && !isspace((unsigned char)*input)) {
                        *dest++ = *input++;
                    }
                    *dest = '\0';
                    count++;
                    break;
                }
                case 'c': { // read a single character
                    char* dest = va_arg(args, char*);
                    *dest = *input ? *input++ : '\0';
                    count++;
                    break;
                }
            }
        } else {
            p++;
        }
    }
    
    va_end(args);
    return count; // Return the number of items successfully read
}

int sscanf(const char *str, const char *fmt, ...) {
    va_list args;
    va_start(args, fmt);
    int ret = 0; // Number of items successfully read
    while (*fmt) {
        if (*fmt == '%') {
            fmt++;
            switch (*fmt) {
                case 'd': {
                    int *i = va_arg(args, int*);
                    *i = strtol(str, (char**)&str, 10); // Read integer from string
                    ret++;
                    break;
                }
                case 'u': {
                    unsigned int *i = va_arg(args, unsigned int*);
                    *i = strtoul(str, (char**)&str, 10); // Read unsigned integer from string
                    ret++;
                    break;
                }
                case 'x': {
                    unsigned int *i = va_arg(args, unsigned int*);
                    *i = strtoul(str, (char**)&str, 16); // Read hexadecimal from string
                    ret++;
                    break;
                }
                case 's': {
                    char *s = va_arg(args, char*);
                    while (*str && !isspace(*str)) { // Read string until whitespace
                        *s++ = *str++;
                    }
                    *s = '\0'; // Null-terminate the string
                    ret++;
                    break;
                }
                case 'c': {
                    char *c = va_arg(args, char*);
                    *c = *str++; // Read character from string
                    ret++;
                    break;
                }
            }
        } else {
            str++; // Skip non-format characters in the input string
        }
        fmt++;
    }
    va_end(args);
    return ret; // Return the number of items successfully read
}

FILE* fopen(const char* filename, const char* mode) {
    return File_Open((char*)filename, (char*)mode);
}

int fclose(FILE* file) {
    return File_Close(file);
}

int fread(void* buffer, unsigned int size, unsigned int nmemb, FILE* stream) {
    return File_Read(buffer, size, nmemb, stream);
}

int fwrite(void* buffer, unsigned int size, unsigned int nmemb, FILE* stream) {
    return File_Write(buffer, size, nmemb, stream);
}

int fseek(FILE* stream, int offset, int whence) {
    return File_Seek(stream, offset, whence);
}

int ftell(FILE* stream) {
    return File_Tell(stream);
}

int fflush(FILE* stream) {
    return File_Flush(stream);
}

int abs(int num)
{
    return (num < 0) ? -num : num;
}
