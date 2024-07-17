
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstring>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

#define PORT 5000

struct User {
    std::string username;
    std::string password;
};

std::vector<User> users;

void load_users() {
    std::ifstream file("users.txt");
    std::string line;
    while (std::getline(file, line)) {
        size_t pos = line.find(\':\');
        if (pos != std::string::npos) {
            User user;
            user.username = line.substr(0, pos);
            user.password = line.substr(pos + 1);
            users.push_back(user);
        }
    }
}

bool authenticate(const std::string& username, const std::string& password) {
    for (const auto& user : users) {
        if (user.username == username && user.password == password) {
            return true;
        }
    }
    return false;
}

void handle_client(int client_socket) {
    char buffer[1024] = {0};
    read(client_socket, buffer, 1024);

    std::string request(buffer);
    size_t pos1 = request.find(\'|\');
    size_t pos2 = request.find(\'|\', pos1 + 1);

    if (pos1 != std::string::npos && pos2 != std::string::npos) {
        std::string command = request.substr(0, pos1);
        std::string username = request.substr(pos1 + 1, pos2 - pos1 - 1);
        std::string password = request.substr(pos2 + 1);

        if (command == "LOGIN") {
            if (authenticate(username, password)) {
                send(client_socket, "LOGIN_SUCCESS", strlen("LOGIN_SUCCESS"), 0);
            } else {
                send(client_socket, "LOGIN_FAILED", strlen("LOGIN_FAILED"), 0);
            }
        }
    }

    close(client_socket);
}

int main() {
    load_users();

    int server_fd, new_socket;
    struct sockaddr_in address;
    int addrlen = sizeof(address);

    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    if (listen(server_fd, 3) < 0) {
        perror("listen");
        exit(EXIT_FAILURE);
    }

    std::cout << "Server started on port " << PORT << std::endl;

    while (true) {
        if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen)) < 0) {
            perror("accept");
            exit(EXIT_FAILURE);
        }

        handle_client(new_socket);
    }

    return 0;
}

// Client code
#include <iostream>
#include <string>
#include <cstring>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 5000

int main() {
    int sock = 0;
    struct sockaddr_in serv_addr;
    char buffer[1024] = {0};
    std::string username, password;

    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        std::cout << "\
 Socket creation error \
";
        return -1;
    }

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);

    if (inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr) <= 0) {
        std::cout << "\
Invalid address/ Address not supported \
";
        return -1;
    }

    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        std::cout << "\
Connection Failed \
";
        return -1;
    }

    std::cout << "Enter username: ";
    std::getline(std::cin, username);

    std::cout << "Enter password: ";
    std::getline(std::cin, password);

    std::string request = "LOGIN|" + username + "|" + password;
    send(sock, request.c_str(), request.length(), 0);
    
    memset(buffer, 0, sizeof(buffer));
    read(sock, buffer, 1024);
    std::cout << "Server response: " << buffer << std::endl;

    return 0;
}
