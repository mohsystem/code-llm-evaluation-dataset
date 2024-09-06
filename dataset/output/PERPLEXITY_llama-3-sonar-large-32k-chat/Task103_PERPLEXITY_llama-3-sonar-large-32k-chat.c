#include <stdio.h>
#include <ctype.h>
#include <string.h>

int passwordStrength(const char* password) {
    if (strlen(password) < 8) {
        return 0;
    }
    int hasUpper = 0, hasLower = 0, hasDigit = 0;
    for (int i = 0; password[i]; i++) {
        if (isupper(password[i])) {
            hasUpper = 1;
        } else if (islower(password[i])) {
            hasLower = 1;
        } else if (isdigit(password[i])) {
            hasDigit = 1;
        }
        if (hasUpper && hasLower && hasDigit) {
            break;
        }
    }
    return hasUpper && hasLower && hasDigit;
}

int main() {
    char password[256];
    printf("Enter a password: ");
    fgets(password, 256, stdin);
    password[strcspn(password, "\n")] = 0; // remove newline character
    if (passwordStrength(password)) {
        printf("Strong password\n");
    } else {
        printf("Weak password\n");
    }
    return 0;
}