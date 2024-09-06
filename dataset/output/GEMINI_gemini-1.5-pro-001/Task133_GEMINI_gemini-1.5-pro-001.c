#include <stdio.h>
#include <string.h>
#include <ctype.h>

int isValidPassword(const char *password) {
    int hasLower = 0, hasUpper = 0, hasDigit = 0;
    size_t len = strlen(password);

    if (len < 8) {
        return 0; 
    }

    for (size_t i = 0; i < len; ++i) {
        if (islower(password[i])) {
            hasLower = 1;
        } else if (isupper(password[i])) {
            hasUpper = 1;
        } else if (isdigit(password[i])) {
            hasDigit = 1;
        }
    }

    return hasLower && hasUpper && hasDigit;
}

void resetPassword() {
    char newPassword[100], confirmPassword[100];

    while (1) {
        printf("Enter your new password: ");
        fgets(newPassword, sizeof(newPassword), stdin);
        newPassword[strcspn(newPassword, "\n")] = 0; // Remove trailing newline

        printf("Confirm your new password: ");
        fgets(confirmPassword, sizeof(confirmPassword), stdin);
        confirmPassword[strcspn(confirmPassword, "\n")] = 0; // Remove trailing newline

        if (strcmp(newPassword, confirmPassword) == 0 && isValidPassword(newPassword)) {
            printf("Password reset successfully!\n");
            break;
        } else {
            printf("Invalid password or passwords don't match. Please try again.\n");
        }
    }
}

int main() {
    resetPassword();
    return 0;
}