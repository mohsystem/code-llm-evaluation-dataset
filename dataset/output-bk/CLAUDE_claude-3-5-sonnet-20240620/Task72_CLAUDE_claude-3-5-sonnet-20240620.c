
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/aes.h>
#include <openssl/rand.h>

#define AES_BLOCK_SIZE 16

void pad_data(unsigned char *data, int len, int block_size) {
    int padding = block_size - (len % block_size);
    for (int i = 0; i < padding; i++) {
        data[len + i] = padding;
    }
}

int main() {
    unsigned char iv[AES_BLOCK_SIZE];
    RAND_bytes(iv, AES_BLOCK_SIZE);

    const char *key = "1234567890123456";
    const char *data = "Hello, World!";
    int data_len = strlen(data);
    int padded_len = ((data_len + AES_BLOCK_SIZE - 1) / AES_BLOCK_SIZE) * AES_BLOCK_SIZE;

    unsigned char *padded_data = malloc(padded_len);
    memcpy(padded_data, data, data_len);
    pad_data(padded_data, data_len, AES_BLOCK_SIZE);

    unsigned char *encrypted_data = malloc(padded_len);
    AES_KEY aes_key;
    AES_set_encrypt_key((const unsigned char *)key, 128, &aes_key);
    AES_cbc_encrypt(padded_data, encrypted_data, padded_len, &aes_key, iv, AES_ENCRYPT);

    printf("Encrypted: ");
    for (int i = 0; i < padded_len; i++) {
        printf("%02x", encrypted_data[i]);
    }
    printf("\
");

    free(padded_data);
    free(encrypted_data);
    return 0;
}
