#include <stdio.h>
#include <string.h>

void run_C(int bufferSize, char input[]) {
    char buffer[10] = {0};
    printf("Enter input (C): ");
    fgets(input, bufferSize, stdin);
    strncpy(buffer, input, bufferSize - 1);
    printf("Buffer contents (C): %s
", buffer);
}