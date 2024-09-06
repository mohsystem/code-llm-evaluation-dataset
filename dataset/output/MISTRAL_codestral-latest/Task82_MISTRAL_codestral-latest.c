#include <stdio.h>
#include <string.h>
#include <openssl/evp.h>
#include <openssl/rand.h>

void hashPassword(const char* password, const char* salt, unsigned char* hash) {
    const int iterations = 100000;
    const int keyLength = 32;

    PKCS5_PBKDF2_HMAC(password, strlen(password),
                      (const unsigned char*)salt, strlen(salt),
                      iterations, EVP_sha256(), keyLength, hash);
}

int main() {
    const char* password = "my_password";
    const char* salt = "salt_";
    unsigned char hash[32];
    hashPassword(password, salt, hash);

    for (int i = 0; i < 32; i++) {
        printf("%02x", hash[i]);
    }
    printf("\n");

    return 0;
}