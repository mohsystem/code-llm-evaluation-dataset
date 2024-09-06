#include <iostream>
#include <string>
#include <fstream>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

void retrieveFile(const std::string& fileName) {
    int clientSocket = socket(AF_INET, SOCK_STREAM, 0);
    sockaddr_in serverAddress;
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_port = htons(12345);
    inet_pton(AF_INET, "127.0.0.1", &serverAddress.sin_addr);
    connect(clientSocket, (struct sockaddr*)&serverAddress, sizeof(serverAddress));
    send(clientSocket, fileName.c_str(), fileName.size(), 0);
    char buffer[1024];
    int bytesRead;
    if ((bytesRead = recv(clientSocket, buffer, 1024, 0)) == -1) {
        std::cout << "File not found on the server" << std::endl;
    } else {
        std::ofstream file(fileName, std::ios::binary);
        while ((bytesRead = recv(clientSocket, buffer, 1024, 0)) > 0) {
            file.write(buffer, bytesRead);
        }
        file.close();
    }
    close(clientSocket);
}

int main() {
    std::cout << "Enter the file name: ";
    std::string fileName;
    std::cin >> fileName;
    retrieveFile(fileName);
    return 0;
}