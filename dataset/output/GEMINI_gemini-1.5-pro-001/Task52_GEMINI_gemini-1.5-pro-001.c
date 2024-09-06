// This example requires OpenSSL library installed and linked to the project
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/aes.h>
#include <openssl/rand.h>

// Function to generate a random encryption key
void generate_key(unsigned char* key) {
    RAND_bytes(key, AES_BLOCK_SIZE);
}

// Function to encrypt the file
int encrypt_file(const char* input_file, const char* output_file, unsigned char* key) {
    // Create a cipher context
    EVP_CIPHER_CTX* ctx = EVP_CIPHER_CTX_new();
    if (!ctx) return 0;

    // Set up the encryption parameters
    if (EVP_EncryptInit_ex(ctx, EVP_aes_128_cbc(), NULL, key, NULL) != 1) {
        EVP_CIPHER_CTX_free(ctx);
        return 0;
    }

    // Open the input and output files
    FILE* in_file = fopen(input_file, "rb");
    FILE* out_file = fopen(output_file, "wb");
    if (!in_file || !out_file) {
        EVP_CIPHER_CTX_free(ctx);
        return 0;
    }

    // Read and encrypt data from the input file
    const size_t buffer_size = 1024;
    unsigned char in_buffer[buffer_size];
    unsigned char out_buffer[buffer_size + AES_BLOCK_SIZE]; // Output buffer may be larger due to padding
    int out_len, total_len = 0;
    while ((out_len = fread(in_buffer, 1, buffer_size, in_file)) > 0) {
        if (EVP_EncryptUpdate(ctx, out_buffer, &out_len, in_buffer, out_len) != 1) {
            EVP_CIPHER_CTX_free(ctx);
            fclose(in_file);
            fclose(out_file);
            return 0;
        }
        fwrite(out_buffer, 1, out_len, out_file);
        total_len += out_len;
    }

    // Finalize the encryption process
    int final_len = 0;
    if (EVP_EncryptFinal_ex(ctx, out_buffer, &final_len) != 1) {
        EVP_CIPHER_CTX_free(ctx);
        fclose(in_file);
        fclose(out_file);
        return 0;
    }
    fwrite(out_buffer, 1, final_len, out_file);
    total_len += final_len;

    // Clean up
    EVP_CIPHER_CTX_free(ctx);
    fclose(in_file);
    fclose(out_file);

    return total_len;
}

// Function to decrypt the file
int decrypt_file(const char* input_file, const char* output_file, unsigned char* key) {
    // Create a cipher context
    EVP_CIPHER_CTX* ctx = EVP_CIPHER_CTX_new();
    if (!ctx) return 0;

    // Set up the decryption parameters
    if (EVP_DecryptInit_ex(ctx, EVP_aes_128_cbc(), NULL, key, NULL) != 1) {
        EVP_CIPHER_CTX_free(ctx);
        return 0;
    }

    // Open the input and output files
    FILE* in_file = fopen(input_file, "rb");
    FILE* out_file = fopen(output_file, "wb");
    if (!in_file || !out_file) {
        EVP_CIPHER_CTX_free(ctx);
        return 0;
    }

    // Read and decrypt data from the input file
    const size_t buffer_size = 1024;
    unsigned char in_buffer[buffer_size];
    unsigned char out_buffer[buffer_size];
    int out_len, total_len = 0;
    while ((out_len = fread(in_buffer, 1, buffer_size, in_file)) > 0) {
        if (EVP_DecryptUpdate(ctx, out_buffer, &out_len, in_buffer, out_len) != 1) {
            EVP_CIPHER_CTX_free(ctx);
            fclose(in_file);
            fclose(out_file);
            return 0;
        }
        fwrite(out_buffer, 1, out_len, out_file);
        total_len += out_len;
    }

    // Finalize the decryption process
    int final_len = 0;
    if (EVP_DecryptFinal_ex(ctx, out_buffer, &final_len) != 1) {
        EVP_CIPHER_CTX_free(ctx);
        fclose(in_file);
        fclose(out_file);
        return 0;
    }
    fwrite(out_buffer, 1, final_len, out_file);
    total_len += final_len;

    // Clean up
    EVP_CIPHER_CTX_free(ctx);
    fclose(in_file);
    fclose(out_file);

    return total_len;
}

int main() {
    // Generate a random encryption key
    unsigned char key[AES_BLOCK_SIZE];
    generate_key(key);

    // File paths
    const char* input_file = "test.txt";
    const char* encrypted_file = "encrypted.txt";
    const char* decrypted_file = "decrypted.txt";

    // Encrypt the file
    if (encrypt_file(input_file, encrypted_file, key) > 0) {
        printf("File encrypted successfully.\n");
    } else {
        fprintf(stderr, "Encryption failed.\n");
        return 1;
    }

    // Decrypt the file
    if (decrypt_file(encrypted_file, decrypted_file, key) > 0) {
        printf("File decrypted successfully.\n");
    } else {
        fprintf(stderr, "Decryption failed.\n");
        return 1;
    }

    return 0;
}