#include <stdio.h>
#include <string.h>

#define MAX_PASSWORD_LEN 100

int checkPassword(const char* storedPassword) {
    char enteredPassword[MAX_PASSWORD_LEN];
    printf("Enter password: ");
    fgets(enteredPassword, MAX_PASSWORD_LEN, stdin);
    enteredPassword[strcspn(enteredPassword, "\n")] = 0; // Remove trailing newline

    if (strlen(enteredPassword) != strlen(storedPassword)) {
        return 0;
    }
    for (size_t i = 0; i < strlen(storedPassword); ++i) {
        if (storedPassword[i] != enteredPassword[i]) {
            return 0;
        }
    }
    return 1;
}

int main() {
    FILE* file = fopen("password.txt", "r");
    if (file == NULL) {
        fprintf(stderr, "Password file not found. Please create 'password.txt'.\n");
        return 1;
    }

    char storedPassword[MAX_PASSWORD_LEN];
    fgets(storedPassword, MAX_PASSWORD_LEN, file);
    storedPassword[strcspn(storedPassword, "\n")] = 0; // Remove trailing newline
    fclose(file);

    if (checkPassword(storedPassword)) {
        printf("Passwords match.\n");
    } else {
        printf("Passwords do not match.\n");
    }

    return 0;
}