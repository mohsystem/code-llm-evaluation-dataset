#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

void retrieveFile(const char* fileName) {
    int clientSocket = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in serverAddress;
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_port = htons(12345);
    inet_pton(AF_INET, "127.0.0.1", &serverAddress.sin_addr);
    connect(clientSocket, (struct sockaddr*)&serverAddress, sizeof(serverAddress));
    send(clientSocket, fileName, strlen(fileName), 0);
    char buffer[1024];
    int bytesRead;
    if ((bytesRead = recv(clientSocket, buffer, 1024, 0)) == -1) {
        printf("File not found on the server\n");
    } else {
        FILE* file = fopen(fileName, "wb");
        while ((bytesRead = recv(clientSocket, buffer, 1024, 0)) > 0) {
            fwrite(buffer, 1, bytesRead, file);
        }
        fclose(file);
    }
    close(clientSocket);
}

int main() {
    printf("Enter the file name: ");
    char fileName[256];
    scanf("%255s", fileName);
    retrieveFile(fileName);
    return 0;
}