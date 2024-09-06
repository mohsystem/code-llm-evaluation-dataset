#include <iostream>
#include <fstream>
#include <iomanip>
#include <openssl/sha.h>
#include <openssl/x509.h>
#include <openssl/pem.h>

std::string get_cert_hash(const std::string &cert_path) {
    std::ifstream file(cert_path, std::ios::binary);
    std::stringstream buffer;
    buffer << file.rdbuf();
    std::string cert_pem = buffer.str();

    BIO *bio = BIO_new_mem_buf(cert_pem.c_str(), cert_pem.size());
    X509 *cert = PEM_read_bio_X509(bio, NULL, 0, NULL);
    unsigned char *der = NULL;
    int len = i2d_X509(cert, &der);

    unsigned char hash[SHA256_DIGEST_LENGTH];
    SHA256(der, len, hash);

    std::ostringstream oss;
    for (int i = 0; i < SHA256_DIGEST_LENGTH; ++i)
        oss << std::hex << std::setw(2) << std::setfill('0') << (int)hash[i];

    X509_free(cert);
    BIO_free(bio);
    OPENSSL_free(der);

    return oss.str();
}

int main() {
    std::string known_hash = "your_known_hash_here";
    std::string cert_path = "path_to_your_certificate.crt";
    std::string cert_hash = get_cert_hash(cert_path);

    if (cert_hash == known_hash) {
        std::cout << "Certificate matches the known hash." << std::endl;
    } else {
        std::cout << "Certificate does not match the known hash." << std::endl;
    }
    return 0;
}