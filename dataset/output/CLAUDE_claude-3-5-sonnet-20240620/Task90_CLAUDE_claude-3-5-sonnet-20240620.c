
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <pthread.h>

#define MAX_CLIENTS 10
#define BUFFER_SIZE 1024
#define PORT 5555

int clients[MAX_CLIENTS];
int client_count = 0;

pthread_mutex_t clients_mutex = PTHREAD_MUTEX_INITIALIZER;

void broadcast(char *message, int sender_sd) {
    pthread_mutex_lock(&clients_mutex);
    for (int i = 0; i < client_count; i++) {
        if (clients[i] != sender_sd) {
            send(clients[i], message, strlen(message), 0);
        }
    }
    pthread_mutex_unlock(&clients_mutex);
}

void *handle_client(void *arg) {
    int client_sd = *(int*)arg;
    char buffer[BUFFER_SIZE];
    
    while (1) {
        int bytes_received = recv(client_sd, buffer, BUFFER_SIZE, 0);
        if (bytes_received <= 0) {
            break;
        }
        buffer[bytes_received] = '\\0';
        printf("Received: %s\\n", buffer);
        broadcast(buffer, client_sd);
    }
    
    pthread_mutex_lock(&clients_mutex);
    for (int i = 0; i < client_count; i++) {
        if (clients[i] == client_sd) {
            for (int j = i; j < client_count - 1; j++) {
                clients[j] = clients[j+1];
            }
            client_count--;
            break;
        }
    }
    pthread_mutex_unlock(&clients_mutex);
    
    close(client_sd);
    free(arg);
    return NULL;
}

int main() {
    int server_sd, client_sd;
    struct sockaddr_in server_addr, client_addr;
    socklen_t addr_size;
    pthread_t tid;
    
    server_sd = socket(AF_INET, SOCK_STREAM, 0);
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    server_addr.sin_addr.s_addr = INADDR_ANY;
    
    bind(server_sd, (struct sockaddr*)&server_addr, sizeof(server_addr));
    listen(server_sd, 5);
    
    printf("Server is listening on port %d\\n", PORT);
    
    while (1) {
        addr_size = sizeof(client_addr);
        client_sd = accept(server_sd, (struct sockaddr*)&client_addr, &addr_size);
        
        pthread_mutex_lock(&clients_mutex);
        if (client_count < MAX_CLIENTS) {
            clients[client_count++] = client_sd;
            int *pclient = malloc(sizeof(int));
            *pclient = client_sd;
            pthread_create(&tid, NULL, handle_client, pclient);
            printf("New client connected\\n");
        } else {
            printf("Max clients reached. Connection rejected.\\n");
            close(client_sd);
        }
        pthread_mutex_unlock(&clients_mutex);
    }
    
    return 0;
}
