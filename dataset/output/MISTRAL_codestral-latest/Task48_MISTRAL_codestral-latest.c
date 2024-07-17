// C code for the server
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <pthread.h>

#define PORT 1234
#define MAX_CLIENTS 100
#define BUFFER_SIZE 2048

int client_sockets[MAX_CLIENTS] = {0};
char client_names[MAX_CLIENTS][256] = {0};

void broadcast(char *message, int sender_socket) {
    for (int i = 0; i < MAX_CLIENTS; i++) {
        if (client_sockets[i] != 0 && client_sockets[i] != sender_socket) {
            send(client_sockets[i], message, strlen(message), 0);
        }
    }
}

void *handle_client(void *arg) {
    int client_socket = *(int *)arg;
    char buffer[BUFFER_SIZE] = {0};
    char name[256] = {0};

    recv(client_socket, name, 256, 0);
    strtok(name, "
");

    sprintf(buffer, "%s has joined
", name);
    printf("%s", buffer);
    broadcast(buffer, client_socket);

    while (1) {
        char message[BUFFER_SIZE] = {0};
        int valread = recv(client_socket, message, BUFFER_SIZE, 0);
        if (valread == 0) {
            sprintf(buffer, "%s has left
", name);
            printf("%s", buffer);
            broadcast(buffer, client_socket);
            break;
        }
        sprintf(buffer, "%s: %s", name, message);
        printf("%s", buffer);
        broadcast(buffer, client_socket);
    }

    close(client_socket);
    pthread_exit(NULL);
}

int main(int argc, char const *argv[]) {
    int server_fd, new_socket, valread;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);
    pthread_t thread_id;

    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
        perror("setsockopt");
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

    printf("Chat Server is running...
");

    while (1) {
        if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t *)&addrlen)) < 0) {
            perror("accept");
            exit(EXIT_FAILURE);
        }

        pthread_create(&thread_id, NULL, handle_client, &new_socket);
        pthread_detach(thread_id);
    }

    return 0;
}