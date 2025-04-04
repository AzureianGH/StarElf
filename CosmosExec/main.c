#include "Cosmos.h"
NO_NAME_MANGLE void main(void*** funcTable) {
    COSMOS_INIT();

    printf("What's your name and age and favorite number and favorite float?\n");
    char nameage[100];
    int age;
    int favnum;

    scanf("%s %d %d", nameage, &age, &favnum);
    printf("Hello, %d, you are %d, and your favorite number is %d!\n", nameage, age, favnum);
    char vendor[13];
    unsigned int eax, ebx, ecx, edx;
    __asm__ __volatile__ ("cpuid" : "=a"(eax), "=b"(ebx), "=c"(ecx), "=d"(edx) : "a"(0) : "cc");
    *((unsigned int*)vendor) = ebx;
    *((unsigned int*)(vendor + 4)) = edx;
    *((unsigned int*)(vendor + 8)) = ecx;
    vendor[12] = '\0';
    printf("CPU Vendor: %s\n", vendor);

    return;
}