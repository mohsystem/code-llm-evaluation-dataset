#include <stdio.h>
#include <string.h>
#include <openssl/md5.h>
#include <openssl/sha.h>

// Function to calculate the hash of a file
char* calculate_file_hash(const char* filename, const char* algorithm) {
    FILE *fp = fopen(filename, "rb");
    if (fp == NULL) {
        fprintf(stderr, "Error opening file: %s\n", filename);
        return NULL;
    }

    // Determine the hash algorithm to use
    const EVP_MD *md;
    if (strcmp(algorithm, "sha256") == 0) {
        md = EVP_sha256();
    } else if (strcmp(algorithm, "md5") == 0) {
        md = EVP_md5();
    } else {
        fprintf(stderr, "Unsupported hash algorithm: %s\n", algorithm);
        fclose(fp);
        return NULL;
    }

    EVP_MD_CTX *ctx = EVP_MD_CTX_new();
    EVP_DigestInit_ex(ctx, md, NULL);

    unsigned char buffer[1024];
    size_t bytes_read;
    while ((bytes_read = fread(buffer, 1, sizeof(buffer), fp)) > 0) {
        EVP_DigestUpdate(ctx, buffer, bytes_read);
    }

    unsigned char hash[EVP_MAX_MD_SIZE];
    unsigned int hash_len;
    EVP_DigestFinal_ex(ctx, hash, &hash_len);

    EVP_MD_CTX_free(ctx);
    fclose(fp);

    // Convert the binary hash to a hexadecimal string
    char *hash_string = (char*)malloc(hash_len * 2 + 1);
    for (unsigned int i = 0; i < hash_len; ++i) {
        sprintf(&hash_string[i * 2], "%02x", hash[i]);
    }
    hash_string[hash_len * 2] = '\0';

    return hash_string;
}

// Function to verify the hash of a file against a known hash
int verify_file_hash(const char* filename, const char* expected_hash, const char* algorithm) {
    char *calculated_hash = calculate_file_hash(filename, algorithm);
    if (calculated_hash == NULL) {
        return 0; // Error calculating hash
    }

    int result = strcmp(calculated_hash, expected_hash) == 0;

    free(calculated_hash);
    return result;
}

int main() {
    char filename[256];
    char expected_hash[64];
    char algorithm[16];

    printf("Enter the path to the SSL certificate: ");
    scanf("%s", filename);

    printf("Enter the expected hash value: ");
    scanf("%s", expected_hash);

    printf("Enter the hash algorithm used (e.g., sha256, md5): ");
    scanf("%s", algorithm);

    if (verify_file_hash(filename, expected_hash, algorithm)) {
        printf("Certificate hash matches!\n");
    } else {
        printf("Certificate hash does not match.\n");
    }

    return 0;
}