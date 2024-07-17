#include <iostream>
#include <string>
#include <openssl/ssl.h>
#include <openssl/err.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define HOST "localhost"
#define PORT 8443

int main() {
    int sockfd;
    struct sockaddr_in6 serv_addr;
    SSL_CTX *ctx;
    SSL *ssl;

    // Initialize OpenSSL
    SSL_library_init();
    SSL_load_error_strings();
    ctx = SSL_CTX_new(TLS_client_method());
    if (ctx == NULL) {
        std::cerr << "Error creating SSL context." << std::endl;
        ERR_print_errors_fp(stderr);
        return 1;
    }

    // Create socket
    sockfd = socket(AF_INET6, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Error opening socket");
        return 1;
    }

    // Set address
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin6_family = AF_INET6;
    inet_pton(AF_INET6, HOST, &serv_addr.sin6_addr);
    serv_addr.sin6_port = htons(PORT);

    // Connect to server
    if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("Error connecting");
        return 1;
    }

    // Create SSL object
    ssl = SSL_new(ctx);
    SSL_set_fd(ssl, sockfd);

    // Connect to SSL server
    if (SSL_connect(ssl) != 1) {
        std::cerr << "Error connecting to SSL server." << std::endl;
        ERR_print_errors_fp(stderr);
        return 1;
    }

    std::cout << "Connected to: " << HOST << ":" << PORT << std::endl;

    // Clean up
    SSL_free(ssl);
    close(sockfd);
    SSL_CTX_free(ctx);

    return 0;
}