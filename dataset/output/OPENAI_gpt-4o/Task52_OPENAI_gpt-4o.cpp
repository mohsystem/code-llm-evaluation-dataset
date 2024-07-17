#include <iostream>
#include <fstream>
#include <vector>
#include <openssl/evp.h>
#include <openssl/aes.h>

void handleErrors() {
    std::cerr << "An error occurred!" << std::endl;
    exit(1);
}

void encrypt(const std::string &in_filename, const std::string &out_filename) {
    std::ifstream in_file(in_filename, std::ios::binary);
    std::ofstream out_file(out_filename, std::ios::binary);
    if (!in_file.is_open() || !out_file.is_open()) {
        std::cerr << "File open error!" << std::endl;
        exit(1);
    }

    unsigned char key[16] = "1234567890123456";
    unsigned char iv[16] = {0};

    EVP_CIPHER_CTX *ctx = EVP_CIPHER_CTX_new();
    if (!ctx) handleErrors();

    if (1 != EVP_EncryptInit_ex(ctx, EVP_aes_128_cbc(), NULL, key, iv))
        handleErrors();

    std::vector<unsigned char> in_buf(1024);
    std::vector<unsigned char> out_buf(1024 + EVP_MAX_BLOCK_LENGTH);
    int in_len, out_len;

    while (in_file.read(reinterpret_cast<char*>(in_buf.data()), in_buf.size())) {
        in_len = in_file.gcount();
        if (1 != EVP_EncryptUpdate(ctx, out_buf.data(), &out_len, in_buf.data(), in_len))
            handleErrors();
        out_file.write(reinterpret_cast<char*>(out_buf.data()), out_len);
    }

    if (1 != EVP_EncryptFinal_ex(ctx, out_buf.data(), &out_len))
        handleErrors();
    out_file.write(reinterpret_cast<char*>(out_buf.data()), out_len);

    EVP_CIPHER_CTX_free(ctx);
}

void decrypt(const std::string &in_filename, const std::string &out_filename) {
    std::ifstream in_file(in_filename, std::ios::binary);
    std::ofstream out_file(out_filename, std::ios::binary);
    if (!in_file.is_open() || !out_file.is_open()) {
        std::cerr << "File open error!" << std::endl;
        exit(1);
    }

    unsigned char key[16] = "1234567890123456";
    unsigned char iv[16] = {0};

    EVP_CIPHER_CTX *ctx = EVP_CIPHER_CTX_new();
    if (!ctx) handleErrors();

    if (1 != EVP_DecryptInit_ex(ctx, EVP_aes_128_cbc(), NULL, key, iv))
        handleErrors();

    std::vector<unsigned char> in_buf(1024);
    std::vector<unsigned char> out_buf(1024 + EVP_MAX_BLOCK_LENGTH);
    int in_len, out_len;

    while (in_file.read(reinterpret_cast<char*>(in_buf.data()), in_buf.size())) {
        in_len = in_file.gcount();
        if (1 != EVP_DecryptUpdate(ctx, out_buf.data(), &out_len, in_buf.data(), in_len))
            handleErrors();
        out_file.write(reinterpret_cast<char*>(out_buf.data()), out_len);
    }

    if (1 != EVP_DecryptFinal_ex(ctx, out_buf.data(), &out_len))
        handleErrors();
    out_file.write(reinterpret_cast<char*>(out_buf.data()), out_len);

    EVP_CIPHER_CTX_free(ctx);
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        std::cerr << "Usage: " << argv[0] << " <encrypt/decrypt> <inputFile> <outputFile>" << std::endl;
        return 1;
    }

    if (std::string(argv[1]) == "encrypt") {
        encrypt(argv[2], argv[3]);
    } else if (std::string(argv[1]) == "decrypt") {
        decrypt(argv[2], argv[3]);
    } else {
        std::cerr << "Invalid command." << std::endl;
    }

    return 0;
}