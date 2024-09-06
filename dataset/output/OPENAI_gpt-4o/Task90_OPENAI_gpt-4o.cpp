#include <iostream>
#include <vector>
#include <thread>
#include <mutex>
#include <arpa/inet.h>
#include <unistd.h>

std::vector<int> clients;
std::mutex clients_mutex;

void handle_client(int client_socket) {
    char buffer[1024];
    while (true) {
        int bytes_received = recv(client_socket, buffer, sizeof(buffer), 0);
        if (bytes_received <= 0) {
            close(client_socket);
            std::lock_guard<std::mutex> lock(clients_mutex);
            clients.erase(std::remove(clients.begin(), clients.end(), client_socket), clients.end());
            return;
        }
        
        buffer[bytes_received] = '\0';
        std::cout << "Received: " << buffer << std::endl;
        
        std::lock_guard<std::mutex> lock(clients_mutex);
        for (const auto& client : clients) {
            if (client != client_socket) {
                send(client, buffer, bytes_received, 0);
            }
        }
    }
}

int main() {
    int server_socket;
    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(5555);
    server_addr.sin_addr.s_addr = INADDR_ANY;

    bind(server_socket, (struct sockaddr*)&server_addr, sizeof(server_addr));
    listen(server_socket, 10);
    std::cout << "Server started, waiting for clients..." << std::endl;

    while (true) {
        int client_socket = accept(server_socket, nullptr, nullptr);
        {
            std::lock_guard<std::mutex> lock(clients_mutex);
            clients.push_back(client_socket);
        }
        std::thread(handle_client, client_socket).detach();
    }

    return 0;
}