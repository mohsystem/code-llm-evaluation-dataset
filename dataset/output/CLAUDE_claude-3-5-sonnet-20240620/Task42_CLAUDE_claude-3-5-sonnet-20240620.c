
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <openssl/sha.h>
#include <openssl/rand.h>

#define MAX_USERS 100
#define SALT_LENGTH 32
#define HASH_LENGTH (SALT_LENGTH + SHA256_DIGEST_LENGTH)

struct User {
    char username[50];
    unsigned char password_hash[HASH_LENGTH];
};

struct User users[MAX_USERS];
int user_count = 0;

void hash_password(const char* password, const unsigned char* salt, unsigned char* result) {
    memcpy(result, salt, SALT_LENGTH);
    SHA256_CTX sha256;
    SHA256_Init(&sha256);
    SHA256_Update(&sha256, salt, SALT_LENGTH);
    SHA256_Update(&sha256, password, strlen(password));
    SHA256_Final(result + SALT_LENGTH, &sha256);
}

int verify_password(const unsigned char* stored_hash, const char* provided_password) {
    unsigned char computed_hash[HASH_LENGTH];
    hash_password(provided_password, stored_hash, computed_hash);
    return memcmp(stored_hash, computed_hash, HASH_LENGTH) == 0;
}

int register_user(const char* username, const char* password) {
    if (user_count >= MAX_USERS) {
        return 0;
    }
    for (int i = 0; i < user_count; i++) {
        if (strcmp(users[i].username, username) == 0) {
            return 0;
        }
    }
    strcpy(users[user_count].username, username);
    unsigned char salt[SALT_LENGTH];
    RAND_bytes(salt, SALT_LENGTH);
    hash_password(password, salt, users[user_count].password_hash);
    user_count++;
    return 1;
}

int login(const char* username, const char* password) {
    for (int i = 0; i < user_count; i++) {
        if (strcmp(users[i].username, username) == 0) {
            return verify_password(users[i].password_hash, password);
        }
    }
    return 0;
}

int main() {
    register_user("alice", "password123");
    printf("%d\\n", login("alice", "password123")); // 1 (true)
    printf("%d\\n", login("alice", "wrongpassword")); // 0 (false)
    return 0;
}
