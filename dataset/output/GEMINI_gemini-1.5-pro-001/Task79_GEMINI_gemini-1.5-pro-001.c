#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/aes.h>

char* encryptMessage(const char* message, const char* key) {
    // Create a cipher for encryption
    AES_KEY aesKey;
    AES_set_encrypt_key((const unsigned char*)key, 128, &aesKey);

    // Calculate the size of the encrypted message
    size_t messageLen = strlen(message);
    size_t encryptedLen = messageLen + AES_BLOCK_SIZE;
    char* encryptedMessage = (char*)malloc(encryptedLen);

    // Encrypt the message
    unsigned char iv[AES_BLOCK_SIZE] = {0};
    AES_cbc_encrypt((const unsigned char*)message, (unsigned char*)encryptedMessage, messageLen, &aesKey, iv, AES_ENCRYPT);

    // Return the encrypted message
    return encryptedMessage;
}