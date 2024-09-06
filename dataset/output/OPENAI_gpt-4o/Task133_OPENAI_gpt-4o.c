// C
#include <stdio.h>

void resetPassword(const char* username, const char* newPassword) {
    printf("Password for %s has been reset to %s\n", username, newPassword);
}

int main() {
    char username[50], newPassword[50];
    
    printf("Enter your username: ");
    scanf("%49s", username);

    printf("Enter your new password: ");
    scanf("%49s", newPassword);

    resetPassword(username, newPassword);

    return 0;
}