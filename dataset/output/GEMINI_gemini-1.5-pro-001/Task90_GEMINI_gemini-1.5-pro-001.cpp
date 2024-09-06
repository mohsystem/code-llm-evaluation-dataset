#include <iostream>
#include <string>
#include <vector>
#include <thread>
#include <mutex>
#include <winsock2.h>
#include <ws2tcpip.h>

#pragma comment(lib, "Ws2_32.lib")

#define PORT 65432
#define BUFFER_SIZE 1024

std::mutex clients_mutex;
std::vector<SOCKET> clients;

void handle_client(SOCKET client_socket) {
    char buffer[BUFFER_SIZE];
    int bytes_received;

    while (true) {
        bytes_received = recv(client_socket, buffer, BUFFER_SIZE, 0);
        if (bytes_received > 0) {
            buffer[bytes_received] = '\0';
            std::string message(buffer);

            std::cout << "Received: " << message << std::endl;

            // Broadcast the message to all clients
            clients_mutex.lock();
            for (SOCKET client : clients) {
                if (client != client_socket) {
                    send(client, message.c_str(), message.length(), 0);
                }
            }
            clients_mutex.unlock();
        } else if (bytes_received == 0) {
            std::cout << "Client disconnected." << std::endl;
            break;
        } else {
            std::cerr << "Error receiving data." << std::endl;
            break;
        }
    }

    // Remove the client from the list
    clients_mutex.lock();
    clients.erase(std::remove(clients.begin(), clients.end(), client_socket), clients.end());
    clients_mutex.unlock();

    closesocket(client_socket);
}

int main() {
    WSADATA wsa_data;
    if (WSAStartup(MAKEWORD(2, 2), &wsa_data) != 0) {
        std::cerr << "Error initializing Winsock." << std::endl;
        return 1;
    }

    SOCKET server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket == INVALID_SOCKET) {
        std::cerr << "Error creating socket." << std::endl;
        WSACleanup();
        return 1;
    }

    sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(PORT);

    if (bind(server_socket, (sockaddr*)&server_address, sizeof(server_address)) == SOCKET_ERROR) {
        std::cerr << "Error binding socket." << std::endl;
        closesocket(server_socket);
        WSACleanup();
        return 1;
    }

    if (listen(server_socket, SOMAXCONN) == SOCKET_ERROR) {
        std::cerr << "Error listening on socket." << std::endl;
        closesocket(server_socket);
        WSACleanup();
        return 1;
    }

    std::cout << "Server started on port " << PORT << "." << std::endl;

    while (true) {
        sockaddr_in client_address;
        int client_address_size = sizeof(client_address);
        SOCKET client_socket = accept(server_socket, (sockaddr*)&client_address, &client_address_size);
        if (client_socket == INVALID_SOCKET) {
            std::cerr << "Error accepting client connection." << std::endl;
            continue;
        }

        std::cout << "Client connected." << std::endl;

        clients_mutex.lock();
        clients.push_back(client_socket);
        clients_mutex.unlock();

        std::thread client_thread(handle_client, client_socket);
        client_thread.detach();
    }

    closesocket(server_socket);
    WSACleanup();

    return 0;
}