#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <uuid/uuid.h>

typedef struct Session {
    char *sessionId;
    char *username;
} Session;

typedef struct Node {
    Session *session;
    struct Node *next;
} Node;

Node *head = NULL;

char *generateSessionId() {
    uuid_t uuid;
    char *sessionId = malloc(37);
    uuid_generate(uuid);
    uuid_unparse_lower(uuid, sessionId);
    return sessionId;
}

Session *createSession(char *username) {
    Session *session = malloc(sizeof(Session));
    session->sessionId = generateSessionId();
    session->username = strdup(username);

    Node *newNode = malloc(sizeof(Node));
    newNode->session = session;
    newNode->next = head;
    head = newNode;

    return session;
}

Session *getSession(char *sessionId) {
    Node *current = head;
    while (current != NULL) {
        if (strcmp(current->session->sessionId, sessionId) == 0) {
            return current->session;
        }
        current = current->next;
    }
    return NULL;
}

void invalidateSession(char *sessionId) {
    Node *current = head;
    Node *previous = NULL;

    while (current != NULL) {
        if (strcmp(current->session->sessionId, sessionId) == 0) {
            if (previous == NULL) {
                head = current->next;
            } else {
                previous->next = current->next;
            }
            free(current->session->sessionId);
            free(current->session->username);
            free(current->session);
            free(current);
            return;
        }
        previous = current;
        current = current->next;
    }
}

int main() {
    // Create a session for user "john.doe"
    Session *session = createSession("john.doe");
    printf("Created session: %s
", session->sessionId);

    // Retrieve the session
    Session *retrievedSession = getSession(session->sessionId);
    if (retrievedSession != NULL) {
        printf("Retrieved session: %s - %s
", retrievedSession->sessionId, retrievedSession->username);
    }

    // Invalidate the session
    invalidateSession(session->sessionId);
    printf("Invalidated session: %s
", session->sessionId);

    return 0;
}