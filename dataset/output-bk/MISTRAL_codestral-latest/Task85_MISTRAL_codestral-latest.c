#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char* generateRandomString(int length) {
    const char characters[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
    int charactersLength = sizeof(characters) - 1;

    char* randomString = malloc(length + 1);
    if (randomString == NULL) {
        return NULL;
    }

    srand(time(NULL));
    for (int i = 0; i < length; i++) {
        randomString[i] = characters[rand() % charactersLength];
    }
    randomString[length] = '\0';

    return randomString;
}

int main() {
    int length = 10; // specify the length of the random string
    char* randomString = generateRandomString(length);
    printf("Random String: %s
", randomString);
    free(randomString);
    return 0;
}