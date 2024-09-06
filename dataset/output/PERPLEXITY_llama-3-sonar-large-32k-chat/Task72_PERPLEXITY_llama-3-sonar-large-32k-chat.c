#include <stdio.h>
#include <string.h>
#include <openssl/aes.h>
#include <openssl/err.h>

int main() {
    const char *plainText = "Hello, World!";
    unsigned char iv[AES_BLOCK_SIZE];  // static IV
    for (int i = 0; i < AES_BLOCK_SIZE; i++) {
        iv[i] = 0;
    }
    unsigned char key[] = "your_secret_key_here";
    AES_KEY aes_key;
    AES_set_encrypt_key(key, 128, &aes_key);
    int len = strlen(plainText), written = 0;
    int blockSize = AES_BLOCK_SIZE;
    int padding = blockSize - (len % blockSize);
    len += padding;
    unsigned char *encryptedData = malloc(len);
    for (int i = 0; i < padding; i++) {
        encryptedData[written++] = (unsigned char)padding;
    }
    AES_cbc_encrypt((unsigned char*)plainText, encryptedData, len, &aes_key, iv, AES_ENCRYPT);
    for (int i = 0; i < len; i++) {
        printf("%02x", encryptedData[i]);
    }
    free(encryptedData);
    return 0;
}