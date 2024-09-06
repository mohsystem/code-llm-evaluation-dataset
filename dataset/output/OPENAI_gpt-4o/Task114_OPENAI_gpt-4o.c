#include <stdio.h>
#include <string.h>

void c_copy_string(char* dest, const char* src) {
    strcpy(dest, src);
}

int main() {
    // C string operations
    char cStr[50] = "Hello, C!";
    char cCopiedStr[50];
    c_copy_string(cCopiedStr, cStr);
    strcat(cStr, " How are you?");
    char cConcatenatedStr[50];
    strcpy(cConcatenatedStr, cStr);

    // Output C strings
    printf("C copied string: %s\n", cCopiedStr);
    printf("C concatenated string: %s\n", cConcatenatedStr);

    return 0;
}