#include <openssl/ssl.h>
#include <openssl/err.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

int main() {
    SSL_load_error_strings();
    OpenSSL_add_ssl_algorithms();
    const SSL_METHOD *method = TLS_client_method();
    SSL_CTX *ctx = SSL_CTX_new(method);
    SSL *ssl = SSL_new(ctx);
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    struct hostent *host = gethostbyname("google.com");
    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_port = htons(443);
    addr.sin_addr.s_addr = *(long*)(host->h_addr);
    connect(sockfd, (struct sockaddr*)&addr, sizeof(addr));
    SSL_set_fd(ssl, sockfd);
    if (SSL_connect(ssl) <= 0)
        ERR_print_errors_fp(stderr);
    SSL_write(ssl, "GET / HTTP/1.0\r
\r
", 18);
    char buf[1024];
    int bytes;
    while ((bytes = SSL_read(ssl, buf, sizeof(buf))) > 0)
        write(1, buf, bytes);
    SSL_free(ssl);
    close(sockfd);
    SSL_CTX_free(ctx);
    EVP_cleanup();
    return 0;
}