
// C doesn't have built-in support for creating web servers or handling CORS.\n// Implementing CORS would typically be done at a higher level using a web framework or library.\n// This example is a basic socket server that sets CORS headers, but it's not a complete solution.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 8080
#define BUFFER_SIZE 1024

int main() {
    int server_fd, new_socket;
    struct sockaddr_in address;
    int addrlen = sizeof(address);
    char buffer[BUFFER_SIZE] = {0};
    char *response = "HTTP/1.1 200 OK\\r\\n"
                     "Access-Control-Allow-Origin: *\\r\\n"
                     "Access-Control-Allow-Methods: GET, POST, PUT, DELETE, OPTIONS\\r\\n"
                     "Access-Control-Allow-Headers: Content-Type\\r\\n"
                     "Content-Type: application/json\\r\\n\\r\\n"
                     "{\\"message\\": \\"This is CORS-enabled data\\"}";

    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    if (listen(server_fd, 3) < 0) {
        perror("listen");
        exit(EXIT_FAILURE);
    }

    while(1) {
        printf("Waiting for a connection...\\n");
        if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen)) < 0) {
            perror("accept");
            exit(EXIT_FAILURE);
        }

        read(new_socket, buffer, BUFFER_SIZE);
        printf("%s\\n", buffer);
        write(new_socket, response, strlen(response));
        close(new_socket);
    }

    return 0;
}
