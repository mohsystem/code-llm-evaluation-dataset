
#include <iostream>
#include <string>
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
        std::cerr << "Unable to create SSL context" << std::endl;
        ERR_print_errors_fp(stderr);
        exit(EXIT_FAILURE);
    }
    return ctx;
}

void create_ssl_connection(const std::string& host, int port) {
    SSL_CTX* ctx = create_context();
    SSL* ssl = SSL_new(ctx);
    
    BIO* bio = BIO_new_ssl_connect(ctx);
    SSL_set_mode(ssl, SSL_MODE_AUTO_RETRY);

    BIO_set_conn_hostname(bio, (host + ":" + std::to_string(port)).c_str());

    if (BIO_do_connect(bio) <= 0) {
        std::cerr << "Error connecting to server" << std::endl;
        ERR_print_errors_fp(stderr);
        exit(EXIT_FAILURE);
    }

    if (SSL_get_verify_result(ssl) != X509_V_OK) {
        std::cerr << "Certificate verification error" << std::endl;
        exit(EXIT_FAILURE);
    }

    std::cout << "Connected to " << host << ":" << port << std::endl;
    std::cout << "SSL version: " << SSL_get_version(ssl) << std::endl;
    std::cout << "Cipher: " << SSL_get_cipher(ssl) << std::endl;

    BIO_free_all(bio);
    SSL_CTX_free(ctx);
}

int main() {
    initialize_openssl();
    create_ssl_connection("www.example.com", 443);
    cleanup_openssl();
    return 0;
}
