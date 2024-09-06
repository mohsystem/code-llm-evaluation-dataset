#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool checkPassword(const char *inputPassword) {
    FILE *file = fopen("password.txt", "r");
    if (file == NULL) return false;

    char storedPassword[100];
    fgets(storedPassword, 100, file);
    fclose(file);

    size_t lenStored = strlen(storedPassword);
    size_t lenInput = strlen(inputPassword);

    if (storedPassword[lenStored - 1] == '\n') 
        storedPassword[lenStored - 1] = '\0';

    if (lenStored != lenInput + 1) return false;

    for (size_t i = 0; i < lenInput; ++i) {
        if (storedPassword[i] != inputPassword[i]) {
            return false;
        }
    }
    return true;
}

int main() {
    const char password[] = "correctpassword";
    FILE *file = fopen("password.txt", "w");
    fputs(password, file);
    fclose(file);

    char userInput[100];
    printf("Enter your password: ");
    scanf("%99s", userInput);

    if (checkPassword(userInput)) {
        printf("Password is correct\n");
    } else {
        printf("Password is incorrect\n");
    }

    return 0;
}