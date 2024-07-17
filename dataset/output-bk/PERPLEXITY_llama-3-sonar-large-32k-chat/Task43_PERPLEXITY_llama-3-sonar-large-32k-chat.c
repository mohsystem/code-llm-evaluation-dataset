#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
    char id[256];
    // other session data
} Session;

Session* sessions = NULL;
int numSessions = 0;

void createSession(const char* id) {
    Session* newSession = (Session*) malloc(sizeof(Session));
    strcpy(newSession->id, id);
    sessions = (Session*) realloc(sessions, (numSessions + 1) * sizeof(Session));
    sessions[numSessions++] = *newSession;
}

void terminateSession(const char* id) {
    for (int i = 0; i < numSessions; i++) {
        if (strcmp(sessions[i].id, id) == 0) {
            sessions[i] = sessions[--numSessions];
            sessions = (Session*) realloc(sessions, numSessions * sizeof(Session));
            return;
        }
    }
}

int main() {
    // assume a web framework that provides the following functions
    char* requestMethod = getRequestMethod();
    char* requestId = getRequestParam("id");
    char* requestAction = getRequestParam("action");

    if (strcmp(requestMethod, "GET") == 0) {
        if (strcmp(requestAction, "create") == 0) {
            createSession(requestId(requestId));
        } else if (strcmp(requestAction, "terminate") == 0) {
            terminateSession(requestId);
        }
    }

    return 0;
}