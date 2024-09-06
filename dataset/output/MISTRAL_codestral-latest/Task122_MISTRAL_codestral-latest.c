// C
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct User {
    char username[50];
    char password[50];
};

struct User passwords[100]; // Assuming a maximum of 100 users
int userCount = 0;

void signup(char* username, char* password) {
    strcpy(passwords[userCount].username, username);
    strcpy(passwords[userCount].password, password);
    userCount++;
}

// Example usage
int main() {
    signup("user1", "password1");
    return 0;
}