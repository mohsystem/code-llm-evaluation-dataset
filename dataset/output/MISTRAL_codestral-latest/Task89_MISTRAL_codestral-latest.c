// C code:

#include <stdio.h>
#include <string.h>

int comparePasswords(const char* filePath, const char* userPassword) {
    FILE* file = fopen(filePath, "r");
    char storedPassword[100];

    if (file != NULL) {
        if (fgets(storedPassword, sizeof(storedPassword), file) != NULL) {
            // Remove newline character from storedPassword
            storedPassword[strcspn(storedPassword, "\n")] = '\0';

            if (strcmp(userPassword, storedPassword) == 0) {
                fclose(file);
                return 1;
            } else {
                fclose(file);
                return 0;
            }
        } else {
            printf("Error reading the file.\n");
            fclose(file);
            return 0;
        }
    } else {
        printf("Error opening the file.\n");
        return 0;
    }
}

int main() {
    const char* filePath = "password.txt";
    char userPassword[100];

    printf("Enter your password: ");
    fgets(userPassword, sizeof(userPassword), stdin);

    // Remove newline character from userPassword
    userPassword[strcspn(userPassword, "\n")] = '\0';

    if (comparePasswords(filePath, userPassword)) {
        printf("Password is correct.\n");
    } else {
        printf("Password is incorrect.\n");
    }

    return 0;
}