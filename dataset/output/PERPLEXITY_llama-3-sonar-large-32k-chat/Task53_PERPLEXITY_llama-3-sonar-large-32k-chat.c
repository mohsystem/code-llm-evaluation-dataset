#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
    char userId[20];
    char sessionId[20];
} Session;

Session* sessions;
int sessionCount = 0;

void createUserSession(char* userId, char* sessionId) {
    Session* newSession = (Session*) malloc(sizeof(Session));
    strcpy(newSession->userId, userId);
    strcpy(newSession->sessionId, sessionId);
    sessions = (Session*) realloc(sessions, (sessionCount + 1) * sizeof(Session));
    sessions[sessionCount] = *newSession;
    sessionCount++;
}

void deleteUserSession(char* userId) {
    for (int i = 0; i < sessionCount; i++) {
        if (strcmp(sessions[i].userId, userId) == 0) {
            for (int j = i; j < sessionCount - 1; j++) {
                sessions[j] = sessions[j + 1];
            }
            sessionCount--;
            break;
        }
    }
}

char* getUserSessionId(char* userId) {
    for (int i = 0; i < sessionCount; i++) {
        if (strcmp(sessions[i].userId, userId) == 0) {
            return sessions[i].sessionId;
        }
    }
    return NULL;
}

int main() {
    sessions = (Session*) malloc(sizeof(Session));
    createUserSession("user1", "session1");
    createUserSession("user2", "session2");
    printf("%s
", getUserSessionId("user1")); // prints "session1"
    deleteUserSession("user1");
    printf("%s
", getUserSessionId("user1")); // prints null
    return 0;
}