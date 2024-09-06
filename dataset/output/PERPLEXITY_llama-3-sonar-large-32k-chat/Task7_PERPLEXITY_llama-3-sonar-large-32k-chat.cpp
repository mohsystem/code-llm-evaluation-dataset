// C++ Code (Server)
#include <iostream>
#include <string>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <fstream>

bool authenticate(const std::string& username, const std::string& password) {
    std::ifstream file("users.txt");
    std::string line;
    while (std::getline(file, line)) {
        size_t colonPos = line.find(":");
        if (colonPos != std::string::npos) {
            std::string user = line.substr(0, colonPos);
            std::string pwd = line.substr(colonPos + 1);
            if (user == username && pwd == password) {
                return true;
            }
        }
    }
    return false;
}

int main() {
    int serverSocket = socket(AF_INET, SOCK_STREAM, 0);
    sockaddr_in serverAddress;
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_port = htons(10000);
    inet_pton(AF_INET, "127.0.0.1", &serverAddress.sin_addr);

    bind(serverSocket, (struct sockaddr *)&serverAddress, sizeof(serverAddress));
    listen(serverSocket, 1);

    std::cout << "Server started. Waiting for connections...\n";
    int connection = accept(serverSocket, nullptr, nullptr);
    std::cout << "Connected to client\n";

    char buffer[1024];
    while (true) {
        recv(connection, buffer, 1024, 0);
        std::string data(buffer);
        if (data.find("LOGIN") == 0) {
            size_t spacePos = data.find(" ");
            if (spacePos != std::string::npos) {
                std::string username = data.substr(spacePos + 1);
                spacePos = username.find(" ");
                if (spacePos != std::string::npos) {
                    std::string password = username.substr(spacePos + 1);
                    username = username.substr(0, spacePos);
                    if (authenticate(username, password)) {
                        send(connection, "LOGIN_SUCCESS", 12, 0);
                    } else {
                        send(connection, "LOGIN_FAILED", 12, 0);
                    }
                }
            }
        } else {
            std::cout << "Received message: " << data << std::endl;
            std::string response = "Server received your message: " + data;
            send(connection, response.c_str(), response.length(), 0);
        }
    }

    return 0;
}