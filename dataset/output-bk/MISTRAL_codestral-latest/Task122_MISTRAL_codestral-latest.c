// C

#include <stdio.h>
#include <stdlib.h>

void signup() {
    char username[50], password[50];
    printf("Enter username: ");
    scanf("%s", username);
    printf("Enter password: ");
    scanf("%s", password);
    // In a real-world application, you would hash the password before storing it.
    // For simplicity, we're storing it as is.
    FILE *file = fopen("passwords.txt", "a");
    if (file == NULL) {
        printf("Error opening file!
");
        exit(1);
    }
    fprintf(file, "%s:%s
", username, password);
    fclose(file);
}

int main() {
    signup();
    return 0;
}