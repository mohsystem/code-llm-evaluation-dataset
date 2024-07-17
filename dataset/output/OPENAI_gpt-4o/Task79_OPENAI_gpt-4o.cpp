#include <iostream>
#include <string>
#include <openssl/evp.h>
#include <openssl/aes.h>
#include <cstring> // for memset

int main() {
    // Secret key (randomly chosen for demonstration)
    unsigned char key[16] = "0123456789abcdef";

    // Message to encrypt
    std::string message = "Hello, World!";

    // Create cipher context
    EVP_CIPHER_CTX *ctx = EVP_CIPHER_CTX_new();
    EVP_EncryptInit_ex(ctx, EVP_aes_128_ecb(), NULL, key, NULL);

    // Encrypt message
    unsigned char encryptedMessage[128];
    int len;
    EVP_EncryptUpdate(ctx, encryptedMessage, &len, (unsigned char*)message.c_str(), message.length());
    
    int ciphertext_len = len;
    EVP_EncryptFinal_ex(ctx, encryptedMessage + len, &len);
    ciphertext_len += len;

    // Print encrypted message in hex format
    for (int i = 0; i < ciphertext_len; i++) {
        std::cout << std::hex << (int)encryptedMessage[i];
    }
    std::cout << std::endl;

    EVP_CIPHER_CTX_free(ctx);
    return 0;
}