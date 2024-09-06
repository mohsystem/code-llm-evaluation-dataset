// C
// C does not have built-in support for cryptographic key management.
// You would typically use a library like OpenSSL for this.
// Here's an example using OpenSSL to generate and save a RSA key.

#include <openssl/rsa.h>
#include <openssl/pem.h>

RSA* generateKey() {
    RSA *rsa = RSA_new();
    BIGNUM *e = BN_new();
    BN_set_word(e, RSA_F4);
    RSA_generate_key_ex(rsa, 2048, e, NULL);
    BN_free(e);
    return rsa;
}

void saveKey(RSA* rsa, const char* filename) {
    FILE* fp = fopen(filename, "wb");
    PEM_write_RSAPrivateKey(fp, rsa, NULL, NULL, 0, NULL, NULL);
    fclose(fp);
}

RSA* loadKey(const char* filename) {
    FILE* fp = fopen(filename, "rb");
    RSA* rsa = PEM_read_RSAPrivateKey(fp, NULL, NULL, NULL);
    fclose(fp);
    return rsa;
}