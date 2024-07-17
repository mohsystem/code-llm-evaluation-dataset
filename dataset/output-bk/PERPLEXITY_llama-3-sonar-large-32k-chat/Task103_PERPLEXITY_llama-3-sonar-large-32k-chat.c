#include <stdio.h>
#include <ctype.h>
#include <string.h>

int isValidPassword(char *password) {
    int hasUpper = 0, hasLower = 0, hasDigit = 0;
    if (strlen(password) < 8) return 0;
    for (int i = 0; i < strlen(password); i++) {
        if (isupper(password[i])) hasUpper = 1;
        if (islower(password[i])) hasLower = 1;
        if (isdigit(password[i])) hasDigit = 1;
    }
    return hasUpper && hasLower && hasDigit;
}

int main() {
    char password[100];
    printf("Enter password: ");
    scanf("%99s", password);
    if (isValidPassword(password)) {
        printf("Strong password
");
    } else {
        printf("Weak password
");
    }
    return 0;
}