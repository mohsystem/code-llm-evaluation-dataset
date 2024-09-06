#include <iostream>
#include <openssl/ssl.h>
#include <openssl/err.h>

int main() {
    OpenSSL_add_all_algorithms();
    SSL_load_error_strings();

    SSL_CTX *ctx = SSL_CTX_new(TLS_client_method());
    if (!ctx) {
        std::cerr << "Error creating SSL context" << std::endl;
        return 1;
    }

    BIO *bio = BIO_new_connect("www.google.com:443");
    if (!bio) {
        std::cerr << "Error creating BIO" << std::endl;
        SSL_CTX_free(ctx);
        return 1;
    }

    SSL *ssl = SSL_new(ctx);
    SSL_set_bio(ssl, bio, bio);

    if (SSL_connect(ssl) <= 0) {
        std::cerr << "Error establishing SSL connection" << std::endl;
        ERR_print_errors_fp(stderr);
        SSL_free(ssl);
        SSL_CTX_free(ctx);
        return 1;
    }

    std::cout << "Connected to " << SSL_get_peer_certificate(ssl)->subject_name << std::endl;
    std::cout << "SSL/TLS version: " << SSL_get_version(ssl) << std::endl;
    std::cout << "Cipher suite: " << SSL_get_cipher(ssl) << std::endl;

    SSL_shutdown(ssl);
    SSL_free(ssl);
    SSL_CTX_free(ctx);

    return 0;
}