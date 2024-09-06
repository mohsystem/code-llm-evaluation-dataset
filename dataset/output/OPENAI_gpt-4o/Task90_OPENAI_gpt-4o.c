#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <pthread.h>

int clients[100];
int n = 0;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

void *handle_client(void *client_socket) {
    int sock = *(int *)client_socket;
    char message[1024];
    
    while (1) {
        int len = recv(sock, message, sizeof(message), 0);
        if (len <= 0) {
            pthread_mutex_lock(&mutex);
            for (int i = 0; i < n; i++) {
                if (clients[i] == sock) {
                    for (int j = i; j < n - 1; j++) {
                        clients[j] = clients[j + 1];
                    }
                    break;
                }
            }
            n--;
            pthread_mutex_unlock(&mutex);
            close(sock);
            pthread_exit(0);
        }
        message[len] = '\0';
        printf("Received: %s\n", message);
        
        pthread_mutex_lock(&mutex);
        for (int i = 0; i < n; i++) {
            if (clients[i] != sock) {
                send(clients[i], message, len, 0);
            }
        }
        pthread_mutex_unlock(&mutex);
    }
}

int main() {
    int server_socket = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(5555);
    server_addr.sin_addr.s_addr = INADDR_ANY;

    bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr));
    listen(server_socket, 10);
    printf("Server started, waiting for clients...\n");

    while (1) {
        int client_socket = accept(server_socket, NULL, NULL);
        pthread_mutex_lock(&mutex);
        clients[n++] = client_socket;
        pthread_mutex_unlock(&mutex);

        pthread_t thread;
        pthread_create(&thread, NULL, handle_client, &client_socket);
    }

    return 0;
}