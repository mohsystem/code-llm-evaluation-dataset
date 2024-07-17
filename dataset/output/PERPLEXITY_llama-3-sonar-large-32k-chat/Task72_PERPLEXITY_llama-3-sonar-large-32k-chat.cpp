#include <openssl/aes.h>
#include <openssl/err.h>
#include <iostream>
#include <string>
#include <cstring>

#define KEY_SIZE 16
#define BLOCK_SIZE 16

int main() {
    unsigned char key[KEY_SIZE] = "Bar4567890123456";
    unsigned char iv[BLOCK_SIZE] = {0};
    RAND_bytes(iv, BLOCK_SIZE);
    AES_KEY aes_key;
    AES_set_encrypt_key(key, KEY_SIZE * 8, &aes_key);
    std::string data = "Hello, World!";
    int data_len = data.length();
    int padded_len = ((data_len + BLOCK_SIZE - 1) / BLOCK_SIZE) * BLOCK_SIZE;
    unsigned char padded_data[padded_len];
    memset(padded_data, 0, padded_len);
    memcpy(padded_data, data.c_str(), data_len);
    unsigned char encrypted_data[padded_len];
    AES_cbc_encrypt(padded_data, encrypted_data, padded_len, &aes_key, iv, AES_ENCRYPT);
    for (int i = 0; i < padded_len; i++) {
        std::cout << std::hex << (int)encrypted_data[i];
    }
    std::cout << std::endl;
    return 0;
}