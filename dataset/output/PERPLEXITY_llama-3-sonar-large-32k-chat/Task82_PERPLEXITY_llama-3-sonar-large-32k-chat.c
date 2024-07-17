#include <stdio.h>
#include <string.h>
#include <openssl/sha.h>
#include <openssl/err.h>
#include <base64.h>

int main() {
    unsigned char hash[SHA256_DIGEST_LENGTH];
    char password[] = "mypassword";
    char salt[] = "mysalt";
    char combined[strlen(password) + strlen(salt) + 1];
    strcpy(combined, password);
    strcat(combined, salt);
    SHA256(combined, strlen(combined), hash);
    char base64[BASE64_ENCODE_LENGTH(SHA256_DIGEST_LENGTH) + 1];
    base64_encode(hash, SHA256_DIGEST_LENGTH, base64);
    printf("Hash: %s
", base64);
    return 0;
}