// C
// This is a simple example using AES encryption algorithm.
// Please note that you need to add OpenSSL library to your project.
#include <openssl/aes.h>
#include <openssl/rand.h>
#include <stdio.h>
#include <string.h>

void encryptFile(const unsigned char* key, const char* inputFile, const char* outputFile) {
    AES_KEY enc_key;
    AES_set_encrypt_key(key, 128, &enc_key);

    FILE* in = fopen(inputFile, "rb");
    FILE* out = fopen(outputFile, "wb");

    unsigned char iv[AES_BLOCK_SIZE];
    RAND_bytes(iv, AES_BLOCK_SIZE);
    fwrite(iv, 1, AES_BLOCK_SIZE, out);

    unsigned char in_buf[AES_BLOCK_SIZE], out_buf[AES_BLOCK_SIZE];
    size_t bytes_read;
    while ((bytes_read = fread(in_buf, 1, AES_BLOCK_SIZE, in)) == AES_BLOCK_SIZE) {
        AES_encrypt(in_buf, out_buf, &enc_key);
        fwrite(out_buf, 1, AES_BLOCK_SIZE, out);
    }

    if (bytes_read != 0) {
        memset(in_buf + bytes_read, 0, AES_BLOCK_SIZE - bytes_read);
        AES_encrypt(in_buf, out_buf, &enc_key);
        fwrite(out_buf, 1, AES_BLOCK_SIZE, out);
    }

    fclose(in);
    fclose(out);
}

void decryptFile(const unsigned char* key, const char* inputFile, const char* outputFile) {
    AES_KEY dec_key;
    AES_set_decrypt_key(key, 128, &dec_key);

    FILE* in = fopen(inputFile, "rb");
    FILE* out = fopen(outputFile, "wb");

    unsigned char iv[AES_BLOCK_SIZE];
    fread(iv, 1, AES_BLOCK_SIZE, in);

    unsigned char in_buf[AES_BLOCK_SIZE], out_buf[AES_BLOCK_SIZE];
    size_t bytes_read;
    while ((bytes_read = fread(in_buf, 1, AES_BLOCK_SIZE, in)) == AES_BLOCK_SIZE) {
        AES_decrypt(in_buf, out_buf, &dec_key);
        fwrite(out_buf, 1, AES_BLOCK_SIZE, out);
    }

    fclose(in);
    fclose(out);
}