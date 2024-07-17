
#include <stdio.h>
#include <string.h>
#include <openssl/x509.h>
#include <openssl/pem.h>
#include <openssl/sha.h>

int main() {
    const char* cert_path = "path/to/certificate.crt";
    const char* known_hash = "known_hash_value";

    FILE* cert_file = fopen(cert_path, "rb");
    if (!cert_file) {
        fprintf(stderr, "Error opening certificate file\
");
        return 1;
    }

    X509* cert = PEM_read_X509(cert_file, NULL, NULL, NULL);
    fclose(cert_file);

    if (!cert) {
        fprintf(stderr, "Error reading certificate\
");
        return 1;
    }

    unsigned char md[SHA256_DIGEST_LENGTH];
    unsigned int md_len;
    X509_digest(cert, EVP_sha256(), md, &md_len);

    char calculated_hash[SHA256_DIGEST_LENGTH * 2 + 1];
    for (int i = 0; i < SHA256_DIGEST_LENGTH; i++) {
        sprintf(&calculated_hash[i * 2], "%02x", md[i]);
    }

    if (strcmp(calculated_hash, known_hash) == 0) {
        printf("Certificate hash matches the known hash.\
");
    } else {
        printf("Certificate hash does not match the known hash.\
");
    }

    X509_free(cert);
    return 0;
}
