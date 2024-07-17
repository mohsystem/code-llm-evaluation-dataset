#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <openssl/sha.h>

#define MAX_USERS 100
#define MAX_USERNAME_LENGTH 50
#define MAX_PASSWORD_LENGTH 50

struct User {
    char username[MAX_USERNAME_LENGTH];
    char password_hash[SHA256_DIGEST_LENGTH * 2 + 1];
};

struct User users[MAX_USERS];
int num_users = 0;

void registerUser();
void loginUser();
void hashPassword(const char *password, char *hash);

int main() {
    int choice;
    while (1) {
        printf("1. Register
");
        printf("2. Login
");
        printf("3. Exit
");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // consume newline character

        switch (choice) {
            case 1:
                registerUser();
                break;
            case 2:
                loginUser();
                break;
            case 3:
                printf("Exiting...
");
                return 0;
            default:
                printf("Invalid choice!
");
        }
    }
}

void registerUser() {
    if (num_users >= MAX_USERS) {
        printf("Maximum number of users reached!
");
        return;
    }

    char username[MAX_USERNAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];

    printf("Enter username: ");
    fgets(username, MAX_USERNAME_LENGTH, stdin);
    username[strcspn(username, "
")] = 0; // remove trailing newline

    for (int i = 0; i < num_users; ++i) {
        if (strcmp(username, users[i].username) == 0) {
            printf("Username already exists!
");
            return;
        }
    }

    printf("Enter password: ");
    fgets(password, MAX_PASSWORD_LENGTH, stdin);
    password[strcspn(password, "
")] = 0;

    hashPassword(password, users[num_users].password_hash);
    strcpy(users[num_users].username, username);
    ++num_users;

    printf("User registered successfully!
");
}

void loginUser() {
    char username[MAX_USERNAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
    char password_hash[SHA256_DIGEST_LENGTH * 2 + 1];

    printf("Enter username: ");
    fgets(username, MAX_USERNAME_LENGTH, stdin);
    username[strcspn(username, "
")] = 0;

    printf("Enter password: ");
    fgets(password, MAX_PASSWORD_LENGTH, stdin);
    password[strcspn(password, "
")] = 0;

    hashPassword(password, password_hash);

    for (int i = 0; i < num_users; ++i) {
        if (strcmp(username, users[i].username) == 0 &&
            strcmp(password_hash, users[i].password_hash) == 0) {
            printf("Login successful!
");
            return;
        }
    }

    printf("Invalid username or password!
");
}

void hashPassword(const char *password, char *hash) {
    unsigned char hash_bytes[SHA256_DIGEST_LENGTH];
    SHA256_CTX sha256;
    SHA256_Init(&sha256);
    SHA256_Update(&sha256, password, strlen(password));
    SHA256_Final(hash_bytes, &sha256);

    for (int i = 0; i < SHA256_DIGEST_LENGTH; ++i) {
        sprintf(&hash[i * 2], "%02x", hash_bytes[i]);
    }
}