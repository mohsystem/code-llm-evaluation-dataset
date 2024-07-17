#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SESSION_FILE "sessions.txt"

// Simplified session structure
typedef struct {
    char id[32];
    char username[50];
} Session;

// Function to generate a random session ID
void generateSessionId(char *sessionId) {
    srand(time(NULL));
    for (int i = 0; i < 31; i++) {
        sessionId[i] = 'a' + (rand() % 26);
    }
    sessionId[31] = '\0';
}

// Function to create a new session
Session *createSession(const char *username) {
    Session *session = (Session *)malloc(sizeof(Session));
    if (session == NULL) {
        perror("Memory allocation failed");
        exit(1);
    }
    generateSessionId(session->id);
    strcpy(session->username, username);

    // Store session data in a file (replace with database in production)
    FILE *fp = fopen(SESSION_FILE, "a");
    if (fp == NULL) {
        perror("Error opening session file");
        free(session);
        exit(1);
    }
    fprintf(fp, "%s,%s
", session->id, session->username);
    fclose(fp);

    return session;
}

// Function to retrieve a session by ID
Session *getSession(const char *sessionId) {
    // ... (Implementation to read from session storage)
    return NULL; // Replace with actual session retrieval
}

// Function to terminate a session
void terminateSession(const char *sessionId) {
    // ... (Implementation to remove session from storage)
}

int main() {
    // Example usage:
    Session *newSession = createSession("user123");
    printf("Session created with ID: %s
", newSession->id);

    // ... (Further session management operations)

    free(newSession);
    return 0;
}