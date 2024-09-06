
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_PASSWORD_LENGTH 100

bool check_password(const char* stored_password, const char* entered_password) {
    if (strlen(stored_password) != strlen(entered_password)) {
        return false;
    }
    for (int i = 0; stored_password[i] != '\\0'; i++) {
        if (stored_password[i] != entered_password[i]) {
            return false;
        }
    }
    return true;
}

int main() {
    char stored_password[MAX_PASSWORD_LENGTH];
    FILE* file = fopen("password.txt", "r");
    if (file == NULL) {
        printf("Password file not found.\\n");
        return 1;
    }
    if (fgets(stored_password, sizeof(stored_password), file) == NULL) {
        printf("Error reading password file.\\n");
        fclose(file);
        return 1;
    }
    fclose(file);

    // Remove newline character if present
    stored_password[strcspn(stored_password, "\\n")] = 0;

    char entered_password[MAX_PASSWORD_LENGTH];
    printf("Enter your password: ");
    if (fgets(entered_password, sizeof(entered_password), stdin) == NULL) {
        printf("Error reading input.\\n");
        return 1;
    }
    
    // Remove newline character if present
    entered_password[strcspn(entered_password, "\\n")] = 0;

    if (check_password(stored_password, entered_password)) {
        printf("Password correct!\\n");
    } else {
        printf("Password incorrect.\\n");
    }

    return 0;
}
