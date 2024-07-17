
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define ALPHABET "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz"

char* generateRandomString(int length) {
    char* result = malloc((length + 1) * sizeof(char));
    int alphabetLength = strlen(ALPHABET);

    srand(time(NULL));
    for (int i = 0; i < length; i++) {
        int index = rand() % alphabetLength;
        result[i] = ALPHABET[index];
    }
    result[length] = \'\\0\';

    return result;
}

int main() {
    int length = 10;
    char* randomString = generateRandomString(length);
    printf("Random string: %s\
", randomString);
    free(randomString);
    return 0;
}
