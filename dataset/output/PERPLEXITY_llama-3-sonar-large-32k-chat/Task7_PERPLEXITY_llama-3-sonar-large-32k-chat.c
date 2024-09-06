// C Code (Server)
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <stdbool.h>

bool authenticate(const char* username, const char* password) {
    FILE* file = fopen("users.txt", "r");
    char line[1024];
    while (fgets(line, 1024, file)) {
        char* colonPos = strchr(line, ':');
        if (colonPos != NULL) {
            *colonPos = '\0';
            char* user = line;
            char* pwd = colonPos + 1;
            if (strcmp(user, username) == 0 && strcmp(pwd, password) == 0) {
                fclose(file);
                return true;
            }
        }
    }
    fclose(file);
    return false;
}

int main() {
    int serverSocket = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in serverAddress;
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_port = htons(10000);
    inet_pton(AF_INET, "127.0.0.1", &serverAddress.sin_addr);

    bind(serverSocket, (struct sockaddr *)&serverAddress, sizeof(serverAddress));
    listen(serverSocket, 1);

    printf("Server started. Waiting for connections...\n");
    int connection = accept(serverSocket, NULL, NULL);
    printf("Connected to client\n");

    char buffer[1024];
    while (true) {
        recv(connection, buffer, 1024, 0);
        char* data = buffer;
        if (strstr(data, "LOGIN") == data) {
            char* spacePos = strchr(data, ' ');
            if (spacePos != NULL) {
                *spacePos = '\0';
                char* username = data + 6; // "LOGIN "
                spacePos = strchr(username, ' ');
                if (spacePos != NULL) {
                    *spacePos = '\0';
                    char* password = spacePos + 1;
                    if (authenticate(username, password)) {
                        send(connection, "LOGIN_SUCCESS", 12, 0);
                    } else {
                        send(connection, "LOGIN_FAILED", 12, 0);
                    }
                }
            }
        } else {
            printf("Received message: %s\n", data);
            char response[1024];
            sprintf(response, "Server received your message: %s", data);
            send(connection, response, strlen(response), 0);
        }
    }

    return 0;
}