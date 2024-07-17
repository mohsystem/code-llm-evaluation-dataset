#include <stdio.h>
#include <string.h>

int main() {
    char username[100], password[100], confirmPassword[100];

    printf("Enter your username: ");
    scanf("%s", username);

    printf("Enter your password: ");
    scanf("%s", password);

    printf("Confirm your password: ");
    scanf("%s", confirmPassword);

    if (strcmp(password, confirmPassword) == 0) {
        FILE *file = fopen("users.txt", "a");
        if (file != NULL) {
            fprintf(file, "%s:%s
", username, password);
            fclose(file);
            printf("Signup successful!
");
        } else {
            printf("An error occurred while saving your information.
");
        }
    } else {
        printf("Passwords don't match. Please try again.
");
    }

    return 0;
}