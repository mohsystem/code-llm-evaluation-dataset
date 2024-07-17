#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>

#define PORT 65432
#define BUFFER_SIZE 1024

int main() {
    int serverSocket, clientSocket;
    struct sockaddr_in serverAddress, clientAddress;
    socklen_t clientAddressSize;
    char buffer[BUFFER_SIZE];

    // Create socket
    serverSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (serverSocket == -1) {
        std::cerr << "Failed to create socket" << std::endl;
        return 1;
    }

    // Set address information
    memset(&serverAddress, 0, sizeof(serverAddress));
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_addr.s_addr = INADDR_ANY;
    serverAddress.sin_port = htons(PORT);

    // Bind socket to address
    if (bind(serverSocket, (struct sockaddr *)&serverAddress, sizeof(serverAddress)) == -1) {
        std::cerr << "Failed to bind socket" << std::endl;
        close(serverSocket);
        return 1;
    }

    // Listen for incoming connections
    if (listen(serverSocket, 5) == -1) {
        std::cerr << "Failed to listen on socket" << std::endl;
        close(serverSocket);
        return 1;
    }

    std::cout << "Server started on port " << PORT << std::endl;

    while (true) {
        clientAddressSize = sizeof(clientAddress);

        // Accept connection from client
        clientSocket = accept(serverSocket, (struct sockaddr *)&clientAddress, &clientAddressSize);
        if (clientSocket == -1) {
            std::cerr << "Failed to accept client connection" << std::endl;
            continue;
        }

        std::cout << "Client connected: " << inet_ntoa(clientAddress.sin_addr) << ":" << ntohs(clientAddress.sin_port) << std::endl;

        // Receive file name
        int bytesReceived = recv(clientSocket, buffer, BUFFER_SIZE, 0);
        if (bytesReceived <= 0) {
            std::cerr << "Failed to receive file name" << std::endl;
            close(clientSocket);
            continue;
        }
        buffer[bytesReceived] = '\0';
        std::string fileName(buffer);

        // Receive file size
        bytesReceived = recv(clientSocket, buffer, BUFFER_SIZE, 0);
        if (bytesReceived <= 0) {
            std::cerr << "Failed to receive file size" << std::endl;
            close(clientSocket);
            continue;
        }
        buffer[bytesReceived] = '\0';
        long fileSize = std::stol(buffer);

        // Open file for writing
        std::ofstream file(fileName, std::ios::binary);
        if (!file.is_open()) {
            std::cerr << "Failed to open file for writing: " << fileName << std::endl;
            close(clientSocket);
            continue;
        }

        // Receive and write file data
        long totalBytesReceived = 0;
        while (totalBytesReceived < fileSize) {
            bytesReceived = recv(clientSocket, buffer, BUFFER_SIZE, 0);
            if (bytesReceived <= 0) {
                std::cerr << "Failed to receive file data" << std::endl;
                break;
            }

            file.write(buffer, bytesReceived);
            totalBytesReceived += bytesReceived;
        }

        // Close file
        file.close();

        // Send confirmation message
        if (totalBytesReceived == fileSize) {
            send(clientSocket, "File uploaded successfully!", strlen("File uploaded successfully!"), 0);
            std::cout << "File '" << fileName << "' uploaded successfully!" << std::endl;
        } else {
            send(clientSocket, "Error uploading file", strlen("Error uploading file"), 0);
            std::cerr << "Error uploading file '" << fileName << "'" << std::endl;
        }

        // Close client socket
        close(clientSocket);
    }

    // Close server socket
    close(serverSocket);

    return 0;
}