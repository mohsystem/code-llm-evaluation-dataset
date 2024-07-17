// C
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_USERS 100
#define MAX_LENGTH 50

struct User {
    char username[MAX_LENGTH];
    char password[MAX_LENGTH];
};

struct User users[MAX_USERS];
int userCount = 0;

void registerUser() {
    if (userCount >= MAX_USERS) {
        printf("Maximum number of users reached
");
        return;
    }

    struct User newUser;
    printf("Enter username: ");
    scanf("%s", newUser.username);
    printf("Enter password: ");
    scanf("%s", newUser.password);

    users[userCount++] = newUser;
}

void login() {
    char username[MAX_LENGTH];
    char password[MAX_LENGTH];

    printf("Enter username: ");
    scanf("%s", username);
    printf("Enter password: ");
    scanf("%s", password);

    for (int i = 0; i < userCount; i++) {
        if (strcmp(users[i].username, username) == 0 && strcmp(users[i].password, password) == 0) {
            printf("Login successful
");
            return;
        }
    }

    printf("Invalid username or password
");
}

int main() {
    int choice;

    while (1) {
        printf("1. Register
2. Login
3. Exit
");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                registerUser();
                break;
            case 2:
                login();
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid choice
");
        }
    }

    return 0;
}