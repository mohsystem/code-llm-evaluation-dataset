
#include <iostream>
#include <string>
#include <cstring>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <openssl/ssl.h>
#include <openssl/err.h>

class SSLSocket {
public:
    SSLSocket(const std::string& host, int port) : host_(host), port_(port) {}

    bool connect() {
        // Initialize OpenSSL
        SSL_library_init();
        OpenSSL_add_all_algorithms();
        SSL_load_error_strings();

        // Create SSL context
        ctx_ = SSL_CTX_new(TLS_client_method());
        if (!ctx_) {
            ERR_print_errors_fp(stderr);
            return false;
        }

        // Create socket
        sock_ = socket(AF_INET6, SOCK_STREAM, 0);
        if (sock_ < 0) {
            std::cerr << "Socket creation failed" << std::endl;
            return false;
        }

        // Set up server address
        struct sockaddr_in6 addr;
        std::memset(&addr, 0, sizeof(addr));
        addr.sin6_family = AF_INET6;
        addr.sin6_port = htons(port_);
        if (inet_pton(AF_INET6, host_.c_str(), &addr.sin6_addr) <= 0) {
            std::cerr << "Invalid address" << std::endl;
            return false;
        }

        // Connect to server
        if (::connect(sock_, (struct sockaddr*)&addr, sizeof(addr)) < 0) {
            std::cerr << "Connection failed" << std::endl;
            return false;
        }

        // Create SSL connection
        ssl_ = SSL_new(ctx_);
        SSL_set_fd(ssl_, sock_);
        if (SSL_connect(ssl_) <= 0) {
            ERR_print_errors_fp(stderr);
            return false;
        }

        std::cout << "SSL connection established" << std::endl;
        return true;
    }

    ~SSLSocket() {
        if (ssl_) SSL_free(ssl_);
        if (sock_ >= 0) close(sock_);
        if (ctx_) SSL_CTX_free(ctx_);
    }

private:
    std::string host_;
    int port_;
    int sock_ = -1;
    SSL_CTX* ctx_ = nullptr;
    SSL* ssl_ = nullptr;
};

int main() {
    SSLSocket socket("2001:db8::1", 443);
    if (socket.connect()) {
        std::cout << "Connected successfully" << std::endl;
    } else {
        std::cerr << "Connection failed" << std::endl;
    }
    return 0;
}
