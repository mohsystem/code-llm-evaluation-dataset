
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
    unsigned char hashed_password[SHA256_DIGEST_LENGTH];
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
    sha256(password, users[user_count].hashed_password);
    user_count++;
    return true;
}

bool login(const char *username, const char *password) {
    for (int i = 0; i < user_count; i++) {
        if (strcmp(users[i].username, username) == 0) {
            unsigned char hashed_password[SHA256_DIGEST_LENGTH];
            sha256(password, hashed_password);
            return memcmp(users[i].hashed_password, hashed_password, SHA256_DIGEST_LENGTH) == 0;
        }
    }
    return false;
}

int main() {
    char choice[2], username[MAX_USERNAME_LENGTH], password[MAX_PASSWORD_LENGTH];
    while (1) {
        printf("1. Register\
2. Login\
3. Exit\
Choose an option: ");
        fgets(choice, sizeof(choice), stdin);
        choice[strcspn(choice, "\
")] = 0;

        if (strcmp(choice, "1") == 0) {
            printf("Enter username: ");
            fgets(username, sizeof(username), stdin);
            username[strcspn(username, "\
")] = 0;
            printf("Enter password: ");
            fgets(password, sizeof(password), stdin);
            password[strcspn(password, "\
")] = 0;
            if (register_user(username, password)) {
                printf("Registration successful\
");
            } else {
                printf("Registration failed\
");
            }
        } else if (strcmp(choice, "2") == 0) {
            printf("Enter username: ");
            fgets(username, sizeof(username), stdin);
            username[strcspn(username, "\
")] = 0;
            printf("Enter password: ");
            fgets(password, sizeof(password), stdin);
            password[strcspn(password, "\
")] = 0;
            if (login(username, password)) {
                printf("Login successful\
");
            } else {
                printf("Invalid credentials\
");
            }
        } else if (strcmp(choice, "3") == 0) {
            break;
        } else {
            printf("Invalid choice\
");
        }
    }
    return 0;
}
