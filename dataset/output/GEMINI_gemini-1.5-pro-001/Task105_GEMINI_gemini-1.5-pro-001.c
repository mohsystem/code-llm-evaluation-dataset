#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/ssl.h>
#include <openssl/err.h>

int main() {
    OpenSSL_add_all_algorithms();
    SSL_load_error_strings();

    SSL_CTX *ctx = SSL_CTX_new(TLS_client_method());
    if (!ctx) {
        fprintf(stderr, "Error creating SSL context\n");
        return 1;
    }

    SSL *ssl = SSL_new(ctx);
    BIO *bio = BIO_new_ssl_connect(ctx);
    BIO_set_conn_hostname(bio, "www.google.com:443");
    SSL_set_bio(ssl, bio, bio);

    if (SSL_connect(ssl) <= 0) {
        fprintf(stderr, "Error establishing SSL connection\n");
        ERR_print_errors_fp(stderr);
        SSL_free(ssl);
        SSL_CTX_free(ctx);
        return 1;
    }

    printf("Connected to %s\n", SSL_get_peer_certificate(ssl)->subject_name);
    printf("SSL/TLS version: %s\n", SSL_get_version(ssl));
    printf("Cipher suite: %s\n", SSL_get_cipher(ssl));

    SSL_shutdown(ssl);
    SSL_free(ssl);
    SSL_CTX_free(ctx);

    return 0;
}