#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

void echo_message(int client_socket) {
    char buffer[1024];
    int n;
    while ((n = read(client_socket, buffer, sizeof(buffer)-1)) > 0) {
        buffer[n] = '\0';
        if (send(client_socket, buffer, n, 0) != n) {
            perror("send failed");
            exit(1);
        }
    }
}

int main() {
    // C Code Block
    int server_socket, client_socket;
    struct sockaddr_in server_addr, client_addr;
    socklen_t client_len;

    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(8081);

    if (bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Bind failed");
        exit(EXIT_FAILURE);
    }

    if (listen(server_socket, 5) < 0) {
        perror("Listen failed");
        exit(EXIT_FAILURE);
    }

    printf("C Server listening on port 8081...
");

    client_len = sizeof(client_addr);
    while (1) {
        client_socket = accept(server_socket, (struct sockaddr *)&client_addr, &client_len);
        if (client_socket >= 0) {
            echo_message(client_socket);
            close(client_socket);
        } else {
            perror("Accept failed");
            exit(EXIT_FAILURE);
        }
    }

    close(server_socket);
    return 0;
}