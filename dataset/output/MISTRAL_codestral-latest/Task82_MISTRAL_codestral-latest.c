// C
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/sha.h>
#include <openssl/rand.h>

#define SALT_SIZE 16
#define ITERATIONS 10000

void hash_password(const char *password, const unsigned char *salt, char *hashed_password) {
    unsigned char hash[SHA256_DIGEST_LENGTH];
    SHA256_CTX sha256;
    int i;

    SHA256_Init(&sha256);
    SHA256_Update(&sha256, salt, SALT_SIZE);
    SHA256_Update(&sha256, password, strlen(password));
    SHA256_Final(hash, &sha256);

    for (i = 0; i < ITERATIONS; i++) {
        SHA256_Init(&sha256);
        SHA256_Update(&sha256, hash, SHA256_DIGEST_LENGTH);
        SHA256_Final(hash, &sha256);
    }

    for (i = 0; i < SHA256_DIGEST_LENGTH; i++) {
        sprintf(hashed_password + (i * 2), "%02x", hash[i]);
    }
}

int main() {
    const char *password = "your_password";
    unsigned char salt[SALT_SIZE];
    char hashed_password[SHA256_DIGEST_LENGTH * 2 + 1];

    RAND_bytes(salt, SALT_SIZE);
    hash_password(password, salt, hashed_password);

    printf("%s
", hashed_password);

    return 0;
}