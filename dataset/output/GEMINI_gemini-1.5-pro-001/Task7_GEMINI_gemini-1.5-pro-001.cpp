#include <iostream>
#include <string>
#include <vector>
#include <thread>
#include <mutex>
#include <unordered_map>
#include <fstream>
#include <winsock2.h>
#include <ws2tcpip.h>

#pragma comment(lib, "Ws2_32.lib")

using namespace std;

#define PORT 65432

// Global variables
vector<SOCKET> clientSockets;
unordered_map<SOCKET, string> clientUsernames;
mutex clientListMutex;
unordered_map<string, string> users;

// Function to load users from file
void loadUsers() {
    ifstream file("users.txt");
    string line, username, password;

    while (getline(file, line)) {
        stringstream ss(line);
        getline(ss, username, ':');
        getline(ss, password);
        users[username] = password;
    }
}

// Function to handle client connections
void handleClient(SOCKET clientSocket) {
    char buffer[1024];
    string username;

    // Authentication loop
    while (true) {
        // Receive username
        recv(clientSocket, buffer, sizeof(buffer), 0);
        username = string(buffer);

        // Receive password
        recv(clientSocket, buffer, sizeof(buffer), 0);
        string password = string(buffer);

        // Authenticate user
        if (users.find(username) != users.end() && users[username] == password) {
            // Send success message
            send(clientSocket, "Login successful!", 17, 0);

            // Add client to list
            clientListMutex.lock();
            clientSockets.push_back(clientSocket);
            clientUsernames[clientSocket] = username;
            clientListMutex.unlock();

            // Send join message to other clients
            for (SOCKET socket : clientSockets) {
                if (socket != clientSocket) {
                    string message = username + " has joined the chat!";
                    send(socket, message.c_str(), message.length() + 1, 0);
                }
            }

            break;
        } else {
            // Send error message
            send(clientSocket, "Invalid username or password!", 29, 0);
        }
    }

    // Chat loop
    while (true) {
        // Receive message from client
        int bytesReceived = recv(clientSocket, buffer, sizeof(buffer), 0);
        if (bytesReceived == SOCKET_ERROR) {
            break;
        } else if (bytesReceived == 0) {
            // Connection closed
            break;
        }

        // Send message to other clients
        string message = username + ": " + string(buffer, 0, bytesReceived);
        clientListMutex.lock();
        for (SOCKET socket : clientSockets) {
            if (socket != clientSocket) {
                send(socket, message.c_str(), message.length() + 1, 0);
            }
        }
        clientListMutex.unlock();
    }

    // Remove client from list
    clientListMutex.lock();
    clientSockets.erase(remove(clientSockets.begin(), clientSockets.end(), clientSocket), clientSockets.end());
    clientUsernames.erase(clientSocket);
    clientListMutex.unlock();

    // Send leave message to other clients
    for (SOCKET socket : clientSockets) {
        string message = username + " has left the chat!";
        send(socket, message.c_str(), message.length() + 1, 0);
    }

    // Close client socket
    closesocket(clientSocket);
}

int main() {
    // Load users from file
    loadUsers();

    // Initialize Winsock
    WSADATA wsaData;
    int result = WSAStartup(MAKEWORD(2, 2), &wsaData);
    if (result != 0) {
        cerr << "WSAStartup failed: " << result << endl;
        return 1;
    }

    // Create socket
    SOCKET listenSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (listenSocket == INVALID_SOCKET) {
        cerr << "Socket creation failed: " << WSAGetLastError() << endl;
        WSACleanup();
        return 1;
    }

    // Bind socket to address and port
    sockaddr_in serverAddress;
    memset(&serverAddress, 0, sizeof(serverAddress));
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_addr.S_un.S_addr = INADDR_ANY;
    serverAddress.sin_port = htons(PORT);
    result = bind(listenSocket, (sockaddr*)&serverAddress, sizeof(serverAddress));
    if (result == SOCKET_ERROR) {
        cerr << "Bind failed: " << WSAGetLastError() << endl;
        closesocket(listenSocket);
        WSACleanup();
        return 1;
    }

    // Listen for incoming connections
    result = listen(listenSocket, SOMAXCONN);
    if (result == SOCKET_ERROR) {
        cerr << "Listen failed: " << WSAGetLastError() << endl;
        closesocket(listenSocket);
        WSACleanup();
        return 1;
    }

    cout << "Server started on port " << PORT << endl;

    // Accept client connections
    while (true) {
        sockaddr_in clientAddress;
        int clientAddressSize = sizeof(clientAddress);
        SOCKET clientSocket = accept(listenSocket, (sockaddr*)&clientAddress, &clientAddressSize);
        if (clientSocket == INVALID_SOCKET) {
            cerr << "Accept failed: " << WSAGetLastError() << endl;
            continue;
        }

        // Create a new thread to handle the client connection
        thread clientThread(handleClient, clientSocket);
        clientThread.detach();
    }

    // Close listen socket
    closesocket(listenSocket);

    // Clean up Winsock
    WSACleanup();

    return 0;
}