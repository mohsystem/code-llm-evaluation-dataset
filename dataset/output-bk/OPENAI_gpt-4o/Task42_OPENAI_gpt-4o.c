#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <openssl/sha.h>

#define MAX_USERS 100
#define USERNAME_LEN 50
#define PASSWORD_LEN 256

typedef struct {
    char username[USERNAME_LEN];
    char password_hash[PASSWORD_LEN * 2 + 1];
} User;

User users[MAX_USERS];
int user_count = 0;

void hashPassword(const char *password, char *outputBuffer) {
    unsigned char hash[SHA256_DIGEST_LENGTH];
    SHA256_CTX sha256;
    SHA256_Init(&sha256);
    SHA256_Update(&sha256, password, strlen(password));
    SHA256_Final(hash, &sha256);

    for (int i = 0; i < SHA256_DIGEST_LENGTH; i++) {
        snprintf(outputBuffer + (i * 2), 3, "%02x", hash[i]);
    }
}

void registerUser() {
    if (user_count >= MAX_USERS) {
        printf("User limit reached.
");
        return;
    }

    char username[USERNAME_LEN];
    char password[PASSWORD_LEN];
    printf("Enter username: ");
    scanf("%s", username);
    printf("Enter password: ");
    scanf("%s", password);

    hashPassword(password, users[user_count].password_hash);
    strncpy(users[user_count].username, username, USERNAME_LEN);
    user_count++;

    printf("User registered successfully!
");
}

void loginUser() {
    char username[USERNAME_LEN];
    char password[PASSWORD_LEN];
    char hashedPassword[PASSWORD_LEN * 2 + 1];
    printf("Enter username: ");
    scanf("%s", username);
    printf("Enter password: ");
    scanf("%s", password);

    hashPassword(password, hashedPassword);

    for (int i = 0; i < user_count; i++) {
        if (strcmp(users[i].username, username) == 0 && strcmp(users[i].password_hash, hashedPassword) == 0) {
            printf("Login successful!
");
            return;
        }
    }
    printf("Invalid credentials.
");
}

int main() {
    int choice;

    while (1) {
        printf("1. Register
2. Login
3. Exit
");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                registerUser();
                break;
            case 2:
                loginUser();
                break;
            case 3:
                exit(0);
        }
    }

    return 0;
}