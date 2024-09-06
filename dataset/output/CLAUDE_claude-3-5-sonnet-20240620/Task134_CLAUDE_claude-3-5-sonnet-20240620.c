
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/aes.h>
#include <openssl/rand.h>

#define KEY_SIZE 32
#define KEY_FILE "secret.key"

void generate_key(unsigned char *key) {
    RAND_bytes(key, KEY_SIZE);
}

void save_key(const unsigned char *key, const char *filename) {
    FILE *file = fopen(filename, "wb");
    fwrite(key, 1, KEY_SIZE, file);
    fclose(file);
}

void load_key(unsigned char *key, const char *filename) {
    FILE *file = fopen(filename, "rb");
    fread(key, 1, KEY_SIZE, file);
    fclose(file);
}

void encrypt_message(const unsigned char *message, int message_len, const unsigned char *key, unsigned char *encrypted) {
    AES_KEY aes_key;
    AES_set_encrypt_key(key, KEY_SIZE * 8, &aes_key);
    
    int padded_len = ((message_len + AES_BLOCK_SIZE - 1) / AES_BLOCK_SIZE) * AES_BLOCK_SIZE;
    unsigned char padded_message[padded_len];
    memcpy(padded_message, message, message_len);
    memset(padded_message + message_len, 0, padded_len - message_len);

    for (int i = 0; i < padded_len; i += AES_BLOCK_SIZE) {
        AES_encrypt(padded_message + i, encrypted + i, &aes_key);
    }
}

void decrypt_message(const unsigned char *encrypted, int encrypted_len, const unsigned char *key, unsigned char *decrypted) {
    AES_KEY aes_key;
    AES_set_decrypt_key(key, KEY_SIZE * 8, &aes_key);

    for (int i = 0; i < encrypted_len; i += AES_BLOCK_SIZE) {
        AES_decrypt(encrypted + i, decrypted + i, &aes_key);
    }
}

int main() {
    unsigned char key[KEY_SIZE];
    FILE *key_file = fopen(KEY_FILE, "rb");

    if (key_file == NULL) {
        generate_key(key);
        save_key(key, KEY_FILE);
    } else {
        fclose(key_file);
        load_key(key, KEY_FILE);
    }

    const char *message = "Hello, World!";
    int message_len = strlen(message);
    int padded_len = ((message_len + AES_BLOCK_SIZE - 1) / AES_BLOCK_SIZE) * AES_BLOCK_SIZE;

    unsigned char encrypted[padded_len];
    unsigned char decrypted[padded_len];

    encrypt_message((unsigned char *)message, message_len, key, encrypted);
    decrypt_message(encrypted, padded_len, key, decrypted);

    printf("Original: %s\\n", message);
    printf("Encrypted: ");
    for (int i = 0; i < padded_len; i++) {
        printf("%02x", encrypted[i]);
    }
    printf("\\n");
    printf("Decrypted: %s\\n", decrypted);

    return 0;
}
