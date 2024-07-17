#include <iostream>
#include <string>
#include <openssl/ssl.h>
#include <openssl/err.h>

int main(int argc, char **argv) {
    if (argc != 3) {
        std::cerr << "Usage: " << argv[0] << " <hostname> <port>" << std::endl;
        return 1;
    }

    const std::string hostname = argv[1];
    int port = std::stoi(argv[2]);

    SSL_CTX *ctx;
    SSL *ssl;
    BIO *bio;

    SSL_library_init();
    SSL_load_error_strings();
    ctx = SSL_CTX_new(TLS_client_method());
    if (!ctx) {
        std::cerr << "Error creating SSL context" << std::endl;
        return 1;
    }

    ssl = SSL_new(ctx);
    if (!ssl) {
        std::cerr << "Error creating SSL object" << std::endl;
        SSL_CTX_free(ctx);
        return 1;
    }

    bio = BIO_new_connect((hostname + ":" + std::to_string(port)).c_str());
    if (!bio) {
        std::cerr << "Error creating BIO object" << std::endl;
        SSL_free(ssl);
        SSL_CTX_free(ctx);
        return 1;
    }

    SSL_set_bio(ssl, bio, bio);

    if (SSL_connect(ssl) <= 0) {
        std::cerr << "Error establishing SSL connection" << std::endl;
        ERR_print_errors_fp(stderr);
        SSL_free(ssl);
        SSL_CTX_free(ctx);
        BIO_free_all(bio);
        return 1;
    }

    std::cout << "Secure connection established:" << std::endl;
    std::cout << "SSL Session ID: " << SSL_SESSION_get_id(SSL_get_session(ssl)) << std::endl;

    SSL_shutdown(ssl);
    SSL_free(ssl);
    SSL_CTX_free(ctx);
    BIO_free_all(bio);

    return 0;
}