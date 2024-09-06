// C
#include <stdio.h>
#include <string.h>

struct User {
    char username[50];
    char password[50];
};

struct User users[] = {{"user1", "password1"}, {"user2", "password2"}};
int numUsers = sizeof(users) / sizeof(users[0]);

int main() {
    char username[50], password[50];
    int i, found = 0;

    printf("Enter your username: ");
    scanf("%s", username);

    printf("Enter your password: ");
    scanf("%s", password);

    for (i = 0; i < numUsers; i++) {
        if (strcmp(username, users[i].username) == 0 && strcmp(password, users[i].password) == 0) {
            printf("Authentication successful.\n");
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Invalid username or password.\n");
    }

    return 0;
}