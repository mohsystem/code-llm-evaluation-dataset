#include <openssl/x509.h>
#include <openssl/sha.h>
#include <openssl/bio.h>
#include <openssl/err.h>
#include <string.h>
#include <iostream>

bool cert_hash_matches(const char *cert_path, const char *known_hash) {
    X509 *cert = NULL;
    FILE *fp = fopen(cert_path, "rb");
    if (!fp) {
        perror("Unable to open certificate file");
        return false;
    }
    cert = d2i_X509_fp(fp, NULL);
    fclose(fp);
    if (!cert) {
        ERR_print_errors_fp(stderr);
        return false;
    }

    unsigned char md[SHA256_DIGEST_LENGTH];
    unsigned int md_len;
    if (!X509_digest(cert, EVP_sha256(), md, &md_len)) {
        ERR_print_errors_fp(stderr);
        X509_free(cert);
        return false;
    }
    X509_free(cert);

    std::string calculated_hash;
    char buf[3];
    for (int i = 0; i < SHA256_DIGEST_LENGTH; i++) {
        snprintf(buf, sizeof(buf), "%02x", (unsigned int)md[i]);
        calculated_hash += buf;
    }

    return calculated_hash == known_hash;
}

int main() {
    const char *cert_path = "path_to_certificate.crt";
    const char *known_hash = "known_hash";

    bool matches = cert_hash_matches(cert_path, known_hash);
    std::cout << "Certificate hash matches known hash: " << (matches ? "true" : "false") << std::endl;

    return 0;
}