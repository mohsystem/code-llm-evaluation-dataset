code here:
// Note: C does not have a built-in string class, so we'll use char arrays instead.
// Also, C does not have a built-in vector class, so we'll use a fixed-size array instead.

#include <stdio.h>
#include <string.h>

typedef struct {
    char username[20];
    char password[20];
} User;

bool authenticate(User user, char* username, char* password) {
    if (strcmp(user.username, username) == 0 && strcmp(user.password, password) == 0) {
        return true;
    } else {
        return false;
    }
}

int main() {
    User users[2] = {{"user1", "password1"}, {"user2", "password2"}};
    char username[20], password[20];
    printf("Enter username: ");
    scanf("%19s", username);
    printf("Enter password: ");
    scanf("%19s", password);
    for (int i = 0; i < 2; i++) {
        if (authenticate(users[i], username, password)) {
            printf("Authentication successful!\n");
            return 0;
        }
    }
    printf("Invalid credentials!\n");
    return 0;
}