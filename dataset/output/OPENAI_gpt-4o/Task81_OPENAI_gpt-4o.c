#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/sha.h>
#include <openssl/x509.h>
#include <openssl/pem.h>

void get_cert_hash(const char *cert_path, char *output) {
    FILE *file = fopen(cert_path, "rb");
    if (!file) {
        fprintf(stderr, "Unable to open file\n");
        exit(EXIT_FAILURE);
    }

    X509 *cert = PEM_read_X509(file, NULL, NULL, NULL);
    fclose(file);

    if (!cert) {
        fprintf(stderr, "Unable to read certificate\n");
        exit(EXIT_FAILURE);
    }

    int len = i2d_X509(cert, NULL);
    unsigned char *der = malloc(len);
    unsigned char *p = der;
    i2d_X509(cert, &p);

    unsigned char hash[SHA256_DIGEST_LENGTH];
    SHA256(der, len, hash);

    for (int i = 0; i < SHA256_DIGEST_LENGTH; ++i) {
        sprintf(output + (i * 2), "%02x", hash[i]);
    }

    X509_free(cert);
    free(der);
}

int main() {
    const char *known_hash = "your_known_hash_here";
    const char *cert_path = "path_to_your_certificate.crt";
    char cert_hash[SHA256_DIGEST_LENGTH * 2 + 1];

    get_cert_hash(cert_path, cert_hash);

    if (strcmp(cert_hash, known_hash) == 0) {
        printf("Certificate matches the known hash.\n");
    } else {
        printf("Certificate does not match the known hash.\n");
    }

    return 0;
}