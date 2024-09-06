#include <iostream>
#include <string>
#include <vector>
#include <openssl/aes.h>
#include <openssl/rand.h>
#include <openssl/evp.h>

std::vector<unsigned char> encrypt(const std::vector<unsigned char>& key, const std::vector<unsigned char>& plaintext) {
    std::vector<unsigned char> ciphertext(plaintext.size() + AES_BLOCK_SIZE);
    unsigned char iv[AES_BLOCK_SIZE];
    RAND_bytes(iv, AES_BLOCK_SIZE);
    
    EVP_CIPHER_CTX *ctx = EVP_CIPHER_CTX_new();
    EVP_EncryptInit_ex(ctx, EVP_aes_128_cbc(), NULL, key.data(), iv);
    
    int len;
    EVP_EncryptUpdate(ctx, ciphertext.data(), &len, plaintext.data(), plaintext.size());
    int ciphertext_len = len;
    
    EVP_EncryptFinal_ex(ctx, ciphertext.data() + len, &len);
    ciphertext_len += len;

    EVP_CIPHER_CTX_free(ctx);
    
    ciphertext.resize(ciphertext_len);
    ciphertext.insert(ciphertext.begin(), iv, iv + AES_BLOCK_SIZE);
    
    return ciphertext;
}

int main() {
    std::vector<unsigned char> key(16);
    RAND_bytes(key.data(), key.size());

    std::string plaintext = "exampleplaintext";
    std::vector<unsigned char> encrypted = encrypt(key, std::vector<unsigned char>(plaintext.begin(), plaintext.end()));

    std::cout << "Encrypted Byte Array: ";
    for (unsigned char c : encrypted) {
        std::cout << std::to_string(c) << " ";
    }
    std::cout << std::endl;

    return 0;
}