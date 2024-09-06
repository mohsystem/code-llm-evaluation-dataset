// C - Server
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <pthread.h>

#define PORT 12345
#define BUFFER_SIZE 1024

void *handle_client(void *socket_desc) {
    int sock = *(int *)socket_desc;
    free(socket_desc);
    char buffer[BUFFER_SIZE];
    char message[BUFFER_SIZE];
    ssize_t read_size;
    
    while ((read_size = recv(sock, buffer, BUFFER_SIZE - 1, 0)) > 0) {
        buffer[read_size] = '\0';
        
        char *delimiter = strchr(buffer, ':');
        if (!delimiter) {
            strcpy(message, "Invalid format. Use username:password\n");
            send(sock, message, strlen(message), 0);
            continue;
        }
        
        *delimiter = '\0';
        char *username = buffer;
        char *password = delimiter + 1;
        
        FILE *users_file = fopen("users.txt", "r");
        if (!users_file) {
            strcpy(message, "Unable to open users.txt\n");
            send(sock, message, strlen(message), 0);
            break;
        }
        
        char users_line[BUFFER_SIZE];
        int auth = 0;
        while (fgets(users_line, BUFFER_SIZE, users_file)) {
            users_line[strcspn(users_line, "\r\n")] = 0;
            if (strcmp(users_line, buffer) == 0) {
                auth = 1;
                break;
            }
        }
        fclose(users_file);
        
        if (auth) {
            strcpy(message, "Login successful\n");
        } else {
            strcpy(message, "Login failed\n");
        }
        
        send(sock, message, strlen(message), 0);
    }
    
    close(sock);
    return 0;
}


int main() {
    int server_fd, new_socket, *new_sock;
    struct sockaddr_in address;
    int addrlen = sizeof(address);
    
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("Socket failed");
        exit(EXIT_FAILURE);
    }
    
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);
    
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("Bind failed");
        exit(EXIT_FAILURE);
    }
    
    if (listen(server_fd, 3) < 0) {
        perror("Listen failed");
        exit(EXIT_FAILURE);
    }
    
    printf("Server listening on port %d\n", PORT);
    
    while ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t *)&addrlen))) {
        printf("Connection accepted\n");

        pthread_t sniffer_thread;
        new_sock = malloc(1);
        *new_sock = new_socket;

        if (pthread_create(&sniffer_thread, NULL, handle_client, (void *)new_sock) < 0) {
            perror("Thread creation failed");
            return 1;
        }
        
        pthread_detach(sniffer_thread);
    }
    
    if (new_socket < 0) {
        perror("Accept failed");
        exit(EXIT_FAILURE);
    }
    
    return 0;
}