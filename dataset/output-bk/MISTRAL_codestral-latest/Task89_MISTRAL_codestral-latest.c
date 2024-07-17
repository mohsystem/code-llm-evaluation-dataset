#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 100

int main() {
    char inputPassword[MAX_LENGTH];
    char storedPassword[MAX_LENGTH];

    printf("Enter password: ");
    fgets(inputPassword, MAX_LENGTH, stdin);
    inputPassword[strcspn(inputPassword, "
")] = 0; // remove newline character

    FILE *file = fopen("password.txt", "r");
    if (file == NULL) {
        printf("An error occurred while reading the file.
");
        return 1;
    }

    fgets(storedPassword, MAX_LENGTH, file);
    storedPassword[strcspn(storedPassword, "
")] = 0; // remove newline character

    if (strcmp(inputPassword, storedPassword) == 0) {
        printf("Password is correct.
");
    } else {
        printf("Password is incorrect.
");
    }

    fclose(file);
    return 0;
}