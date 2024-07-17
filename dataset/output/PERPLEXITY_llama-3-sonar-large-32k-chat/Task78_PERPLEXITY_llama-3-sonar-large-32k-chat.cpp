#include <openssl/rsa.h>
#include <openssl/pem.h>
#include <openssl/err.h>
#include <iostream>
#include <string>
#include <sstream>

int main() {
    RSA *rsa;
    BIGNUM *exponent = BN_new();
    BN_set_word(exponent, 65537);

    rsa = RSA_new();
    RSA_generate_key_ex(rsa, 2048, exponent, NULL);

    BIO *bio = BIO_new(BIO_s_mem());
    PEM_write_bio_RSAPrivateKey(bio, rsa, NULL, NULL, 0, NULL, NULL);

    char *p;
    int len = BIO_get_mem_data(bio, &p);
    std::string privateKeyOpenSSH(p, len);

    std::stringstream ss;
    ss << "-----BEGIN OPENSSH PRIVATE KEY-----
" << privateKeyOpenSSH << "
-----END OPENSSH PRIVATE KEY-----";
    std::cout << ss.str() << std::endl;

    RSA_free(rsa);
    BN_free(exponent);
    BIO_free(bio);

    return 0;
}