#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

// Note: This implementation uses a simple array for session storage,
// which is not efficient for large numbers of sessions.
// In a real application, use a more robust data structure like a hash table.

#define MAX_SESSIONS 100

struct Session {
    char username[50];
    char session_id[50];
    time_t created_at;
};

struct Session sessions[MAX_SESSIONS];
int session_count = 0;

char* createSession(char* username) {
    if (session_count >= MAX_SESSIONS) {
        return NULL; // Session limit reached
    }

    struct Session* new_session = &sessions[session_count++];
    strcpy(new_session->username, username);

    // In a real application, generate a unique session ID
    sprintf(new_session->session_id, "session_%d", session_count);
    new_session->created_at = time(NULL);

    return new_session->session_id;
}

struct Session* getSession(char* session_id) {
    for (int i = 0; i < session_count; i++) {
        if (strcmp(sessions[i].session_id, session_id) == 0) {
            return &sessions[i];
        }
    }
    return NULL;
}

int deleteSession(char* session_id) {
    for (int i = 0; i < session_count; i++) {
        if (strcmp(sessions[i].session_id, session_id) == 0) {
            // Shift remaining sessions back in the array
            for (int j = i; j < session_count - 1; j++) {
                sessions[j] = sessions[j + 1];
            }
            session_count--;
            return 1; // Session deleted
        }
    }
    return 0; // Session not found
}

int main() {
    // Create a new session
    char* session_id = createSession("user1");
    if (session_id != NULL) {
        printf("Session created for user1 with ID: %s\n", session_id);
    } else {
        printf("Session creation failed.\n");
    }

    // Get the session
    struct Session* session = getSession(session_id);
    if (session != NULL) {
        printf("Session is valid for user: %s\n", session->username);
    } else {
        printf("Session is not valid.\n");
    }

    // Delete the session
    if (deleteSession(session_id)) {
        printf("Session with ID %s deleted.\n", session_id);
    } else {
        printf("Session with ID %s not found.\n", session_id);
    }

    return 0;
}