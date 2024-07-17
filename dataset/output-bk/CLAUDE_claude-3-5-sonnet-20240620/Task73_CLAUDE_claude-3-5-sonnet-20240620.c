
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_PASSWORD_LENGTH 100

int isValidPassword(const char* password) {
    int len = strlen(password);
    int hasUpper = 0, hasLower = 0, hasDigit = 0, hasSpecial = 0;
    const char* specialChars = "!@#$%^&*()_+-=[]{};\':\\"\\\\|,.<>/?";

    if (len < 12) return 0;

    for (int i = 0; i < len; i++) {
        if (isupper(password[i])) hasUpper = 1;
        else if (islower(password[i])) hasLower = 1;
        else if (isdigit(password[i])) hasDigit = 1;
        else if (strchr(specialChars, password[i])) hasSpecial = 1;
    }

    return hasUpper && hasLower && hasDigit && hasSpecial;
}

int main() {
    char password[MAX_PASSWORD_LENGTH];
    printf("Enter password: ");
    fgets(password, sizeof(password), stdin);
    password[strcspn(password, "\
")] = 0;  // Remove newline

    if (isValidPassword(password)) {
        printf("Password is valid.\
");
    } else {
        printf("Password is invalid.\
");
    }

    return 0;
}
