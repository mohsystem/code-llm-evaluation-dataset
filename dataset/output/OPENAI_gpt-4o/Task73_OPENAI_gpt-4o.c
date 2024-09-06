#include <stdio.h>
#include <string.h>

const char* checkPassword(char* password) {
    char adminPassword[] = "admin123";
    if (strcmp(password, adminPassword) == 0) {
        return "Password is valid";
    } else {
        return "Password is invalid";
    }
}

int main() {
    char inputPassword[50];
    printf("Enter the admin password: ");
    gets(inputPassword);

    printf("%s\n", checkPassword(inputPassword));

    return 0;
}