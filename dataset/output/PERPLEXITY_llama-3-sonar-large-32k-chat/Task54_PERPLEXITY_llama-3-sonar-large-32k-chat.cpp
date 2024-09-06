#include <iostream>
#include <ctime>
#include <cstdlib>

std::string generateOTP() {
    srand(static_cast<unsigned int>(time(0)));
    return std::to_string(rand() % 900000 + 100000);
}

std::string authenticate(std::string username, std::string password, std::string otp) {
    if (username == "admin" && password == "password" && otp == generateOTP()) {
        return "Authentication successful";
    } else {
        return "Authentication failed";
    }
}

int main() {
    std::string username, password, otp;
    std::cout << "Enter username: ";
    std::cin >> username;
    std::cout << "Enter password: ";
    std::cin >> password;
    std::cout << "Enter OTP: ";
    std::cin >> otp;
    std::cout << authenticate(username, password, otp) << std::endl;
    return 0;
}