
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <openssl/ssl.h>
#include <openssl/err.h>

int create_ssl_socket(const char* host, int port) {
    int sock = -1;
    struct sockaddr_in6 addr;
    SSL_CTX *ctx;
    SSL *ssl;

    // Initialize OpenSSL
    SSL_library_init();
    OpenSSL_add_all_algorithms();
    SSL_load_error_strings();

    // Create SSL context
    ctx = SSL_CTX_new(TLS_client_method());
    if (!ctx) {
        ERR_print_errors_fp(stderr);
        return -1;
    }

    // Create socket
    sock = socket(AF_INET6, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("Socket creation failed");
        SSL_CTX_free(ctx);
        return -1;
    }

    // Set up server address
    memset(&addr, 0, sizeof(addr));
    addr.sin6_family = AF_INET6;
    addr.sin6_port = htons(port);
    if (inet_pton(AF_INET6, host, &addr.sin6_addr) <= 0) {
        perror("Invalid address");
        close(sock);
        SSL_CTX_free(ctx);
        return -1;
    }

    // Connect to server
    if (connect(sock, (struct sockaddr*)&addr, sizeof(addr)) < 0) {
        perror("Connection failed");
        close(sock);
        SSL_CTX_free(ctx);
        return -1;
    }

    // Create SSL connection
    ssl = SSL_new(ctx);
    SSL_set_fd(ssl, sock);
    if (SSL_connect(ssl) <= 0) {
        ERR_print_errors_fp(stderr);
        SSL_free(ssl);
        close(sock);
        SSL_CTX_free(ctx);
        return -1;
    }

    printf("SSL connection established\
");
    
    // Clean up (in a real application, you\'d return the SSL object and clean up later)
    SSL_free(ssl);
    close(sock);
    SSL_CTX_free(ctx);

    return 0;
}

int main() {
    create_ssl_socket("2001:db8::1", 443);
    return 0;
}
