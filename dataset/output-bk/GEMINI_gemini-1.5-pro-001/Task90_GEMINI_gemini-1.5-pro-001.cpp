#include <iostream>
#include <string>
#include <thread>
#include <vector>
#include <mutex>
#include <WS2tcpip.h>

#pragma comment(lib, "ws2_32.lib")

using namespace std;

// Global variables
vector<pair<SOCKET, string>> clients; // List of connected clients (socket, username)
mutex clientsMutex; // Mutex for accessing the clients list

// Function to handle client communication
void handleClient(SOCKET clientSocket) {
    // Receive and send messages
    char buffer[4096];
    string username;

    // Receive username
    int bytesReceived = recv(clientSocket, buffer, 4095, 0);
    if (bytesReceived > 0) {
        buffer[bytesReceived] = '\0';
        username = string(buffer);

        // Send welcome message
        string welcomeMessage = "Welcome, " + username + "!\r
";
        send(clientSocket, welcomeMessage.c_str(), welcomeMessage.size() + 1, 0);

        // Notify other clients about the new connection
        {
            lock_guard<mutex> lock(clientsMutex);
            for (auto& client : clients) {
                if (client.first != clientSocket) {
                    string connectionMessage = username + " has joined the chat.\r
";
                    send(client.first, connectionMessage.c_str(), connectionMessage.size() + 1, 0);
                }
            }
        }

        // Add client to the list
        {
            lock_guard<mutex> lock(clientsMutex);
            clients.push_back(make_pair(clientSocket, username));
        }

        // Receive and broadcast messages
        while (true) {
            bytesReceived = recv(clientSocket, buffer, 4095, 0);

            if (bytesReceived > 0) {
                buffer[bytesReceived] = '\0';
                string message = username + ": " + string(buffer);

                // Broadcast message to all clients
                {
                    lock_guard<mutex> lock(clientsMutex);
                    for (auto& client : clients) {
                        if (client.first != clientSocket) {
                            send(client.first, message.c_str(), message.size() + 1, 0);
                        }
                    }
                }
            }
            else {
                // Client disconnected
                closesocket(clientSocket);

                // Remove client from the list
                {
                    lock_guard<mutex> lock(clientsMutex);
                    clients.erase(remove_if(clients.begin(), clients.end(),
                        [&](const pair<SOCKET, string>& c) { return c.first == clientSocket; }),
                        clients.end());
                }

                // Notify other clients about the disconnection
                string disconnectMessage = username + " has left the chat.\r
";
                {
                    lock_guard<mutex> lock(clientsMutex);
                    for (auto& client : clients) {
                        send(client.first, disconnectMessage.c_str(), disconnectMessage.size() + 1, 0);
                    }
                }

                break;
            }
        }
    }
}

int main() {
    // Initialize Winsock
    WSADATA wsData;
    WORD ver = MAKEWORD(2, 2);

    int wsOk = WSAStartup(ver, &wsData);
    if (wsOk != 0) {
        cerr << "Can't initialize Winsock! Error: " << wsOk << endl;
        return 1;
    }

    // Create a socket
    SOCKET listeningSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (listeningSocket == INVALID_SOCKET) {
        cerr << "Can't create a socket! Error: " << WSAGetLastError() << endl;
        WSACleanup();
        return 1;
    }

    // Bind the socket to an IP address and port
    sockaddr_in hint;
    hint.sin_family = AF_INET;
    hint.sin_port = htons(65432);
    hint.sin_addr.S_un.S_addr = INADDR_ANY;

    if (bind(listeningSocket, (sockaddr*)&hint, sizeof(hint)) == SOCKET_ERROR) {
        cerr << "Can't bind to IP/port! Error: " << WSAGetLastError() << endl;
        closesocket(listeningSocket);
        WSACleanup();
        return 1;
    }

    // Tell the socket to listen for connections
    if (listen(listeningSocket, SOMAXCONN) == SOCKET_ERROR) {
        cerr << "Can't listen on socket! Error: " << WSAGetLastError() << endl;
        closesocket(listeningSocket);
        WSACleanup();
        return 1;
    }

    cout << "Server started. Listening on port 65432..." << endl;

    // Accept and handle client connections
    fd_set master;
    FD_ZERO(&master);
    FD_SET(listeningSocket, &master);

    while (true) {
        fd_set copy = master;
        int socketCount = select(0, &copy, nullptr, nullptr, nullptr);

        for (int i = 0; i < socketCount; i++) {
            SOCKET socket = copy.fd_array[i];

            if (socket == listeningSocket) {
                // Accept a new connection
                sockaddr_in clientAddr;
                int clientSize = sizeof(clientAddr);
                SOCKET clientSocket = accept(listeningSocket, (sockaddr*)&clientAddr, &clientSize);

                if (clientSocket == INVALID_SOCKET) {
                    cerr << "Error accepting client connection! Error: " << WSAGetLastError() << endl;
                    continue;
                }

                // Add the new connection to the master set
                FD_SET(clientSocket, &master);

                // Create a thread to handle the client
                thread clientThread(handleClient, clientSocket);
                clientThread.detach();
            }
        }
    }

    // Close the listening socket
    closesocket(listeningSocket);

    // Clean up Winsock
    WSACleanup();

    return 0;
}