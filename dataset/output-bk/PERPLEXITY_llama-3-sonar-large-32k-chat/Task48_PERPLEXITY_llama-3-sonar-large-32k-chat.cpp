#include <iostream>
#include <string>
#include <vector>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 8000
#define BUFFER_SIZE 1024

class Server {
public:
    int serverSocket;
    std::vector<int> clients;

    Server() {
        serverSocket = socket(AF_INET, SOCK_STREAM, 0);
        if (serverSocket < 0) {
            perror("socket failed");
            exit(1);
        }

        struct sockaddr_in serverAddress;
        serverAddress.sin_family = AF_INET;
        serverAddress.sin_addr.s_addr = INADDR_ANY;
        serverAddress.sin_port = htons(PORT);

        if (bind(serverSocket, (struct sockaddr*)&serverAddress, sizeof(serverAddress)) < 0) {
            perror("bind failed");
            exit(1);
        }

        if (listen(serverSocket, 3) < 0) {
            perror("listen failed");
            exit(1);
        }

        std::cout << "Server started. Waiting for clients...
";
    }

    void broadcast(const std::string& message) {
        for (int client : clients) {
            send(client, message.c_str(), message.size(), 0);
        }
    }

    void run() {
        struct sockaddr_in clientAddress;
        int addrlen = sizeof(clientAddress);

        while (true) {
            int clientSocket = accept(serverSocket, (struct sockaddr*)&clientAddress, &addrlen);
            if (clientSocket < 0) {
                perror("accept failed");
                continue;
            }

            std::cout << "Client connected
";
            clients.push_back(clientSocket);

            char buffer[BUFFER_SIZE];
            while (true) {
                recv(clientSocket, buffer, BUFFER_SIZE, 0);
                std::string message(buffer);
                std::cout << "Received from client: " << message << std::endl;
                broadcast(message);
            }
        }
    }
};

int main() {
    Server server;
    server.run();
    return 0;
}