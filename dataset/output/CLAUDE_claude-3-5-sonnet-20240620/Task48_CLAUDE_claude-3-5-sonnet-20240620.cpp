
#include <iostream>
#include <cstring>
#include <vector>
#include <thread>
#include <mutex>
#include <algorithm>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

const int PORT = 5000;
const int BUFFER_SIZE = 1024;

std::vector<int> clients;
std::mutex clients_mutex;

void broadcast(const std::string& message, int sender_sd) {
    std::lock_guard<std::mutex> lock(clients_mutex);
    for (int client : clients) {
        if (client != sender_sd) {
            send(client, message.c_str(), message.length(), 0);
        }
    }
}

void handle_client(int client_sd) {
    char buffer[BUFFER_SIZE];
    
    while (true) {
        int bytes_received = recv(client_sd, buffer, BUFFER_SIZE, 0);
        if (bytes_received <= 0) {
            std::lock_guard<std::mutex> lock(clients_mutex);
            clients.erase(std::remove(clients.begin(), clients.end(), client_sd), clients.end());
            break;
        }
        
        std::string message(buffer, bytes_received);
        broadcast(message, client_sd);
    }
    
    close(client_sd);
}

int main() {
    int server_sd = socket(AF_INET, SOCK_STREAM, 0);
    sockaddr_in server_addr;
    
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);
    
    bind(server_sd, (struct sockaddr*)&server_addr, sizeof(server_addr));
    listen(server_sd, 10);
    
    std::cout << "Chat Server is running..." << std::endl;
    
    while (true) {
        int client_sd = accept(server_sd, NULL, NULL);
        
        std::lock_guard<std::mutex> lock(clients_mutex);
        clients.push_back(client_sd);
        
        std::thread client_thread(handle_client, client_sd);
        client_thread.detach();
    }
    
    return 0;
}

// Chat Client
#include <iostream>
#include <cstring>
#include <thread>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

const int PORT = 5000;
const int BUFFER_SIZE = 1024;
const char* SERVER_IP = "127.0.0.1";

void receive_messages(int sock) {
    char buffer[BUFFER_SIZE];
    int read_size;
    
    while ((read_size = recv(sock, buffer, BUFFER_SIZE, 0)) > 0) {
        buffer[read_size] = \'\\0\';
        std::cout << buffer;
    }
    
    if (read_size == 0) {
        std::cout << "Server disconnected" << std::endl;
    } else if (read_size == -1) {
        std::cerr << "recv failed" << std::endl;
    }
}

int main() {
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    sockaddr_in server_addr;
    
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = inet_addr(SERVER_IP);
    server_addr.sin_port = htons(PORT);
    
    if (connect(sock, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        std::cerr << "Connect failed" << std::endl;
        return 1;
    }
    
    std::cout << "Connected to server" << std::endl;
    
    std::thread recv_thread(receive_messages, sock);
    
    std::string message;
    while (std::getline(std::cin, message)) {
        if (send(sock, message.c_str(), message.length(), 0) < 0) {
            std::cerr << "Send failed" << std::endl;
            return 1;
        }
    }
    
    close(sock);
    recv_thread.join();
    
    return 0;
}
