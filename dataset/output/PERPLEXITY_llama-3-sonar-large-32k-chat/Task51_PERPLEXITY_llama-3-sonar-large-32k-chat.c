#include <stdio.h>
#include <string.h>

void encrypt(char* str) {
    for (int i = 0; i < strlen(str); i++) {
        str[i] += 3;
    }
}

int main() {
    char str[] = "Hello, World!";
    printf("Original: %s
", str);
    encrypt(str);
    printf("Encrypted: %s
", str);
    return 0;
}