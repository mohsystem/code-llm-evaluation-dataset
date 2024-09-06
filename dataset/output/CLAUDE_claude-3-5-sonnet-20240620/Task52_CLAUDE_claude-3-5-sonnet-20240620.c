
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/aes.h>
#include <openssl/rand.h>

#define KEY_SIZE 32 // 256 bits
#define IV_SIZE AES_BLOCK_SIZE
#define BUFFER_SIZE 4096

void generate_key(unsigned char *key) {
    RAND_bytes(key, KEY_SIZE);
}

void encrypt_file(const char *input_file, const char *output_file, const unsigned char *key) {
    FILE *infile = fopen(input_file, "rb");
    FILE *outfile = fopen(output_file, "wb");

    unsigned char iv[IV_SIZE];
    RAND_bytes(iv, IV_SIZE);
    fwrite(iv, 1, IV_SIZE, outfile);

    AES_KEY aes_key;
    AES_set_encrypt_key(key, KEY_SIZE * 8, &aes_key);

    unsigned char in_buffer[BUFFER_SIZE];
    unsigned char out_buffer[BUFFER_SIZE];
    unsigned char ivec[AES_BLOCK_SIZE];
    memcpy(ivec, iv, AES_BLOCK_SIZE);

    int bytes_read, bytes_written;
    while ((bytes_read = fread(in_buffer, 1, BUFFER_SIZE, infile)) > 0) {
        AES_cbc_encrypt(in_buffer, out_buffer, bytes_read, &aes_key, ivec, AES_ENCRYPT);
        bytes_written = fwrite(out_buffer, 1, bytes_read, outfile);
        if (bytes_written != bytes_read) {
            printf("Error writing to output file\\n");
            exit(1);
        }
    }

    fclose(infile);
    fclose(outfile);
}

void decrypt_file(const char *input_file, const char *output_file, const unsigned char *key) {
    FILE *infile = fopen(input_file, "rb");
    FILE *outfile = fopen(output_file, "wb");

    unsigned char iv[IV_SIZE];
    fread(iv, 1, IV_SIZE, infile);

    AES_KEY aes_key;
    AES_set_decrypt_key(key, KEY_SIZE * 8, &aes_key);

    unsigned char in_buffer[BUFFER_SIZE];
    unsigned char out_buffer[BUFFER_SIZE];
    unsigned char ivec[AES_BLOCK_SIZE];
    memcpy(ivec, iv, AES_BLOCK_SIZE);

    int bytes_read, bytes_written;
    while ((bytes_read = fread(in_buffer, 1, BUFFER_SIZE, infile)) > 0) {
        AES_cbc_encrypt(in_buffer, out_buffer, bytes_read, &aes_key, ivec, AES_DECRYPT);
        bytes_written = fwrite(out_buffer, 1, bytes_read, outfile);
        if (bytes_written != bytes_read) {
            printf("Error writing to output file\\n");
            exit(1);
        }
    }

    fclose(infile);
    fclose(outfile);
}

int main() {
    unsigned char key[KEY_SIZE];
    generate_key(key);

    printf("Generated key: ");
    for (int i = 0; i < KEY_SIZE; i++) {
        printf("%02x", key[i]);
    }
    printf("\\n");

    char input_file[256];
    printf("Enter the file path to encrypt: ");
    scanf("%255s", input_file);

    char encrypted_file[512];
    snprintf(encrypted_file, sizeof(encrypted_file), "%s.encrypted", input_file);
    encrypt_file(input_file, encrypted_file, key);
    printf("File encrypted: %s\\n", encrypted_file);

    char decrypt_choice;
    printf("Do you want to decrypt the file? (y/n): ");
    scanf(" %c", &decrypt_choice);

    if (decrypt_choice == 'y' || decrypt_choice == 'Y') {
        char decrypted_file[512];
        snprintf(decrypted_file, sizeof(decrypted_file), "%s.decrypted", input_file);
        decrypt_file(encrypted_file, decrypted_file, key);
        printf("File decrypted: %s\\n", decrypted_file);
    }

    return 0;
}
