#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/ssl.h>
#include <openssl/err.h>

int main(int argc, char **argv) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <hostname> <port>
", argv[0]);
        return 1;
    }

    const char *hostname = argv[1];
    int port = atoi(argv[2]);

    SSL_CTX *ctx;
    SSL *ssl;
    BIO *bio;

    SSL_library_init();
    SSL_load_error_strings();
    ctx = SSL_CTX_new(TLS_client_method());
    if (!ctx) {
        fprintf(stderr, "Error creating SSL context
");
        return 1;
    }

    ssl = SSL_new(ctx);
    if (!ssl) {
        fprintf(stderr, "Error creating SSL object
");
        SSL_CTX_free(ctx);
        return 1;
    }

    bio = BIO_new_connect(hostname);
    if (!bio) {
        fprintf(stderr, "Error creating BIO object
");
        SSL_free(ssl);
        SSL_CTX_free(ctx);
        return 1;
    }

    BIO_set_conn_port(bio, port);
    SSL_set_bio(ssl, bio, bio);

    if (SSL_connect(ssl) <= 0) {
        fprintf(stderr, "Error establishing SSL connection
");
        ERR_print_errors_fp(stderr);
        SSL_free(ssl);
        SSL_CTX_free(ctx);
        BIO_free_all(bio);
        return 1;
    }

    printf("Secure connection established:
");
    printf("SSL Session ID: %s
", SSL_SESSION_get_id(SSL_get_session(ssl)));

    SSL_shutdown(ssl);
    SSL_free(ssl);
    SSL_CTX_free(ctx);
    BIO_free_all(bio);

    return 0;
}