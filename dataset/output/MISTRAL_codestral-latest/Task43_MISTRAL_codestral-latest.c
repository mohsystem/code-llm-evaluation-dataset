// C
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <uuid/uuid.h>

typedef struct {
    char sessionId[37];
    char userId[256];
} Session;

Session* createSession(const char* userId) {
    Session* session = malloc(sizeof(Session));
    uuid_t uuid;
    uuid_generate(uuid);
    uuid_unparse(uuid, session->sessionId);
    strncpy(session->userId, userId, 255);
    return session;
}

char* getUserFromSession(const char* sessionId, Session* sessions, int size) {
    for (int i = 0; i < size; i++) {
        if (strcmp(sessions[i].sessionId, sessionId) == 0) {
            return sessions[i].userId;
        }
    }
    return NULL;
}

void terminateSession(const char* sessionId, Session* sessions, int* size) {
    for (int i = 0; i < *size; i++) {
        if (strcmp(sessions[i].sessionId, sessionId) == 0) {
            memmove(&sessions[i], &sessions[i + 1], (*size - i - 1) * sizeof(Session));
            (*size)--;
            return;
        }
    }
}