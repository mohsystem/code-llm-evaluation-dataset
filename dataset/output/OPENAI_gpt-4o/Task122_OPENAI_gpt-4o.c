#include <stdio.h>
#include <string.h>

#define MAX_USERS 100

typedef struct {
    char username[50];
    char password[50];
} User;

User database[MAX_USERS];
int user_count = 0;

void signup(const char *username, const char *password) {
    if (user_count < MAX_USERS) {
        strcpy(database[user_count].username, username);
        strcpy(database[user_count].password, password);
        user_count++;
        printf("User signed up successfully\n");
    } else {
        printf("User database is full\n");
    }
}

int main() {
    char username[50];
    char password[50];

    printf("Enter username: ");
    scanf("%49s", username);
    printf("Enter password: ");
    scanf("%49s", password);
    signup(username, password);

    return 0;
}