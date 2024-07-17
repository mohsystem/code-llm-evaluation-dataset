
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int generateRandomNumber() {
    return rand() % 100 + 1;
}

void generateRandomToken(char *token) {
    const char characters[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";
    for (int i = 0; i < 8; i++) {
        token[i] = characters[rand() % strlen(characters)];
    }
    token[8] = \'\\0\';
}

int main() {
    srand(time(NULL));
    
    printf("Random Number: %d\
", generateRandomNumber());
    
    char token[9];
    generateRandomToken(token);
    printf("Random Token: %s\
", token);
    
    return 0;
}
