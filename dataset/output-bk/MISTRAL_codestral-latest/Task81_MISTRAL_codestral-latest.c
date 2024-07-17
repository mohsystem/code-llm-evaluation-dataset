#include <openssl/x509.h>
#include <openssl/sha.h>
#include <openssl/bio.h>
#include <openssl/err.h>
#include <string.h>

int cert_hash_matches(const char *cert_path, const char *known_hash) {
    X509 *cert = NULL;
    FILE *fp = fopen(cert_path, "rb");
    if (!fp) {
        perror("Unable to open certificate file");
        return 0;
    }
    cert = d2i_X509_fp(fp, NULL);
    fclose(fp);
    if (!cert) {
        ERR_print_errors_fp(stderr);
        return 0;
    }

    unsigned char md[SHA256_DIGEST_LENGTH];
    unsigned int md_len;
    if (!X509_digest(cert, EVP_sha256(), md, &md_len)) {
        ERR_print_errors_fp(stderr);
        X509_free(cert);
        return 0;
    }
    X509_free(cert);

    char calculated_hash[SHA256_DIGEST_LENGTH * 2 + 1];
    for (int i = 0; i < SHA256_DIGEST_LENGTH; i++) {
        sprintf(&calculated_hash[i * 2], "%02x", (unsigned int)md[i]);
    }

    return strcmp(calculated_hash, known_hash) == 0;
}

int main() {
    const char *cert_path = "path_to_certificate.crt";
    const char *known_hash = "known_hash";

    int matches = cert_hash_matches(cert_path, known_hash);
    printf("Certificate hash matches known hash: %s
", matches ? "true" : "false");

    return 0;
}