#include <stdio.h>
#include <string.h>
#include <ctype.h>

int isValidPassword(const char *password) {
    if (strlen(password) < 8) return 0;
    int hasUpperCase = 0, hasLowerCase = 0, hasDigit = 0;

    for (int i = 0; password[i]; i++) {
        if (isupper(password[i])) hasUpperCase = 1;
        if (islower(password[i])) hasLowerCase = 1;
        if (isdigit(password[i])) hasDigit = 1;
    }

    return hasUpperCase && hasLowerCase && hasDigit;
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("No password provided
");
        return 1;
    }
    if (isValidPassword(argv[1])) {
        printf("Password is strong
");
    } else {
        printf("Password is weak
");
    }
    return 0;
}