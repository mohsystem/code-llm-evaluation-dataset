#include <iostream>
#include <cstdlib>
#include <ctime>

int generateOTP() {
    return 100000 + std::rand() % 900000;
}

bool verifyOTP(int userOTP, int actualOTP) {
    return userOTP == actualOTP;
}

int main() {
    std::srand(std::time(nullptr));
    
    std::string username, password;
    std::cout << "Enter username: ";
    std::cin >> username;
    std::cout << "Enter password: ";
    std::cin >> password;

    // Simulate verifying username and password
    if (username == "user" && password == "pass") {
        int otp = generateOTP();
        std::cout << "Your OTP is: " << otp << std::endl;
        int userOTP;
        std::cout << "Enter the OTP you received: ";
        std::cin >> userOTP;
        if (verifyOTP(userOTP, otp)) {
            std::cout << "Login successful!" << std::endl;
        } else {
            std::cout << "Invalid OTP!" << std::endl;
        }
    } else {
        std::cout << "Invalid username or password!" << std::endl;
    }

    return 0;
}