// Note: This code is not a real API endpoint, but a simple console-based program that stores user data in a file.
#include <iostream>
#include <fstream>
#include <string>

int main() {
    std::string name, email;
    std::cout << "Enter name: ";
    std::getline(std::cin, name);
    std::cout << "Enter email: ";
    std::getline(std::cin, email);

    std::ofstream file("users.txt", std::ios::app);
    file << name << "," << email << std::endl;
    file.close();

    std::cout << "User created successfully!" << std::endl;
    return 0;
}