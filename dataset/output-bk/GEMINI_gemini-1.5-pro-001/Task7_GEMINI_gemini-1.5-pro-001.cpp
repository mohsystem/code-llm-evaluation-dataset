#include <iostream>
#include <string>
#include <thread>
#include <vector>
#include <map>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <cstring>

const int PORT = 9001;

std::map<std::string, std::string> userDatabase = {
    {"user1", "pass1"},
    {"user2", "pass2"}
};

void handleClient(int clientSocket) {
    char buffer[1024] = {0};
    read(clientSocket, buffer, 1024);

    std::string request(buffer);
    std::string response;

    // Basic parsing for login
    if (request.substr(0, 5) == "LOGIN") {
        size_t pos1 = request.find(' ', 5);
        size_t pos2 = request.find(' ', pos1 + 1);
        std::string username = request.substr(pos1 + 1, pos2 - pos1 - 1);
        std::string password = request.substr(pos2 + 1);

        if (userDatabase.count(username) > 0 && userDatabase[username] == password) {
            response = "Welcome, " + username + "!
";
        } else {
            response = "Invalid username or password.
";
        }
    } else {
        response = "Invalid request.
";
    }

    send(clientSocket, response.c_str(), response.size(), 0);
    close(clientSocket);
}

int main() {
    int serverSocket, clientSocket;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);

    // Create socket
    serverSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (serverSocket == 0) {
        std::cerr << "Socket creation failed" << std::endl;
        return 1;
    }

    // Set socket options
    if (setsockopt(serverSocket, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt))) {
        std::cerr << "Setsockopt failed" << std::endl;
        return 1;
    }

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    // Bind socket
    if (bind(serverSocket, (struct sockaddr*)&address, sizeof(address)) < 0) {
        std::cerr << "Bind failed" << std::endl;
        return 1;
    }

    // Listen for connections
    if (listen(serverSocket, 3) < 0) {
        std::cerr << "Listen failed" << std::endl;
        return 1;
    }

    std::cout << "Server started on port " << PORT << std::endl;

    while (true) {
        clientSocket = accept(serverSocket, (struct sockaddr*)&address, (socklen_t*)&addrlen);
        if (clientSocket < 0) {
            std::cerr << "Accept failed" << std::endl;
            return 1;
        }

        std::thread clientThread(handleClient, clientSocket);
        clientThread.detach();
    }

    return 0;
}