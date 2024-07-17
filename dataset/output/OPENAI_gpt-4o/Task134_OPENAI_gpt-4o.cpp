#include <iostream>
#include <fstream>
#include <openssl/rsa.h>
#include <openssl/pem.h>
#include <openssl/err.h>

void handleOpenSSLErrors(void) {
    ERR_print_errors_fp(stderr);
    abort();
}

void generateRSAKeys() {
    RSA* rsa = nullptr;
    BIGNUM* bn = nullptr;
    BIO* bio_private = nullptr;
    BIO* bio_public = nullptr;

    bn = BN_new();
    if (!BN_set_word(bn, RSA_F4)) handleOpenSSLErrors();

    rsa = RSA_new();
    if (!RSA_generate_key_ex(rsa, 2048, bn, nullptr)) handleOpenSSLErrors();

    bio_private = BIO_new_file("rsa_private.pem", "w+");
    PEM_write_bio_RSAPrivateKey(bio_private, rsa, NULL, NULL, 0, NULL, NULL);

    bio_public = BIO_new_file("rsa_public.pem", "w+");
    PEM_write_bio_RSAPublicKey(bio_public, rsa);

    BIO_free_all(bio_private);
    BIO_free_all(bio_public);
    RSA_free(rsa);
    BN_free(bn);
}

int main() {
    generateRSAKeys();
    std::cout << "Keys are generated and stored as rsa_private.pem and rsa_public.pem" << std::endl;
    return 0;
}