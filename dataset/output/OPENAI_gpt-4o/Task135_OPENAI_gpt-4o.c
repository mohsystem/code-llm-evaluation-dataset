#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/sha.h>

typedef struct {
    char token[SHA256_DIGEST_LENGTH*2 + 1];
} CSRFProtection;

void generateToken(CSRFProtection* csrf, const char* sessionId) {
    unsigned char randomValue[60];
    FILE* urandom = fopen("/dev/urandom", "rb");
    fread(randomValue, sizeof(randomValue), 1, urandom);
    fclose(urandom);

    unsigned char hash[SHA256_DIGEST_LENGTH];
    SHA256(randomValue, sizeof(randomValue), hash);

    for (int i = 0; i < SHA256_DIGEST_LENGTH; ++i) {
        sprintf(csrf->token + (i * 2), "%02x", hash[i]);
    }
    strcat(csrf->token, sessionId);
}

int validateToken(CSRFProtection* csrf, const char* token, const char* sessionId) {
    char expectedToken[sizeof(csrf->token)];
    strcpy(expectedToken, csrf->token);
    strcat(expectedToken, sessionId);
    return strcmp(expectedToken, token) == 0;
}

int main() {
    CSRFProtection csrf;
    const char* sessionId = "12345ABC";
    generateToken(&csrf, sessionId);
    printf("Token: %s\n", csrf.token);
    printf("Validation: %d\n", validateToken(&csrf, csrf.token, sessionId));
    return 0;
}