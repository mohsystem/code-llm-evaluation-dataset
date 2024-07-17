#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void generateRandomString(char *str, int length) {
    const char charset[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
    for (int i = 0; i < length; i++) {
        int key = rand() % (int)(sizeof(charset) - 1);
        str[i] = charset[key];
    }
    str[length] = '\0';
}

int main() {
    srand(time(0));
    int length = 10;
    char str[length + 1];
    generateRandomString(str, length);
    printf("%s
", str);
    return 0;
}