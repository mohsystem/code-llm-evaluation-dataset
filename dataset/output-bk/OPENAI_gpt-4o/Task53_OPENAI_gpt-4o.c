#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char sessionId[37];
    char username[50];
} Session;

Session sessions[100];
int sessionCount = 0;

char *generateSessionId() {
    static char uuid[37];
    snprintf(uuid, sizeof(uuid), "%x-%x-%x-%x-%x", rand(), rand(), rand(), rand(), rand());
    return uuid;
}

void createSession(char *username) {
    Session s;
    strcpy(s.sessionId, generateSessionId());
    strcpy(s.username, username);
    sessions[sessionCount++] = s;
    printf("Session ID: %s
", s.sessionId);
}

char *getSession(char *sessionId) {
    for (int i = 0; i < sessionCount; i++) {
        if (strcmp(sessions[i].sessionId, sessionId) == 0) {
            return sessions[i].username;
        }
    }
    return NULL;
}

void removeSession(char *sessionId) {
    for (int i = 0; i < sessionCount; i++) {
        if (strcmp(sessions[i].sessionId, sessionId) == 0) {
            for (int j = i; j < sessionCount - 1; j++) {
                sessions[j] = sessions[j + 1];
            }
            sessionCount--;
            break;
        }
    }
}

int main() {
    createSession("JohnDoe");
    char *username = getSession(generateSessionId());
    printf("User: %s
", username ? username : "Session not found");
    removeSession(generateSessionId());
    username = getSession(generateSessionId());
    printf("Session removed. User: %s
", username ? username : "Session not found");
    return 0;
}