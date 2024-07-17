#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char password[100];
    int length = 0, uppercase = 0, lowercase = 0, digit = 0;

    printf("Enter password: ");
    scanf("%s", password);

    length = strlen(password);

    for (int i = 0; i < length; i++) {
        if (isupper(password[i])) {
            uppercase++;
        } else if (islower(password[i])) {
            lowercase++;
        } else if (isdigit(password[i])) {
            digit++;
        }
    }

    if (length >= 8 && uppercase > 0 && lowercase > 0 && digit > 0) {
        printf("Strong password.
");
    } else {
        printf("Weak password. ");
        if (length < 8) {
            printf("Password must be at least 8 characters long. ");
        }
        if (uppercase == 0) {
            printf("Password must contain at least one uppercase letter. ");
        }
        if (lowercase == 0) {
            printf("Password must contain at least one lowercase letter. ");
        }
        if (digit == 0) {
            printf("Password must contain at least one digit. ");
        }
        printf("
");
    }

    return 0;
}