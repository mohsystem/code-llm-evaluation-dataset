#include <iostream>
#include <fstream>
#include <openssl/rsa.h>
#include <openssl/pem.h>
#include <openssl/err.h>

int main() {
    // Initialize OpenSSL
    OpenSSL_add_all_algorithms_noconf();
    OpenSSL_add_all_ciphers();
    ERR_load_crypto_strings();

    // Generate a new RSA key pair
    RSA* rsa = RSA_new();
    BIGNUM* exponent = BN_new();
    BN_set_word(exponent, RSA_F4);
    RSA_generate_key_ex(rsa, 2048, exponent, nullptr);
    BN_free(exponent);

    // Export the private key in OpenSSH format
    FILE* fp = fopen("id_rsa", "w");
    if (fp == nullptr) {
        std::cerr << "Error opening file for writing private key." << std::endl;
        return 1;
    }
    PEM_write_RSAPrivateKey(fp, rsa, nullptr, nullptr, 0, nullptr, nullptr);
    fclose(fp);

    // Clean up
    RSA_free(rsa);

    return 0;
}