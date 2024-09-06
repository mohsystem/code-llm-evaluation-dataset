#include <openssl/ssl.h>
#include <openssl/err.h>
#include <stdio.h>

int main() {
    SSL_library_init();
    SSL_CTX *ctx = SSL_CTX_new(TLS_client_method());
    SSL *ssl = SSL_new(ctx);

    BIO *bio = BIO_new_connect("www.example.com:443");
    if (BIO_do_connect(bio) <= 0) {
        ERR_print_errors_fp(stderr);
        return 1;
    }

    SSL_set_bio(ssl, bio, bio);
    if (SSL_connect(ssl) <= 0) {
        ERR_print_errors_fp(stderr);
        return 1;
    }

    printf("SSL connection established\n");

    const char *request = "Hello, world!";
    SSL_write(ssl, request, strlen(request));

    char buffer[1024];
    int bytes = SSL_read(ssl, buffer, 1024);
    if (bytes > 0) {
        printf("Received: %s\n", buffer);
    }

    SSL_shutdown(ssl);
    SSL_free(ssl);
    BIO_free_all(bio);
    SSL_CTX_free(ctx);
    return 0;
}