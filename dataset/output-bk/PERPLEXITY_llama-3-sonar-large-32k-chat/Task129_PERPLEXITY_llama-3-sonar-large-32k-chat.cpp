#include <iostream>
#include <string>
#include <fstream>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

void retrieveFile(const std::string& filename) {
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(8080);
    inet_pton(AF_INET, "127.0.0.1", &server_address.sin_addr);
    connect(sock, (struct sockaddr*)&server_address, sizeof(server_address));
    send(sock, filename.c_str(), filename.size(), 0);
    char data[1024];
    int bytesRead = recv(sock, data, 1024, 0);
    if (bytesRead > 0) {
        std::ofstream file(filename, std::ios::binary);
        file.write(data, bytesRead);
        file.close();
        std::cout << "File retrieved successfully" << std::endl;
    } else {
        std::cout << "File not found on the server" << std::endl;
    }
    close(sock);
}

int main() {
    std::cout << "Enter the filename: ";
    std::string filename;
    std::cin >> filename;
    retrieveFile(filename);
    return 0;
}