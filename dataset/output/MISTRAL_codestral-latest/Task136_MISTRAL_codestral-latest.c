// C

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_USERS 100
#define MAX_LENGTH 50

typedef struct {
    char username[MAX_LENGTH];
    char password[MAX_LENGTH];
} User;

typedef struct {
    User users[MAX_USERS];
    int count;
} Authentication;

void registerUser(Authentication* auth, const char* username, const char* password) {
    if (auth->count < MAX_USERS) {
        strcpy(auth->users[auth->count].username, username);
        strcpy(auth->users[auth->count].password, password);
        auth->count++;
        printf("User registered successfully.\n");
    } else {
        printf("Maximum number of users reached.\n");
    }
}

void login(Authentication* auth, const char* username, const char* password) {
    for (int i = 0; i < auth->count; i++) {
        if (strcmp(auth->users[i].username, username) == 0 && strcmp(auth->users[i].password, password) == 0) {
            printf("Login successful.\n");
            return;
        }
    }
    printf("Invalid username or password.\n");
}

int main() {
    Authentication auth;
    auth.count = 0;

    registerUser(&auth, "user1", "password1");
    login(&auth, "user1", "password1");

    return 0;
}