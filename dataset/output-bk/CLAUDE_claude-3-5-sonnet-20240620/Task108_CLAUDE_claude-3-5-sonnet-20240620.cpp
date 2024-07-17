
#include <iostream>
#include <string>
#include <cstring>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>

#define PORT 8080
#define BUFFER_SIZE 1024

class RemoteObject {
private:
    int value;

public:
    RemoteObject() : value(0) {}

    int getValue() const { return value; }
    void setValue(int newValue) { value = newValue; }
};

RemoteObject obj;

void handle_client(int client_socket) {
    char buffer[BUFFER_SIZE] = {0};
    int valread = read(client_socket, buffer, BUFFER_SIZE);
    
    std::string request(buffer);
    if (request.substr(0, 3) == "GET") {
        std::string response = std::to_string(obj.getValue());
        send(client_socket, response.c_str(), response.length(), 0);
    } else if (request.substr(0, 3) == "SET") {
        int newValue = std::stoi(request.substr(4));
        obj.setValue(newValue);
        send(client_socket, "OK", 2, 0);
    }
}

int main() {
    int server_fd, new_socket;
    struct sockaddr_in address;
    int addrlen = sizeof(address);
    
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        std::cerr << "Socket failed" << std::endl;
        exit(EXIT_FAILURE);
    }
    
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);
    
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        std::cerr << "Bind failed" << std::endl;
        exit(EXIT_FAILURE);
    }
    
    if (listen(server_fd, 3) < 0) {
        std::cerr << "Listen failed" << std::endl;
        exit(EXIT_FAILURE);
    }
    
    std::cout << "Server is running on port " << PORT << "..." << std::endl;
    
    while(true) {
        if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen)) < 0) {
            std::cerr << "Accept failed" << std::endl;
            exit(EXIT_FAILURE);
        }
        
        handle_client(new_socket);
        close(new_socket);
    }
    
    return 0;
}
