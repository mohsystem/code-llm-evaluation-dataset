#include <stdio.h>
#include <string.h>
#include <time.h>
#include <openssl/sha.h>

char* generateToken(const char* username, const char* password) {
    time_t timestamp = time(NULL);
    char tokenStr[256];
    sprintf(tokenStr, "%s%s%ld", username, password, timestamp);
    unsigned char hash[SHA256_DIGEST_LENGTH];
    SHA256((unsigned char*)tokenStr, strlen(tokenStr), hash);
    char tokenHash[SHA256_DIGEST_LENGTH * 2 + 1];
    for (int i = 0; i < SHA256_DIGEST_LENGTH; i++) {
        sprintf(tokenHash + i * 2, "%02x", hash[i]);
    }
    return strdup(tokenHash);
}

int main() {
    char* username = "john";
    char* password = "password123";
    char* token = generateToken(username, password);
    printf("Token: %s\n", token);
    free(token);
    return 0;
}