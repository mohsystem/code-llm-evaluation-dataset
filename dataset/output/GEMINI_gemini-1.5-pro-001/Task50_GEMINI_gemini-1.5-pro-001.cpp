#include <iostream>
#include <fstream>
#include <string>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <cstring>

#define PORT 65432

using namespace std;

void handleClient(int clientSocket) {
    const int BUFFER_SIZE = 1024;
    char buffer[BUFFER_SIZE];

    // Receive filename and filesize
    recv(clientSocket, buffer, BUFFER_SIZE, 0);
    string filename(buffer);

    recv(clientSocket, buffer, BUFFER_SIZE, 0);
    long filesize = stol(string(buffer));

    cout << "Receiving file: " << filename << " (" << filesize << " bytes)" << endl;

    // Receive and save the file
    ofstream file(filename, ios::binary);
    if (!file.is_open()) {
        cerr << "Error opening file: " << filename << endl;
        return;
    }

    long bytesReceived = 0;
    while (bytesReceived < filesize) {
        int bytesRead = recv(clientSocket, buffer, BUFFER_SIZE, 0);
        if (bytesRead <= 0) {
            cerr << "Error receiving file data" << endl;
            break;
        }

        file.write(buffer, bytesRead);
        bytesReceived += bytesRead;
    }

    file.close();

    cout << filename << " uploaded successfully!" << endl;
    send(clientSocket, "File uploaded successfully!", 26, 0);
}

int main() {
    int serverSocket, clientSocket;
    sockaddr_in serverAddress, clientAddress;
    socklen_t clientAddressSize;

    // Create socket
    serverSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (serverSocket == -1) {
        cerr << "Error creating socket" << endl;
        return 1;
    }

    // Bind socket to address
    memset(&serverAddress, 0, sizeof(serverAddress));
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_addr.s_addr = INADDR_ANY;
    serverAddress.sin_port = htons(PORT);
    if (bind(serverSocket, (sockaddr*)&serverAddress, sizeof(serverAddress)) == -1) {
        cerr << "Error binding socket" << endl;
        return 1;
    }

    // Listen for incoming connections
    if (listen(serverSocket, 5) == -1) {
        cerr << "Error listening for connections" << endl;
        return 1;
    }

    cout << "Server started on port " << PORT << endl;

    while (true) {
        clientAddressSize = sizeof(clientAddress);
        clientSocket = accept(serverSocket, (sockaddr*)&clientAddress, &clientAddressSize);
        if (clientSocket == -1) {
            cerr << "Error accepting connection" << endl;
            continue;
        }

        cout << "Client connected" << endl;
        handleClient(clientSocket);
        close(clientSocket);
    }

    close(serverSocket);
    return 0;
}