#include <iostream>
#include <openssl/ssl.h>
#include <openssl/err.h>
#include <arpa/inet.h>
#include <sys/socket.h>

SSL* createSSLClientSocket(const char* host, int port) {
    SSL_library_init();
    SSL_CTX* ctx = SSL_CTX_new(TLS_client_method());
    SSL* ssl = SSL_new(ctx);
    BIO* bio = BIO_new_connect(host);
    BIO_set_conn_port(bio, std::to_string(port).c_str());
    SSL_set_bio(ssl, bio, bio);
    SSL_connect(ssl);
    return ssl;
}