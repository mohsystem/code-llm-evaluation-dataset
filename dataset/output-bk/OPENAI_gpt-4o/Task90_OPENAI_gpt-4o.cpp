// C++ code
#include <iostream>
#include <string>
#include <vector>
#include <thread>
#include <mutex>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 12345
#define BUFFER_SIZE 2048

std::vector<int> clients;
std::mutex clients_mutex;

void handle_client(int client_socket) {
    char buffer[BUFFER_SIZE];
    ssize_t nbytes;

    {
        std::lock_guard<std::mutex> lock(clients_mutex);
        clients.push_back(client_socket);
    }

    while ((nbytes = read(client_socket, buffer, sizeof(buffer))) > 0) {
        buffer[nbytes] = '\0';
        std::lock_guard<std::mutex> lock(clients_mutex);
        for (int client : clients) {
            if (client != client_socket) {
                write(client, buffer, nbytes);
            }
        }
    }

    close(client_socket);
    {
        std::lock_guard<std::mutex> lock(clients_mutex);
        clients.erase(std::remove(clients.begin(), clients.end(), client_socket), clients.end());
    }
}

int main() {
    int server_socket, client_socket;
    sockaddr_in server_addr{}, client_addr{};
    socklen_t addr_len = sizeof(client_addr);

    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    server_addr.sin_addr.s_addr = INADDR_ANY;

    bind(server_socket, (sockaddr *)&server_addr, sizeof(server_addr));
    listen(server_socket, 10);

    std::cout << "Chat server started on port " << PORT << std::endl;

    while (true) {
        client_socket = accept(server_socket, (sockaddr *)&client_addr, &addr_len);
        std::thread(handle_client, client_socket).detach();
    }

    return 0;
}