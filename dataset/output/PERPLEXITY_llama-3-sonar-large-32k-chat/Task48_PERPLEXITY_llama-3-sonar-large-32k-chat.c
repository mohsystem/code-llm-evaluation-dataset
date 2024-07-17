#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 8000
#define BUFFER_SIZE 1024

void broadcast(char* message, int clients[], int numClients) {
    for (int i = 0; i < numClients; i++) {
        send(clients[i], message, strlen(message), 0);
    }
}

int main() {
    int serverSocket, clientSocket;
    struct sockaddr_in serverAddress, clientAddress;
    int addrlen = sizeof(clientAddress);
    char buffer[BUFFER_SIZE];
    int clients[10];
    int numClients = 0;

    serverSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (serverSocket < 0) {
        perror("socket failed");
        exit(1);
    }

    serverAddress.sin_family = AF_INET;
    serverAddress.sin_addr.s_addr = INADDR_ANY;
    serverAddress.sin_port = htons(PORT);

    if (bind(serverSocket, (struct sockaddr*)&serverAddress, sizeof(serverAddress)) < 0) {
        perror("bind failed");
        exit(1);
    }

    if (listen(serverSocket, 3) < 0) {
        perror("listen failed");
        exit(1);
    }

    printf("Server started. Waiting for clients...
");

    while (1) {
        clientSocket = accept(serverSocket, (struct sockaddr*)&clientAddress, &addrlen);
        if (clientSocket < 0) {
            perror("accept failed");
            continue;
        }

        printf("Client connected
");
        clients[numClients++] = clientSocket;

        while (1) {
            recv(clientSocket, buffer, BUFFER_SIZE, 0);
            printf("Received from client: %s
", buffer);
            broadcast(buffer, clients, numClients);
        }
    }

    return 0;
}