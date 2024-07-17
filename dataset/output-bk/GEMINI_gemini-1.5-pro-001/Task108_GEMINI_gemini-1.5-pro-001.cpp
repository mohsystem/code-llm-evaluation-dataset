#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <thread>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>

const int PORT = 65432;
const int BUFFER_SIZE = 1024;

class DataObject {
public:
    DataObject(int val) : value(val) {}
    int getValue() const { return value; }
    void setValue(int val) { value = val; }
private:
    int value;
};

std::vector<DataObject> objects;

void handle_client(int client_socket) {
    char buffer[BUFFER_SIZE];

    while (true) {
        memset(buffer, 0, sizeof(buffer)); 
        int bytes_read = recv(client_socket, buffer, sizeof(buffer), 0);
        if (bytes_read <= 0) {
            break;
        }

        std::string request(buffer, bytes_read);
        std::istringstream iss(request);
        std::string command, arg1, arg2;
        iss >> command >> arg1 >> arg2;

        std::string response;

        if (command == "GET") {
            int index = std::stoi(arg1);
            if (index >= 0 && index < objects.size()) {
                response = std::to_string(objects[index].getValue());
            } else {
                response = "Invalid object index";
            }
        } else if (command == "SET") {
            int index = std::stoi(arg1);
            int new_value = std::stoi(arg2);
            if (index >= 0 && index < objects.size()) {
                objects[index].setValue(new_value);
                response = "Value updated";
            } else {
                response = "Invalid object index";
            }
        } else {
            response = "Invalid command";
        }

        send(client_socket, response.c_str(), response.size(), 0);
    }

    close(client_socket);
}

int main() {
    objects.push_back(DataObject(10)); 
    int server_socket, client_socket;
    struct sockaddr_in server_addr, client_addr;
    socklen_t client_addr_size = sizeof(client_addr);

    // Create socket
    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket == -1) {
        std::cerr << "Failed to create socket" << std::endl;
        return 1;
    }

    // Set socket options for reusability
    int optval = 1;
    setsockopt(server_socket, SOL_SOCKET, SO_REUSEADDR, &optval, sizeof(optval));

    // Bind socket to address
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    if (bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        std::cerr << "Failed to bind socket" << std::endl;
        close(server_socket);
        return 1;
    }

    // Listen for connections
    if (listen(server_socket, 5) == -1) {
        std::cerr << "Failed to listen on socket" << std::endl;
        close(server_socket);
        return 1;
    }

    std::cout << "Server started on port " << PORT << std::endl;

    while (true) {
        client_socket = accept(server_socket, (struct sockaddr *)&client_addr, &client_addr_size);
        if (client_socket == -1) {
            std::cerr << "Failed to accept connection" << std::endl;
            continue;
        }
        std::thread client_thread(handle_client, client_socket);
        client_thread.detach();
    }

    close(server_socket);
    return 0;
}