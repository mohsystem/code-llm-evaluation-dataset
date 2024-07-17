#include <stdio.h>
#include <string.h>

typedef struct {
    char username[20];
    char password[20];
} User;

User users[] = {
    {"admin", "password123"},
    {"user", "password456"}
};

int authenticate(char *username, char *password) {
    for (int i = 0; i < sizeof(users) / sizeof(User); i++) {
        if (strcmp(users[i].username, username) == 0 && strcmp(users[i].password, password) == 0) {
            return 1;
        }
    }
    return 0;
}

int main() {
    char username[20];
    char password[20];

    printf("Enter username: ");
    scanf("%19s", username);

    printf("Enter password: ");
    scanf("%19s", password);

    if (authenticate(username, password)) {
        printf("Authentication successful!
");
    } else {
        printf("Invalid credentials!
");
    }

    return 0;
}