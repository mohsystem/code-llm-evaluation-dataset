#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define PORT 65432
#define BUFFER_SIZE 1024

void handle_client(int client_socket) {
    char buffer[BUFFER_SIZE];
    char filename[BUFFER_SIZE];
    long file_size;

    // Receive filename
    if (recv(client_socket, filename, BUFFER_SIZE, 0) <= 0) {
        perror("Error receiving filename");
        return;
    }

    // Receive filesize
    if (recv(client_socket, buffer, BUFFER_SIZE, 0) <= 0) {
        perror("Error receiving filesize");
        return;
    }
    file_size = strtol(buffer, NULL, 10);

    printf("Receiving file: %s (%ld bytes)\n", filename, file_size);

    // Open file for writing
    FILE *fp = fopen(filename, "wb");
    if (fp == NULL) {
        perror("Error opening file");
        return;
    }

    // Receive and write file data
    long total_bytes_received = 0;
    while (total_bytes_received < file_size) {
        int bytes_received = recv(client_socket, buffer, BUFFER_SIZE, 0);
        if (bytes_received <= 0) {
            perror("Error receiving file data");
            break;
        }

        fwrite(buffer, 1, bytes_received, fp);
        total_bytes_received += bytes_received;
    }

    fclose(fp);

    printf("%s uploaded successfully!\n", filename);
    send(client_socket, "File uploaded successfully!", 26, 0);
}

int main() {
    int server_socket, client_socket;
    struct sockaddr_in server_address, client_address;
    socklen_t client_address_size = sizeof(client_address);

    // Create socket
    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket == -1) {
        perror("Error creating socket");
        exit(1);
    }

    // Bind socket to address
    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(PORT);
    if (bind(server_socket, (struct sockaddr *)&server_address, sizeof(server_address)) == -1) {
        perror("Error binding socket");
        close(server_socket);
        exit(1);
    }

    // Listen for connections
    if (listen(server_socket, 5) == -1) {
        perror("Error listening for connections");
        close(server_socket);
        exit(1);
    }

    printf("Server started on port %d\n", PORT);

    while (1) {
        // Accept connection
        client_socket = accept(server_socket, (struct sockaddr *)&client_address, &client_address_size);
        if (client_socket == -1) {
            perror("Error accepting connection");
            continue;
        }

        printf("Client connected\n");

        // Handle client request
        handle_client(client_socket);

        // Close client socket
        close(client_socket);
    }

    // Close server socket
    close(server_socket);

    return 0;
}