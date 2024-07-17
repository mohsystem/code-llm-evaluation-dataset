#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

char* generateRandomString(int length) {
    char* str = (char*)malloc((length + 1) * sizeof(char));
    char alphabet[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    srand(time(NULL));
    for (int i = 0; i < length; i++) {
        str[i] = alphabet[rand() % (sizeof(alphabet) - 1)];
    }
    str[length] = '\0';
    return str;
}

int main() {
    char* str = generateRandomString(10);
    printf("%s
", str);
    free(str);
    return 0;
}