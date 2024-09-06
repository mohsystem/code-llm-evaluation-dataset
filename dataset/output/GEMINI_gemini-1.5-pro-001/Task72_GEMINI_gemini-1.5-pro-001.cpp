#include <iostream>
#include <string>
#include <openssl/aes.h>
#include <openssl/evp.h>
#include <openssl/err.h>

using namespace std;

// Function to handle encryption errors
void handleErrors(void) {
  ERR_print_errors_fp(stderr);
  abort();
}

// Function to encrypt data using AES-CBC with a static IV
vector<unsigned char> encryptData(const unsigned char *plaintext, int plaintext_len,
                                   const unsigned char *key, const unsigned char *iv) {
  // Create and initialize cipher context
  EVP_CIPHER_CTX *ctx = EVP_CIPHER_CTX_new();
  if (!ctx) handleErrors();

  // Set cipher to AES-CBC
  if (EVP_EncryptInit_ex(ctx, EVP_aes_128_cbc(), NULL, key, iv) != 1)
    handleErrors();

  // Output buffer for encrypted data
  vector<unsigned char> ciphertext(plaintext_len + AES_BLOCK_SIZE);
  int len;

  // Encrypt the plaintext
  if (EVP_EncryptUpdate(ctx, ciphertext.data(), &len, plaintext, plaintext_len) != 1)
    handleErrors();
  int ciphertext_len = len;

  // Finalize encryption
  if (EVP_EncryptFinal_ex(ctx, ciphertext.data() + len, &len) != 1)
    handleErrors();
  ciphertext_len += len;

  // Resize ciphertext vector to actual size
  ciphertext.resize(ciphertext_len);

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
  string data = "This is some secret data.";
  cout << "Original Data: " << data << endl;

  // Convert data to unsigned char array
  unsigned char *plaintext = (unsigned char *)data.c_str();
  int plaintext_len = data.size();

  // Encrypt the data
  vector<unsigned char> ciphertext = encryptData(plaintext, plaintext_len, key, iv);

  // Print encrypted data in hexadecimal format
  cout << "Encrypted Data (Hex): ";
  for (unsigned char c : ciphertext) {
    cout << hex << (int)c;
  }
  cout << endl;

  return 0;
}