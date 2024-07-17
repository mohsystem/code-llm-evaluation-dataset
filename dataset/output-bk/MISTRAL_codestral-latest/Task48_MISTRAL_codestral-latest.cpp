// C++ code for the server
#include <iostream>
#include <string>
#include <vector>
#include <thread>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 1234
#define MAX_CLIENTS 100
#define BUFFER_SIZE 2048

std::vector<int> client_sockets;
std::vector<std::string> client_names;

void broadcast(const std::string &message, int sender_socket) {
    for (int i = 0; i < client_sockets.size(); i++) {
        if (client_sockets[i] != 0 && client_sockets[i] != sender_socket) {
            send(client_sockets[i], message.c_str(), message.size(), 0);
        }
    }
}

void handle_client(int client_socket) {
    char buffer[BUFFER_SIZE] = {0};
    std::string name;

    recv(client_socket, buffer, BUFFER_SIZE, 0);
    name = std::string(buffer).substr(0, std::string(buffer).find("
"));

    std::string join_message = name + " has joined
";
    std::cout << join_message;
    broadcast(join_message, client_socket);

    while (1) {
        char message[BUFFER_SIZE] = {0};
        int valread = recv(client_socket, message, BUFFER_SIZE, 0);
        if (valread == 0) {
            std::string leave_message = name + " has left
";
            std::cout << leave_message;
            broadcast(leave_message, client_socket);
            break;
        }
        std::string full_message = name + ": " + std::string(message);
        std::cout << full_message;
        broadcast(full_message, client_socket);
    }

    close(client_socket);
}

int main(int argc, char const *argv[]) {
    int server_fd, new_socket, valread;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);

    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
        perror("setsockopt");
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

    std::cout << "Chat Server is running...
";

    while (1) {
        if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t *)&addrlen)) < 0) {
            perror("accept");
            exit(EXIT_FAILURE);
        }

        client_sockets.push_back(new_socket);
        std::thread(handle_client, new_socket).detach();
    }

    return 0;
}