#include "Cosmos.h"
#include <stdio.h>
NO_NAME_MANGLE void main(void*** funcTable) {
    COSMOS_INIT();

    printf("What's your name and age and favorite number and favorite float?\n");
    char nameage[100];
    int age;
    int favnum;
    int favnumf;
    scanf("%s %d %d %d", nameage, &age, &favnum, &favnumf);
    printf("Hello, %s, you are %x, and your favorite number is %x, %x!\n", nameage, age, favnum, favnumf);

    return;
}