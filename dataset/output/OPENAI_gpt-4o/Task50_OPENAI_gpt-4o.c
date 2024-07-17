#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 1234
#define UPLOAD_DIR "uploads/"

void handle_client(int client_socket) {
    char file_name[256];
    int file_name_len;

    read(client_socket, &file_name_len, sizeof(file_name_len));
    read(client_socket, file_name, file_name_len);
    file_name[file_name_len] = '\0';

    FILE *file;
    char file_path[512];
    snprintf(file_path, sizeof(file_path), UPLOAD_DIR "%s", file_name);
    file = fopen(file_path, "wb");

    if (!file) {
        perror("fopen");
        close(client_socket);
        exit(1);
    }

    long file_size;
    read(client_socket, &file_size, sizeof(file_size));

    char buffer[4096];
    int bytes_read;
    while (file_size > 0 && (bytes_read = read(client_socket, buffer, sizeof(buffer))) > 0) {
        fwrite(buffer, 1, bytes_read, file);
        file_size -= bytes_read;
    }

    fclose(file);

    const char *message = "File uploaded successfully";
    write(client_socket, message, strlen(message) + 1);

    close(client_socket);
}

int main() {
    struct sockaddr_in server_addr, client_addr;
    socklen_t client_addr_len = sizeof(client_addr);
    int server_socket = socket(AF_INET, SOCK_STREAM, 0);

    if (server_socket == -1) {
        perror("socket");
        exit(1);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    server_addr.sin_addr.s_addr = INADDR_ANY;

    if (bind(server_socket, (struct sockaddr*)&server_addr, sizeof(server_addr)) == -1) {
        perror("bind");
        exit(1);
    }

    if (listen(server_socket, 5) == -1) {
        perror("listen");
        exit(1);
    }

    printf("Server listening on port %d
", PORT);

    while (1) {
        int client_socket = accept(server_socket, (struct sockaddr*)&client_addr, &client_addr_len);
        if (client_socket == -1) {
            perror("accept");
            continue;
        }

        handle_client(client_socket);
    }

    close(server_socket);
    return 0;
}