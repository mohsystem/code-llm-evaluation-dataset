#include <stdio.h>
#include <string.h>
#include <openssl/aes.h>
#include <openssl/evp.h>
#include <openssl/err.h>

#define BLOCK_SIZE 16

// Function to handle encryption errors
void handleErrors(void) {
  ERR_print_errors_fp(stderr);
  abort();
}

// Function to pad data to the block size
int pad_data(unsigned char *data, int data_len) {
  int padding_len = BLOCK_SIZE - (data_len % BLOCK_SIZE);
  if (padding_len == BLOCK_SIZE) {
    padding_len = 0;
  } else {
    memset(data + data_len, padding_len, padding_len);
    data_len += padding_len;
  }
  return data_len;
}

// Function to encrypt data using AES-CBC with a static IV
unsigned char *encrypt_data(unsigned char *plaintext, int plaintext_len,
                         unsigned char *key, unsigned char *iv,
                         int *ciphertext_len) {
  // Create and initialize cipher context
  EVP_CIPHER_CTX *ctx = EVP_CIPHER_CTX_new();
  if (!ctx) handleErrors();

  // Set cipher to AES-CBC
  if (EVP_EncryptInit_ex(ctx, EVP_aes_128_cbc(), NULL, key, iv) != 1)
    handleErrors();

  // Pad the plaintext
  plaintext_len = pad_data(plaintext, plaintext_len);

  // Allocate memory for ciphertext
  unsigned char *ciphertext = (unsigned char *)malloc(plaintext_len + BLOCK_SIZE);
  if (!ciphertext) handleErrors();

  int len;

  // Encrypt the plaintext
  if (EVP_EncryptUpdate(ctx, ciphertext, &len, plaintext, plaintext_len) != 1)
    handleErrors();
  *ciphertext_len = len;

  // Finalize encryption
  if (EVP_EncryptFinal_ex(ctx, ciphertext + len, &len) != 1)
    handleErrors();
  *ciphertext_len += len;

  // Clean up and return ciphertext
  EVP_CIPHER_CTX_free(ctx);
  return ciphertext;
}

int main() {
  // Static Initialization Vector (IV) - Must be 16 bytes
  unsigned char iv[] = "ThisIsMyStaticIV";

  // Encryption Key - Must be 16, 24, or 32 bytes
  unsigned char key[] = "ThisIsMySecretKey";

  // Data to be encrypted
  unsigned char plaintext[] = "This is some secret data.";
  int plaintext_len = strlen((char *)plaintext);

  // Encrypt the data
  int ciphertext_len;
  unsigned char *ciphertext = encrypt_data(plaintext, plaintext_len, key, iv, &ciphertext_len);

  // Print encrypted data in hexadecimal format
  printf("Encrypted Data (Hex): ");
  for (int i = 0; i < ciphertext_len; i++) {
    printf("%02x", ciphertext[i]);
  }
  printf("\n");

  // Free allocated memory
  free(ciphertext);

  return 0;
}