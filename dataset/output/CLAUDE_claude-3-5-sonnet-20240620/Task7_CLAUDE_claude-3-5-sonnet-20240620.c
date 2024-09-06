
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <pthread.h>

#define MAX_CLIENTS 10
#define BUFFER_SIZE 1024

typedef struct {
    char username[50];
    char password[50];
} Credentials;

typedef struct {
    char status[10];
    char message[100];
} Response;

void *handle_client(void *arg);
Response authenticate(Credentials creds);

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <s|c>\\n", argv[0]);
        return 1;
    }

    if (strcmp(argv[1], "s") == 0) {
        // Server code
        int server_sock, client_sock;
        struct sockaddr_in server_addr, client_addr;
        socklen_t addr_size;
        pthread_t thread_id;

        server_sock = socket(AF_INET, SOCK_STREAM, 0);
        server_addr.sin_family = AF_INET;
        server_addr.sin_port = htons(5000);
        server_addr.sin_addr.s_addr = INADDR_ANY;

        bind(server_sock, (struct sockaddr*)&server_addr, sizeof(server_addr));
        listen(server_sock, 5);
        printf("Server listening on port 5000\\n");

        while (1) {
            addr_size = sizeof(client_addr);
            client_sock = accept(server_sock, (struct sockaddr*)&client_addr, &addr_size);
            pthread_create(&thread_id, NULL, handle_client, (void*)&client_sock);
        }
    } else if (strcmp(argv[1], "c") == 0) {
        // Client code
        int sock;
        struct sockaddr_in addr;
        Credentials creds;
        Response response;

        sock = socket(AF_INET, SOCK_STREAM, 0);
        addr.sin_family = AF_INET;
        addr.sin_port = htons(5000);
        addr.sin_addr.s_addr = inet_addr("127.0.0.1");

        connect(sock, (struct sockaddr*)&addr, sizeof(addr));

        printf("Enter username: ");
        scanf("%s", creds.username);
        printf("Enter password: ");
        scanf("%s", creds.password);

        send(sock, &creds, sizeof(creds), 0);
        recv(sock, &response, sizeof(response), 0);

        printf("%s\\n", response.message);

        close(sock);
    } else {
        printf("Invalid option. Use 's' for server or 'c' for client.\\n");
    }

    return 0;
}

void *handle_client(void *arg) {
    int client_sock = *(int*)arg;
    Credentials creds;
    Response response;

    recv(client_sock, &creds, sizeof(creds), 0);
    response = authenticate(creds);
    send(client_sock, &response, sizeof(response), 0);

    close(client_sock);
    return NULL;
}

Response authenticate(Credentials creds) {
    Response response;
    FILE *file = fopen("users.txt", "r");
    if (file == NULL) {
        strcpy(response.status, "failure");
        strcpy(response.message, "Error opening users file");
        return response;
    }

    char line[100];
    while (fgets(line, sizeof(line), file)) {
        char username[50], password[50];
        sscanf(line, "%[^:]:%s", username, password);
        if (strcmp(username, creds.username) == 0 && strcmp(password, creds.password) == 0) {
            strcpy(response.status, "success");
            strcpy(response.message, "Login successful");
            fclose(file);
            return response;
        }
    }

    strcpy(response', type='text')