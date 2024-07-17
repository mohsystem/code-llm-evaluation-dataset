#include <iostream>
#include <string.h>
#include <openssl/aes.h>
#include <openssl/rand.h>

void encrypt(const char *input, const unsigned char *key, const unsigned char *iv, unsigned char *output) {
    AES_KEY encryptKey;
    AES_set_encrypt_key(key, 128, &encryptKey);
    AES_cbc_encrypt((const unsigned char *)input, output, strlen(input), &encryptKey, (unsigned char *)iv, AES_ENCRYPT);
}

void runCpp() {
    std::string input = "This is a secret message.";
    unsigned char key[] = "1234567890123456";
    unsigned char iv[] = "abcdef1234567890";
    unsigned char output[AES_BLOCK_SIZE * ((input.size() + AES_BLOCK_SIZE) / AES_BLOCK_SIZE)];

    encrypt(input.c_str(), key, iv, output);
    std::cout << "Encrypted (C++): ";
    for (size_t i = 0; i < sizeof(output); i++)
        std::cout << std::hex << (int)output[i];
    std::cout << std::endl;
}