
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define SESSION_ID_LENGTH 32

char* generateSessionID() {
    static const char alphanum[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
    char* sessionID = malloc((SESSION_ID_LENGTH + 1) * sizeof(char));
    
    srand(time(NULL));
    for (int i = 0; i < SESSION_ID_LENGTH; ++i) {
        sessionID[i] = alphanum[rand() % (sizeof(alphanum) - 1)];
    }
    sessionID[SESSION_ID_LENGTH] = \'\\0\';
    
    return sessionID;
}

int main() {
    char* sessionID = generateSessionID();
    printf("Generated Session ID: %s\
", sessionID);
    free(sessionID);
    return 0;
}
