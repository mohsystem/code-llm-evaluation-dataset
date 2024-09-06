#include <iostream>
#include <string>
#include <openssl/evp.h>
#include <openssl/aes.h>
#include <openssl/rand.h>
#include <cstring>

void handleErrors() {
    ERR_print_errors_fp(stderr);
    abort();
}

void encrypt_data(const std::string &data, const std::string &key, std::string &encrypted_data) {
    unsigned char iv[AES_BLOCK_SIZE] = {0};  // Static IV
    unsigned char outbuf[1024];
    int outlen, tmplen;
    EVP_CIPHER_CTX *ctx = EVP_CIPHER_CTX_new();

    if (!EVP_EncryptInit_ex(ctx, EVP_aes_128_cbc(), NULL, reinterpret_cast<const unsigned char*>(key.c_str()), iv))
        handleErrors();

    if (!EVP_EncryptUpdate(ctx, outbuf, &outlen, reinterpret_cast<const unsigned char*>(data.c_str()), data.length()))
        handleErrors();

    encrypted_data.assign(reinterpret_cast<const char*>(outbuf), outlen);

    if (!EVP_EncryptFinal_ex(ctx, outbuf + outlen, &tmplen))
        handleErrors();

    encrypted_data.append(reinterpret_cast<const char*>(outbuf), tmplen);

    EVP_CIPHER_CTX_free(ctx);
}

int main() {
    std::string key = "sixteen byte key";
    std::string data = "Hello, World!";
    std::string encrypted_data;

    encrypt_data(data, key, encrypted_data);

    std::cout << std::hex << encrypted_data << std::endl;
    return 0;
}