#include <openssl/rsa.h>
#include <openssl/pem.h>
#include <openssl/bio.h>
#include <openssl/err.h>
#include <cstdio>

void generate_key() {
    int             ret = 0;
    RSA             *r = nullptr;
    BIGNUM          *bne = nullptr;
    BIO             *bp_private = nullptr;
    int             bits = 2048;
    unsigned long   e = RSA_F4;

    bne = BN_new();
    ret = BN_set_word(bne, e);
    if(ret != 1){
        printf("Error setting BIGNUM structure.
");
        return;
    }

    r = RSA_new();
    ret = RSA_generate_key_ex(r, bits, bne, nullptr);
    if(ret != 1){
        printf("Error generating RSA key.
");
        return;
    }

    bp_private = BIO_new_file("id_rsa_cpp.pem", "w+");
    PEM_write_bio_RSAPrivateKey(bp_private, r, nullptr, nullptr, 0, nullptr, nullptr);

    RSA_free(r);
    BIO_free_all(bp_private);
    BN_free(bne);
}

int main() {
    generate_key();
    return 0;
}