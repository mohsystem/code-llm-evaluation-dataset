#include <stdio.h>
#include <string.h>
#include <openssl/sha.h>

void hash_password(const char* password, const char* salt, char* output) {
  // Concatenate salt and password
  char salted_password[256];
  snprintf(salted_password, sizeof(salted_password), "%s%s", salt, password);

  // Calculate SHA-256 hash
  unsigned char hash[SHA256_DIGEST_LENGTH];
  SHA256_CTX sha256;
  SHA256_Init(&sha256);
  SHA256_Update(&sha256, salted_password, strlen(salted_password));
  SHA256_Final(hash, &sha256);

  // Convert hash to hexadecimal string
  for (int i = 0; i < SHA256_DIGEST_LENGTH; i++) {
    sprintf(output + (i * 2), "%02x", hash[i]);
  }
}