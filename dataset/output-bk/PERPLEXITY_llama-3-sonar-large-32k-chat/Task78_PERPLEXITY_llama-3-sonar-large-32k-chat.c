#include <openssl/rsa.h>
#include <openssl/pem.h>
#include <openssl/err.h>
#include <stdio.h>
#include <string.h>

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
    char privateKeyOpenSSH[len + 1];
    strncpy(privateKeyOpenSSH, p, len);
    privateKeyOpenSSH[len] = '\0';

    printf("%s
", privateKeyOpenSSH);

    RSA_free(rsa);
    BN_free(exponent);
    BIO_free(bio);

    return 0;
}