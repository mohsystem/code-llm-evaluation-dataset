#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char password[100];
    printf("Enter your password: ");
    scanf("%s", password);

    int hasLower = 0, hasUpper = 0, hasDigit = 0;
    size_t length = strlen(password);

    if (length >= 8) {
        for (size_t i = 0; i < length; i++) {
            if (islower(password[i])) hasLower = 1;
            if (isupper(password[i])) hasUpper = 1;
            if (isdigit(password[i])) hasDigit = 1;
        }
    }

    if (hasLower && hasUpper && hasDigit && length >= 8) {
        printf("Password is strong.\n");
    } else {
        printf("Password is weak.\n");
    }

    return 0;
}