#include "Cosmos.h"

int get_file_size(FILE* file) {
    int current_pos = ftell(file);
    fseek(file, 0, SEEK_END);
    int size = ftell(file);
    fseek(file, current_pos, SEEK_SET);
    return size;
}

NO_NAME_MANGLE void main(void*** funcTable) {
    COSMOS_INIT();
    
    char file[100];

    clrscr();

    printf("Enter file name: ");
    scanf("%s", file);
    printf("File name: %s\n", file);

    FILE* handle = fopen(file, "r+");
    if (handle == NULL) {
        printf("Failed to open file.\n");
        return;
    }

    int size = get_file_size(handle);
    printf("File size: %d bytes\n", size);
    
    char* buffer = (char*)malloc(size + 1);
    if (buffer == NULL) {
        printf("Failed to allocate memory.\n");
        fclose(handle);
        return;
    }

    int bytesRead = fread(buffer, 1, size, handle);
    if (bytesRead != size) {
        printf("Failed to read file.\n");
        free(buffer);
        fclose(handle);
        return;
    }

    buffer[size] = '\0';
    printf("File contents: %s\n", buffer);

    fclose(handle);

    return;
}