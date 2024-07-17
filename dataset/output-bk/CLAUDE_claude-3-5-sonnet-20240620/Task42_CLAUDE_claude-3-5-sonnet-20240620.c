
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/sha.h>

#define MAX_USERS 100
#define MAX_USERNAME_LENGTH 50
#define MAX_PASSWORD_LENGTH 50

struct User {
    char username[MAX_USERNAME_LENGTH];
    unsigned char password_hash[SHA256_DIGEST_LENGTH];
};

struct User users[MAX_USERS];
int user_count = 0;

void hash_password(const char* password, unsigned char* hash) {
    SHA256_CTX sha256;
    SHA256_Init(&sha256);
    SHA256_Update(&sha256, password, strlen(password));
    SHA256_Final(hash, &sha256);
}

void register_user() {
    if (user_count >= MAX_USERS) {
        printf("Maximum number of users reached.\
");
        return;
    }

    char username[MAX_USERNAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];

    printf("Enter username: ");
    scanf("%s", username);

    for (int i = 0; i < user_count; i++) {
        if (strcmp(users[i].username, username) == 0) {
            printf("Username already exists. Please choose another.\
");
            return;
        }
    }

    printf("Enter password: ");
    scanf("%s", password);

    strcpy(users[user_count].username, username);
    hash_password(password, users[user_count].password_hash);
    user_count++;

    printf("Registration successful.\
");
}

void login() {
    char username[MAX_USERNAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];

    printf("Enter username: ");
    scanf("%s", username);
    printf("Enter password: ");
    scanf("%s", password);

    for (int i = 0; i < user_count; i++) {
        if (strcmp(users[i].username, username) == 0) {
            unsigned char hash[SHA256_DIGEST_LENGTH];
            hash_password(password, hash);

            if (memcmp(hash, users[i].password_hash, SHA256_DIGEST_LENGTH) == 0) {
                printf("Login successful.\
");
                return;
            }
        }
    }

    printf("Invalid username or password.\
");
}

int main() {
    int choice;

    while (1) {
        printf("1. Register\
");
        printf("2. Login\
");
        printf("3. Exit\
");
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                register_user();
                break;
            case 2:
                login();
                break;
            case 3:
                printf("Goodbye!\
");
                exit(0);
            default:
                printf("Invalid option. Please try again.\
");
        }
    }

    return 0;
}
