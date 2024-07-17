#include <iostream>
#include <fstream>
#include <cstring>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 1234
#define UPLOAD_DIR "uploads/"

void handle_client(int client_socket) {
    char file_name[256];
    int file_name_len;

    recv(client_socket, &file_name_len, sizeof(file_name_len), 0);
    recv(client_socket, file_name, file_name_len, 0);
    file_name[file_name_len] = '\0';

    std::string file_path = std::string(UPLOAD_DIR) + file_name;
    std::ofstream file(file_path, std::ios::binary);

    if (!file) {
        std::cerr << "Failed to create file: " << file_path << std::endl;
        close(client_socket);
        return;
    }

    long file_size;
    recv(client_socket, &file_size, sizeof(file_size), 0);

    char buffer[4096];
    int bytes_read;
    while (file_size > 0 && (bytes_read = recv(client_socket, buffer, sizeof(buffer), 0)) > 0) {
        file.write(buffer, bytes_read);
        file_size -= bytes_read;
    }

    file.close();
    
    const char *message = "File uploaded successfully";
    send(client_socket, message, strlen(message) + 1, 0);

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

    std::cout << "Server listening on port " << PORT << std::endl;

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