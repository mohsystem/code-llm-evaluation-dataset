
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int generateRandomNumber(int minVal, int maxVal) {
    return rand() % (maxVal - minVal + 1) + minVal;
}

void generateRandomToken(char *token, int length) {
    const char characters[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";
    int charactersLength = strlen(characters);
    
    for (int i = 0; i < length; i++) {
        token[i] = characters[rand() % charactersLength];
    }
    token[length] = '\\0';
}

int main() {
    srand(time(NULL));
    
    printf("Random number: %d\\n", generateRandomNumber(1, 100));
    
    char token[11];
    generateRandomToken(token, 10);
    printf("Random token: %s\\n", token);
    
    return 0;
}
