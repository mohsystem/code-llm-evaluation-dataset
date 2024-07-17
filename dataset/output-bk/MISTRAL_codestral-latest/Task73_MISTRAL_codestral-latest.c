// C
#include <stdio.h>
#include <string.h>

int main() {
    char password[50];
    printf("Enter admin password: ");
    scanf("%s", password);

    if (strcmp(password, "admin123") == 0) {
        printf("Password is valid.
");
    } else {
        printf("Password is invalid.
");
    }

    return 0;
}