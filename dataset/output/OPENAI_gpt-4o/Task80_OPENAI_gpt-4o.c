#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <openssl/ssl.h>
#include <openssl/err.h>

int createSSLClientSocket(const char *hostname, int port) {
    SSL_CTX *ctx;
    SSL *ssl;
    int server;
    struct sockaddr_in6 addr;

    SSL_library_init();
    SSL_load_error_strings();

    ctx = SSL_CTX_new(TLS_client_method());
    if (ctx == NULL) {
        ERR_print_errors_fp(stderr);
        return -1;
    }

    server = socket(AF_INET6, SOCK_STREAM, 0);
    if (server < 0) {
        perror("Unable to create socket");
        return -1;
    }

    memset(&addr, 0, sizeof(addr));
    addr.sin6_family = AF_INET6;
    addr.sin6_port = htons(port);
    inet_pton(AF_INET6, hostname, &addr.sin6_addr);

    if (connect(server, (struct sockaddr*)&addr, sizeof(addr)) != 0) {
        close(server);
        perror("Unable to connect");
        return -1;
    }

    ssl = SSL_new(ctx);
    SSL_set_fd(ssl, server);

    if (SSL_connect(ssl) <= 0) {
        ERR_print_errors_fp(stderr);
        return -1;
    }

    printf("Connected with %s encryption
", SSL_get_cipher(ssl));
    SSL_free(ssl);
    close(server);
    SSL_CTX_free(ctx);

    return server;
}

int main() {
    createSSLClientSocket("hostname", 443);
    return 0;
}