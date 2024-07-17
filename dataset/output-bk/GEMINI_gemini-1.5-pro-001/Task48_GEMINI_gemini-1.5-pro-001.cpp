#include <iostream>
#include <thread>
#include <vector>
#include <string>
#include <mutex>
#include <WS2tcpip.h>

#pragma comment (lib, "ws2_32.lib")

using namespace std;

const int PORT = 65432;
vector<thread> clientThreads;
vector<SOCKET> clientSockets;
mutex clientsMutex;

void handleClient(SOCKET clientSocket) {
    char buffer[4096];

    while (true) {
        int bytesReceived = recv(clientSocket, buffer, 4096, 0);
        if (bytesReceived == SOCKET_ERROR) {
            break;
        }
        if (bytesReceived == 0) {
            // Client disconnected
            break;
        }

        // Broadcast the message to other clients
        clientsMutex.lock();
        for (SOCKET otherSocket : clientSockets) {
            if (otherSocket != clientSocket) {
                send(otherSocket, buffer, bytesReceived, 0);
            }
        }
        clientsMutex.unlock();
    }

    // Remove the client from the list
    clientsMutex.lock();
    clientSockets.erase(remove(clientSockets.begin(), clientSockets.end(), clientSocket), clientSockets.end());
    clientsMutex.unlock();

    closesocket(clientSocket);
}

int main() {
    // Initialize Winsock
    WSADATA wsData;
    int result = WSAStartup(MAKEWORD(2, 2), &wsData);
    if (result != 0) {
        cerr << "WSAStartup failed with error: " << result << endl;
        return 1;
    }

    // Create a socket
    SOCKET listenSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (listenSocket == INVALID_SOCKET) {
        cerr << "Socket creation failed with error: " << WSAGetLastError() << endl;
        WSACleanup();
        return 1;
    }

    // Bind the socket to an address and port
    sockaddr_in serverAddress;
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_addr.S_un.S_addr = INADDR_ANY;
    serverAddress.sin_port = htons(PORT);
    if (bind(listenSocket, (sockaddr*)&serverAddress, sizeof(serverAddress)) == SOCKET_ERROR) {
        cerr << "Bind failed with error: " << WSAGetLastError() << endl;
        closesocket(listenSocket);
        WSACleanup();
        return 1;
    }

    // Listen for incoming connections
    if (listen(listenSocket, SOMAXCONN) == SOCKET_ERROR) {
        cerr << "Listen failed with error: " << WSAGetLastError() << endl;
        closesocket(listenSocket);
        WSACleanup();
        return 1;
    }

    cout << "Server started on port " << PORT << endl;

    // Accept and handle client connections
    while (true) {
        sockaddr_in clientAddress;
        int clientSize = sizeof(clientAddress);
        SOCKET clientSocket = accept(listenSocket, (sockaddr*)&clientAddress, &clientSize);
        if (clientSocket == INVALID_SOCKET) {
            cerr << "Accept failed with error: " << WSAGetLastError() << endl;
            continue;
        }

        clientsMutex.lock();
        clientSockets.push_back(clientSocket);
        clientsMutex.unlock();

        // Create a thread to handle the client
        clientThreads.push_back(thread(handleClient, clientSocket));
    }

    // Close the listening socket and clean up Winsock
    closesocket(listenSocket);
    WSACleanup();

    return 0;
}