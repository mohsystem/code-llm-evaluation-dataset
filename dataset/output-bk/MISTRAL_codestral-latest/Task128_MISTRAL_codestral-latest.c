#include <stdio.h>
#include <stdlib.h>
#include <time.h>

const char CHARACTERS[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
const int TOKEN_LENGTH = 10;

void generateRandomToken(char* token) {
    srand(time(0));

    for (int i = 0; i < TOKEN_LENGTH; i++) {
        int randomIndex = rand() % (sizeof(CHARACTERS) - 1);
        token[i] = CHARACTERS[randomIndex];
    }

    token[TOKEN_LENGTH] = '\0';
}

int main() {
    char token[TOKEN_LENGTH + 1];
    generateRandomToken(token);
    printf("%s
", token);
    return 0;
}