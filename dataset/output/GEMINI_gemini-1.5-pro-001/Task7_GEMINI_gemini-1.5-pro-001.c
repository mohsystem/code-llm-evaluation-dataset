#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define PORT 8080

int main() {
    int server_fd, client_fd, valread;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);
    char buffer[1024] = {0};

    // Create socket
    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd == 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    // Forcefully attach socket to the port
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt))) {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    // Bind the socket
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    // Listen for connections
    if (listen(server_fd, 3) < 0) {
        perror("listen");
        exit(EXIT_FAILURE);
    }

    // Accept connections
    while ((client_fd = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen))) {
        printf("New connection
");

        // Read from client
        valread = read(client_fd, buffer, 1024);
        printf("Client: %s
", buffer);

        // Basic authentication check
        char *username = strtok(buffer, " ");
        char *password = strtok(NULL, " ");
        if (username != NULL && password != NULL && strcmp(username, "user1") == 0 && strcmp(password, "pass1") == 0) {
            send(client_fd, "Welcome!
", strlen("Welcome!
"), 0);
        } else {
            send(client_fd, "Invalid credentials
", strlen("Invalid credentials
"), 0);
        }

        // Close the connection
        close(client_fd);
    }

    return 0;
}