
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX_PASSWORD_LENGTH 100

int main() {
    FILE *file;
    char storedPassword[MAX_PASSWORD_LENGTH];
    char enteredPassword[MAX_PASSWORD_LENGTH];
    bool match = true;

    file = fopen("password.txt", "r");
    if (file == NULL) {
        printf("Password file not found.\
");
        return 1;
    }

    fgets(storedPassword, MAX_PASSWORD_LENGTH, file);
    storedPassword[strcspn(storedPassword, "\
")] = 0; // Remove newline
    fclose(file);

    printf("Enter password: ");
    fgets(enteredPassword, MAX_PASSWORD_LENGTH, stdin);
    enteredPassword[strcspn(enteredPassword, "\
")] = 0; // Remove newline

    if (strlen(storedPassword) != strlen(enteredPassword)) {
        match = false;
    } else {
        for (int i = 0; i < strlen(storedPassword); i++) {
            if (storedPassword[i] != enteredPassword[i]) {
                match = false;
                break;
            }
        }
    }

    if (match) {
        printf("Password correct!\
");
    } else {
        printf("Password incorrect!\
");
    }

    return 0;
}
