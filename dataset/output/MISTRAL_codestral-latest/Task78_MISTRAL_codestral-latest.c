// C
#include <openssl/pem.h>
#include <openssl/rsa.h>
#include <stdio.h>

int main() {
    RSA *rsa = RSA_new();
    BIGNUM *e = BN_new();
    BN_set_word(e, RSA_F4);
    RSA_generate_key_ex(rsa, 2048, e, NULL);

    PEM_write_RSAPrivateKey(stdout, rsa, NULL, NULL, 0, NULL, NULL);

    RSA_free(rsa);
    BN_free(e);
    return 0;
}