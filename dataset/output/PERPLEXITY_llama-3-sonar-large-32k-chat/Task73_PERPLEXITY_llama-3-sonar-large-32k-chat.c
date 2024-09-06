#include <stdio.h>
#include <string.h>
#include <ctype.h>

int checkPassword(const char* password) {
    if (strlen(password) < 8) {
        return 0;
    }
    int hasDigit = 0;
    int hasUpper = 0;
    int hasLower = 0;
    for (int i = 0; password[i] != '\0'; i++) {
        if (isdigit(password[i])) {
            hasDigit = 1;
        }
        if (isupper(password[i])) {
            hasUpper = 1;
        }
        if (islower(password[i])) {
            hasLower = 1;
        }
    }
    return hasDigit && hasUpper && hasLower;
}

int main() {
    char password[256];
    printf("Enter password: ");
    fgets(password, 256, stdin);
    password[strcspn(password, "\n")] = 0; // remove newline character
    if (checkPassword(password)) {
        printf("Password is valid\n");
    } else {
        printf("Password is not valid\n");
    }
    return 0;
}