#include <stdio.h>
#include <string.h>
#include <openssl/evp.h>
#include <openssl/aes.h>
#include <openssl/rand.h>

void encrypt(const char *message, const char *secretKey, unsigned char *encryptedMessage) {
    unsigned char key[32], iv[32];
    EVP_CIPHER_CTX *ctx = EVP_CIPHER_CTX_new();

    RAND_bytes(key, sizeof(key));
    RAND_bytes(iv, sizeof(iv));

    EVP_EncryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, (unsigned char *)secretKey, iv);

    int len, encryptedMessageLen;

    EVP_EncryptUpdate(ctx, encryptedMessage, &len, (unsigned char *)message, strlen(message));
    encryptedMessageLen = len;

    EVP_EncryptFinal_ex(ctx, encryptedMessage + len, &len);
    encryptedMessageLen += len;

    EVP_CIPHER_CTX_free(ctx);
}

int main() {
    const char *message = "Secret Message";
    const char *secretKey = "thisisaverysecret";
    unsigned char encryptedMessage[128];

    encrypt(message, secretKey, encryptedMessage);
    printf("Encrypted: %s\n", encryptedMessage);

    return 0;
}