
#include <iostream>
#include <string>
#include <unordered_map>
#include <ctime>
#include <random>
#include <algorithm>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>

class Session {
public:
    std::string id;
    std::string username;
    time_t creation_time;
    time_t last_access_time;

    Session(const std::string& user) : username(user) {
        id = generate_session_id();
        creation_time = time(nullptr);
        last_access_time = creation_time;
    }

private:
    std::string generate_session_id() {
        const char charset[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> dis(0, sizeof(charset) - 2);

        std::string id(32, 0);
        std::generate_n(id.begin(), 32, [&]() { return charset[dis(gen)]; });
        return id;
    }
};

class SessionManager {
private:
    std::unordered_map<std::string, Session> sessions;
    const int SESSION_TIMEOUT = 1800; // 30 minutes in seconds

public:
    std::string create_session(const std::string& username) {
        Session session(username);
        sessions[session.id] = session;
        return session.id;
    }

    bool validate_session(const std::string& session_id) {
        auto it = sessions.find(session_id);
        if (it != sessions.end()) {
            time_t current_time = time(nullptr);
            if (current_time - it->second.last_access_time <= SESSION_TIMEOUT) {
                it->second.last_access_time = current_time;
                return true;
            } else {
                terminate_session(session_id);
            }
        }
        return false;
    }

    void terminate_session(const std::string& session_id) {
        sessions.erase(session_id);
    }
};

int main() {
    SessionManager session_manager;
    int server_fd, new_socket;
    struct sockaddr_in address;
    int addrlen = sizeof(address);
    char buffer[1024] = {0};

    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        std::cerr << "Socket creation error" << std::endl;
        return -1;
    }

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(8080);

    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        std::cerr << "Bind failed" << std::endl;
        return -1;
    }

    if (listen(server_fd, 3) < 0) {
        std::cerr << "Listen failed" << std::endl;
        return -1;
    }

    std::cout << "Server started on port 8080" << std::endl;

    while (true) {
        if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen)) < 0) {
            std::cerr << "Accept failed" << std::endl;
            continue;
        }

        read(new_socket, buffer, 1024);
        std::string request(buffer);
        std::string action = request.substr(0, request.find(" "));
        std::string arg = request.substr(request.find(" ") + 1);

        if (action == "LOGIN") {
            std::string session_id = session_manager.create_session(arg);
            std::string response = "Session created: " + session_id + "\
";
            send(new_socket, response.c_str(), response.length(), 0);
        } else if (action == "VALIDATE") {
            bool is_valid = session_manager.validate_session(arg);
            std::string response = "Session valid: " + std::string(is_valid ? "true" : "false") + "\
";
            send(new_socket, response.c_str(), response.length(), 0);
        } else if (action == "LOGOUT") {
            session_manager.terminate_session(arg);
            send(new_socket, "Session terminated\
", 19, 0);
        } else {
            send(new_socket, "Invalid action\
", 15, 0);
        }

        close(new_socket);
    }

    return 0;
}
