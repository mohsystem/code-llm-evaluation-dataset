#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/evp.h>
#include <openssl/rand.h>

#define ENCRYPTION_KEY_SIZE 32
#define IV_SIZE 16

int main() {
    // Generate a random encryption key
    unsigned char encryptionKey[ENCRYPTION_KEY_SIZE];
    RAND_bytes(encryptionKey, ENCRYPTION_KEY_SIZE);

    // Generate a random initialization vector (IV)
    unsigned char iv[IV_SIZE];
    RAND_bytes(iv, IV_SIZE);

    // Open the OpenSSL library
    OpenSSL_add_all_algorithms();

    // Create a cipher context for AES-256-CBC
    EVP_CIPHER_CTX *ctx = EVP_CIPHER_CTX_new();
    if (!ctx) {
        fprintf(stderr, "Error creating cipher context
");
        return 1;
    }

    // Initialize the cipher context for encryption
    if (!EVP_EncryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, encryptionKey, iv)) {
        fprintf(stderr, "Error initializing cipher context
");
        EVP_CIPHER_CTX_free(ctx);
        return 1;
    }

    // Encrypt the key
    int ciphertextLen = 0;
    int len;
    unsigned char ciphertext[ENCRYPTION_KEY_SIZE + EVP_MAX_BLOCK_SIZE];
    if (!EVP_EncryptUpdate(ctx, ciphertext, &len, encryptionKey, ENCRYPTION_KEY_SIZE)) {
        fprintf(stderr, "Error encrypting data
");
        EVP_CIPHER_CTX_free(ctx);
        return 1;
    }
    ciphertextLen += len;

    // Finalize the encryption
    if (!EVP_EncryptFinal_ex(ctx, ciphertext + ciphertextLen, &len)) {
        fprintf(stderr, "Error finalizing encryption
");
        EVP_CIPHER_CTX_free(ctx);
        return 1;
    }
    ciphertextLen += len;

    // Print the encrypted key and IV in Base64 encoding
    char *base64Ciphertext = (char *)malloc(ciphertextLen * 2 + 1);
    EVP_EncodeBlock((unsigned char *)base64Ciphertext, ciphertext, ciphertextLen);
    printf("Encrypted Key (Base64): %s
", base64Ciphertext);

    char *base64Iv = (char *)malloc(IV_SIZE * 2 + 1);
    EVP_EncodeBlock((unsigned char *)base64Iv, iv, IV_SIZE);
    printf("IV (Base64): %s
", base64Iv);

    // Clean up
    EVP_CIPHER_CTX_free(ctx);
    free(base64Ciphertext);
    free(base64Iv);

    return 0;
}