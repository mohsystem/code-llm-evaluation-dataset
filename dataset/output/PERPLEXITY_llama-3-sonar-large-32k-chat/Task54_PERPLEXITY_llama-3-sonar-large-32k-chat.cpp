#include <iostream>
#include <cstdlib>
#include <ctime>

int main() {
    srand(static_cast<unsigned int>(time(0)));
    int otp = rand() % 900000 + 100000;

    std::string username;
    std::string password;

    std::cout << "Enter username: ";
    std::cin >> username;
    std::cout << "Enter password: ";
    std::cin >> password;

    if (username == "admin" && password == "password") {
        std::cout << "One Time Password (OTP) is: " << otp << std::endl;
        int userOtp;
        std::cout << "Enter OTP: ";
        std::cin >> userOtp;

        if (userOtp == otp) {
            std::cout << "Login successful!" << std::endl;
        } else {
            std::cout << "Invalid OTP. Login failed." << std::endl;
        }
    } else {
        std::cout << "Invalid username or password. Login failed." << std::endl;
    }

    return 0;
}