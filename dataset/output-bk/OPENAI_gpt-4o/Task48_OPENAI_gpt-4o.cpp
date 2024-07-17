// C++
#include <iostream>
#include <string>
#include <vector>
#include <thread>
#include <mutex>
#include <unistd.h>
#include <netinet/in.h>

#define PORT 12345

std::vector<int> client_sockets;
std::mutex clients_mutex;

void handle_client(int client_socket) {
    char buffer[1024];
    int len;

    while ((len = read(client_socket, buffer, sizeof(buffer) - 1)) > 0) {
        buffer[len] = '\0';
        
        std::lock_guard<std::mutex> guard(clients_mutex);
        for (int sock : client_sockets) {
            if (sock != client_socket) {
                send(sock, buffer, len, 0);
            }
        }
    }

    close(client_socket);
    std::lock_guard<std::mutex> guard(clients_mutex);
    client_sockets.erase(std::remove(client_sockets.begin(), client_sockets.end(), client_socket), client_sockets.end());
}

int main() {
    int server_socket, client_socket;
    sockaddr_in server_addr, client_addr;
    socklen_t client_len = sizeof(client_addr);

    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    bind(server_socket, (struct sockaddr*)&server_addr, sizeof(server_addr));
    listen(server_socket, 10);

    std::cout << "Chat server started..." << std::endl;

    while (true) {
        client_socket = accept(server_socket, (struct sockaddr*)&client_addr, &client_len);
        
        std::lock_guard<std::mutex> guard(clients_mutex);
        client_sockets.push_back(client_socket);

        std::thread(handle_client, client_socket).detach();
    }

    close(server_socket);
    return 0;
}