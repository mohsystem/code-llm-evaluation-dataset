#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/hmac.h>
#include <openssl/rand.h>

char* generate_csrf_token() {
    unsigned char key[32];
    RAND_bytes(key, sizeof(key));

    unsigned char* out = HMAC(EVP_sha256(), "SuperSecretKey", 13, key, sizeof(key), NULL, NULL);

    char* token = (char*)malloc(EVP_MAX_MD_SIZE * 2 + 1);
    for (int i = 0; i < EVP_MAX_MD_SIZE; i++) {
        sprintf(&token[i * 2], "%02x", out[i]);
    }

    return token;
}

int main() {
    char* csrf_token = generate_csrf_token();
    printf("Generated CSRF Token: %s
", csrf_token);
    free(csrf_token);
    // This is a mock-up example. Add HTTP handling using a library like libmicrohttpd for a full example.

    return 0;
}