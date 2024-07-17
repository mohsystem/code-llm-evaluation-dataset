#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char *generateSessionId(int length) {
    char *sessionId = malloc(length + 1);
    if (sessionId == NULL) {
        return NULL;
    }
    srand(time(NULL));
    const char charset[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    for (int i = 0; i < length; i++) {
        sessionId[i] = charset[rand() % (sizeof(charset) - 1)];
    }
    sessionId[length] = '\0';
    return sessionId;
}

int main() {
    char *sessionId = generateSessionId(32);
    if (sessionId != NULL) {
        printf("%s
", sessionId);
        free(sessionId);
    } else {
        fprintf(stderr, "Failed to generate session ID.
");
        return 1;
    }
    return 0;
}