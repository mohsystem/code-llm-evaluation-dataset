// Note: C does not have built-in support for UUID or hash maps, so this implementation is simplified
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    char sessionId[37];
    char userId[10];
} Session;

Session sessions[100]; // assume max 100 sessions
int sessionCount = 0;

void createSession(const char* userId) {
    time_t t;
    time(&t);
    sprintf(sessions[sessionCount].sessionId, "%ld", t);
    strcpy(sessions[sessionCount].userId, userId);
    sessionCount++;
}

const char* getUserId(const char* sessionId) {
    for (int i = 0; i < sessionCount; i++) {
        if (strcmp(sessions[i].sessionId, sessionId) == 0) {
            return sessions[i].userId;
        }
    }
    return NULL;
}

void invalidateSession(const char* sessionId) {
    for (int i = 0; i < sessionCount; i++) {
        if (strcmp(sessions[i].sessionId, sessionId) == 0) {
            sessions[i].sessionId[0] = '\0';
            sessions[i].userId[0] = '\0';
            return;
        }
    }
}

int main() {
    createSession("user1");
    const char* sessionId = sessions[0].sessionId;
    printf("Session ID: %s\n", sessionId);

    const char* userId = getUserId(sessionId);
    printf("User ID: %s\n", userId);

    invalidateSession(sessionId);
    printf("Session invalidated\n");

    return 0;
}