#include <openssl/aes.h>
#include <openssl/err.h>
#include <stdio.h>
#include <string.h>

#define KEY_SIZE 16
#define BLOCK_SIZE 16

int main() {
    unsigned char key[KEY_SIZE];
    unsigned char iv[BLOCK_SIZE];
    RAND_bytes(key, KEY_SIZE);
    RAND_bytes(iv, BLOCK_SIZE);

    AES_KEY aes_key;
    AES_set_encrypt_key(key, KEY_SIZE * 8, &aes_key);

    unsigned char encryptedKey[KEY_SIZE];
    AES_cbc_encrypt(key, encryptedKey, KEY_SIZE, &aes_key, iv, AES_ENCRYPT);

    printf("IV: ");
    for (int i = 0; i < BLOCK_SIZE; i++) {
        printf("%02x", iv[i]);
    }
    printf("
");

    printf("Encrypted Key: ");
    for (int i = 0; i < KEY_SIZE; i++) {
        printf("%02x", encryptedKey[i]);
    }
    printf("
");

    return 0;
}