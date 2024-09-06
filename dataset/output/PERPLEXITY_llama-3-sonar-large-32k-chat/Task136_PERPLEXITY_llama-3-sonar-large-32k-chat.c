// C code
#include <stdio.h>
#include <string.h>

int main() {
    char users[][2][20] = {{"admin", "password"}, {"user", "password"}};
    int numUsers = sizeof(users) / sizeof(users[0]);

    char username[20], password[20];
    printf("Enter username: ");
    scanf("%s", username);
    printf("Enter password: ");
    scanf("%s", password);

    int authenticated = 0;
    for (int i = 0; i < numUsers; i++) {
        if (strcmp(users[i][0], username) == 0 && strcmp(users[i][1], password) == 0) {
            authenticated = 1;
            break;
        }
    }

    if (authenticated) {
        printf("Authentication successful!\n");
    } else {
        printf("Invalid username or password\n");
    }
    return 0;
}