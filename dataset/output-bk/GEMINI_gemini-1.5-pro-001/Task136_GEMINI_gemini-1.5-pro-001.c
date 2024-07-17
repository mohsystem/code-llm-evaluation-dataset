#include <stdio.h>
#include <string.h>

int authenticate(char *username, char *password) {
    // Check if the provided username and password match a predefined set
    char validUsername[] = "user";
    char validPassword[] = "password";
    return (strcmp(username, validUsername) == 0) && (strcmp(password, validPassword) == 0);
}

int main() {
    // Get user credentials
    char username[100], password[100];
    printf("Username: ");
    scanf("%s", username);
    printf("Password: ");
    scanf("%s", password);

    // Authenticate user
    if (authenticate(username, password)) {
        printf("Authentication successful. Welcome!
");
    } else {
        printf("Authentication failed. Invalid username or password.
");
    }

    return 0;
}