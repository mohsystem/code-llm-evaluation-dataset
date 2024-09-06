#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/aes.h>
#include <openssl/rand.h>
#include <openssl/evp.h>

void handleErrors(void) {
    ERR_print_errors_fp(stderr);
    abort();
}

void encrypt(unsigned char *plaintext, int plaintext_len, unsigned char *key,
             unsigned char *iv, unsigned char *ciphertext) {
    EVP_CIPHER_CTX *ctx = EVP_CIPHER_CTX_new();
    
    EVP_EncryptInit_ex(ctx, EVP_aes_128_cbc(), NULL, key, iv);

    int len;
    if (1 != EVP_EncryptUpdate(ctx, ciphertext, &len, plaintext, plaintext_len))
        handleErrors();
    int ciphertext_len = len;

    if (1 != EVP_EncryptFinal_ex(ctx, ciphertext + len, &len)) 
        handleErrors();
    ciphertext_len += len;

    EVP_CIPHER_CTX_free(ctx);
}

int main(void) {
    unsigned char key[16];
    RAND_bytes(key, sizeof(key));

    unsigned char iv[AES_BLOCK_SIZE];
    RAND_bytes(iv, sizeof(iv));

    unsigned char *plaintext = (unsigned char *)"exampleplaintext";
    unsigned char ciphertext[128];

    encrypt(plaintext, strlen((char *)plaintext), key, iv, ciphertext);

    printf("Encrypted Byte Array: ");
    for (int i = 0; i < sizeof(iv) + strlen((char *)ciphertext); i++) {
        printf("%x ", ciphertext[i]);
    }
    printf("\n");

    return 0;
}