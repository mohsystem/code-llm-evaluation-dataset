#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int userId;
    char username[256];
} Session;

typedef struct {
    Session* sessions;
    int size;
} SessionManager;

SessionManager* createSessionManager() {
    SessionManager* manager = (SessionManager*)malloc(sizeof(SessionManager));
    manager->sessions = (Session*)malloc(sizeof(Session) * 10);
    manager->size = 0;
    return manager;
}

void createSession(SessionManager* manager, int userId, const char* username) {
    if (manager->size < 10) {
        manager->sessions[manager->size].userId = userId;
        strcpy(manager->sessions[manager->size].username, username);
        manager->size++;
        printf("Session created for user %s with ID %d\n", username, userId);
    } else {
        printf("Session manager is full\n");
    }
}

const char* getUsername(SessionManager* manager, int userId) {
    for (int i = 0; i < manager->size; i++) {
        if (manager->sessions[i].userId == userId) {
            return manager->sessions[i].username;
        }
    }
    return NULL;
}

void deleteSession(SessionManager* manager, int userId) {
    for (int i = 0; i < manager->size; i++) {
        if (manager->sessions[i].userId == userId) {
            for (int j = i; j < manager->size - 1; j++) {
                manager->sessions[j] = manager->sessions[j + 1];
            }
            manager->size--;
            printf("Session deleted for user ID %d\n", userId);
            return;
        }
    }
    printf("No session found for user ID %d\n", userId);
}

int main() {
    SessionManager* manager = createSessionManager();
    createSession(manager, 1, "John");
    createSession(manager, 2, "Alice");
    const char* username = getUsername(manager, 1);
    if (username) {
        printf("Username: %s\n", username);  // Output: John
    }
    deleteSession(manager, 2);
    return 0;
}