#include <stdio.h>
#include <openssl/sha.h>
#include <string.h>

void getHash(const char *password, char outputBuffer[65]) {
    unsigned char hash[SHA256_DIGEST_LENGTH];
    SHA256_CTX sha256;
    SHA256_Init(&sha256);
    SHA256_Update(&sha256, password, strlen(password));
    SHA256_Final(hash, &sha256);
    for (int i = 0; i < SHA256_DIGEST_LENGTH; ++i) {
        sprintf(outputBuffer + (i * 2), "%02x", hash[i]);
    }
    outputBuffer[64] = 0;
}

int authenticate(const char *inputPassword, const char *storedPasswordHash) {
    char hash[65];
    getHash(inputPassword, hash);
    return strcmp(hash, storedPasswordHash) == 0;
}

int main() {
    char storedPasswordHash[65];
    getHash("securepassword", storedPasswordHash);
    char inputPassword[256];
    
    printf("Enter your password: ");
    fgets(inputPassword, sizeof(inputPassword), stdin);
    inputPassword[strcspn(inputPassword, "
")] = 0;
    
    if (authenticate(inputPassword, storedPasswordHash)) {
        printf("Authentication successful.
");
    } else {
        printf("Authentication failed.
");
    }
    
    return 0;
}