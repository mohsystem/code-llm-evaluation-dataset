#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 7896
#define BUFFER_SIZE 1024

typedef struct {
    char key[256];
    char value[256];
} Object;

Object objects[100];
int object_count = 0;

void handle_client(int new_socket) {
    char buffer[BUFFER_SIZE];
    read(new_socket, buffer, BUFFER_SIZE);
    char action[10], key[256], value[256];
    sscanf(buffer, "%s %s %s", action, key, value);

    if (strcmp(action, "put") == 0) {
        strcpy(objects[object_count].key, key);
        strcpy(objects[object_count].value, value);
        object_count++;
        write(new_socket, "Success", strlen("Success"));
    } else if (strcmp(action, "get") == 0) {
        for (int i = 0; i < object_count; i++) {
            if (strcmp(objects[i].key, key) == 0) {
                write(new_socket, objects[i].value, strlen(objects[i].value));
                break;
            }
        }
    }

    close(new_socket);
    return;
}

int main() {
    int server_fd, new_socket;
    struct sockaddr_in address;
    int addrlen = sizeof(address);

    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("bind failed");
        close(server_fd);
        exit(EXIT_FAILURE);
    }

    if (listen(server_fd, 3) < 0) {
        perror("listen");
        close(server_fd);
        exit(EXIT_FAILURE);
    }

    while ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen)) >= 0) {
        handle_client(new_socket);
    }

    close(server_fd);
    return 0;
}