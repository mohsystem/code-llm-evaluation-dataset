#include <openssl/ssl.h>
#include <openssl/err.h>
#include <openssl/x509.h>
#include <string.h>

int main() {
    SSL_CTX *ctx;
    SSL *ssl;
    X509 *cert;
    unsigned char hash[SHA256_DIGEST_LENGTH];
    char expected_hash[65]; // assuming 64 character hash + 1 for null terminator
    strcpy(expected_hash, "expected_hash_here");

    ctx = SSL_CTX_new(TLS_client_method());
    ssl = SSL_new(ctx);
    SSL_set_connect_state(ssl);
    SSL_set_fd(ssl, socket(AF_INET, SOCK_STREAM, 0));
    SSL_connect(ssl);

    cert = SSL_get_peer_certificate(ssl);
    X509_digest(cert, EVP_sha256(), hash, NULL);
    for (int i = 0; i < SHA256_DIGEST_LENGTH; i++) {
        printf("%02x", hash[i]);
    }
    printf("\n");

    if (strcmp(expected_hash, hash) == 0) {
        printf("Certificate matches the expected hash\n");
    } else {
        printf("Certificate does not match the expected hash\n");
    }

    X509_free(cert);
    SSL_free(ssl);
    SSL_CTX_free(ctx);
    return 0;
}