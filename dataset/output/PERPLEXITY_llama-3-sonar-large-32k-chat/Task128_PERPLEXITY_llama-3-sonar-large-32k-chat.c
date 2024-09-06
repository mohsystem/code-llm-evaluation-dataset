#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

char* generateToken(int length) {
    static char lettersAndDigits[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890";
    static char token[11];
    for (int i = 0; i < length; i++) {
        token[i] = lettersAndDigits[rand() % (sizeof(lettersAndDigits) - 1)];
    }
    token[length] = '\0';
    return token;
}

int main() {
    srand(time(0));
    printf("Random token is %s\n", generateToken(10));
    return 0;
}