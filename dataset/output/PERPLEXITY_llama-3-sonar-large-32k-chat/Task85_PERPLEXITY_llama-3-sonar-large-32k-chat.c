#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

char* generateRandomString(int length) {
    char chars[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char* str = (char*)malloc((length + 1) * sizeof(char));
    srand(time(0));
    for (int i = 0; i < length; i++) {
        str[i] = chars[rand() % (sizeof(chars) - 1)];
    }
    str[length] = '\0';
    return str;
}

int main() {
    char* str = generateRandomString(10);
    printf("%s\n", str);
    free(str);
    return 0;
}