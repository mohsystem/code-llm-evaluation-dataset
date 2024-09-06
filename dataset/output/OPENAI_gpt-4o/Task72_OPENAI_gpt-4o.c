#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/evp.h>
#include <openssl/aes.h>

void handleErrors() {
    ERR_print_errors_fp(stderr);
    abort();
}

void encrypt_data(const char *data, const char *key, unsigned char *encrypted_data, int *encrypted_data_len) {
    unsigned char iv[AES_BLOCK_SIZE] = {0};  // Static IV
    EVP_CIPHER_CTX *ctx = EVP_CIPHER_CTX_new();
    int outlen, finallen;

    if (!EVP_EncryptInit_ex(ctx, EVP_aes_128_cbc(), NULL, (unsigned char *)key, iv))
        handleErrors();

    if (!EVP_EncryptUpdate(ctx, encrypted_data, &outlen, (unsigned char *)data, strlen(data)))
        handleErrors();

    if (!EVP_EncryptFinal_ex(ctx, encrypted_data + outlen, &finallen))
        handleErrors();

    *encrypted_data_len = outlen + finallen;
    EVP_CIPHER_CTX_free(ctx);
}

int main() {
    const char *key = "sixteen byte key";
    const char *data = "Hello, World!";
    unsigned char encrypted_data[128];
    int encrypted_data_len;

    encrypt_data(data, key, encrypted_data, &encrypted_data_len);

    for(int i = 0; i < encrypted_data_len; i++)
        printf("%02x", encrypted_data[i]);
    printf("\n");

    return 0;
}