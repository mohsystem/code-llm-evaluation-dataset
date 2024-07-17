#include <stdio.h>
#include <string.h>

int main() {
    char username[100], oldPassword[100], newPassword[100], confirmPassword[100];

    printf("Enter your username: ");
    fgets(username, sizeof(username), stdin);
    username[strcspn(username, "
")] = 0; // remove newline character

    printf("Enter your old password: ");
    fgets(oldPassword, sizeof(oldPassword), stdin);
    oldPassword[strcspn(oldPassword, "
")] = 0; // remove newline character

    printf("Enter your new password: ");
    fgets(newPassword, sizeof(newPassword), stdin);
    newPassword[strcspn(newPassword, "
")] = 0; // remove newline character

    printf("Confirm your new password: ");
    fgets(confirmPassword, sizeof(confirmPassword), stdin);
    confirmPassword[strcspn(confirmPassword, "
")] = 0; // remove newline character

    if (strcmp(newPassword, confirmPassword) == 0) {
        printf("Password reset successfully!
");
    } else {
        printf("New password and confirm password do not match. Please try again.
");
    }

    return 0;
}