#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void generateRandomString(int length, char* result) {
    const char characters[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
    srand(time(0));

    for (int i = 0; i < length; ++i) {
        result[i] = characters[rand() % (sizeof(characters) - 1)];
    }
    result[length] = '\0';
}

int main() {
    int length = 10;
    char result[length + 1];
    generateRandomString(length, result);
    printf("%s\n", result);
    return 0;
}