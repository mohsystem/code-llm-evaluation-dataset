#include <stdio.h>
#include <string.h>

int main() {
    char inputPassword[100];
    char storedPassword[100];

    printf("Enter password: ");
    scanf("%99s", inputPassword);

    FILE *file = fopen("password.txt", "r");
    fscanf(file, "%99s", storedPassword);
    fclose(file);

    int isValid = 1;
    if (strlen(inputPassword) != strlen(storedPassword)) {
        isValid = 0;
    } else {
        for (int i = 0; i < strlen(inputPassword); i++) {
            if (inputPassword[i] != storedPassword[i]) {
                isValid = 0;
                break;
            }
        }
    }

    if (isValid) {
        printf("Password is valid
");
    } else {
        printf("Password is invalid
");
    }

    return 0;
}