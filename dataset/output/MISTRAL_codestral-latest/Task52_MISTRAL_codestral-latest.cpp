// C++
// This is a simple example using AES encryption algorithm.
// Please note that you need to add OpenSSL library to your project.
#include <openssl/aes.h>
#include <openssl/rand.h>
#include <iostream>
#include <fstream>

void encryptFile(const unsigned char* key, const std::string& inputFile, const std::string& outputFile) {
    AES_KEY enc_key;
    AES_set_encrypt_key(key, 128, &enc_key);

    std::ifstream in(inputFile, std::ios::binary);
    std::ofstream out(outputFile, std::ios::binary);

    unsigned char iv[AES_BLOCK_SIZE];
    RAND_bytes(iv, AES_BLOCK_SIZE);
    out.write(reinterpret_cast<char*>(iv), AES_BLOCK_SIZE);

    unsigned char in_buf[AES_BLOCK_SIZE], out_buf[AES_BLOCK_SIZE];
    while (in.read(reinterpret_cast<char*>(in_buf), AES_BLOCK_SIZE)) {
        AES_encrypt(in_buf, out_buf, &enc_key);
        out.write(reinterpret_cast<char*>(out_buf), AES_BLOCK_SIZE);
    }

    if (in.gcount() != 0) {
        memset(in_buf + in.gcount(), 0, AES_BLOCK_SIZE - in.gcount());
        AES_encrypt(in_buf, out_buf, &enc_key);
        out.write(reinterpret_cast<char*>(out_buf), AES_BLOCK_SIZE);
    }
}

void decryptFile(const unsigned char* key, const std::string& inputFile, const std::string& outputFile) {
    AES_KEY dec_key;
    AES_set_decrypt_key(key, 128, &dec_key);

    std::ifstream in(inputFile, std::ios::binary);
    std::ofstream out(outputFile, std::ios::binary);

    unsigned char iv[AES_BLOCK_SIZE];
    in.read(reinterpret_cast<char*>(iv), AES_BLOCK_SIZE);

    unsigned char in_buf[AES_BLOCK_SIZE], out_buf[AES_BLOCK_SIZE];
    while (in.read(reinterpret_cast<char*>(in_buf), AES_BLOCK_SIZE)) {
        AES_decrypt(in_buf, out_buf, &dec_key);
        out.write(reinterpret_cast<char*>(out_buf), AES_BLOCK_SIZE);
    }
}