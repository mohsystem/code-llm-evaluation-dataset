
#include <stdio.h>
#include <string.h>
#include <openssl/sha.h>

#define MAX_PASSWORD_LENGTH 100
#define MAX_SALT_LENGTH 50

void hash_password(const char* password, const char* salt, char* hashed_password) {
    char combined[MAX_PASSWORD_LENGTH + MAX_SALT_LENGTH];
    unsigned char hash[SHA256_DIGEST_LENGTH];
    SHA256_CTX sha256;

    snprintf(combined, sizeof(combined), "%s%s", password, salt);

    SHA256_Init(&sha256);
    SHA256_Update(&sha256, combined, strlen(combined));
    SHA256_Final(hash, &sha256);

    for (int i = 0; i < SHA256_DIGEST_LENGTH; i++) {
        sprintf(hashed_password + (i * 2), "%02x", hash[i]);
    }
    hashed_password[SHA256_DIGEST_LENGTH * 2] = 0;
}

int main() {
    const char* password = "myPassword123";
    const char* salt = "randomSalt";
    char hashed_password[SHA256_DIGEST_LENGTH * 2 + 1];

    hash_password(password, salt, hashed_password);
    printf("Hashed password: %s\
", hashed_password);

    return 0;
}
