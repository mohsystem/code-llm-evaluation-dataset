// C
#include <stdio.h>
#include <string.h>

#define MAX_PASSWORD_LENGTH 50

int main() {
    char currentPassword[MAX_PASSWORD_LENGTH], newPassword[MAX_PASSWORD_LENGTH], confirmPassword[MAX_PASSWORD_LENGTH];

    printf("Enter your current password: ");
    fgets(currentPassword, MAX_PASSWORD_LENGTH, stdin);
    currentPassword[strcspn(currentPassword, "
")] = 0; // Remove trailing newline

    printf("Enter your new password: ");
    fgets(newPassword, MAX_PASSWORD_LENGTH, stdin);
    newPassword[strcspn(newPassword, "
")] = 0; // Remove trailing newline

    printf("Confirm your new password: ");
    fgets(confirmPassword, MAX_PASSWORD_LENGTH, stdin);
    confirmPassword[strcspn(confirmPassword, "
")] = 0; // Remove trailing newline

    if (strcmp(newPassword, confirmPassword) == 0) {
        printf("Password reset successful.
");
    } else {
        printf("Passwords do not match. Password reset failed.
");
    }

    return 0;
}