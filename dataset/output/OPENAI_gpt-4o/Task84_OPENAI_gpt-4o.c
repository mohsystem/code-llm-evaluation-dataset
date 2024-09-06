#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

void generateSessionID(char* sessionID) {
    const char characters[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";
    size_t characters_len = strlen(characters);
    for (int i = 0; i < 16; i++) {
        sessionID[i] = characters[rand() % characters_len];
    }
    sessionID[16] = '\0';
}

int main() {
    srand(time(0));
    char sessionID[17];
    generateSessionID(sessionID);
    printf("C generated session ID: %s\n", sessionID);
    return 0;
}