#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/aes.h>
#include <openssl/rand.h>

void encrypt(const char *input, const unsigned char *key, const unsigned char *iv, unsigned char *output) {
    AES_KEY encryptKey;
    AES_set_encrypt_key(key, 128, &encryptKey);
    AES_cbc_encrypt((const unsigned char *)input, output, strlen(input), &encryptKey, (unsigned char *)iv, AES_ENCRYPT);
}

void runC() {
    char input[] = "This is a secret message.";
    unsigned char key[] = "1234567890123456";
    unsigned char iv[] = "abcdef1234567890";
    unsigned char output[AES_BLOCK_SIZE * ((sizeof(input) + AES_BLOCK_SIZE) / AES_BLOCK_SIZE)];

    encrypt(input, key, iv, output);
    printf("Encrypted (C): ");
    for (int i = 0; i < sizeof(output); i++)
        printf("%02x", output[i]);
    printf("
");
}