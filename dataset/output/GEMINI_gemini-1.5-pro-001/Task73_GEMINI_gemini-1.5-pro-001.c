#include <stdio.h>
#include <string.h>
#include <ctype.h>

int isPasswordValid(const char *password) {
    if (strlen(password) < 8) {
        return 0;
    }
    int hasUpper = 0, hasLower = 0, hasDigit = 0;
    for (int i = 0; password[i] != '\0'; i++) {
        if (isupper(password[i])) {
            hasUpper = 1;
        } else if (islower(password[i])) {
            hasLower = 1;
        } else if (isdigit(password[i])) {
            hasDigit = 1;
        }
    }
    return hasUpper && hasLower && hasDigit;
}

int main() {
    char password[100];
    printf("Enter the password: ");
    scanf("%s", password);

    if (isPasswordValid(password)) {
        printf("Valid password\n");
    } else {
        printf("Invalid password\n");
    }

    return 0;
}