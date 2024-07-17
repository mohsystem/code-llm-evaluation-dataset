
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_SESSIONS 100
#define SESSION_ID_LENGTH 37

typedef struct {
    char session_id[SESSION_ID_LENGTH];
    char user_id[50];
    time_t creation_time;
    time_t last_activity;
} Session;

typedef struct {
    Session sessions[MAX_SESSIONS];
    int count;
    int session_timeout;
} SessionManager;

void init_session_manager(SessionManager* manager, int timeout) {
    manager->count = 0;
    manager->session_timeout = timeout;
}

char* generate_session_id() {
    static char session_id[SESSION_ID_LENGTH];
    static int counter = 0;
    time_t now = time(NULL);
    struct tm* t = localtime(&now);
    
    snprintf(session_id, sizeof(session_id), "%04d%02d%02d%02d%02d%02d-%d",
             t->tm_year + 1900, t->tm_mon + 1, t->tm_mday,
             t->tm_hour, t->tm_min, t->tm_sec, ++counter);
    
    return session_id;
}

char* create_session(SessionManager* manager, const char* user_id) {
    if (manager->count >= MAX_SESSIONS) {
        return NULL;
    }

    Session* session = &manager->sessions[manager->count++];
    strcpy(session->session_id, generate_session_id());
    strcpy(session->user_id, user_id);
    session->creation_time = time(NULL);
    session->last_activity = session->creation_time;

    return session->session_id;
}

Session* get_session(SessionManager* manager, const char* session_id) {
    time_t now = time(NULL);

    for (int i = 0; i < manager->count; i++) {
        if (strcmp(manager->sessions[i].session_id, session_id) == 0) {
            if (now - manager->sessions[i].last_activity > manager->session_timeout) {
                // Session expired
                memmove(&manager->sessions[i], &manager->sessions[i + 1], 
                        (manager->count - i - 1) * sizeof(Session));
                manager->count--;
                return NULL;
            }
            manager->sessions[i].last_activity = now;
            return &manager->sessions[i];
        }
    }

    return NULL;
}

void destroy_session(SessionManager* manager, const char* session_id) {
    for (int i = 0; i < manager->count; i++) {
        if (strcmp(manager->sessions[i].session_id, session_id) == 0) {
            memmove(&manager->sessions[i], &manager->sessions[i + 1], 
                    (manager->count - i - 1) * sizeof(Session));
            manager->count--;
            return;
        }
    }
}

void cleanup_expired_sessions(SessionManager* manager) {
    time_t now = time(NULL);
    int i = 0;

    while (i < manager->count) {
        if (now - manager->sessions[i].last_activity > manager->session_timeout) {
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

    // Create a session
    const char* user_id = "user123";
    char* session_id = create_session(&manager, user_id);
    if (session_id) {
        printf("Session created for user %s: %s\
", user_id, session_id);
    } else {
        printf("Failed to create session\
");
    }

    // Get session
    Session* session = get_session(&manager, session_id);
    if (session) {
        printf("Session found for user %s\
", session->user_id);
    } else {
        printf("Session not found\
");
    }

    // Simulate session expiration
    sleep(2);
    init_session_manager(&manager, 1); // Set timeout to 1 second for demonstration
    session = get_session(&manager, session_id);
    if (session) {
        printf("Session still active for user %s\
", session->user_id);
    } else {
        printf("Session expired\
");
    }

    // Cleanup expired sessions
    cleanup_expired_sessions(&manager);
    printf("Expired sessions cleaned up\
");

    return 0;
}
