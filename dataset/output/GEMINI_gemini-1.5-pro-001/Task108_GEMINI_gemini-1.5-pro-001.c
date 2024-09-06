#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <pthread.h>

#define PORT 5000

// Structure to represent an object
typedef struct {
    char name[50];
    int value;
} Object;

// Global object store
Object objects[100];
int object_count = 0;

// Function to handle client requests
void *handle_client(void *arg) {
    int client_socket = *(int *)arg;
    char buffer[1024];

    while (1) {
        // Receive command from client
        int bytes_received = recv(client_socket, buffer, sizeof(buffer), 0);
        if (bytes_received <= 0) {
            break;
        }

        // Parse command and arguments
        char command[50];
        char arg1[50], arg2[50];
        sscanf(buffer, "%s %s %s", command, arg1, arg2);

        // Process command
        if (strcmp(command, "CREATE") == 0) {
            // Create a new object
            Object new_object;
            strcpy(new_object.name, arg1);
            new_object.value = atoi(arg2);
            objects[object_count++] = new_object;
            send(client_socket, "Object created", 14, 0);
        } else if (strcmp(command, "GET") == 0) {
            // Get object value
            for (int i = 0; i < object_count; i++) {
                if (strcmp(objects[i].name, arg1) == 0) {
                    char response[100];
                    sprintf(response, "Value: %d", objects[i].value);
                    send(client_socket, response, strlen(response), 0);
                    break;
                }
            }
        } else if (strcmp(command, "SET") == 0) {
            // Set object value
            for (int i = 0; i < object_count; i++) {
                if (strcmp(objects[i].name, arg1) == 0) {
                    objects[i].value = atoi(arg2);
                    send(client_socket, "Value updated", 13, 0);
                    break;
                }
            }
        } else {
            send(client_socket, "Invalid command", 16, 0);
        }
    }

    close(client_socket);
    pthread_exit(NULL);
}

int main() {
    int server_socket, client_socket;
    struct sockaddr_in server_address, client_address;
    socklen_t client_address_size;
    pthread_t thread_id;

    // Create socket
    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket == -1) {
        perror("Failed to create socket");
        exit(1);
    }

    // Set server address
    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(PORT);

    // Bind socket to address
    if (bind(server_socket, (struct sockaddr *)&server_address, sizeof(server_address)) == -1) {
        perror("Failed to bind socket");
        close(server_socket);
        exit(1);
    }

    // Listen for incoming connections
    if (listen(server_socket, 5) == -1) {
        perror("Failed to listen on socket");
        close(server_socket);
        exit(1);
    }

    printf("Server started on port %d\n", PORT);

    while (1) {
        client_address_size = sizeof(client_address);

        // Accept incoming connection
        client_socket = accept(server_socket, (struct sockaddr *)&client_address, &client_address_size);
        if (client_socket == -1) {
            perror("Failed to accept client connection");
            continue;
        }

        // Create a new thread to handle the client
        if (pthread_create(&thread_id, NULL, handle_client, (void *)&client_socket) != 0) {
            perror("Failed to create thread");
            close(client_socket);
            continue;
        }

        // Detach the thread
        pthread_detach(thread_id);
    }

    // Close server socket
    close(server_socket);

    return 0;
}