
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define PASSWORD_LENGTH 12
#define MAX_USERNAME_LENGTH 50

const char CHAR_SET[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!@#$%^&*()_+-=[]{}|;:,.<>?";

void generatePassword(char *password, int length) {
    int charSetLength = strlen(CHAR_SET);
    for (int i = 0; i < length; i++) {
        password[i] = CHAR_SET[rand() % charSetLength];
    }
    password[length] = '\\0';
}

void resetPassword(const char *username) {
    char newPassword[PASSWORD_LENGTH + 1];
    generatePassword(newPassword, PASSWORD_LENGTH);
    printf("Password for %s has been reset.\\n", username);
    printf("New password: %s\\n", newPassword);
    // In a real system, you would hash and save this password securely
}

int main() {
    srand(time(NULL));
    char username[MAX_USERNAME_LENGTH];
    printf("Enter username to reset password: ");
    fgets(username, MAX_USERNAME_LENGTH, stdin);
    username[strcspn(username, "\\n")] = 0; // Remove newline if present
    resetPassword(username);
    return 0;
}
