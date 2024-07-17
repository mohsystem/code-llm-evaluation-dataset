
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_PASSWORD_LENGTH 100

int checkPasswordStrength(const char* password) {
    int length = strlen(password);
    if (length < 8) {
        return 0;
    }

    int hasUppercase = 0;
    int hasLowercase = 0;
    int hasDigit = 0;

    for (int i = 0; i < length; i++) {
        if (isupper(password[i])) {
            hasUppercase = 1;
        } else if (islower(password[i])) {
            hasLowercase = 1;
        } else if (isdigit(password[i])) {
            hasDigit = 1;
        }
    }

    return hasUppercase && hasLowercase && hasDigit;
}

int main() {
    char password[MAX_PASSWORD_LENGTH];
    printf("Enter a password: ");
    fgets(password, sizeof(password), stdin);
    password[strcspn(password, "\
")] = 0;  // Remove newline character

    int isStrong = checkPasswordStrength(password);

    if (isStrong) {
        printf("Strong password!\
");
    } else {
        printf("Weak password. Please try again.\
");
    }

    return 0;
}
