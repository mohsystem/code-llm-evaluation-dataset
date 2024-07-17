#include <openssl/x509.h>
#include <openssl/err.h>
#include <openssl/pem.h>
#include <stdio.h>
#include <string.h>

int main() {
    const char* knownHash = "your_known_hash_here";
    const char* certificatePath = "path_to_your_certificate.cer";

    FILE* file = fopen(certificatePath, "r");
    if (!file) {
        fprintf(stderr, "Error opening file
");
        return 1;
    }

    X509* cert = PEM_read_X509(file, NULL, NULL, NULL);
    fclose(file);

    if (!cert) {
        fprintf(stderr, "Error reading certificate
");
        return 1;
    }

    unsigned char hash[SHA256_DIGEST_LENGTH];
    X509_digest(cert, EVP_sha256(), hash, NULL);

    char calculatedHash[SHA256_DIGEST_LENGTH * 2 + 1];
    for (int i = 0; i < SHA256_DIGEST_LENGTH; i++) {
        sprintf(calculatedHash + i * 2, "%02x", hash[i]);
    }

    if (strcmp(calculatedHash, knownHash) == 0) {
        printf("Certificate matches the known hash.
");
    } else {
        printf("Certificate does not match the known hash.
");
    }

    X509_free(cert);
    return 0;
}