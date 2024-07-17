#include <iostream>
#include <map>
#include <string>

class UserSession {
private:
    std::string username;
    bool loggedIn;

public:
    UserSession(const std::string& username) : username(username), loggedIn(false) {}

    void login() {
        loggedIn = true;
        std::cout << username << " has logged in." << std::endl;
    }

    void logout() {
        loggedIn = false;
        std::cout << username << " has logged out." << std::endl;
    }
};

int main() {
    std::map<std::string, UserSession> sessions;
    while (true) {
        std::cout << "1. Create session" << std::endl;
        std::cout << "2. Login" << std::endl;
        std::cout << "3. Logout" << std::endl;
        std::cout << "4. Exit" << std::endl;
        int choice;
        std::cout << "Choose an option: ";
        std::cin >> choice;
        if (choice == 1) {
            std::string username;
            std::cout << "Enter username: ";
            std::cin >> username;
            sessions[username] = UserSession(username);
            std::cout << "Session created for " << username << "." << std::endl;
        } else if (choice == 2) {
            std::string username;
            std::cout << "Enter username: ";
            std::cin >> username;
            if (sessions.find(username) != sessions.end()) {
                sessions[username].login();
            } else {
                std::cout << "Session not found." << std::endl;
            }
        } else if (choice == 3) {
            std::string username;
            std::cout << "Enter username: ";
            std::cin >> username;
            if (sessions.find(username) != sessions.end()) {
                sessions[username].logout();
            } else {
                std::cout << "Session not found." << std::endl;
            }
        } else if (choice == 4) {
            break;
        } else {
            std::cout << "Invalid option. Please try again." << std::endl;
        }
    }
    return 0;
}