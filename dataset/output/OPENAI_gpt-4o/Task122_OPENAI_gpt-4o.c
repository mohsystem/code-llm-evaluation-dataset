#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_USERS 100
#define MAX_LEN 100

typedef struct {
    char username[MAX_LEN];
    char password[MAX_LEN];
} User;

User users[MAX_USERS];
int user_count = 0;

void signup(char* username, char* password) {
    strcpy(users[user_count].username, username);
    strcpy(users[user_count].password, password);
    user_count++;
    printf("Signup successful!
");
}

int main() {
    char username[MAX_LEN];
    char password[MAX_LEN];
    
    printf("Enter Username: ");
    scanf("%s", username);
    printf("Enter Password: ");
    scanf("%s", password);
    
    signup(username, password);
    
    return 0;
}