#include <iostream>
#include <openssl/ssl.h>
#include <openssl/err.h>
#include <netdb.h>
#include <unistd.h>

void connect(const char* hostname, int port) {
    SSL_library_init();
    SSL_CTX *ctx = SSL_CTX_new(SSLv23_client_method());
    if (!ctx) {
        std::cerr << "Error creating SSL context\n";
        return;
    }
    
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    struct hostent *host = gethostbyname(hostname);
    struct sockaddr_in dest_addr{};
    dest_addr.sin_family = AF_INET;
    dest_addr.sin_port = htons(port);
    dest_addr.sin_addr.s_addr = *(long*)(host->h_addr);

    connect(sockfd, (struct sockaddr*)&dest_addr, sizeof(dest_addr));
    SSL *ssl = SSL_new(ctx);
    SSL_set_fd(ssl, sockfd);
    if (SSL_connect(ssl) == -1) {
        std::cerr << "SSL connection failed\n";
    } else {
        std::cout << SSL_get_cipher(ssl) << std::endl;
    }
    
    SSL_free(ssl);
    close(sockfd);
    SSL_CTX_free(ctx);
    ERR_free_strings();
}

int main() {
    connect("example.com", 443);
    return 0;
}