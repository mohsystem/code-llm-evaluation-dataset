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

struct client_info {
    int sockfd;
    char username[BUFFER_SIZE];
};

struct client_info clients[MAX_CLIENTS];
int client_count = 0;
pthread_mutex_t clients_mutex = PTHREAD_MUTEX_INITIALIZER;

void *handle_client(void *arg) {
    struct client_info *client = (struct client_info *)arg;
    char buffer[BUFFER_SIZE];
    int bytes_received;

    // Receive and broadcast messages from the client
    while ((bytes_received = recv(client->sockfd, buffer, BUFFER_SIZE, 0)) > 0) {
        buffer[bytes_received] = '\0';
        printf("Received from %s: %s\n", client->username, buffer);

        // Broadcast the message to all other clients
        pthread_mutex_lock(&clients_mutex);
        for (int i = 0; i < client_count; i++) {
            if (clients[i].sockfd != client->sockfd) {
                send(clients[i].sockfd, buffer, bytes_received, 0);
            }
        }
        pthread_mutex_unlock(&clients_mutex);
    }

    // Handle client disconnection
    printf("Client %s disconnected.\n", client->username);
    pthread_mutex_lock(&clients_mutex);
    for (int i = 0; i < client_count; i++) {
        if (clients[i].sockfd == client->sockfd) {
            for (int j = i; j < client_count - 1; j++) {
                clients[j] = clients[j + 1];
            }
            client_count--;
            break;
        }
    }
    pthread_mutex_unlock(&clients_mutex);
    close(client->sockfd);
    free(client);

    return NULL;
}

int main() {
    int server_socket, client_socket;
    struct sockaddr_in server_address, client_address;
    socklen_t client_address_size;
    pthread_t thread_id;

    // Create a socket
    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket == -1) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Set address information
    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(PORT);

    // Bind the socket to the address
    if (bind(server_socket, (struct sockaddr *)&server_address, sizeof(server_address)) == -1) {
        perror("Socket binding failed");
        close(server_socket);
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    if (listen(server_socket, MAX_CLIENTS) == -1) {
        perror("Listening on socket failed");
        close(server_socket);
        exit(EXIT_FAILURE);
    }

    printf("Server started on port %d\n", PORT);

    while (1) {
        client_address_size = sizeof(client_address);

        // Accept a client connection
        client_socket = accept(server_socket, (struct sockaddr *)&client_address, &client_address_size);
        if (client_socket == -1) {
            perror("Accepting client connection failed");
            continue;
        }

        // Create a new client info structure
        struct client_info *client = (struct client_info *)malloc(sizeof(struct client_info));
        if (client == NULL) {
            perror("Memory allocation failed");
            close(client_socket);
            continue;
        }
        client->sockfd = client_socket;

        // Receive the client's username
        recv(client->sockfd, client->username, BUFFER_SIZE, 0);
        client->username[strcspn(client->username, "\r\n")] = 0;

        // Add the client to the list of clients
        pthread_mutex_lock(&clients_mutex);
        clients[client_count] = *client;
        client_count++;
        pthread_mutex_unlock(&clients_mutex);

        // Create a new thread to handle the client
        if (pthread_create(&thread_id, NULL, handle_client, (void *)client) != 0) {
            perror("Thread creation failed");
            close(client_socket);
            free(client);
            continue;
        }

        // Detach the thread
        pthread_detach(thread_id);

        printf("Client %s connected.\n", client->username);
    }

    // Close the server socket
    close(server_socket);

    return 0;
}