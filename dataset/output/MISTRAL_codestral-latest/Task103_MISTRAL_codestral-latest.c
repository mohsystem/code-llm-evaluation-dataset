#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#include <string.h>

bool isValidPassword(const char* password) {
    if (strlen(password) < 8) {
        return false;
    }

    bool hasUpperCase = false;
    bool hasLowerCase = false;
    bool hasDigit = false;

    for (int i = 0; i < strlen(password); i++) {
        char c = password[i];
        if (isupper(c)) {
            hasUpperCase = true;
        } else if (islower(c)) {
            hasLowerCase = true;
        } else if (isdigit(c)) {
            hasDigit = true;
        }
    }

    return hasUpperCase && hasLowerCase && hasDigit;
}

int main() {
    char password[100];
    printf("Enter a password: ");
    fgets(password, sizeof(password), stdin);
    password[strcspn(password, "
")] = 0; // Remove trailing newline character

    if (isValidPassword(password)) {
        printf("Password is strong.
");
    } else {
        printf("Password is weak. It should be at least 8 characters long, contain both uppercase and lowercase letters, and contain at least one digit.
");
    }

    return 0;
}