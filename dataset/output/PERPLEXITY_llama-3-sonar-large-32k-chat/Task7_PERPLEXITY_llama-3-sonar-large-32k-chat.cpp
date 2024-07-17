// Server side
#include <iostream>
#include <string>
#include <fstream>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 8000

using namespace std;

bool authenticate(string username, string password) {
    // Implement authentication logic here
    // For demonstration purposes, assume authentication is successful
    return true;
}

int main() {
    int server_fd, new_socket;
    struct sockaddr_in address;
    int addrlen = sizeof(address);
    char buffer[1024] = {0};

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
    string credentials(buffer);
    size_t commaPos = credentials.find(",");
    string username = credentials.substr(0, commaPos);
    string password = credentials.substr(commaPos + 1);
    if (authenticate(username, password)) {
        send(new_socket, "Login successful!", 13, 0);
    } else {
        send(new_socket, "Invalid credentials", 17, 0);
    }

    return 0;
}

// Client side
#include <iostream>
#include <string>
#include <fstream>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 8000

using namespace std;

int main() {
    int sock = 0;
    struct sockaddr_in serv_addr;
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

    cout << "Enter username: ";
    string username;
    getline(cin, username);

    cout << "Enter password: ";
    string password;
    getline(cin, password);

    string credentials = username + "," + password;
    send(sock, credentials.c_str(), credentials.length(), 0);

    int valread = read(sock, buffer, 1024);
    cout << buffer << endl;

    return 0;
}