#include <stdio.h>
#include <string.h>

void resetPassword() {
    char currentPassword[100], newPassword[100], confirmPassword[100];

    while (1) {
        printf("Enter your current password: ");
        fgets(currentPassword, sizeof(currentPassword), stdin);
        currentPassword[strcspn(currentPassword, "
")] = 0; // Remove trailing newline
        if (strcmp(currentPassword, "password123") == 0) {
            break;
        } else {
            printf("Incorrect password. Please try again.
");
        }
    }

    while (1) {
        printf("Enter your new password: ");
        fgets(newPassword, sizeof(newPassword), stdin);
        newPassword[strcspn(newPassword, "
")] = 0; // Remove trailing newline
        printf("Confirm your new password: ");
        fgets(confirmPassword, sizeof(confirmPassword), stdin);
        confirmPassword[strcspn(confirmPassword, "
")] = 0; // Remove trailing newline
        if (strcmp(newPassword, confirmPassword) == 0) {
            printf("Password reset successful.
");
            break;
        } else {
            printf("Passwords don't match. Please try again.
");
        }
    }
}

int main() {
    resetPassword();
    return 0;
}