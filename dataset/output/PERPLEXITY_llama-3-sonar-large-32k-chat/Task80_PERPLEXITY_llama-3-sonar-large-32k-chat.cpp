#include <openssl/ssl.h>
#include <openssl/err.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>

SSL* createSSLSocket(const char *host, int port) {
    SSL_CTX *ctx = SSL_CTX_new(TLS_client_method());
    SSL *ssl = SSL_new(ctx);
    BIO *bio = BIO_new_connect(host);
    SSL_set_bio(ssl, bio, bio);
    SSL_connect(ssl);
    return ssl;
}

int main() {
    SSL *ssl = createSSLSocket("::1", 443);
    if (ssl) {
        printf("Connected to ::1:443
");
        SSL_free(ssl);
    } else {
        ERR_print_errors_fp(stderr);
    }
    return 0;
}