// CPP - Client
#include <iostream>
#include <string>
#include <cstring>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

int main() {
    std::string server_address = "127.0.0.1";
    int port = 12345;
    int sock = 0;
    struct sockaddr_in serv_addr;
    
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        std::cout << "Socket creation error.\n";
        return -1;
    }
    
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(port);
    
    if (inet_pton(AF_INET, server_address.c_str(), &serv_addr.sin_addr) <= 0) {
        std::cout << "Invalid address or Address not supported.\n";
        return -1;
    }
    
    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        std::cout << "Connection failed.\n";
        return -1;
    }
    
    std::string username, password;
    std::cout << "Username: ";
    std::cin >> username;
    std::cout << "Password: ";
    std::cin >> password;
    
    std::string message = username + ":" + password;
    send(sock, message.c_str(), message.size(), 0);
    
    char buffer[1024] = {0};
    read(sock, buffer, 1024);
    std::cout << "Response from server: " << buffer << "\n";
    
    close(sock);
    return 0;
}