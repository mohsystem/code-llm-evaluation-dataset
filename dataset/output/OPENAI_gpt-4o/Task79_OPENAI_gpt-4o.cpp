#include <iostream>
#include <string>
#include <openssl/evp.h>
#include <openssl/aes.h>
#include <openssl/rand.h>
#include <openssl/err.h>

std::string encrypt(const std::string &message, const std::string &secretKey) {
    unsigned char key[32], iv[32];
    EVP_CIPHER_CTX *ctx = EVP_CIPHER_CTX_new();

    RAND_bytes(key, sizeof(key));
    RAND_bytes(iv, sizeof(iv));

    EVP_EncryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, (unsigned char *)secretKey.c_str(), iv);

    unsigned char ciphertext[128];
    int len, ciphertext_len;

    EVP_EncryptUpdate(ctx, ciphertext, &len, (unsigned char *)message.c_str(), message.length());
    ciphertext_len = len;

    EVP_EncryptFinal_ex(ctx, ciphertext + len, &len);
    ciphertext_len += len;

    EVP_CIPHER_CTX_free(ctx);
    return std::string((char *)ciphertext, ciphertext_len);
}

int main() {
    std::string message = "Secret Message";
    std::string secretKey = "thisisaverysecret";
    std::string encryptedMessage = encrypt(message, secretKey);
    std::cout << "Encrypted: " << encryptedMessage << std::endl;
    return 0;
}