#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <pthread.h>

void *handle_client(void *arg);
void start_server();
void start_client();
void load_users();

typedef struct User {
    char username[50];
    char password[50];
} User;

User users[10];
int user_count = 0;

int main() {
    load_users();
    pthread_t server_thread, client_thread;
    pthread_create(&server_thread, NULL, (void *)start_server, NULL);
    sleep(1); // Ensure server starts first
    pthread_create(&client_thread, NULL, (void *)start_client, NULL);
    pthread_join(server_thread, NULL);
    pthread_join(client_thread, NULL);
    return 0;
}

void start_server() {
    int server_fd, new_socket;
    struct sockaddr_in address;
    int addrlen = sizeof(address);

    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(12345);

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
    printf("Server started on port 12345.
");

    while ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen)) >= 0) {
        pthread_t client_thread;
        int *pclient = malloc(sizeof(int));
        *pclient = new_socket;
        pthread_create(&client_thread, NULL, handle_client, pclient);
    }
}

void *handle_client(void *arg) {
    int client_socket = *((int *)arg);
    free(arg);

    char buffer[1024] = {0};
    read(client_socket, buffer, 1024);

    char *username = strtok(buffer, ",");
    char *password = strtok(NULL, ",");

    for (int i = 0; i < user_count; i++) {
        if (strcmp(users[i].username, username) == 0 && strcmp(users[i].password, password) == 0) {
            send(client_socket, "Login success", strlen("Login success"), 0);
            close(client_socket);
            return NULL;
        }
    }
    send(client_socket, "Login failed", strlen("Login failed"), 0);
    close(client_socket);
    return NULL;
}

void start_client() {
    struct sockaddr_in address;
    struct sockaddr_in serv_addr;
    int sock = 0;
    char buffer[1024] = {0};
    char username[50], password[50];

    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        printf("
 Socket creation error 
");
        return;
    }

    address.sin_family = AF_INET;
    address.sin_port = htons(12345);

    if (inet_pton(AF_INET, "127.0.0.1", &address.sin_addr) <= 0) {
        printf("
Invalid address/ Address not supported 
");
        return;
    }

    if (connect(sock, (struct sockaddr *)&address, sizeof(address)) < 0) {
        printf("
Connection Failed 
");
        return;
    }

    printf("Enter username: ");
    scanf("%s", username);
    printf("Enter password: ");
    scanf("%s", password);

    snprintf(buffer, sizeof(buffer), "%s,%s", username, password);
    send(sock, buffer, strlen(buffer), 0);

    read(sock, buffer, 1024);
    printf("Server response: %s
", buffer);
}

void load_users() {
    strcpy(users[0].username, "user1");
    strcpy(users[0].password, "pass1");
    strcpy(users[1].username, "user2");
    strcpy(users[1].password, "pass2");
    user_count = 2;
}