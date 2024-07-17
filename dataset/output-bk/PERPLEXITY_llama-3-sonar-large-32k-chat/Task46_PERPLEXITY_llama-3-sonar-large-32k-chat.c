#include <stdio.h>
#include <string.h>

#define MAX_USERS 100
#define MAX_EMAIL_LENGTH 100
#define MAX_NAME_LENGTH 100
#define MAX_PASSWORD_LENGTH 100

typedef struct {
    char email[MAX_EMAIL_LENGTH];
    char name[MAX_NAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
} User;

User database[MAX_USERS];
int userCount = 0;

void registerUser(char* name, char* email, char* password) {
    strcpy(database[userCount].email, email);
    strcpy(database[userCount].name, name);
    strcpy(database[userCount].password, password);
    userCount++;
}

int main() {
    char name[MAX_NAME_LENGTH];
    char email[MAX_EMAIL_LENGTH];
    char password[MAX_PASSWORD_LENGTH];

    printf("Welcome to the User Registration System!
");
    printf("Enter your name: ");
    fgets(name, MAX_NAME_LENGTH, stdin);
    name[strcspn(name, "
")] = 0; // remove newline character

    printf("Enter your email: ");
    fgets(email, MAX_EMAIL_LENGTH, stdin);
    email[strcspn(email, "
")] = 0; // remove newline character

    printf("Enter your password: ");
    fgets(password, MAX_PASSWORD_LENGTH, stdin);
    password[strcspn(password, "
")] = 0; // remove newline character

    registerUser(name, email, password);

    printf("User registered successfully!
");
    printf("User information stored in database:
");
    printf("Email: %s
", email);
    printf("Name: %s
", name);
    printf("Password: %s
", password);

    return 0;
}