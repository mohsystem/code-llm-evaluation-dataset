#include <openssl/ssl.h>
#include <openssl/err.h>
#include <arpa/inet.h>
#include <sys/socket.h>

SSL* createSSLClientSocket(const char* host, int port) {
    SSL_library_init();
    SSL_CTX* ctx = SSL_CTX_new(TLS_client_method());
    SSL* ssl = SSL_new(ctx);
    int sockfd = socket(AF_INET6, SOCK_STREAM, 0);
    struct sockaddr_in6 addr;
    inet_pton(AF_INET6, host, &addr.sin6_addr);
    addr.sin6_family = AF_INET6;
    addr.sin6_port = htons(port);
    connect(sockfd, (struct sockaddr*)&addr, sizeof(addr));
    SSL_set_fd(ssl, sockfd);
    SSL_connect(ssl);
    return ssl;
}