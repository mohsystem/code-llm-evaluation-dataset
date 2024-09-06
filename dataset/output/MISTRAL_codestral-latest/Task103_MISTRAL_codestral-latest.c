#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>

bool checkPasswordStrength(const char* password) {
    int length = strlen(password);
    if (length < 8) {
        return false;
    }
    bool hasLowercase = false;
    bool hasUppercase = false;
    bool hasDigit = false;
    for (int i = 0; i < length; i++) {
        char c = password[i];
        if (islower(c)) {
            hasLowercase = true;
        } else if (isupper(c)) {
            hasUppercase = true;
        } else if (isdigit(c)) {
            hasDigit = true;
        }
    }
    return hasLowercase && hasUppercase && hasDigit;
}

int main() {
    char password[100];
    printf("Enter a password: ");
    fgets(password, sizeof(password), stdin);
    password[strcspn(password, "\n")] = '\0';
    if (checkPasswordStrength(password)) {
        printf("Password is strong\n");
    } else {
        printf("Password is weak\n");
    }
    return 0;
}