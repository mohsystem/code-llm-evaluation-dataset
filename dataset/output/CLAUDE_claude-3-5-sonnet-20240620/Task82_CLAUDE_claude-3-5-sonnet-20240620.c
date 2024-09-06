
#include <stdio.h>
#include <string.h>
#include <openssl/sha.h>

void sha256_hash_string(unsigned char hash[SHA256_DIGEST_LENGTH], char outputBuffer[65]) {
    int i = 0;
    for(i = 0; i < SHA256_DIGEST_LENGTH; i++) {
        sprintf(outputBuffer + (i * 2), "%02x", hash[i]);
    }
    outputBuffer[64] = 0;
}

void sha256(const char *string, char outputBuffer[65]) {
    unsigned char hash[SHA256_DIGEST_LENGTH];
    SHA256_CTX sha256;
    SHA256_Init(&sha256);
    SHA256_Update(&sha256, string, strlen(string));
    SHA256_Final(hash, &sha256);
    sha256_hash_string(hash, outputBuffer);
}

void hashPassword(const char *password, const char *salt, char outputBuffer[65]) {
    char combined[256];
    snprintf(combined, sizeof(combined), "%s%s", password, salt);
    sha256(combined, outputBuffer);
}

int main() {
    const char *password = "mypassword123";
    const char *salt = "randomsalt";
    char hashedPassword[65];
    hashPassword(password, salt, hashedPassword);
    printf("Hashed password: %s\\n", hashedPassword);
    return 0;
}
