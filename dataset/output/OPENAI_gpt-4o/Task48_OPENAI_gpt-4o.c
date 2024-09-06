#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
#include <arpa/inet.h>

#define PORT 5555
#define MAX_CLIENTS 100

int client_sockets[MAX_CLIENTS];
int client_count = 0;
pthread_mutex_t clients_mutex = PTHREAD_MUTEX_INITIALIZER;

void broadcast(const char* message, int sender_socket) {
    pthread_mutex_lock(&clients_mutex);
    for (int i = 0; i < client_count; ++i) {
        if (client_sockets[i] != sender_socket) {
            send(client_sockets[i], message, strlen(message), 0);
        }
    }
    pthread_mutex_unlock(&clients_mutex);
}

void* handle_client(void* arg) {
    int client_socket = *(int*)arg;
    char buffer[1024];
    while (1) {
        int bytes_received = recv(client_socket, buffer, 1024, 0);
        if (bytes_received <= 0) {
            close(client_socket);
            pthread_mutex_lock(&clients_mutex);
            for (int i = 0; i < client_count; ++i) {
                if (client_sockets[i] == client_socket) {
                    for (int j = i; j < client_count - 1; ++j) {
                        client_sockets[j] = client_sockets[j + 1];
                    }
                    --client_count;
                    break;
                }
            }
            pthread_mutex_unlock(&clients_mutex);
            break;
        } else {
            buffer[bytes_received] = '\0';
            broadcast(buffer, client_socket);
        }
    }
    free(arg);
    return NULL;
}

int main() {
    int server_socket, new_socket;
    struct sockaddr_in server_address;
    socklen_t addr_len = sizeof(server_address);

    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(PORT);

    bind(server_socket, (struct sockaddr*)&server_address, sizeof(server_address));
    listen(server_socket, MAX_CLIENTS);

    printf("Server started...\n");

    while (1) {
        new_socket = accept(server_socket, (struct sockaddr*)&server_address, &addr_len);
        pthread_mutex_lock(&clients_mutex);
        client_sockets[client_count++] = new_socket;
        pthread_mutex_unlock(&clients_mutex);
        printf("Connection established.\n");

        pthread_t thread;
        int* pclient = malloc(sizeof(int));
        *pclient = new_socket;
        pthread_create(&thread, NULL, handle_client, pclient);
        pthread_detach(thread);
    }

    return 0;
}