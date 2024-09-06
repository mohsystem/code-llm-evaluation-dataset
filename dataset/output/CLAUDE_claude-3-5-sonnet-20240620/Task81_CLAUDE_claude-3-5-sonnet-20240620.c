
#include <stdio.h>
#include <string.h>
#include <openssl/ssl.h>
#include <openssl/err.h>
#include <openssl/sha.h>

#define MAX_HASH_LENGTH 65

int get_certificate_hash(const char* hostname, int port, char* hash_out) {
    SSL_CTX* ctx = SSL_CTX_new(TLS_client_method());
    if (!ctx) {
        fprintf(stderr, "Failed to create SSL context\\n");
        return -1;
    }

    SSL* ssl = SSL_new(ctx);
    if (!ssl) {
        fprintf(stderr, "Failed to create SSL object\\n");
        SSL_CTX_free(ctx);
        return -1;
    }

    SSL_set_tlsext_host_name(ssl, hostname);

    BIO* bio = BIO_new_ssl_connect(ctx);
    if (!bio) {
        fprintf(stderr, "Failed to create BIO object\\n");
        SSL_free(ssl);
        SSL_CTX_free(ctx);
        return -1;
    }

    char conn_str[256];
    snprintf(conn_str, sizeof(conn_str), "%s:%d", hostname, port);
    BIO_set_conn_hostname(bio, conn_str);

    if (BIO_do_connect(bio) <= 0) {
        fprintf(stderr, "Failed to connect\\n");
        BIO_free_all(bio);
        SSL_CTX_free(ctx);
        return -1;
    }

    if (BIO_do_handshake(bio) <= 0) {
        fprintf(stderr, "Failed to perform SSL handshake\\n");
        BIO_free_all(bio);
        SSL_CTX_free(ctx);
        return -1;
    }

    X509* cert = SSL_get_peer_certificate(ssl);
    if (!cert) {
        fprintf(stderr, "Failed to get peer certificate\\n");
        BIO_free_all(bio);
        SSL_CTX_free(ctx);
        return -1;
    }

    unsigned char md[SHA256_DIGEST_LENGTH];
    unsigned int md_len;
    X509_digest(cert, EVP_sha256(), md, &md_len);

    for (int i = 0; i < SHA256_DIGEST_LENGTH; i++) {
        sprintf(&hash_out[i * 2], "%02x", md[i]);
    }
    hash_out[SHA256_DIGEST_LENGTH * 2] = '\\0';

    X509_free(cert);
    BIO_free_all(bio);
    SSL_CTX_free(ctx);

    return 0;
}

void check_certificate_hash(const char* hostname, const char* known_hash) {
    char cert_hash[MAX_HASH_LENGTH];
    if (get_certificate_hash(hostname, 443, cert_hash) == 0) {
        if (strcmp(cert_hash, known_hash) == 0) {
            printf("Certificate hash for %s matches the known hash.\\n", hostname);
        } else {
            printf("Certificate hash for %s does not match the known hash.\\n", hostname);
            printf("Calculated hash: %s\\n", cert_hash);
            printf("Known hash:     %s\\n", known_hash);
        }
    } else {
        fprintf(stderr, "Error getting certificate hash\\n");
    }
}

int main() {
    const char* hostname = "www.example.com";
    const char* known_hash = "e3b0c44298fc1c149afbf4c8996fb92427ae41e4649b934ca495991b7852b855"; // Example hash
    check_certificate_hash(hostname, known_hash);
    return 0;
}
