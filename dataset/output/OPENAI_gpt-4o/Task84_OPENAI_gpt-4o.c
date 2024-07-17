#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void generateSessionIdC(char *sessionID, int length) {
    const char charset[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";
    for (int i = 0; i < length; i++) {
        int key = rand() % (int)(sizeof(charset) - 1);
        sessionID[i] = charset[key];
    }
    sessionID[length] = '\0';
}

int main() {
    char sessionID[17];
    srand(time(0));
    generateSessionIdC(sessionID, 16);
    printf("C Session ID: %s
", sessionID);
    return 0;
}