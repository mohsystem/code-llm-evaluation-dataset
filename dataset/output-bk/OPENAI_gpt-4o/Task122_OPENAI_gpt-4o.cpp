#include <iostream>
#include <unordered_map>
#include <string>

std::unordered_map<std::string, std::string> passwords;

void signup(const std::string& username, const std::string& password) {
    passwords[username] = password;
    std::cout << "Signup successful!" << std::endl;
}

int main() {
    std::string username, password;
    std::cout << "Enter Username: ";
    std::cin >> username;
    std::cout << "Enter Password: ";
    std::cin >> password;
    signup(username, password);
    return 0;
}