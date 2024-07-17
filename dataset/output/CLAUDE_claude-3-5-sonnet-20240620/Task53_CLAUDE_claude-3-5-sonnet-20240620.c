
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <uuid/uuid.h>

#define SESSION_TIMEOUT_SECONDS 1800 // 30 minutes

typedef struct {
    char session_id[37];
    char user_id[50];
    time_t creation_time;
    time_t last_access_time;
} Session;

typedef struct {
    Session* sessions;
    int count;
    int capacity;
} SessionManager;

void init_session_manager(SessionManager* manager) {
    manager->sessions = NULL;
    manager->count = 0;
    manager->capacity = 0;
}

char* create_session(SessionManager* manager, const char* user_id) {
    if (manager->count == manager->capacity) {
        int new_capacity = manager->capacity == 0 ? 1 : manager->capacity * 2;
        Session* new_sessions = realloc(manager->sessions, new_capacity * sizeof(Session));
        if (new_sessions == NULL) {
            return NULL;
        }
        manager->sessions = new_sessions;
        manager->capacity = new_capacity;
    }

    Session* session = &manager->sessions[manager->count++];
    uuid_t uuid;
    uuid_generate(uuid);
    uuid_unparse(uuid, session->session_id);
    strncpy(session->user_id, user_id, sizeof(session->user_id) - 1);
    session->creation_time = time(NULL);
    session->last_access_time = session->creation_time;

    return session->session_id;
}

int validate_session(SessionManager* manager, const char* session_id) {
    time_t current_time = time(NULL);
    for (int i = 0; i < manager->count; i++) {
        if (strcmp(manager->sessions[i].session_id, session_id) == 0) {
            if (current_time - manager->sessions[i].last_access_time < SESSION_TIMEOUT_SECONDS) {
                manager->sessions[i].last_access_time = current_time;
                return 1;
            } else {
                // Remove expired session
                memmove(&manager->sessions[i], &manager->sessions[i + 1], 
                        (manager->count - i - 1) * sizeof(Session));
                manager->count--;
                return 0;
            }
        }
    }
    return 0;
}

void end_session(SessionManager* manager, const char* session_id) {
    for (int i = 0; i < manager->count; i++) {
        if (strcmp(manager->sessions[i].session_id, session_id) == 0) {
            memmove(&manager->sessions[i], &manager->sessions[i + 1], 
                    (manager->count - i - 1) * sizeof(Session));
            manager->count--;
            return;
        }
    }
}

void free_session_manager(SessionManager* manager) {
    free(manager->sessions);
    manager->sessions = NULL;
    manager->count = 0;
    manager->capacity = 0;
}

int main() {
    SessionManager manager;
    init_session_manager(&manager);

    // Example usage
    const char* user_id = "user123";
    char* session_id = create_session(&manager, user_id);
    if (session_id != NULL) {
        printf("Session created: %s\
", session_id);

        int is_valid = validate_session(&manager, session_id);
        printf("Session valid: %d\
", is_valid);

        end_session(&manager, session_id);
        printf("Session ended\
");

        is_valid = validate_session(&manager, session_id);
        printf("Session valid after ending: %d\
", is_valid);
    }

    free_session_manager(&manager);
    return 0;
}
