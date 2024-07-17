// C
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char sessionId[37];
    char userId[256];
} Session;

Session* createSession(const char* userId) {
    Session* session = malloc(sizeof(Session));
    if (session == NULL) {
        return NULL;
    }
    for (int i = 0; i < 36; i++) {
        session->sessionId[i] = rand() % 26 + 'a';
    }
    session->sessionId[36] = '\0';
    strncpy(session->userId, userId, 255);
    session->userId[255] = '\0';
    return session;
}

// You would need to implement a way to store and retrieve sessions by sessionId