code here:
#include <iostream>
#include <string>
#include <vector>

class User {
private:
    std::string username;
    std::string password;

public:
    User(std::string username, std::string password) : username(username), password(password) {}

    bool authenticate(std::string username, std::string password) {
        if (this->username == username && this->password == password) {
            return true;
        } else {
            return false;
        }
    }
};

int main() {
    std::vector<User> users = {{User("user1", "password1"), User("user2", "password2")}};
    std::string username, password;
    std::cout << "Enter username: ";
    std::cin >> username;
    std::cout << "Enter password: ";
    std::cin >> password;
    for (const auto& user : users) {
        if (user.authenticate(username, password)) {
            std::cout << "Authentication successful!" << std::endl;
            return 0;
        }
    }
    std::cout << "Invalid credentials!" << std::endl;
    return 0;
}