#include <stdio.h>
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
    RSA_generate_key_ex(rsa, 2048, exponent, NULL);
    BN_free(exponent);

    // Export the private key in OpenSSH format
    FILE* fp = fopen("id_rsa", "w");
    if (fp == NULL) {
        fprintf(stderr, "Error opening file for writing private key.
");
        return 1;
    }
    PEM_write_RSAPrivateKey(fp, rsa, NULL, NULL, 0, NULL, NULL);
    fclose(fp);

    // Clean up
    RSA_free(rsa);

    return 0;
}