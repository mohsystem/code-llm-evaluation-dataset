#include <stdio.h>
#include <string.h>
#include <openssl/sha.h>

void compute_hash(const char* password, const char* salt, char* outputBuffer) {
    char combined[512];
    snprintf(combined, sizeof(combined), "%s%s", password, salt);

    unsigned char hash[SHA256_DIGEST_LENGTH];
    SHA256((unsigned char*)combined, strlen(combined), hash);

    for (int i = 0; i < SHA256_DIGEST_LENGTH; ++i) {
        sprintf(outputBuffer + (i * 2), "%02x", hash[i]);
    }
}

int main() {
    const char* password = "example_password";
    const char* salt = "random_salt";
    char outputBuffer[65];
    compute_hash(password, salt, outputBuffer);
    printf("C Hash: %s\n", outputBuffer);
    return 0;
}