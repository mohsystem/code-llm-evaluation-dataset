// C RSA Encryption and Decryption
#include <stdio.h>
#include <openssl/rsa.h>
#include <openssl/pem.h>
#include <openssl/err.h>
#include <string.h>

int main() {
    int bits = 2048;
    unsigned long e = RSA_F4;
    RSA *rsa = RSA_generate_key(bits, e, NULL, NULL);

    BIO *pri = BIO_new(BIO_s_mem());
    BIO *pub = BIO_new(BIO_s_mem());

    PEM_write_bio_RSAPrivateKey(pri, rsa, NULL, NULL, 0, NULL, NULL);
    PEM_write_bio_RSAPublicKey(pub, rsa);

    size_t pri_len = BIO_pending(pri);
    size_t pub_len = BIO_pending(pub);

    char *pri_key = (char*)malloc(pri_len + 1);
    char *pub_key = (char*)malloc(pub_len + 1);

    BIO_read(pri, pri_key, pri_len);
    BIO_read(pub, pub_key, pub_len);

    pri_key[pri_len] = '\0';
    pub_key[pub_len] = '\0';

    printf("Public Key: \n%s\n", pub_key);
    printf("Private Key: \n%s\n", pri_key);

    char message[] = "This is a secret message";

    RSA *rsa_public = RSA_new();
    BIO *pubbio = BIO_new_mem_buf(pub_key, -1);
    PEM_read_bio_RSAPublicKey(pubbio, &rsa_public, NULL, NULL);

    char *encrypted = (char*)malloc(RSA_size(rsa_public));
    int encrypted_length = RSA_public_encrypt(strlen(message), (unsigned char*)message, (unsigned char*)encrypted, rsa_public, RSA_PKCS1_OAEP_PADDING);

    if(encrypted_length == -1) {
        char err[130];
        ERR_load_crypto_strings();
        ERR_error_string(ERR_get_error(), err);
        printf("Encryption Error: %s\n", err);
    } else {
        printf("Encrypted: %s\n", encrypted);
    }

    RSA *rsa_private = RSA_new();
    BIO *pribio = BIO_new_mem_buf(pri_key, -1);
    PEM_read_bio_RSAPrivateKey(pribio, &rsa_private, NULL, NULL);

    char *decrypted = (char*)malloc(encrypted_length);
    int decrypted_length = RSA_private_decrypt(encrypted_length, (unsigned char*)encrypted, (unsigned char*)decrypted, rsa_private, RSA_PKCS1_OAEP_PADDING);

    if(decrypted_length == -1) {
        char err[130];
        ERR_load_crypto_strings();
        ERR_error_string(ERR_get_error(), err);
        printf("Decryption Error: %s\n", err);
    } else {
        decrypted[decrypted_length] = '\0';
        printf("Decrypted: %s\n", decrypted);
    }

    RSA_free(rsa);
    RSA_free(rsa_public);
    RSA_free(rsa_private);
    BIO_free_all(pri);
    BIO_free_all(pub);
    BIO_free_all(pubbio);
    BIO_free_all(pribio);
    free(pri_key);
    free(pub_key);
    free(encrypted);
    free(decrypted);

    return 0;
}