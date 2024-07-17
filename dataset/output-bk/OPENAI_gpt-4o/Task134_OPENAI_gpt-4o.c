#include <stdio.h>
#include <stdlib.h>
#include <openssl/rsa.h>
#include <openssl/pem.h>
#include <openssl/err.h>

void handleErrors(void) {
    ERR_print_errors_fp(stderr);
    abort();
}

void generateRSAKeys() {
    BIGNUM *bn = BN_new();
    if (!BN_set_word(bn, RSA_F4)) handleErrors();

    RSA *rsa = RSA_new();
    if (!RSA_generate_key_ex(rsa, 2048, bn, NULL)) handleErrors();

    FILE *pvtFile = fopen("rsa_private.pem", "wb");
    if (!PEM_write_RSAPrivateKey(pvtFile, rsa, NULL, NULL, 0, NULL, NULL)) handleErrors();
    fclose(pvtFile);

    FILE *pubFile = fopen("rsa_public.pem", "wb");
    if (!PEM_write_RSAPublicKey(pubFile, rsa)) handleErrors();
    fclose(pubFile);

    RSA_free(rsa);
    BN_free(bn);
}

int main() {
    generateRSAKeys();
    printf("Keys are generated and stored as rsa_private.pem and rsa_public.pem
");
    return 0;
}