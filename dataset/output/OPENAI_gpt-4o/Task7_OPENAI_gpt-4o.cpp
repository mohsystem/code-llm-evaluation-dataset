#include <iostream>
#include <cstring>
#include <unistd.h>
#include <arpa/inet.h>
#include <pthread.h>

using namespace std;

void *handle_client(void *arg);
void start_server();
void start_client();
void load_users();

struct User {
    string username;
    string password;
};

User users[10];
int user_count = 0;

int main() {
    load_users();
    pthread_t server_thread, client_thread;
    pthread_create(&server_thread, NULL, reinterpret_cast<void *(*)(void *)>(start_server), NULL);
    sleep(1); // Ensure server starts first
    pthread_create(&client_thread, NULL, reinterpret_cast<void *(*)(void *)>(start_client), NULL);
    pthread_join(server_thread, NULL);
    pthread_join(client_thread, NULL);
    return 0;
}

void start_server() {
    int server_fd, new_socket;
    struct sockaddr_in address;
    int addrlen = sizeof(address);

    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(12345);

    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("bind failed");
        close(server_fd);
        exit(EXIT_FAILURE);
    }

    if (listen(server_fd, 3) < 0) {
        perror("listen");
        close(server_fd);
        exit(EXIT_FAILURE);
    }
    cout << "Server started on port 12345." << endl;

    while ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen)) >= 0) {
        pthread_t client_thread;
        int *pclient = new int;
        *pclient = new_socket;
        pthread_create(&client_thread, NULL, handle_client, pclient);
    }
}

void *handle_client(void *arg) {
    int client_socket = *((int *)arg);
    delete reinterpret_cast<int *>(arg);

    char buffer[1024] = {0};
    read(client_socket, buffer, 1024);

    string request(buffer);
    auto delimiter_pos = request.find(',');
    string username = request.substr(0, delimiter_pos);
    string password = request.substr(delimiter_pos + 1);

    for (int i = 0; i < user_count; i++) {
        if (users[i].username == username && users[i].password == password) {
            send(client_socket, "Login success", strlen("Login success"), 0);
            close(client_socket);
            return NULL;
        }
    }
    send(client_socket, "Login failed", strlen("Login failed"), 0);
    close(client_socket);
    return NULL;
}

void start_client() {
    struct sockaddr_in address;
    int sock = 0;
    char buffer[1024] = {0};
    
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        cout << "Socket creation error" << endl;
        return;
    }

    address.sin_family = AF_INET;
    address.sin_port = htons(12345);

    if (inet_pton(AF_INET, "127.0.0.1", &address.sin_addr) <= 0) {
        cout << "Invalid address/ Address not supported" << endl;
        return;
    }

    if (connect(sock, (struct sockaddr *)&address, sizeof(address)) < 0) {
        cout << "Connection Failed" << endl;
        return;
    }

    string username, password;
    cout << "Enter username: ";
    cin >> username;
    cout << "Enter password: ";
    cin >> password;

    string request = username + "," + password;
    send(sock, request.c_str(), request.length(), 0);

    read(sock, buffer, 1024);
    cout << "Server response: " << buffer << endl;
}

void load_users() {
    users[0] = {"user1", "pass1"};
    users[1] = {"user2", "pass2"};
    user_count = 2;
}