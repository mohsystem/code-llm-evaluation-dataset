#include <iostream>
#include <vector>
#include <string>

class User {
public:
    std::string username;
    std::string password;

    User(std::string uname, std::string pass) : username(uname), password(pass) {}
};

std::vector<User> database;

void signup(std::string username, std::string password) {
    database.push_back(User(username, password));
    std::cout << "User signed up successfully" << std::endl;
}

int main() {
    std::string username, password;
    std::cout << "Enter username: ";
    std::cin >> username;
    std::cout << "Enter password: ";
    std::cin >> password;
    signup(username, password);
    return 0;
}