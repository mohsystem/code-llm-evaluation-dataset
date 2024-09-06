#include <stdio.h>
#include <string.h>
#include <openssl/sha.h>

#define MAX_USERS 100
#define USERNAME_SIZE 50
#define PASSWORD_HASH_SIZE 65

typedef struct {
    char username[USERNAME_SIZE];
    char password_hash[PASSWORD_HASH_SIZE];
} User;

User users[MAX_USERS];
int user_count = 0;

void hash_password(const char *password, char *output_buffer) {
    unsigned char hash[SHA256_DIGEST_LENGTH];
    SHA256_CTX sha256;
    SHA256_Init(&sha256);
    SHA256_Update(&sha256, password, strlen(password));
    SHA256_Final(hash, &sha256);
    for (int i = 0; i < SHA256_DIGEST_LENGTH; i++) {
        sprintf(output_buffer + (i * 2), "%02x", hash[i]);
    }
    output_buffer[64] = 0;
}

void add_user(char *username, char *password) {
    if (user_count < MAX_USERS) {
        strcpy(users[user_count].username, username);
        hash_password(password, users[user_count].password_hash);
        user_count++;
    } else {
        printf("User limit reached.\n");
    }
}

int authenticate(char *username, char *password) {
    char hashed_password[PASSWORD_HASH_SIZE];
    hash_password(password, hashed_password);
    for (int i = 0; i < user_count; i++) {
        if (strcmp(users[i].username, username) == 0 && strcmp(users[i].password_hash, hashed_password) == 0) {
            return 1;
        }
    }
    return 0;
}

int main() {
    add_user("user", "pass");
    printf("%d\n", authenticate("user", "pass"));
    printf("%d\n", authenticate("user", "wrongpass"));
    return 0;
}