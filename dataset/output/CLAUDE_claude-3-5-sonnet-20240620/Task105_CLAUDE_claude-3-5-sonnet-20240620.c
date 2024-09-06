
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/ssl.h>
#include <openssl/err.h>

void initialize_openssl() {
    SSL_load_error_strings();
    OpenSSL_add_ssl_algorithms();
}

void cleanup_openssl() {
    EVP_cleanup();
}

SSL_CTX* create_context() {
    const SSL_METHOD* method = TLS_client_method();
    SSL_CTX* ctx = SSL_CTX_new(method);
    if (!ctx) {
        fprintf(stderr, "Unable to create SSL context\\n");
        ERR_print_errors_fp(stderr);
        exit(EXIT_FAILURE);
    }
    return ctx;
}

void create_ssl_connection(const char* host, int port) {
    SSL_CTX* ctx = create_context();
    SSL* ssl = SSL_new(ctx);
    
    BIO* bio = BIO_new_ssl_connect(ctx);
    SSL_set_mode(ssl, SSL_MODE_AUTO_RETRY);

    char connection_string[256];
    snprintf(connection_string, sizeof(connection_string), "%s:%d", host, port);
    BIO_set_conn_hostname(bio, connection_string);

    if (BIO_do_connect(bio) <= 0) {
        fprintf(stderr, "Error connecting to server\\n");
        ERR_print_errors_fp(stderr);
        exit(EXIT_FAILURE);
    }

    if (SSL_get_verify_result(ssl) != X509_V_OK) {
        fprintf(stderr, "Certificate verification error\\n");
        exit(EXIT_FAILURE);
    }

    printf("Connected to %s:%d\\n", host, port);
    printf("SSL version: %s\\n", SSL_get_version(ssl));
    printf("Cipher: %s\\n", SSL_get_cipher(ssl));

    BIO_free_all(bio);
    SSL_CTX_free(ctx);
}

int main() {
    initialize_openssl();
    create_ssl_connection("www.example.com", 443);
    cleanup_openssl();
    return 0;
}
