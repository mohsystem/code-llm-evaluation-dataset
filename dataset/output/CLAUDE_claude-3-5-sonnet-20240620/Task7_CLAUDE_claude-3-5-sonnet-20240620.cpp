
#include <iostream>
#include <string>
#include <vector>
#include <thread>
#include <fstream>
#include <sstream>
#include <cstring>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <nlohmann/json.hpp>

using json = nlohmann::json;

class Server {
private:
    int serverSocket;
    std::vector<int> clients;

    json authenticate(const std::string& username, const std::string& password) {
        std::ifstream file("users.txt");
        std::string line;
        while (std::getline(file, line)) {
            std::istringstream iss(line);
            std::string storedUsername, storedPassword;
            if (std::getline(iss, storedUsername, ':') && std::getline(iss, storedPassword)) {
                if (username == storedUsername && password == storedPassword) {
                    return {{"status", "success"}, {"message", "Login successful"}};
                }
            }
        }
        return {{"status", "failure"}, {"message", "Invalid credentials"}};
    }

    void handleClient(int clientSocket) {
        char buffer[1024] = {0};
        while (true) {
            memset(buffer, 0, sizeof(buffer));
            int valread = read(clientSocket, buffer, 1024);
            if (valread <= 0) break;

            json request = json::parse(buffer);
            if (request["action"] == "login") {
                json response = authenticate(request["username"], request["password"]);
                std::string responseStr = response.dump();
                send(clientSocket, responseStr.c_str(), responseStr.length(), 0);
            }
        }
        close(clientSocket);
    }

public:
    Server(int port) {
        serverSocket = socket(AF_INET, SOCK_STREAM, 0);
        sockaddr_in address;
        address.sin_family = AF_INET;
        address.sin_addr.s_addr = INADDR_ANY;
        address.sin_port = htons(port);

        bind(serverSocket, (struct sockaddr *)&address, sizeof(address));
        listen(serverSocket, 3);
    }

    void start() {
        std::cout << "Server listening on port 5000" << std::endl;
        while (true) {
            sockaddr_in clientAddr;
            socklen_t clientAddrLen = sizeof(clientAddr);
            int clientSocket = accept(serverSocket, (struct sockaddr *)&clientAddr, &clientAddrLen);
            clients.push_back(clientSocket);
            std::thread(&Server::handleClient, this, clientSocket).detach();
        }
    }
};

class Client {
private:
    int clientSocket;

public:
    void connect(const std::string& ip, int port) {
        clientSocket = socket(AF_INET, SOCK_STREAM, 0);
        sockaddr_in serverAddr;
        serverAddr.sin_family = AF_INET;
        serverAddr.sin_port = htons(port);
        inet_pton(AF_INET, ip.c_str(), &serverAddr.sin_addr);

        ::connect(clientSocket, (struct sockaddr *)&serverAddr, sizeof(serverAddr));
    }

    void login() {
        std::string username, password;
        std::cout << "Enter username: ";
        std::cin >> username;
        std::cout << "Enter password: ";
        std::cin >> password;

        json request = {
            {"action", "login"},
            {"username", username},
            {"password", password}
        };

        std::string requestStr = request.dump();
        send(clientSocket, requestStr.c_str(), requestStr.length(), 0);

        char buffer[1024] = {0};
        read(clientSocket, buffer, 1024);
        json response = json::parse(buffer);
        std::cout << response["message"] << std::endl;
    }

    void disconnect() {
        close(clientSocket);
    }
};

int main() {
    std::string choice;
    std::cout << "Enter 's' for server, 'c' for client: ";
    std::cin >> choice;

    if (choice == "s") {
        Server server(5000);
        server.start();
    } else if (choice == "c") {
        Client client;
        client.connect("127.0.0.1", 5000);
        client.login();
        client.disconnect();
    } else {
        std::cout << "Invalid choice" << std::endl;
    }

    return 0;
}
