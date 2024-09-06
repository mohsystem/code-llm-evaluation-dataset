#include <stdio.h>
#include <openssl/rsa.h>
#include <openssl/pem.h>
#include <openssl/err.h>

int main() {
    int             ret = 0;
    RSA             *r = NULL;
    BIGNUM          *bne = NULL;
    BIO             *bp_private = NULL;
 
    int             bits = 2048;
    unsigned long   e = RSA_F4;
 
    /* 1. create RSA key */
    bne = BN_new();
    ret = BN_set_word(bne,e);
    if(ret != 1){
        printf("Error setting BIGNUM word\n");
        return -1;
    }
 
    r = RSA_new();
    ret = RSA_generate_key_ex(r, bits, bne, NULL);
    if(ret != 1){
        printf("Error generating RSA key\n");
        return -1;
    }

    /* 2. save the private key to pem format */
    bp_private = BIO_new(BIO_s_mem());
    ret = PEM_write_bio_RSAPrivateKey(bp_private, r, NULL, NULL, 0, NULL, NULL);
    if(ret != 1){
        printf("Error writing private key to BIO\n");
        return -1;
    }

    /* 3. read the pem format key */
    char* pem_key;
    long pem_key_len = BIO_get_mem_data(bp_private, &pem_key);
    fwrite(pem_key, 1, pem_key_len, stdout);

    /* Free resources */
    RSA_free(r);
    BN_free(bne);
    BIO_free_all(bp_private);

    return 0;
}