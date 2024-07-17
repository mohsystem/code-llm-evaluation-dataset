#include <openssl/x509.h>
#include <openssl/err.h>
#include <openssl/pem.h>
#include <iostream>
#include <string>
#include <iomanip>

int main() {
    const std::string knownHash = "your_known_hash_here";
    const std::string certificatePath = "path_to_your_certificate.cer";

    FILE* file = fopen(certificatePath.c_str(), "r");
    if (!file) {
        std::cerr << "Error opening file" << std::endl;
        return 1;
    }

    X509* cert = PEM_read_X509(file, NULL, NULL, NULL);
    fclose(file);

    if (!cert) {
        std::cerr << "Error reading certificate" << std::endl;
        return 1;
    }

    unsigned char hash[SHA256_DIGEST_LENGTH];
    X509_digest(cert, EVP_sha256(), hash, NULL);

    std::string calculatedHash;
    for (int i = 0; i < SHA256_DIGEST_LENGTH; i++) {
        calculatedHash += std::setw(2) << std::setfill('0') << std::hex << static_cast<int>(hash[i]);
    }

    if (calculatedHash == knownHash) {
        std::cout << "Certificate matches the known hash." << std::endl;
    } else {
        std::cout << "Certificate does not match the known hash." << std::endl;
    }

    X509_free(cert);
    return 0;
}