#include <iostream>
#include <fstream>
#include <string>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 8000
#define BUFFER_SIZE 1024

int main() {
    int server_fd, new_socket;
    struct sockaddr_in address;
    int addrlen = sizeof(address);
    char buffer[BUFFER_SIZE] = {0};
    std::ofstream fp;

    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        std::cerr << "socket failed" << std::endl;
        exit(EXIT_FAILURE);
    }

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        std::cerr << "bind failed" << std::endl;
        exit(EXIT_FAILURE);
    }

    if (listen(server_fd, 3) < 0) {
        std::cerr << "listen" << std::endl;
        exit(EXIT_FAILURE);
    }

    if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen)) < 0) {
        std::cerr << "accept" << std::endl;
        exit(EXIT_FAILURE);
    }

    fp.open("uploaded_file", std::ios::binary);
    if (!fp) {
        std::cerr << "fopen" << std::endl;
        exit(EXIT_FAILURE);
    }

    while (read(new_socket, buffer, BUFFER_SIZE) > 0) {
        fp.write(buffer, BUFFER_SIZE);
    }

    fp.close();
    close(new_socket);
    close(server_fd);

    std::cout << "File uploaded successfully!" << std::endl;

    return 0;
}