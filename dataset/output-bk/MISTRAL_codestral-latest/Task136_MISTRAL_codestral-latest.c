// C

#include <stdio.h>
#include <string.h>

int authenticateUser(const char* username, const char* password) {
    // This is a simple example. In a real-world application,
    // you would check the username and password against a database.
    if (strcmp(username, "admin") == 0 && strcmp(password, "password") == 0) {
        return 1;
    } else {
        return 0;
    }
}

int main() {
    char username[50], password[50];

    printf("Enter your username: ");
    fgets(username, sizeof(username), stdin);
    username[strcspn(username, "
")] = 0; // Remove trailing newline

    printf("Enter your password: ");
    fgets(password, sizeof(password), stdin);
    password[strcspn(password, "
")] = 0; // Remove trailing newline

    if (authenticateUser(username, password)) {
        printf("Authentication successful.
");
    } else {
        printf("Authentication failed.
");
    }

    return 0;
}