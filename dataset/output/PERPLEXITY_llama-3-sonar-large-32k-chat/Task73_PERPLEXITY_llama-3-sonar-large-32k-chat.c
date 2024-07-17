#include <stdio.h>
#include <string.h>

int main() {
    char password[20];
    printf("Enter password:");
    scanf("%19s", password);
    if (strcmp(password, "admin123") == 0) {
        printf("Password is valid
");
    } else {
        printf("Password is not valid
");
    }
    return 0;
}