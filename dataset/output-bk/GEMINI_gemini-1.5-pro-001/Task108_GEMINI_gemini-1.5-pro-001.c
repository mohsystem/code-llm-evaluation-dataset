#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define PORT 65432 
#define BUFFER_SIZE 1024

typedef struct {
    int value;
} DataObject;

void handle_request(int client_socket, DataObject* data_object) {
    char buffer[BUFFER_SIZE];
    int bytes_received = recv(client_socket, buffer, BUFFER_SIZE, 0);
    if (bytes_received <= 0) {
        return;
    }
    buffer[bytes_received] = '\0';

    char command[16];
    sscanf(buffer, "%s", command);

    if (strcmp(command, "GET") == 0) {
        char response[BUFFER_SIZE];
        snprintf(response, BUFFER_SIZE, "%d", data_object->value);
        send(client_socket, response, strlen(response), 0);
    } else if (strcmp(command, "SET") == 0) {
        int new_value;
        sscanf(buffer, "%*s %d", &new_value);
        data_object->value = new_value;
        send(client_socket, "Value updated", 13, 0);
    } else {
        send(client_socket, "Invalid command", 16, 0);
    }
}

int main() {
    int server_socket, client_socket;
    struct sockaddr_in server_address, client_address;
    socklen_t client_address_size = sizeof(client_address);

    // Create socket
    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket == -1) {
        perror("Failed to create socket");
        exit(1);
    }

    // Bind socket to address
    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY; 
    server_address.sin_port = htons(PORT); 

    if (bind(server_socket, (struct sockaddr*)&server_address, sizeof(server_address)) == -1) {
        perror("Bind failed");
        close(server_socket);
        exit(1);
    }

    // Listen for connections
    if (listen(server_socket, 5) == -1) {
        perror("Listen failed");
        close(server_socket);
        exit(1);
    }

    printf("Server started on port %d
", PORT);

    DataObject data_object = {10}; 

    while (1) {
        // Accept a connection
        client_socket = accept(server_socket, (struct sockaddr*)&client_address, &client_address_size);
        if (client_socket == -1) {
            perror("Accept failed");
            continue;
        }
        // Handle the request
        handle_request(client_socket, &data_object);

        close(client_socket); 
    }

    // Close the server socket
    close(server_socket);

    return 0;
}