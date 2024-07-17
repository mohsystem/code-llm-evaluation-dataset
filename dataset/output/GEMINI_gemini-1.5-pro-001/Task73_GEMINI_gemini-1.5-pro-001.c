#include <stdio.h>
#include <string.h>
#include <ctype.h>

int isValidAdminPassword(char *password);

int main() {
    char password[100];
    printf("Enter password: ");
    fgets(password, sizeof(password), stdin);
    password[strcspn(password, "
")] = 0; // remove trailing newline

    if (isValidAdminPassword(password)) {
        printf("Valid password
");
    } else {
        printf("Invalid password
");
    }
    return 0;
}

int isValidAdminPassword(char *password) {
    int hasUpper = 0, hasLower = 0, hasDigit = 0, hasSpecial = 0;
    if (strlen(password) < 10) {
        return 0;
    }
    for (int i = 0; password[i] != '\0'; i++) {
        if (isupper(password[i])) {
            hasUpper = 1;
        } else if (islower(password[i])) {
            hasLower = 1;
        } else if (isdigit(password[i])) {
            hasDigit = 1;
        } else if (strchr("!@#$%^&*()", password[i]) != NULL) {
            hasSpecial = 1;
        }
    }
    return hasUpper && hasLower && hasDigit && hasSpecial;
}