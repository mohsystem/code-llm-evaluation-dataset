
#include <iostream>
#include <string>
#include <fstream>
#include <openssl/x509.h>
#include <openssl/pem.h>
#include <openssl/sha.h>

int main() {
    std::string cert_path = "path/to/certificate.crt";
    std::string known_hash = "known_hash_value";

    std::ifstream cert_file(cert_path, std::ios::binary);
    if (!cert_file) {
        std::cerr << "Error opening certificate file" << std::endl;
        return 1;
    }

    X509* cert = PEM_read_X509(cert_file, NULL, NULL, NULL);
    cert_file.close();

    if (!cert) {
        std::cerr << "Error reading certificate" << std::endl;
        return 1;
    }

    unsigned char md[SHA256_DIGEST_LENGTH];
    unsigned int md_len;
    X509_digest(cert, EVP_sha256(), md, &md_len);

    std::string calculated_hash;
    char hex[3];
    for (int i = 0; i < SHA256_DIGEST_LENGTH; i++) {
        sprintf(hex, "%02x", md[i]);
        calculated_hash += hex;
    }

    if (calculated_hash == known_hash) {
        std::cout << "Certificate hash matches the known hash." << std::endl;
    } else {
        std::cout << "Certificate hash does not match the known hash." << std::endl;
    }

    X509_free(cert);
    return 0;
}
