
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/aes.h>
#include <openssl/rand.h>
#include <openssl/bio.h>
#include <openssl/evp.h>
#include <openssl/buffer.h>

char* base64_encode(const unsigned char* input, int length) {
    BIO *bio, *b64;
    BUF_MEM *bufferPtr;

    b64 = BIO_new(BIO_f_base64());
    bio = BIO_new(BIO_s_mem());
    bio = BIO_push(b64, bio);

    BIO_set_flags(bio, BIO_FLAGS_BASE64_NO_NL);
    BIO_write(bio, input, length);
    BIO_flush(bio);
    BIO_get_mem_ptr(bio, &bufferPtr);
    BIO_set_close(bio, BIO_NOCLOSE);
    BIO_free_all(bio);

    char* result = (char*)malloc(bufferPtr->length + 1);
    memcpy(result, bufferPtr->data, bufferPtr->length);
    result[bufferPtr->length] = '\\0';

    return result;
}

char* encrypt_key(const char* key) {
    unsigned char iv[AES_BLOCK_SIZE];
    unsigned char aes_key[32];
    RAND_bytes(iv, AES_BLOCK_SIZE);
    RAND_bytes(aes_key, 32);

    AES_KEY aes;
    AES_set_encrypt_key(aes_key, 256, &aes);

    int key_len = strlen(key);
    int padded_len = ((key_len + AES_BLOCK_SIZE) / AES_BLOCK_SIZE) * AES_BLOCK_SIZE;
    unsigned char* padded_key = (unsigned char*)malloc(padded_len);
    memcpy(padded_key, key, key_len);
    int padding = padded_len - key_len;
    memset(padded_key + key_len, padding, padding);

    unsigned char* encrypted = (unsigned char*)malloc(AES_BLOCK_SIZE + padded_len);
    memcpy(encrypted, iv, AES_BLOCK_SIZE);

    unsigned char* out_ptr = encrypted + AES_BLOCK_SIZE;
    const unsigned char* in_ptr = padded_key;
    int remaining = padded_len;

    while (remaining > 0) {
        AES_cbc_encrypt(in_ptr, out_ptr, AES_BLOCK_SIZE, &aes, iv, AES_ENCRYPT);
        in_ptr += AES_BLOCK_SIZE;
        out_ptr += AES_BLOCK_SIZE;
        remaining -= AES_BLOCK_SIZE;
    }

    char* result = base64_encode(encrypted, AES_BLOCK_SIZE + padded_len);

    free(padded_key);
    free(encrypted);

    return result;
}

int main() {
    const char* key_to_encrypt = "MySecretKey123456";
    char* encrypted_key = encrypt_key(key_to_encrypt);
    printf("Encrypted key: %s\\n", encrypted_key);
    free(encrypted_key);
    return 0;
}
