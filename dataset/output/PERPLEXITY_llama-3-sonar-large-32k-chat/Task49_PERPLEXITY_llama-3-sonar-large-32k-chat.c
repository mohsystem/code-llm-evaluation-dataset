// Note: This code is not a real API endpoint, but a simple console-based program that stores user data in a file.
#include <stdio.h>
#include <string.h>

int main() {
    char name[256], email[256];
    printf("Enter name: ");
    fgets(name, 256, stdin);
    name[strcspn(name, "\n")] = 0; // remove newline character

    printf("Enter email: ");
    fgets(email, 256, stdin);
    email[strcspn(email, "\n")] = 0; // remove newline character

    FILE *file = fopen("users.txt", "a");
    fprintf(file, "%s,%s\n", name, email);
    fclose(file);

    printf("User created successfully!\n");
    return 0;
}