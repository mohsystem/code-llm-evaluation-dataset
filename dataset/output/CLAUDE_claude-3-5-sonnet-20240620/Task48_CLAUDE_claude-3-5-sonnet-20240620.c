
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <pthread.h>

#define MAX_CLIENTS 10
#define BUFFER_SIZE 1024
#define PORT 5000

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
        buffer[bytes_received] = \'\\0\';
        broadcast(buffer, client_sd);
    }
}

int main() {
    int server_sd = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in server_addr;
    
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);
    
    bind(server_sd, (struct sockaddr*)&server_addr, sizeof(server_addr));
    listen(server_sd, 10);
    
    printf("Chat Server is running...\
");
    
    while (1) {
        int *client_sd = malloc(sizeof(int));
        *client_sd = accept(server_sd, NULL, NULL);
        
        pthread_mutex_lock(&clients_mutex);
        if (client_count < MAX_CLIENTS) {
            clients[client_count++] = *client_sd;
            pthread_t thread;
            pthread_create(&thread, NULL, handle_client, client_sd);
            pthread_detach(thread);
        } else {
            printf("Max clients reached. Rejecting new connection.\
");
            close(*client_sd);
            free(client_sd);
        }
        pthread_mutex_unlock(&clients_mutex);
    }
    
    return 0;
}

// Chat Client
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <pthread.h>

#define BUFFER_SIZE 1024
#define SERVER_IP "127.0.0.1"
#define SERVER_PORT 5000

void *receive_messages(void *socket_desc) {
    int sock = *(int*)socket_desc;
    char buffer[BUFFER_SIZE];
    int read_size;
    
    while ((read_size = recv(sock, buffer, BUFFER_SIZE, 0)) > 0) {
        buffer[read_size] = \'\\0\';
        printf("%s", buffer);
    }
    
    if (read_size == 0) {
        printf("Server disconnected\
");
    } else if (read_size == -1) {
        perror("recv failed");
    }
    
    return NULL;
}

int main() {
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in server_addr;
    
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = inet_addr(SERVER_IP);
    server_addr.sin_port = htons(SERVER_PORT);
    
    if (connect(sock, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        perror("Connect failed");
        return 1;
    }
    
    printf("Connected to server\
");
    
    pthread_t recv_thread;
    if (pthread_create(&recv_thread, NULL, receive_messages, (void*)&sock) < 0) {
        perror("Could not create thread");
        return 1;
    }
    
    char message[BUFFER_SIZE];
    while (fgets(message, BUFFER_SIZE, stdin) != NULL) {
        if (send(sock, message, strlen(message), 0) < 0) {
            perror("Send failed");
            return 1;
        }
    }
    
    close(sock);
    return 0;
}
