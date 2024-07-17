#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/evp.h>

#define ENCRYPTION_KEY "This is a secret key"

int main() {
    const char *plaintext = "This is a secret message";
    int plaintext_len = strlen(plaintext);

    // Generate a cipher context for encryption
    EVP_CIPHER_CTX *ctx = EVP_CIPHER_CTX_new();
    if (!ctx) {
        fprintf(stderr, "Error creating cipher context
");
        return 1;
    }

    // Set up the encryption parameters
    if (EVP_EncryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, (const unsigned char *)ENCRYPTION_KEY, NULL) != 1) {
        fprintf(stderr, "Error initializing encryption
");
        EVP_CIPHER_CTX_free(ctx);
        return 1;
    }

    // Allocate memory for ciphertext
    int ciphertext_len = plaintext_len + EVP_CIPHER_block_size(EVP_aes_256_cbc());
    unsigned char *ciphertext = (unsigned char *)malloc(ciphertext_len);
    if (!ciphertext) {
        fprintf(stderr, "Error allocating memory for ciphertext
");
        EVP_CIPHER_CTX_free(ctx);
        return 1;
    }

    // Encrypt the plaintext
    int len;
    if (EVP_EncryptUpdate(ctx, ciphertext, &len, (const unsigned char *)plaintext, plaintext_len) != 1) {
        fprintf(stderr, "Error encrypting data
");
        EVP_CIPHER_CTX_free(ctx);
        free(ciphertext);
        return 1;
    }
    ciphertext_len = len;

    // Finalize the encryption process
    if (EVP_EncryptFinal_ex(ctx, ciphertext + len, &len) != 1) {
        fprintf(stderr, "Error finalizing encryption
");
        EVP_CIPHER_CTX_free(ctx);
        free(ciphertext);
        return 1;
    }
    ciphertext_len += len;

    // Print the ciphertext (in hexadecimal format for demonstration)
    printf("Ciphertext: ");
    for (int i = 0; i < ciphertext_len; i++) {
        printf("%02x", ciphertext[i]);
    }
    printf("
");

    // Clean up
    EVP_CIPHER_CTX_free(ctx);
    free(ciphertext);

    return 0;
}