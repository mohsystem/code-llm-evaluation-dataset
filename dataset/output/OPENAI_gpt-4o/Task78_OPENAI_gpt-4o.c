#include <openssl/rsa.h>
#include <openssl/pem.h>
#include <openssl/bio.h>
#include <openssl/err.h>
#include <stdio.h>

void generate_key() {
    int             ret = 0;
    RSA             *r = NULL;
    BIGNUM          *bne = NULL;
    BIO             *bp_private = NULL;
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
    ret = RSA_generate_key_ex(r, bits, bne, NULL);
    if(ret != 1){
        printf("Error generating RSA key.
");
        return;
    }

    bp_private = BIO_new_file("id_rsa_c.pem", "w+");
    PEM_write_bio_RSAPrivateKey(bp_private, r, NULL, NULL, 0, NULL, NULL);

    RSA_free(r);
    BIO_free_all(bp_private);
    BN_free(bne);
}

int main() {
    generate_key();
    return 0;
}