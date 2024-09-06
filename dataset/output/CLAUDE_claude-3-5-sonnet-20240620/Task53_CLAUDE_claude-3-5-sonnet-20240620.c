
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
    time_t created_at;
    time_t last_accessed;
} Session;

typedef struct {
    Session sessions[MAX_SESSIONS];
    int count;
    time_t session_timeout;
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

void init_session_manager(SessionManager *manager, time_t timeout) {
    manager->count = 0;
    manager->session_timeout = timeout;
}

char* create_session(SessionManager *manager, const char *user_id) {
    if (manager->count >= MAX_SESSIONS) {
        return NULL;
    }

    Session *session = &manager->sessions[manager->count++];
    generate_session_id(session->session_id);
    strncpy(session->user_id, user_id, USER_ID_LENGTH);
    session->user_id[USER_ID_LENGTH] = '\\0';
    session->created_at = time(NULL);
    session->last_accessed = session->created_at;

    return session->session_id;
}

Session* get_session(SessionManager *manager, const char *session_id) {
    time_t now = time(NULL);
    for (int i = 0; i < manager->count; i++) {
        if (strcmp(manager->sessions[i].session_id, session_id) == 0) {
            if (now - manager->sessions[i].last_accessed > manager->session_timeout) {
                // Session expired
                memmove(&manager->sessions[i], &manager->sessions[i + 1], 
                        (manager->count - i - 1) * sizeof(Session));
                manager->count--;
                return NULL;
            }
            manager->sessions[i].last_accessed = now;
            return &manager->sessions[i];
        }
    }
    return NULL;
}

void destroy_session(SessionManager *manager, const char *session_id) {
    for (int i = 0; i < manager->count; i++) {
        if (strcmp(manager->sessions[i].session_id, session_id) == 0) {
            memmove(&manager->sessions[i], &manager->sessions[i + 1], 
                    (manager->count - i - 1) * sizeof(Session));
            manager->count--;
            return;
        }
    }
}

void cleanup_expired_sessions(SessionManager *manager) {
    time_t now = time(NULL);
    int i = 0;
    while (i < manager->count) {
        if (now - manager->sessions[i].last_accessed > manager->session_timeout) {
            memmove(&manager->sessions[i], &manager->sessions[i + 1], 
                    (manager->count - i - 1) * sizeof(Session));
            manager->count--;
        } else {
            i++;
        }
    }
}

int main() {
    SessionManager manager;
    init_session_manager(&manager, 1800); // 30 minutes timeout

    // Create a new session
    const char *user_id = "user123";
    char *session_id = create_session(&manager, user_id);
    if (session_id) {
        printf("New session created: %s\\n", session_id);

        // Get session
        Session *session = get_session(&manager, session_id);
        if (session) {
            printf("Session found for user: %s\\n", session->user_id);
        } else {
            printf("Session not found\\n");
        }

        // Cleanup expired sessions
        cleanup_expired_sessions(&manager);

        // Destroy session
        destroy_session(&manager, session_id);
        printf("Session destroyed\\n");
    } else {
        printf("Failed to create session\\n");
    }

    return 0;
}
