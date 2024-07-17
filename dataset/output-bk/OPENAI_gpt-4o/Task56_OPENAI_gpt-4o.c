#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void generateToken(char *token, size_t length) {
    const char charset[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    for (size_t i = 0; i < length; i++) {
        int key = rand() % (int)(sizeof(charset) - 1);
        token[i] = charset[key];
    }
    token[length] = '\0';
}

int main() {
    srand(time(0));
    char token[37];
    generateToken(token, 36);
    printf("C Token: %s
", token);
    return 0;
}