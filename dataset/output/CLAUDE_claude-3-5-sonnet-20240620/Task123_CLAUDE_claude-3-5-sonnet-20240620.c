
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_SESSIONS 100
#define SESSION_ID_LENGTH 36
#define USER_ID_LENGTH 20

typedef struct {
    char session_id[SESSION_ID_LENGTH + 1];
    char user_id[USER_ID_LENGTH + 1];
    time_t creation_time;
    time_t last_activity;
} Session;

typedef struct {
    Session sessions[MAX_SESSIONS];
    int count;
    int session_timeout;
} SessionManager;

void generate_session_id(char *session_id) {
    const char *chars = "0123456789abcdef";
    for (int i = 0; i < SESSION_ID_LENGTH; i++) {
        if (i == 8 || i == 13 || i == 18 || i == 23) {
            session_id[i] = '-';
        } else {
            session_id[i] = chars[rand() % 16];
        }
    }
    session_id[SESSION_ID_LENGTH] = '\\0';
}

void create_session(SessionManager *manager, const char *user_id, char *session_id) {
    if (manager->count >= MAX_SESSIONS) {
        printf("Error: Maximum number of sessions reached\\n");
        return;
    }

    Session *session = &manager->sessions[manager->count++];
    generate_session_id(session->session_id);
    strncpy(session->user_id, user_id, USER_ID_LENGTH);
    session->creation_time = time(NULL);
    session->last_activity = session->creation_time;

    strcpy(session_id, session->session_id);
}

Session *get_session(SessionManager *manager, const char *session_id) {
    time_t current_time = time(NULL);
    for (int i = 0; i < manager->count; i++) {
        if (strcmp(manager->sessions[i].session_id, session_id) == 0) {
            if (current_time - manager->sessions[i].last_activity > manager->session_timeout) {
                // Session expired
                return NULL;
            }
            manager->sessions[i].last_activity = current_time;
            return &manager->sessions[i];
        }
    }
    return NULL;
}

void destroy_session(SessionManager *manager, const char *session_id) {
    for (int i = 0; i < manager->count; i++) {
        if (strcmp(manager->sessions[i].session_id, session_id) == 0) {
            // Move the last session to this position and decrease the count
            manager->sessions[i] = manager->sessions[--manager->count];
            return;
        }
    }
}

void cleanup_expired_sessions(SessionManager *manager) {
    time_t current_time = time(NULL);
    for (int i = 0; i < manager->count; i++) {
        if (current_time - manager->sessions[i].last_activity > manager->session_timeout) {
            destroy_session(manager, manager->sessions[i].session_id);
            i--; // Recheck this index as we've moved a session here
        }
    }
}

int main() {
    SessionManager manager = {.count = 0, .session_timeout = 1800}; // 30 minutes timeout
    char session_id[SESSION_ID_LENGTH + 1];

    // Create a session
    const char *user_id = "user123";
    create_session(&manager, user_id, session_id);
    printf("Session created for user %s: %s\\n", user_id, session_id);

    // Get session
    Session *session = get_session(&manager, session_id);
    if (session) {
        printf("Session found for user %s\\n", session->user_id);
    } else {
        printf("Session not found\\n");
    }

    // Simulate session expiration
    sleep(2);
    manager.session_timeout = 1; // Set timeout to 1 second for demonstration
    session = get_session(&manager, session_id);
    if (session) {
        printf("Session still active for user %s\\n", session->user_id);
    } else {
        printf("Session expired\\n");
    }

    // Cleanup expired sessions
    cleanup_expired_sessions(&manager);
    printf("Expired sessions cleaned up\\n");

    return 0;
}
