#include <stdio.h>
#include <string.h>
#include <openssl/sha.h>

void sha256(const char *str, char outputBuffer[65]) {
    unsigned char hash[SHA256_DIGEST_LENGTH];
    SHA256_CTX sha256;
    SHA256_Init(&sha256);
    SHA256_Update(&sha256, str, strlen(str));
    SHA256_Final(hash, &sha256);
    for (int i = 0; i < SHA256_DIGEST_LENGTH; i++) {
        sprintf(outputBuffer + (i * 2), "%02x", hash[i]);
    }
    outputBuffer[64] = 0;
}

int main() {
    char password[] = "password";
    char salt[] = "12345";
    char combined[100];
    strcpy(combined, password);
    strcat(combined, salt);
    char hash[65];
    sha256(combined, hash);
    printf("%s
", hash);
    return 0;
}