#include <stdio.h>
#include <string.h>
#include <openssl/evp.h>
#include <openssl/aes.h>

void handleErrors() {
    fprintf(stderr, "An error occurred!
");
    exit(1);
}

void encrypt(const char *in_filename, const char *out_filename) {
    FILE *in_file = fopen(in_filename, "rb");
    FILE *out_file = fopen(out_filename, "wb");
    if (!in_file || !out_file) {
        fprintf(stderr, "File open error!
");
        exit(1);
    }

    unsigned char key[16] = "1234567890123456";
    unsigned char iv[16] = {0};

    EVP_CIPHER_CTX *ctx = EVP_CIPHER_CTX_new();
    if (!ctx) handleErrors();

    if (1 != EVP_EncryptInit_ex(ctx, EVP_aes_128_cbc(), NULL, key, iv))
        handleErrors();

    unsigned char in_buf[1024];
    unsigned char out_buf[1024 + EVP_MAX_BLOCK_LENGTH];
    int in_len, out_len;

    while ((in_len = fread(in_buf, 1, 1024, in_file)) > 0) {
        if (1 != EVP_EncryptUpdate(ctx, out_buf, &out_len, in_buf, in_len))
            handleErrors();
        fwrite(out_buf, 1, out_len, out_file);
    }

    if (1 != EVP_EncryptFinal_ex(ctx, out_buf, &out_len))
        handleErrors();
    fwrite(out_buf, 1, out_len, out_file);

    EVP_CIPHER_CTX_free(ctx);
    fclose(in_file);
    fclose(out_file);
}

void decrypt(const char *in_filename, const char *out_filename) {
    FILE *in_file = fopen(in_filename, "rb");
    FILE *out_file = fopen(out_filename, "wb");
    if (!in_file || !out_file) {
        fprintf(stderr, "File open error!
");
        exit(1);
    }

    unsigned char key[16] = "1234567890123456";
    unsigned char iv[16] = {0};

    EVP_CIPHER_CTX *ctx = EVP_CIPHER_CTX_new();
    if (!ctx) handleErrors();

    if (1 != EVP_DecryptInit_ex(ctx, EVP_aes_128_cbc(), NULL, key, iv))
        handleErrors();

    unsigned char in_buf[1024];
    unsigned char out_buf[1024 + EVP_MAX_BLOCK_LENGTH];
    int in_len, out_len;

    while ((in_len = fread(in_buf, 1, 1024, in_file)) > 0) {
        if (1 != EVP_DecryptUpdate(ctx, out_buf, &out_len, in_buf, in_len))
            handleErrors();
        fwrite(out_buf, 1, out_len, out_file);
    }

    if (1 != EVP_DecryptFinal_ex(ctx, out_buf, &out_len))
        handleErrors();
    fwrite(out_buf, 1, out_len, out_file);

    EVP_CIPHER_CTX_free(ctx);
    fclose(in_file);
    fclose(out_file);
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <encrypt/decrypt> <inputFile> <outputFile>
", argv[0]);
        return 1;
    }

    if (strcmp(argv[1], "encrypt") == 0) {
        encrypt(argv[2], argv[3]);
    } else if (strcmp(argv[1], "decrypt") == 0) {
        decrypt(argv[2], argv[3]);
    } else {
        fprintf(stderr, "Invalid command.
");
    }

    return 0;
}