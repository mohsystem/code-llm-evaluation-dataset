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

void *client_handler(void *socket_desc) {
    int sock = *(int*)socket_desc;
    int read_size;
    char client_message[BUFFER_SIZE];

    while((read_size = recv(sock , client_message , BUFFER_SIZE , 0)) > 0) {
        for(int i = 0; i < MAX_CLIENTS; i++) {
            if(client_sockets[i] != 0) {
                if(client_sockets[i] != sock) {
                    send(client_sockets[i] , client_message , strlen(client_message) , 0);
                }
            }
        }
    }

    if(read_size == 0) {
        puts("Client disconnected");
        fflush(stdout);
    } else if(read_size == -1) {
        perror("recv failed");
    }

    return 0;
}

int main(int argc , char *argv[]) {
    int socket_desc , client_sock , c , *new_sock;
    struct sockaddr_in server , client;

    socket_desc = socket(AF_INET , SOCK_STREAM , 0);
    if (socket_desc == -1) {
        printf("Could not create socket");
    }
    puts("Socket created");

    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htons(PORT);

    if(bind(socket_desc,(struct sockaddr *)&server , sizeof(server)) < 0) {
        perror("bind failed. Error");
        return 1;
    }
    puts("bind done");

    listen(socket_desc , 3);

    puts("Waiting for incoming connections...");
    c = sizeof(struct sockaddr_in);

    while((client_sock = accept(socket_desc, (struct sockaddr *)&client, (socklen_t*)&c))) {
        puts("Connection accepted");

        pthread_t sniffer_thread;
        new_sock = malloc(1);
        *new_sock = client_sock;

        if(pthread_create(&sniffer_thread , NULL ,  client_handler , (void*) new_sock) < 0) {
            perror("could not create thread");
            return 1;
        }

        for(int i = 0; i < MAX_CLIENTS; i++) {
            if(client_sockets[i] == 0) {
                client_sockets[i] = client_sock;
                break;
            }
        }
    }

    if (client_sock < 0) {
        perror("accept failed");
        return 1;
    }

    return 0;
}