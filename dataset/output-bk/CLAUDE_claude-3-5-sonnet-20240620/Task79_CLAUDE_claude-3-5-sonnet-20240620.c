
#include <stdio.h>
#include <string.h>
#include <openssl/aes.h>
#include <openssl/bio.h>
#include <openssl/evp.h>
#include <openssl/buffer.h>

char* base64_encode(const unsigned char* input, int length) {
    BIO *bmem, *b64;
    BUF_MEM *bptr;

    b64 = BIO_new(BIO_f_base64());
    bmem = BIO_new(BIO_s_mem());
    b64 = BIO_push(b64, bmem);
    BIO_write(b64, input, length);
    BIO_flush(b64);
    BIO_get_mem_ptr(b64, &bptr);

    char* buff = (char*)malloc(bptr->length);
    memcpy(buff, bptr->data, bptr->length-1);
    buff[bptr->length-1] = 0;

    BIO_free_all(b64);

    return buff;
}

void encrypt(const char* message, const char* key) {
    unsigned char iv[AES_BLOCK_SIZE];
    memset(iv, 0x00, AES_BLOCK_SIZE);

    AES_KEY aes_key;
    AES_set_encrypt_key((const unsigned char*)key, 128, &aes_key);

    int message_len = strlen(message);
    int padded_len = (message_len + AES_BLOCK_SIZE) & ~(AES_BLOCK_SIZE - 1);
    unsigned char* padded_message = (unsigned char*)calloc(padded_len, sizeof(unsigned char));
    memcpy(padded_message, message, message_len);

    unsigned char* encrypted = (unsigned char*)malloc(padded_len);
    AES_cbc_encrypt(padded_message, encrypted, padded_len, &aes_key, iv, AES_ENCRYPT);

    char* base64_encrypted = base64_encode(encrypted, padded_len);
    printf("Encrypted message: %s\
", base64_encrypted);

    free(padded_message);
    free(encrypted);
    free(base64_encrypted);
}

int main() {
    const char* message = "Hello, World!";
    const char* key = "MySecretKey12345";

    encrypt(message, key);

    return 0;
}
