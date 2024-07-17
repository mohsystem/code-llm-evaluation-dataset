#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/rand.h>
#include <openssl/evp.h>

char *hash_password(const char *password, const char *salt, size_t salt_len) {
  const EVP_MD *sha256 = EVP_sha256();
  EVP_PKEY *key = NULL;
  EVP_MD_CTX *ctx = NULL;
  unsigned char hash[EVP_MAX_MD_SIZE];
  unsigned int hash_len = 0;
  char *hash_str = NULL;

  // Generate a random salt if none is provided
  if (salt == NULL) {
    salt_len = 16;
    salt = malloc(salt_len);
    if (salt == NULL) {
      fprintf(stderr, "Failed to allocate memory for salt
");
      return NULL;
    }
    RAND_bytes((unsigned char *)salt, salt_len);
  }

  // Create a key from the password and salt
  key = EVP_PKEY_new_raw_private_key(EVP_PKEY_HMAC, NULL, (const unsigned char *)password, strlen(password));
  if (key == NULL) {
    fprintf(stderr, "Failed to create key
");
    free((void *)salt);
    return NULL;
  }

  // Create a context for hashing
  ctx = EVP_MD_CTX_new();
  if (ctx == NULL) {
    fprintf(stderr, "Failed to create context
");
    EVP_PKEY_free(key);
    free((void *)salt);
    return NULL;
  }

  // Initialize the context for hashing with the key and salt
  if (EVP_DigestSignInit(ctx, NULL, sha256, NULL, key) != 1 ||
      EVP_DigestSignUpdate(ctx, (const unsigned char *)salt, salt_len) != 1 ||
      EVP_DigestSignFinal(ctx, hash, &hash_len) != 1) {
    fprintf(stderr, "Failed to hash password
");
    EVP_MD_CTX_free(ctx);
    EVP_PKEY_free(key);
    free((void *)salt);
    return NULL;
  }

  // Convert the hash to a hexadecimal string
  hash_str = malloc(hash_len * 2 + 1);
  if (hash_str == NULL) {
    fprintf(stderr, "Failed to allocate memory for hash string
");
    EVP_MD_CTX_free(ctx);
    EVP_PKEY_free(key);
    free((void *)salt);
    return NULL;
  }
  for (unsigned int i = 0; i < hash_len; i++) {
    sprintf(&hash_str[i * 2], "%02x", hash[i]);
  }

  // Clean up
  EVP_MD_CTX_free(ctx);
  EVP_PKEY_free(key);

  // Return the hashed password
  return hash_str;
}

int main() {
  char *password = "mysecretpassword";
  char *hashed_password = NULL;

  // Hash the password with a randomly generated salt
  hashed_password = hash_password(password, NULL, 0);
  if (hashed_password == NULL) {
    fprintf(stderr, "Failed to hash password
");
    return 1;
  }

  printf("Hashed password: %s
", hashed_password);

  free(hashed_password);

  return 0;
}