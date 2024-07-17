#include <stdio.h>
#include <openssl/ssl.h>
#include <openssl/err.h>

int main() {
    const SSL_METHOD *method;
    SSL_CTX *ctx;
    SSL *ssl;
    BIO *bio;

    SSL_library_init();
    OpenSSL_add_all_algorithms();
    SSL_load_error_strings();
    method = TLS_client_method();
    ctx = SSL_CTX_new(method);
    bio = BIO_new_ssl_connect(ctx);
    BIO_set_conn_hostname(bio, "www.example.com:443");
    BIO_do_connect(bio);
    ssl = BIO_get_ssl(bio);

    // Use bio to communicate with the server

    SSL_CTX_free(ctx);
    return 0;
}