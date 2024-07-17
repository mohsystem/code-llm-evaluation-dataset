#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/sha.h>

int check_certificate_hash(const char* certificate_path, const char* expected_hash) {
  FILE *fp = fopen(certificate_path, "rb");
  if (fp == NULL) {
    fprintf(stderr, "Error opening certificate file: %s
", certificate_path);
    return 0;
  }

  unsigned char buffer[4096];
  size_t bytes_read;
  SHA256_CTX sha256_ctx;
  SHA256_Init(&sha256_ctx);

  while ((bytes_read = fread(buffer, 1, sizeof(buffer), fp)) > 0) {
    SHA256_Update(&sha256_ctx, buffer, bytes_read);
  }

  unsigned char calculated_hash[SHA256_DIGEST_LENGTH];
  SHA256_Final(calculated_hash, &sha256_ctx);

  fclose(fp);

  char calculated_hash_str[SHA256_DIGEST_LENGTH * 2 + 1];
  for (int i = 0; i < SHA256_DIGEST_LENGTH; i++) {
    sprintf(calculated_hash_str + (i * 2), "%02x", calculated_hash[i]);
  }

  return strcmp(calculated_hash_str, expected_hash) == 0;
}

int main() {
  char certificate_file[256];
  char expected_hash[65];

  printf("Enter the path to the SSL certificate file: ");
  scanf("%s", certificate_file);

  printf("Enter the expected SHA-256 hash: ");
  scanf("%s", expected_hash);

  if (check_certificate_hash(certificate_file, expected_hash)) {
    printf("Certificate hash matches!
");
  } else {
    printf("Certificate hash does not match.
");
  }

  return 0;
}