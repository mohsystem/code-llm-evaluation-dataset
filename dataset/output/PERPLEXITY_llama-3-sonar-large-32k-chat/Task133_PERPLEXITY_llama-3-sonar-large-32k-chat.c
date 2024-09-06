#include <stdio.h>
#include <string.h>

int main() {
    char username[100], oldPassword[100], newPassword[100], confirmPassword[100];

    printf("Enter your username: ");
    fgets(username, sizeof(username), stdin);

    printf("Enter your old password: ");
    fgets(oldPassword, sizeof(oldPassword), stdin);

    printf("Enter your new password: ");
    fgets(newPassword, sizeof(newPassword), stdin);

    printf("Confirm your new password: ");
    fgets(confirmPassword, sizeof(confirmPassword), stdin);

    if (strcmp(newPassword, confirmPassword) == 0) {
        printf("Password reset successfully!\n");
    } else {
        printf("New password and confirm password do not match. Try again!\n");
    }

    return 0;
}