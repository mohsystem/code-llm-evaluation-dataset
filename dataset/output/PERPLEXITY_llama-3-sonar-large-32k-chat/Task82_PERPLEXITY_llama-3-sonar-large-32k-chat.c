#include <stdio.h>
#include <string.h>
#include <openssl/sha.h>

void computeHash(const char* password, const char* salt, char* output) {
    char combined[strlen(password) + strlen(salt) + 1];
    strcpy(combined, password);
    strcat(combined, salt);
    unsigned char hash[SHA256_DIGEST_LENGTH];
    SHA256((unsigned char*)combined, strlen(combined), hash);
    for (int i = 0; i < SHA256_DIGEST_LENGTH; i++) {
        sprintf(output + i * 2, "%02x", hash[i]);
    }
    output[SHA256_DIGEST_LENGTH * 2] = '\0';
}

int main() {
    char output[SHA256_DIGEST_LENGTH * 2 + 1];
    const char* password = "mysecretpassword";
    const char* salt = "mysalt";
    computeHash(password, salt, output);
    printf("%s\n", output);
    return 0;
}