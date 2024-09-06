#include <iostream>
#include <string>
#include <openssl/aes.h>
#include <openssl/pem.h>
#include <openssl/err.h>

std::string encryptAESCBC(unsigned char* key, std::string plaintext) {
    AES_KEY aes_key;
    AES_set_encrypt_key(key, 128, &aes_key);
    unsigned char iv[AES_BLOCK_SIZE];
    for (int i = 0; i < AES_BLOCK_SIZE; i++) {
        iv[i] = 0;
    }
    int len = plaintext.length(), written = 0;
    unsigned char* encrypted = new unsigned char[len + AES_BLOCK_SIZE];
    AES_cbc_encrypt((unsigned char*)plaintext.c_str(), encrypted, len, &aes_key, iv, AES_ENCRYPT);
    std::string encrypted_str((char*)encrypted, len + AES_BLOCK_SIZE);
    delete[] encrypted;
    return encrypted_str;
}

int main() {
    unsigned char key[16];  // 16 byte key
    std::string plaintext = "Hello, World!";
    std::cout << encryptAESCBC(key, plaintext) << std::endl;
    return 0;
}