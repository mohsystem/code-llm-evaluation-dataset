#include <stdio.h>
#include <string.h>

int main() {
    char storedPassword[100], enteredPassword[100];
    FILE *fp;

    printf("Enter password: ");
    fgets(enteredPassword, sizeof(enteredPassword), stdin);
    enteredPassword[strcspn(enteredPassword, "
")] = 0; // Remove trailing newline

    fp = fopen("password.txt", "r");
    if (fp == NULL) {
        printf("Error opening file.
");
        return 1;
    }

    fgets(storedPassword, sizeof(storedPassword), fp);
    fclose(fp);

    storedPassword[strcspn(storedPassword, "
")] = 0; // Remove trailing newline

    if (strcmp(storedPassword, enteredPassword) == 0) {
        printf("Password matches.
");
    } else {
        printf("Incorrect password.
");
    }

    return 0;
}