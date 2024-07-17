#include <openssl/ssl.h>
#include <openssl/err.h>
#include <iostream>
#include <string>

#define HOST "www.example.com"
#define PORT 443

int main() {
    SSL_library_init();
    SSL_load_error_strings();
    SSL_CTX *ctx = SSL_CTX_new(TLS_client_method());
    SSL *ssl = SSL_new(ctx);

    BIO *bio = BIO_new_connect(HOST ":" PORT);
    SSL_set_bio(ssl, bio, bio);

    if (SSL_connect(ssl) <= 0) {
        ERR_print_errors_fp(stderr);
    } else {
        std::string request = "GET / HTTP/1.1\r
"
                             "Host: " HOST "\r
"
                             "Accept: */*\r
"
                             "\r
";
        SSL_write(ssl, request.c_str(), request.size());

        char buffer[1024];
        int bytes;
        while ((bytes = SSL_read(ssl, buffer, 1024)) > 0) {
            std::cout.write(buffer, bytes);
        }
    }

    SSL_free(ssl);
    SSL_CTX_free(ctx);
    return 0;
}