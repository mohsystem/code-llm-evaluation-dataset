#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>

bool isValidPassword(const char* password) {
    // Admin password requirements:
    // - At least 8 characters long
    // - Contains at least one uppercase letter
    // - Contains at least one lowercase letter
    // - Contains at least one digit
    // - Contains at least one special character

    if (strlen(password) < 8) {
        return false;
    }

    bool hasUppercase = false;
    bool hasLowercase = false;
    bool hasDigit = false;
    bool hasSpecialChar = false;

    for (int i = 0; password[i] != '\0'; i++) {
        if (isupper(password[i])) {
            hasUppercase = true;
        } else if (islower(password[i])) {
            hasLowercase = true;
        } else if (isdigit(password[i])) {
            hasDigit = true;
        } else if (strchr("!@#$%^&*()-_=+[]{}|;:,.<>?", password[i]) != NULL) {
            hasSpecialChar = true;
        }
    }

    return hasUppercase && hasLowercase && hasDigit && hasSpecialChar;
}

int main() {
    char password[100];
    printf("Enter admin password: ");
    fgets(password, sizeof(password), stdin);

    // Remove newline character from the input
    password[strcspn(password, "\n")] = '\0';

    if (isValidPassword(password)) {
        printf("Password is valid.\n");
    } else {
        printf("Password is invalid.\n");
    }

    return 0;
}