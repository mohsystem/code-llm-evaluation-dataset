#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/evp.h>
#include <openssl/aes.h>

int main() {
    // Secret key (randomly chosen for demonstration)
    unsigned char key[16] = "0123456789abcdef";

    // Message to encrypt
    unsigned char *message = (unsigned char *)"Hello, World!";
    int message_len = strlen((char *)message);
    
    // Create cipher
    EVP_CIPHER_CTX *ctx = EVP_CIPHER_CTX_new();
    EVP_EncryptInit_ex(ctx, EVP_aes_128_ecb(), NULL, key, NULL);

    // Encrypt message
    unsigned char encryptedMessage[128];
    int len;
    EVP_EncryptUpdate(ctx, encryptedMessage, &len, message, message_len);
    
    int ciphertext_len = len;
    EVP_EncryptFinal_ex(ctx, encryptedMessage + len, &len);
    ciphertext_len += len;

    // Print encrypted message in base64
    for (int i = 0; i < ciphertext_len; i++) {
        printf("%02x", encryptedMessage[i]);
    }
    printf("
");

    EVP_CIPHER_CTX_free(ctx);
    return 0;
}