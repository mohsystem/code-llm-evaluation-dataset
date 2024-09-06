// CPP
#include <openssl/evp.h>
#include <fstream>

EVP_PKEY* generateKey() {
    EVP_PKEY_CTX *ctx = EVP_PKEY_CTX_new_id(EVP_PKEY_RSA, NULL);
    EVP_PKEY *pkey = NULL;
    EVP_PKEY_keygen_init(ctx);
    EVP_PKEY_keygen(ctx, &pkey);
    EVP_PKEY_CTX_free(ctx);
    return pkey;
}

void saveKey(EVP_PKEY* pkey, const std::string& filename) {
    FILE* fp = fopen(filename.c_str(), "wb");
    PEM_write_PrivateKey(fp, pkey, NULL, NULL, 0, NULL, NULL);
    fclose(fp);
}

EVP_PKEY* loadKey(const std::string& filename) {
    FILE* fp = fopen(filename.c_str(), "rb");
    EVP_PKEY* pkey = PEM_read_PrivateKey(fp, NULL, NULL, NULL);
    fclose(fp);
    return pkey;
}