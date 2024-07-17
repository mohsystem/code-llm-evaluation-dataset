#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/aes.h>
#include <openssl/evp.h>

#define AES_BLOCK_SIZE 16

int main() {
    unsigned char key[AES_BLOCK_SIZE] = "YourSecretKeyHere"; // Replace with your actual secret key
    unsigned char iv[AES_BLOCK_SIZE] = { 0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0x0a, 0x0b, 0x0c, 0x0d, 0x0e, 0x0f };
    unsigned char plaintext[] = "This is some data to encrypt.";
    int plaintext_len = strlen((char *)plaintext);

    // Calculate padding length
    int padding_len = AES_BLOCK_SIZE - (plaintext_len % AES_BLOCK_SIZE);

    // Allocate memory for padded plaintext and ciphertext
    int ciphertext_len = plaintext_len + padding_len;
    unsigned char *padded_plaintext = (unsigned char *)malloc(ciphertext_len);
    unsigned char *ciphertext = (unsigned char *)malloc(ciphertext_len);

    // Apply padding
    memcpy(padded_plaintext, plaintext, plaintext_len);
    memset(padded_plaintext + plaintext_len, padding_len, padding_len);

    // Encrypt the data
    EVP_CIPHER_CTX *ctx;
    int len;
    int ciphertext_len_final = 0;

    if(!(ctx = EVP_CIPHER_CTX_new()))
        exit(1);

    if(1 != EVP_EncryptInit_ex(ctx, EVP_aes_128_cbc(), NULL, key, iv))
        exit(1);

    if(1 != EVP_EncryptUpdate(ctx, ciphertext, &len, padded_plaintext, ciphertext_len))
        exit(1);
    ciphertext_len_final = len;

    if(1 != EVP_EncryptFinal_ex(ctx, ciphertext + len, &len))
        exit(1);
    ciphertext_len_final += len;

    EVP_CIPHER_CTX_free(ctx);

    // Print ciphertext in Base64
    BIO *bio, *b64;
    BUF_MEM *bufferPtr;

    b64 = BIO_new(BIO_f_base64());
    bio = BIO_new(BIO_s_mem());
    bio = BIO_push(b64, bio);

    BIO_write(bio, ciphertext, ciphertext_len_final);
    BIO_flush(bio);
    BIO_get_mem_ptr(bio, &bufferPtr);

    char *base64_ciphertext = (char *)malloc(bufferPtr->length);
    memcpy(base64_ciphertext, bufferPtr->data, bufferPtr->length-1);
    base64_ciphertext[bufferPtr->length-1] = 0;

    printf("%s", base64_ciphertext);

    // Clean up
    BIO_free_all(bio);
    free(padded_plaintext);
    free(ciphertext);
    free(base64_ciphertext);

    return 0;
}