#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/evp.h>
#include <openssl/rand.h>
#include <openssl/err.h>

#define KEY_SIZE 256 // 256 bits = 32 bytes
#define IV_SIZE 128  // 128 bits = 16 bytes
#define KEY_FILE "secret.key"
#define IV_FILE "iv.data"

// Function to generate a random key and IV
void generateKeyAndIV() {
    unsigned char key[KEY_SIZE / 8];
    unsigned char iv[IV_SIZE / 8];

    // Generate random key and IV
    if (!RAND_bytes(key, sizeof(key)) || !RAND_bytes(iv, sizeof(iv))) {
        fprintf(stderr, "Error generating key/IV: %s
", ERR_error_string(ERR_get_error(), NULL));
        return;
    }

    // Write key and IV to files
    FILE *keyFile = fopen(KEY_FILE, "wb");
    FILE *ivFile = fopen(IV_FILE, "wb");
    if (!keyFile || !ivFile) {
        fprintf(stderr, "Error opening key/IV file
");
        return;
    }
    fwrite(key, sizeof(key), 1, keyFile);
    fwrite(iv, sizeof(iv), 1, ivFile);
    fclose(keyFile);
    fclose(ivFile);
    printf("Key and IV generated and saved to files.
");
}

// Function to load key and IV from files
int loadKeyAndIV(unsigned char *key, unsigned char *iv) {
    FILE *keyFile = fopen(KEY_FILE, "rb");
    FILE *ivFile = fopen(IV_FILE, "rb");
    if (!keyFile || !ivFile) {
        fprintf(stderr, "Error opening key/IV file.
");
        return 0;
    }
    fread(key, KEY_SIZE / 8, 1, keyFile);
    fread(iv, IV_SIZE / 8, 1, ivFile);
    fclose(keyFile);
    fclose(ivFile);
    return 1;
}

// Function to encrypt a message
int encryptMessage(const unsigned char *plaintext, int plaintext_len,
                   const unsigned char *key, const unsigned char *iv,
                   unsigned char **ciphertext, int *ciphertext_len) {
    EVP_CIPHER_CTX *ctx = EVP_CIPHER_CTX_new();
    if (!ctx) {
        fprintf(stderr, "Error creating cipher context.
");
        return 0;
    }

    // Initialize encryption context
    if (EVP_EncryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, key, iv) != 1) {
        fprintf(stderr, "Error initializing encryption context.
");
        EVP_CIPHER_CTX_free(ctx);
        return 0;
    }

    // Allocate memory for ciphertext
    *ciphertext = (unsigned char *)malloc(plaintext_len + EVP_MAX_BLOCK_LENGTH);
    if (!*ciphertext) {
        fprintf(stderr, "Error allocating memory for ciphertext.
");
        EVP_CIPHER_CTX_free(ctx);
        return 0;
    }

    // Encrypt the plaintext
    int len;
    if (EVP_EncryptUpdate(ctx, *ciphertext, &len, plaintext, plaintext_len) != 1) {
        fprintf(stderr, "Error encrypting message.
");
        EVP_CIPHER_CTX_free(ctx);
        free(*ciphertext);
        return 0;
    }
    *ciphertext_len = len;

    if (EVP_EncryptFinal_ex(ctx, *ciphertext + len, &len) != 1) {
        fprintf(stderr, "Error finalizing encryption.
");
        EVP_CIPHER_CTX_free(ctx);
        free(*ciphertext);
        return 0;
    }
    *ciphertext_len += len;

    EVP_CIPHER_CTX_free(ctx);
    return 1;
}

// Function to decrypt a message
int decryptMessage(const unsigned char *ciphertext, int ciphertext_len,
                   const unsigned char *key, const unsigned char *iv,
                   unsigned char **plaintext, int *plaintext_len) {
    EVP_CIPHER_CTX *ctx = EVP_CIPHER_CTX_new();
    if (!ctx) {
        fprintf(stderr, "Error creating cipher context.
");
        return 0;
    }

    // Initialize decryption context
    if (EVP_DecryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, key, iv) != 1) {
        fprintf(stderr, "Error initializing decryption context.
");
        EVP_CIPHER_CTX_free(ctx);
        return 0;
    }

    // Allocate memory for plaintext
    *plaintext = (unsigned char *)malloc(ciphertext_len);
    if (!*plaintext) {
        fprintf(stderr, "Error allocating memory for plaintext.
");
        EVP_CIPHER_CTX_free(ctx);
        return 0;
    }

    // Decrypt the ciphertext
    int len;
    if (EVP_DecryptUpdate(ctx, *plaintext, &len, ciphertext, ciphertext_len) != 1) {
        fprintf(stderr, "Error decrypting message.
");
        EVP_CIPHER_CTX_free(ctx);
        free(*plaintext);
        return 0;
    }
    *plaintext_len = len;

    if (EVP_DecryptFinal_ex(ctx, *plaintext + len, &len) != 1) {
        fprintf(stderr, "Error finalizing decryption.
");
        EVP_CIPHER_CTX_free(ctx);
        free(*plaintext);
        return 0;
    }
    *plaintext_len += len;

    EVP_CIPHER_CTX_free(ctx);
    return 1;
}

int main() {
    int choice;
    unsigned char key[KEY_SIZE / 8];
    unsigned char iv[IV_SIZE / 8];
    unsigned char *plaintext = NULL;
    unsigned char *ciphertext = NULL;
    int plaintext_len, ciphertext_len;
    char input[1024];

    while (1) {
        printf("
Choose an option:
");
        printf("1. Generate a new key
");
        printf("2. Encrypt a message
");
        printf("3. Decrypt a message
");
        printf("4. Exit
");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                generateKeyAndIV();
                break;
            case 2:
                if (!loadKeyAndIV(key, iv)) {
                    break;
                }
                printf("Enter the message to encrypt: ");
                getchar(); // consume newline
                fgets(input, sizeof(input), stdin);
                input[strcspn(input, "
")] = 0; // remove newline
                plaintext_len = strlen(input);
                plaintext = (unsigned char *)input;
                if (encryptMessage(plaintext, plaintext_len, key, iv, &ciphertext, &ciphertext_len)) {
                    printf("Ciphertext (Hex): ");
                    for (int i = 0; i < ciphertext_len; i++) {
                        printf("%02x", ciphertext[i]);
                    }
                    printf("
");
                    free(ciphertext);
                }
                break;
            case 3:
                if (!loadKeyAndIV(key, iv)) {
                    break;
                }
                printf("Enter the ciphertext (Hex) to decrypt: ");
                getchar(); // consume newline
                fgets(input, sizeof(input), stdin);
                input[strcspn(input, "
")] = 0; // remove newline
                ciphertext_len = strlen(input) / 2; // 2 hex characters per byte
                ciphertext = (unsigned char *)malloc(ciphertext_len);
                if (!ciphertext) {
                    fprintf(stderr, "Error allocating memory for ciphertext.
");
                    break;
                }
                // Convert hex string to binary data
                for (int i = 0; i < ciphertext_len; i++) {
                    sscanf(input + 2 * i, "%02hhx", &ciphertext[i]);
                }
                if (decryptMessage(ciphertext, ciphertext_len, key, iv, &plaintext, &plaintext_len)) {
                    printf("Plaintext: %s
", plaintext);
                    free(plaintext);
                }
                free(ciphertext);
                break;
            case 4:
                printf("Exiting...
");
                return 0;
            default:
                printf("Invalid choice!
");
        }
    }
    return 0;
}