#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define PORT 65432
#define BUFFER_SIZE 1024

int main() {
    int server_socket, client_socket;
    struct sockaddr_in server_address, client_address;
    socklen_t client_address_size;
    char buffer[BUFFER_SIZE];

    // Create socket
    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket == -1) {
        perror("Failed to create socket");
        exit(1);
    }

    // Set address information
    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(PORT);

    // Bind socket to address
    if (bind(server_socket, (struct sockaddr *)&server_address, sizeof(server_address)) == -1) {
        perror("Failed to bind socket");
        close(server_socket);
        exit(1);
    }

    // Listen for incoming connections
    if (listen(server_socket, 5) == -1) {
        perror("Failed to listen on socket");
        close(server_socket);
        exit(1);
    }

    printf("Server started on port %d
", PORT);

    while (1) {
        client_address_size = sizeof(client_address);

        // Accept connection from client
        client_socket = accept(server_socket, (struct sockaddr *)&client_address, &client_address_size);
        if (client_socket == -1) {
            perror("Failed to accept client connection");
            continue;
        }

        printf("Client connected: %s:%d
", inet_ntoa(client_address.sin_addr), ntohs(client_address.sin_port));

        // Receive file name
        int bytes_received = recv(client_socket, buffer, BUFFER_SIZE, 0);
        if (bytes_received <= 0) {
            perror("Failed to receive file name");
            close(client_socket);
            continue;
        }
        buffer[bytes_received] = '\0';
        char file_name[BUFFER_SIZE];
        strcpy(file_name, buffer);

        // Receive file size
        bytes_received = recv(client_socket, buffer, BUFFER_SIZE, 0);
        if (bytes_received <= 0) {
            perror("Failed to receive file size");
            close(client_socket);
            continue;
        }
        buffer[bytes_received] = '\0';
        long file_size = strtol(buffer, NULL, 10);

        // Open file for writing
        FILE *file = fopen(file_name, "wb");
        if (file == NULL) {
            perror("Failed to open file for writing");
            close(client_socket);
            continue;
        }

        // Receive and write file data
        long total_bytes_received = 0;
        while (total_bytes_received < file_size) {
            bytes_received = recv(client_socket, buffer, BUFFER_SIZE, 0);
            if (bytes_received <= 0) {
                perror("Failed to receive file data");
                break;
            }

            fwrite(buffer, 1, bytes_received, file);
            total_bytes_received += bytes_received;
        }

        // Close file
        fclose(file);

        // Send confirmation message
        if (total_bytes_received == file_size) {
            send(client_socket, "File uploaded successfully!", strlen("File uploaded successfully!"), 0);
            printf("File '%s' uploaded successfully!
", file_name);
        } else {
            send(client_socket, "Error uploading file", strlen("Error uploading file"), 0);
            printf("Error uploading file '%s'
", file_name);
        }

        // Close client socket
        close(client_socket);
    }

    // Close server socket
    close(server_socket);

    return 0;
}