#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <pthread.h>

#define PORT 65432
#define MAX_CLIENTS 10
#define BUFFER_SIZE 1024

// Structure to hold client information
typedef struct {
    int sockfd;
    char username[BUFFER_SIZE];
} Client;

Client clients[MAX_CLIENTS];
int num_clients = 0;
pthread_mutex_t clients_mutex = PTHREAD_MUTEX_INITIALIZER;

// Function to handle client communication
void *handle_client(void *arg) {
    Client *client = (Client *)arg;
    char buffer[BUFFER_SIZE];

    // Receive and send messages
    while (1) {
        int bytes_received = recv(client->sockfd, buffer, BUFFER_SIZE, 0);
        if (bytes_received <= 0) {
            // Connection closed
            break;
        }
        buffer[bytes_received] = '\0';

        // Broadcast message to other clients
        pthread_mutex_lock(&clients_mutex);
        for (int i = 0; i < num_clients; i++) {
            if (clients[i].sockfd != client->sockfd) {
                send(clients[i].sockfd, buffer, strlen(buffer), 0);
            }
        }
        pthread_mutex_unlock(&clients_mutex);
    }

    // Remove client from list
    pthread_mutex_lock(&clients_mutex);
    for (int i = 0; i < num_clients; i++) {
        if (clients[i].sockfd == client->sockfd) {
            for (int j = i; j < num_clients - 1; j++) {
                clients[j] = clients[j + 1];
            }
            num_clients--;
            break;
        }
    }
    pthread_mutex_unlock(&clients_mutex);

    // Close client socket
    close(client->sockfd);
    free(client);

    pthread_exit(NULL);
}

int main() {
    int server_socket, client_socket;
    struct sockaddr_in server_address, client_address;
    socklen_t client_address_size;

    // Create server socket
    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket == -1) {
        perror("Failed to create server socket");
        exit(1);
    }

    // Set server address
    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(PORT);

    // Bind socket to address
    if (bind(server_socket, (struct sockaddr *)&server_address, sizeof(server_address)) == -1) {
        perror("Failed to bind server socket");
        close(server_socket);
        exit(1);
    }

    // Listen for incoming connections
    if (listen(server_socket, MAX_CLIENTS) == -1) {
        perror("Failed to listen on server socket");
        close(server_socket);
        exit(1);
    }

    printf("Server started on port %d
", PORT);

    // Accept and handle client connections
    while (1) {
        client_address_size = sizeof(client_address);
        client_socket = accept(server_socket, (struct sockaddr *)&client_address, &client_address_size);
        if (client_socket == -1) {
            perror("Failed to accept client connection");
            continue;
        }

        // Create new client
        Client *new_client = (Client *)malloc(sizeof(Client));
        new_client->sockfd = client_socket;

        // Receive username from client
        recv(client_socket, new_client->username, BUFFER_SIZE, 0);

        // Add client to list
        pthread_mutex_lock(&clients_mutex);
        clients[num_clients++] = *new_client;
        pthread_mutex_unlock(&clients_mutex);

        // Create client thread
        pthread_t thread_id;
        pthread_create(&thread_id, NULL, handle_client, (void *)new_client);

        printf("Client connected: %s
", new_client->username);
    }

    // Close server socket
    close(server_socket);

    return 0;
}