// Server side
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 8000

int main() {
    int server_fd, new_socket;
    struct sockaddr_in address;
    int addrlen = sizeof(address);
    char buffer[1024] = {0};
    char *hello = "Hello from server";

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
        perror("listen failed");
        exit(EXIT_FAILURE);
    }

    if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen)) < 0) {
        perror("accept failed");
        exit(EXIT_FAILURE);
    }

    int valread = read(new_socket, buffer, 1024);
    printf("%s
", buffer);
    char *username = strtok(buffer, ",");
    char *password = strtok(NULL, ",");
    if (authenticate(username, password)) {
        send(new_socket, "Login successful!", 13, 0);
    } else {
        send(new_socket, "Invalid credentials", 17, 0);
    }

    return 0;
}

int authenticate(char *username, char *password) {
    // Implement authentication logic here
    // For demonstration purposes, assume authentication is successful
    return 1;
}

// Client side
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 8000

int main() {
    int sock = 0;
    struct sockaddr_in serv_addr;
    char *hello = "Hello from client";
    char buffer[1024] = {0};

    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        printf("
 Socket creation error 
");
        return -1;
    }

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);

    if (inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr) <= 0) {
        printf("
Invalid address/ Address not supported 
");
        return -1;
    }

    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        printf("
Connection Failed 
");
        return -1;
    }

    printf("Enter username: ");
    char username[1024];
    fgets(username, 1024, stdin);
    username[strcspn(username, "
")] = 0; // remove newline character

    printf("Enter password: ");
    char password[1024];
    fgets(password, 1024, stdin);
    password[strcspn(password, "
")] = 0; // remove newline character

    send(sock, username, strlen(username), 0);
    send(sock, ",", 1, 0);
    send(sock, password, strlen(password), 0);

    int valread = read(sock, buffer, 1024);
    printf("%s
", buffer);

    return 0;
}