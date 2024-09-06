
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
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

void sha256(const char *string, unsigned char hash[SHA256_DIGEST_LENGTH]) {
    SHA256_CTX sha256;
    SHA256_Init(&sha256);
    SHA256_Update(&sha256, string, strlen(string));
    SHA256_Final(hash, &sha256);
}

bool register_user(const char *username, const char *password) {
    if (user_count >= MAX_USERS) {
        return false;
    }
    for (int i = 0; i < user_count; i++) {
        if (strcmp(users[i].username, username) == 0) {
            return false;
        }
    }
    strcpy(users[user_count].username, username);
    sha256(password, users[user_count].password_hash);
    user_count++;
    return true;
}

bool login(const char *username, const char *password) {
    for (int i = 0; i < user_count; i++) {
        if (strcmp(users[i].username, username) == 0) {
            unsigned char input_hash[SHA256_DIGEST_LENGTH];
            sha256(password, input_hash);
            return memcmp(users[i].password_hash, input_hash, SHA256_DIGEST_LENGTH) == 0;
        }
    }
    return false;
}

int main() {
    char username[MAX_USERNAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
    int choice;

    while (1) {
        printf("1. Register\\n2. Login\\n3. Exit\\nChoose an option: ");
        scanf("%d", &choice);
        getchar(); // Clear newline from buffer

        if (choice == 1) {
            printf("Enter username: ");
            fgets(username, MAX_USERNAME_LENGTH, stdin);
            username[strcspn(username, "\\n")] = 0; // Remove newline
            printf("Enter password: ");
            fgets(password, MAX_PASSWORD_LENGTH, stdin);
            password[strcspn(password, "\\n")] = 0; // Remove newline
            if (register_user(username, password)) {
                printf("Registration successful\\n");
            } else {
                printf("Registration failed\\n");
            }
        } else if (choice == 2) {
            printf("Enter username: ");
            fgets(username, MAX_USERNAME_LENGTH, stdin);
            username[strcspn(username, "\\n")] = 0; // Remove newline
            printf("Enter password: ");
            fgets(password, MAX_PASSWORD_LENGTH, stdin);
            password[strcspn(password, "\\n")] = 0; // Remove newline
            if (login(username, password)) {
                printf("Login successful\\n");
            } else {
                printf("Invalid credentials\\n");
            }
        } else if (choice == 3) {
            break;
        } else {
            printf("Invalid choice\\n");
        }
    }

    return 0;
}
