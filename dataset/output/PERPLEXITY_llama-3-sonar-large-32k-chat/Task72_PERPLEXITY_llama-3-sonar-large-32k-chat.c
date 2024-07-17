#include <openssl/aes.h>
#include <openssl/err.h>
#include <stdio.h>
#include <string.h>

#define KEY_SIZE 16
#define BLOCK_SIZE 16

int main() {
    unsigned char key[KEY_SIZE] = "Bar1234567890123456";
    unsigned char iv[BLOCK_SIZE] = {0};
    RAND_bytes(iv, BLOCK_SIZE);
    AES_KEY aes_key;
    AES_set_encrypt_key(key, KEY_SIZE * 8, &aes_key);
    unsigned char data[] = "Hello, World!";
    int data_len = strlen(data);
    int padded_len = ((data_len + BLOCK_SIZE - 1) / BLOCK_SIZE) * BLOCK_SIZE;
    unsigned char padded_data[padded_len];
    memset(padded_data, 0, padded_len);
    memcpy(padded_data, data, data_len);
    unsigned char encrypted_data[padded_len];
    AES_cbc_encrypt(padded_data, encrypted_data, padded_len, &aes_key, iv, AES_ENCRYPT);
    for (int i = 0; i < padded_len; i++) {
        printf("%02x", encrypted_data[i]);
    }
    printf("
");
    return 0;
}