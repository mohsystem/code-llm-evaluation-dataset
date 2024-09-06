
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netdb.h>
#include <openssl/ssl.h>
#include <openssl/err.h>

SSL* create_ssl_ipv6_socket(const char* host, int port) {
    int sock;
    struct addrinfo hints, *res, *p;
    char port_str[6];
    SSL_CTX *ctx;
    SSL *ssl;

    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_INET6;
    hints.ai_socktype = SOCK_STREAM;

    snprintf(port_str, sizeof(port_str), "%d", port);

    if (getaddrinfo(host, port_str, &hints, &res) != 0) {
        perror("getaddrinfo");
        return NULL;
    }

    for (p = res; p != NULL; p = p->ai_next) {
        sock = socket(p->ai_family, p->ai_socktype, p->ai_protocol);
        if (sock == -1) continue;

        if (connect(sock, p->ai_addr, p->ai_addrlen) != -1) break;

        close(sock);
    }

    freeaddrinfo(res);

    if (p == NULL) {
        fprintf(stderr, "Failed to connect\\n");
        return NULL;
    }

    SSL_library_init();
    OpenSSL_add_all_algorithms();
    SSL_load_error_strings();

    ctx = SSL_CTX_new(TLS_client_method());
    if (ctx == NULL) {
        ERR_print_errors_fp(stderr);
        return NULL;
    }

    ssl = SSL_new(ctx);
    SSL_set_fd(ssl, sock);

    if (SSL_connect(ssl) == -1) {
        ERR_print_errors_fp(stderr);
        return NULL;
    }

    return ssl;
}

int main() {
    const char* host = "example.com";
    int port = 443;
    SSL* ssl = create_ssl_ipv6_socket(host, port);
    if (ssl) {
        // Use the SSL connection here
        SSL_shutdown(ssl);
        SSL_free(ssl);
    }
    return 0;
}
