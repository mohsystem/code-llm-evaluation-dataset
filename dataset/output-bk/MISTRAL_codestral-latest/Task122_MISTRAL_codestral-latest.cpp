// C++

#include <iostream>
#include <fstream>
#include <string>

void signup() {
    std::string username, password;
    std::cout << "Enter username: ";
    std::cin >> username;
    std::cout << "Enter password: ";
    std::cin >> password;
    // In a real-world application, you would hash the password before storing it.
    // For simplicity, we're storing it as is.
    std::ofstream outfile;
    outfile.open("passwords.txt", std::ios_base::app);
    outfile << username << ":" << password << "
";
    outfile.close();
}

int main() {
    signup();
    return 0;
}