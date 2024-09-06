#include <stdio.h>
#include <string.h>

int authenticate(const char* username, const char* password) {
    const char* storedUsername = "user";
    const char* storedPassword = "pass";
    return strcmp(username, storedUsername) == 0 && strcmp(password, storedPassword) == 0;
}

int main() {
    char username[50], password[50];

    printf("Enter username: ");
    fgets(username, sizeof(username), stdin);
    username[strcspn(username, "\n")] = 0; // Remove newline character

    printf("Enter password: ");
    fgets(password, sizeof(password), stdin);
    password[strcspn(password, "\n")] = 0; // Remove newline character

    if (authenticate(username, password)) {
        printf("Access granted\n");
    } else {
        printf("Access denied\n");
    }

    return 0;
}