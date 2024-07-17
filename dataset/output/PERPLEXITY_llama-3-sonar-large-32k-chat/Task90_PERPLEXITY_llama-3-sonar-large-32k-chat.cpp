#include <iostream>
#include <string>
#include <vector>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 8000
#define BUFFER_SIZE 1024

class ChatServer {
private:
    int sockfd;
    struct sockaddr_in servaddr, cliaddr;
    socklen_t clilen = sizeof(cliaddr);
    std::vector<std::string> clients;

public:
    ChatServer() {
        sockfd = socket(AF_INET, SOCK_DGRAM, 0);
        if (sockfd < 0) {
            std::cerr << "socket creation failed" << std::endl;
            exit(1);
        }

        memset(&servaddr, 0, sizeof(servaddr));
        servaddr.sin_family = AF_INET;
        servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
        servaddr.sin_port = htons(PORT);

        if (bind(sockfd, (struct sockaddr *) &servaddr, sizeof(servaddr)) < 0) {
            std::cerr << "bind failed" << std::endl;
            exit(1);
        }

        std::cout << "Chat server is running...
";
    }

    void run() {
        char buffer[BUFFER_SIZE];
        while (true) {
            recvfrom(sockfd, buffer, BUFFER_SIZE, 0, (struct sockaddr *) &cliaddr, &clilen);
            std::string message(buffer);
            std::cout << "Received message: " << message << std::endl;
            broadcast(message);
        }
    }

    void broadcast(const std::string &message) {
        for (const auto &client : clients) {
            sendto(sockfd, message.c_str(), message.size(), 0, (struct sockaddr *) &cliaddr, clilen);
        }
    }
};

int main() {
    ChatServer server;
    server.run();
    return 0;
}