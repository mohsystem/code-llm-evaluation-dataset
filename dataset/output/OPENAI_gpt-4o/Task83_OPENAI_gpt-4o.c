#include <openssl/evp.h>
#include <openssl/rand.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void base64_encode(const unsigned char *buffer, size_t length, char **b64text) {
    BIO *bio, *b64;
    BUF_MEM *bufferPtr;

    b64 = BIO_new(BIO_f_base64());
    bio = BIO_new(BIO_s_mem());
    bio = BIO_push(b64, bio);
    BIO_write(bio, buffer, length);
    BIO_flush(bio);
    BIO_get_mem_ptr(bio, &bufferPtr);
    BIO_set_close(bio, BIO_NOCLOSE);

    *b64text = (char *)malloc(bufferPtr->length);
    memcpy(*b64text, bufferPtr->data, bufferPtr->length - 1);
    (*b64text)[bufferPtr->length - 1] = 0;

    BIO_free_all(bio);
}

int main() {
    EVP_CIPHER_CTX *ctx = EVP_CIPHER_CTX_new();
    unsigned char key[32], iv[16], data[16], outbuf[32];
    int outlen;

    RAND_bytes(key, sizeof(key));
    RAND_bytes(data, sizeof(data));
    RAND_bytes(iv, sizeof(iv));

    EVP_EncryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, key, iv);
    EVP_EncryptUpdate(ctx, outbuf, &outlen, data, sizeof(data));
    int tmplen;
    EVP_EncryptFinal_ex(ctx, outbuf + outlen, &tmplen);
    outlen += tmplen;

    char *iv_base64, *enc_base64;
    base64_encode(iv, sizeof(iv), &iv_base64);
    base64_encode(outbuf, outlen, &enc_base64);

    printf("%s%s
", iv_base64, enc_base64);
    
    EVP_CIPHER_CTX_free(ctx);
    free(iv_base64);
    free(enc_base64);

    return 0;
}