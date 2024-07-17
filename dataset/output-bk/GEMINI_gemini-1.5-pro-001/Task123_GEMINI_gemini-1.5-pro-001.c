#include <stdio.h>
#include <string.h>
#include <time.h>

#define MAX_SESSIONS 100
#define MAX_USERNAME_LENGTH 50

struct Session {
    char username[MAX_USERNAME_LENGTH];
    time_t loginTime;
};

struct Session sessions[MAX_SESSIONS];
int sessionCount = 0;

int findSessionIndex(char username[]) {
    for (int i = 0; i < sessionCount; i++) {
        if (strcmp(sessions[i].username, username) == 0) {
            return i;
        }
    }
    return -1;
}

void createSession(char username[]) {
    if (sessionCount < MAX_SESSIONS) {
        int index = findSessionIndex(username);
        if (index == -1) {
            strcpy(sessions[sessionCount].username, username);
            sessions[sessionCount].loginTime = time(NULL);
            sessionCount++;
            printf("Session created for %s
", username);
        } else {
            printf("Session already exists for %s
", username);
        }
    } else {
        printf("Session limit reached
");
    }
}

void getSession(char username[]) {
    int index = findSessionIndex(username);
    if (index != -1) {
        printf("Username: %s, Login Time: %s", sessions[index].username, ctime(&sessions[index].loginTime));
    } else {
        printf("Session not found for %s
", username);
    }
}

void deleteSession(char username[]) {
    int index = findSessionIndex(username);
    if (index != -1) {
        for (int i = index; i < sessionCount - 1; i++) {
            sessions[i] = sessions[i + 1];
        }
        sessionCount--;
        printf("Session deleted for %s
", username);
    } else {
        printf("Session not found for %s
", username);
    }
}

int main() {
    char action[20], username[MAX_USERNAME_LENGTH];
    while (1) {
        printf("Enter action (create/get/delete/exit): ");
        scanf("%s", action);
        if (strcmp(action, "exit") == 0) {
            break;
        }
        printf("Enter username: ");
        scanf("%s", username);
        if (strcmp(action, "create") == 0) {
            createSession(username);
        } else if (strcmp(action, "get") == 0) {
            getSession(username);
        } else if (strcmp(action, "delete") == 0) {
            deleteSession(username);
        } else {
            printf("Invalid action
");
        }
    }
    return 0;
}