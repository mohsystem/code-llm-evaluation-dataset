// C code
#include <stdio.h>
#include <string.h>

int main() {
    char username[20], password[20];
    printf("Enter username: ");
    fgets(username, 20, stdin);
    username[strcspn(username, "
")] = 0; // remove newline character
    printf("Enter password: ");
    fgets(password, 20, stdin);
    password[strcspn(password, "
")] = 0; // remove newline character

    if (strcmp(username, "admin") == 0 && strcmp(password, "password") == 0) {
        printf("Login successful!
");
    } else {
        printf("Invalid username or password
");
    }
    return 0;
}