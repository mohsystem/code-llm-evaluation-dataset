#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

char* generateToken(int length) {
    char lettersAndDigits[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890";
    char* token = (char*)malloc((length + 1) * sizeof(char));
    for (int i = 0; i < length; i++) {
        token[i] = lettersAndDigits[rand() % (sizeof(lettersAndDigits) - 1)];
    }
    token[length] = '\0';
    return token;
}

int main() {
    srand(time(0));
    char* token = generateToken(10);
    printf("Random token is %s
", token);
    free(token);
    return 0;
}