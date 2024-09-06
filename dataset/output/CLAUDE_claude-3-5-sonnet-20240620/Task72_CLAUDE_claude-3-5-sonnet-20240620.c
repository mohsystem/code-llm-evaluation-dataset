
#include <stdio.h>
#include <string.h>
#include <openssl/aes.h>
#include <openssl/rand.h>

void encrypt_data(const unsigned char *data, int data_len, const unsigned char *key, unsigned char *encrypted) {
    // Create a static initialization vector (IV)
    unsigned char iv[AES_BLOCK_SIZE];
    memset(iv, 0, AES_BLOCK_SIZE);

    // Initialize a cipher using AES in CBC mode with the static IV
    AES_KEY aes_key;
    AES_set_encrypt_key(key, 256, &aes_key);

    // Pad the input data to match the block size required by the cipher
    int padded_size = ((data_len + AES_BLOCK_SIZE - 1) / AES_BLOCK_SIZE) * AES_BLOCK_SIZE;
    unsigned char padded_data[padded_size];
    memcpy(padded_data, data, data_len);
    memset(padded_data + data_len, 0, padded_size - data_len);

    // Encrypt the padded data using the cipher
    AES_cbc_encrypt(padded_data, encrypted, padded_size, &aes_key, iv, AES_ENCRYPT);
}

int main() {
    unsigned char key[32];
    RAND_bytes(key, sizeof(key));

    const char *data = "This is a secret message.";
    int data_len = strlen(data);
    int padded_size = ((data_len + AES_BLOCK_SIZE - 1) / AES_BLOCK_SIZE) * AES_BLOCK_SIZE;
    unsigned char encrypted[padded_size];

    encrypt_data((unsigned char *)data, data_len, key, encrypted);

    for (int i = 0; i < padded_size; i++) {
        printf("%02x ", encrypted[i]);
    }
    printf("\\n");

    return 0;
}
