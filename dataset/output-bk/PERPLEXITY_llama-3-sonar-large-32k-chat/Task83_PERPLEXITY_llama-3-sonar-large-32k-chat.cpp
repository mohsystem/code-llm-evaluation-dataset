#include <openssl/aes.h>
#include <openssl/err.h>
#include <iostream>
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

    std::cout << "IV: ";
    for (int i = 0; i < BLOCK_SIZE; i++) {
        std::cout << std::hex << (int)iv[i];
    }
    std::cout << std::endl;

    std::cout << "Encrypted Key: ";
    for (int i = 0; i < KEY_SIZE; i++) {
        std::cout << std::hex << (int)encryptedKey[i];
    }
    std::cout << std::endl;

    return 0;
}