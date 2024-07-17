
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

#define PORT 5000
#define MAX_USERS 100
#define MAX_USERNAME 50
#define MAX_PASSWORD 50

typedef struct {
    char username[MAX_USERNAME];
    char password[MAX_PASSWORD];
} User;

User users[MAX_USERS];
int user_count = 0;

void load_users() {
    FILE *file = fopen("users.txt", "r");
    if (file == NULL) {
        perror("Error opening users file");
        exit(1);
    }

    char line[MAX_USERNAME + MAX_PASSWORD + 2];
    while (fgets(line, sizeof(line), file) && user_count < MAX_USERS) {
        char *username = strtok(line, ":");
        char *password = strtok(NULL, "\
");
        
        if (username && password) {
            strncpy(users[user_count].username, username, MAX_USERNAME);
            strncpy(users[user_count].password, password, MAX_PASSWORD);
            user_count++;
        }
    }

    fclose(file);
}

int authenticate(const char *username, const char *password) {
    for (int i = 0; i < user_count; i++) {
        if (strcmp(users[i].username, username) == 0 && strcmp(users[i].password, password) == 0) {
            return 1;
        }
    }
    return 0;
}

void handle_client(int client_socket) {
    char buffer[1024] = {0};
    read(client_socket, buffer, 1024);

    char *token = strtok(buffer, "|");
    if (strcmp(token, "LOGIN") == 0) {
        char *username = strtok(NULL, "|");
        char *password = strtok(NULL, "|");

        if (authenticate(username, password)) {
            send(client_socket, "LOGIN_SUCCESS", strlen("LOGIN_SUCCESS"), 0);
        } else {
            send(client_socket, "LOGIN_FAILED", strlen("LOGIN_FAILED"), 0);
        }
    }

    close(client_socket);
}

int main() {
    load_users();

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
        exit(EXIT_FAILURE);
    }

    if (listen(server_fd, 3) < 0) {
        perror("listen");
        exit(EXIT_FAILURE);
    }

    printf("Server started on port %d\
", PORT);

    while (1) {
        if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen)) < 0) {
            perror("accept");
            exit(EXIT_FAILURE);
        }

        handle_client(new_socket);
    }

    return 0;
}

// Client code
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 5000

int main() {
    int sock = 0;
    struct sockaddr_in serv_addr;
    char buffer[1024] = {0};
    char username[50], password[50];

    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        printf("\
 Socket creation error \
");
        return -1;
    }

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);

    if (inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr) <= 0) {
        printf("\
Invalid address/ Address not supported \
");
        return -1;
    }

    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        printf("\
Connection Failed \
");
        return -1;
    }

    printf("Enter username: ");
    fgets(username, sizeof(username), stdin);
    username[strcspn(username, "\
")] = 0;

    printf("Enter password: ");
    fgets(password, sizeof(password), stdin);
    password[strcspn(password, "\
")] = 0;

    sprintf(buffer, "LOGIN|%s|%s", username, password);
    send(sock, buffer, strlen(buffer), 0);
    
    memset(buffer, 0, sizeof(buffer));
    read(sock, buffer, 1024);
    printf("Server response: %s\
", buffer);

    return 0;
}
