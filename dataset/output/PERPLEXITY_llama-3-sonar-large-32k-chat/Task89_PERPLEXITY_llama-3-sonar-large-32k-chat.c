#include <stdio.h>
#include <string.h>

int main() {
    FILE *file = fopen("password.txt", "r");
    char storedPassword[100];
    fgets(storedPassword, 100, file);
    storedPassword[strcspn(storedPassword, "\n")] = 0; // remove newline character
    fclose(file);
    char userPassword[100];
    printf("Enter your password: ");
    fgets(userPassword, 100, stdin);
    userPassword[strcspn(userPassword, "\n")] = 0; // remove newline character
    if (strlen(storedPassword) != strlen(userPassword)) {
        printf("Password does not match\n");
    } else {
        int match = 1;
        for (int i = 0; i < strlen(storedPassword); i++) {
            if (storedPassword[i] != userPassword[i]) {
                match = 0;
                break;
            }
        }
        if (match) {
            printf("Password matches\n");
        } else {
            printf("Password does not match\n");
        }
    }
    return 0;
}