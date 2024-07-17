#include <stdio.h>
#include <string.h>

typedef struct {
    char username[256];
    int loggedIn;
} UserSession;

void login(UserSession* session) {
    session->loggedIn = 1;
    printf("%s has logged in.
", session->username);
}

void logout(UserSession* session) {
    session->loggedIn = 0;
    printf("%s has logged out.
", session->username);
}

int main() {
    UserSession sessions[256];
    int numSessions = 0;
    while (true) {
        printf("1. Create session
");
        printf("2. Login
");
        printf("3. Logout
");
        printf("4. Exit
");
        int choice;
        printf("Choose an option: ");
        scanf("%d", &choice);
        if (choice == 1) {
            printf("Enter username: ");
            scanf("%255s", sessions[numSessions].username);
            numSessions++;
            printf("Session created for %s.
", sessions[numSessions-1].username);
        } else if (choice == 2) {
            printf("Enter username: ");
            char username[256];
            scanf("%255s", username);
            for (int i = 0; i < numSessions; i++) {
                if (strcmp(sessions[i].username, username) == 0) {
                    login(&sessions[i]);
                    break;
                }
            }
        } else if (choice == 3) {
            printf("Enter username: ");
            char username[256];
            scanf("%255s", username);
            for (int i = 0; i < numSessions; i++) {
                if (strcmp(sessions[i].username, username) == 0) {
                    logout(&sessions[i]);
                    break;
                }
            }
        } else if (choice == 4) {
            break;
        } else {
            printf("Invalid option. Please try again.
");
        }
    }
    return 0;
}