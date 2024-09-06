
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

#define PORT 8080
#define BUFFER_SIZE 1024

void handle_upload(int client_socket) {
    char buffer[BUFFER_SIZE];
    ssize_t bytes_received;
    FILE *file;
    char filename[256];

    // Receive filename
    bytes_received = recv(client_socket, filename, sizeof(filename), 0);
    if (bytes_received <= 0) {
        perror("Error receiving filename");
        return;
    }
    filename[bytes_received] = '\\0';

    char filepath[512];
    snprintf(filepath, sizeof(filepath), "uploads/%s", filename);

    file = fopen(filepath, "wb");
    if (file == NULL) {
        perror("Error opening file");
        return;
    }

    while ((bytes_received = recv(client_socket, buffer, BUFFER_SIZE, 0)) > 0) {
        fwrite(buffer, 1, bytes_received, file);
    }

    fclose(file);

    const char *response = "File uploaded successfully\\n";
    send(client_socket, response, strlen(response), 0);
}

int main() {
    int server_socket, client_socket;
    struct sockaddr_in server_addr, client_addr;
    socklen_t client_len = sizeof(client_addr);

    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket == -1) {
        perror("Error creating socket");
        exit(EXIT_FAILURE);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    if (bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Error binding socket");
        exit(EXIT_FAILURE);
    }

    if (listen(server_socket, 5) < 0) {
        perror("Error listening");
        exit(EXIT_FAILURE);
    }

    printf("Server listening on port %d\\n", PORT);

    while (1) {
        client_socket = accept(server_socket, (struct sockaddr *)&client_addr, &client_len);
        if (client_socket < 0) {
            perror("Error accepting connection");
            continue;
        }

        printf("Client connected: %s\\n", inet_ntoa(client_addr.sin_addr));

        handle_upload(client_socket);

        close(client_socket);
    }

    close(server_socket);
    return 0;
}
