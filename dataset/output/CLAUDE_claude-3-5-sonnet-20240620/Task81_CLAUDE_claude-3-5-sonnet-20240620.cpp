
#include <iostream>
#include <string>
#include <openssl/ssl.h>
#include <openssl/err.h>
#include <openssl/sha.h>

std::string get_certificate_hash(const std::string& hostname, int port = 443) {
    SSL_CTX* ctx = SSL_CTX_new(TLS_client_method());
    if (!ctx) {
        throw std::runtime_error("Failed to create SSL context");
    }

    SSL* ssl = SSL_new(ctx);
    if (!ssl) {
        SSL_CTX_free(ctx);
        throw std::runtime_error("Failed to create SSL object");
    }

    SSL_set_tlsext_host_name(ssl, hostname.c_str());

    BIO* bio = BIO_new_ssl_connect(ctx);
    if (!bio) {
        SSL_free(ssl);
        SSL_CTX_free(ctx);
        throw std::runtime_error("Failed to create BIO object");
    }

    BIO_set_conn_hostname(bio, (hostname + ":" + std::to_string(port)).c_str());

    if (BIO_do_connect(bio) <= 0) {
        BIO_free_all(bio);
        SSL_CTX_free(ctx);
        throw std::runtime_error("Failed to connect");
    }

    if (BIO_do_handshake(bio) <= 0) {
        BIO_free_all(bio);
        SSL_CTX_free(ctx);
        throw std::runtime_error("Failed to perform SSL handshake");
    }

    X509* cert = SSL_get_peer_certificate(ssl);
    if (!cert) {
        BIO_free_all(bio);
        SSL_CTX_free(ctx);
        throw std::runtime_error("Failed to get peer certificate");
    }

    unsigned char md[SHA256_DIGEST_LENGTH];
    unsigned int md_len;
    X509_digest(cert, EVP_sha256(), md, &md_len);

    char hash[SHA256_DIGEST_LENGTH * 2 + 1];
    for (int i = 0; i < SHA256_DIGEST_LENGTH; i++) {
        sprintf(&hash[i * 2], "%02x", md[i]);
    }

    X509_free(cert);
    BIO_free_all(bio);
    SSL_CTX_free(ctx);

    return std::string(hash);
}

void check_certificate_hash(const std::string& hostname, const std::string& known_hash) {
    try {
        std::string cert_hash = get_certificate_hash(hostname);
        if (cert_hash == known_hash) {
            std::cout << "Certificate hash for " << hostname << " matches the known hash." << std::endl;
        } else {
            std::cout << "Certificate hash for " << hostname << " does not match the known hash." << std::endl;
            std::cout << "Calculated hash: " << cert_hash << std::endl;
            std::cout << "Known hash:     " << known_hash << std::endl;
        }
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
}

int main() {
    std::string hostname = "www.example.com";
    std::string known_hash = "e3b0c44298fc1c149afbf4c8996fb92427ae41e4649b934ca495991b7852b855"; // Example hash
    check_certificate_hash(hostname, known_hash);
    return 0;
}
