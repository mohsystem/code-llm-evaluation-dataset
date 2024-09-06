
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_PASSWORD_LENGTH 100

bool isValidAdminPassword(const char* password) {
    int length = strlen(password);
    if (length < 12) {
        return false;
    }

    bool hasUppercase = false;
    bool hasLowercase = false;
    bool hasDigit = false;
    bool hasSpecialChar = false;

    for (int i = 0; i < length; i++) {
        if (isupper(password[i])) hasUppercase = true;
        if (islower(password[i])) hasLowercase = true;
        if (isdigit(password[i])) hasDigit = true;
        if (strchr("!@#$%^&*(),.?\\":{}|<>", password[i])) hasSpecialChar = true;
    }

    if (!hasUppercase || !hasLowercase || !hasDigit || !hasSpecialChar) {
        return false;
    }

    char lowercasePassword[MAX_PASSWORD_LENGTH];
    strcpy(lowercasePassword, password);
    for (int i = 0; i < length; i++) {
        lowercasePassword[i] = tolower(lowercasePassword[i]);
    }

    if (strstr(lowercasePassword, "admin") != NULL) {
        return false;
    }

    return true;
}

int main() {
    char password[MAX_PASSWORD_LENGTH];
    printf("Enter the admin password: ");
    fgets(password, sizeof(password), stdin);
    password[strcspn(password, "\\n")] = 0; // Remove newline

    if (isValidAdminPassword(password)) {
        printf("Password is valid\\n");
    } else {
        printf("Password is invalid\\n");
    }

    return 0;
}
