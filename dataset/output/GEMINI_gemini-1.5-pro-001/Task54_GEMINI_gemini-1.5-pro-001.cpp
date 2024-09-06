#include <iostream>
#include <string>
#include <random>
#include <chrono>

// Note: Sending emails from C++ requires external libraries. 
//       This example focuses on OTP generation and verification.

std::string generateOTP(int length = 6) {
    std::string digits = "0123456789";
    std::random_device rd;
    std::mt19937 generator(rd());
    std::uniform_int_distribution<> distribution(0, digits.size() - 1);

    std::string otp;
    for (int i = 0; i < length; ++i) {
        otp += digits[distribution(generator)];
    }
    return otp;
}

int main() {
    std::string username, password;

    std::cout << "Username: ";
    std::cin >> username;
    std::cout << "Password: ";
    std::cin >> password;

    // Simulate user authentication (replace with your actual authentication logic)
    if (username == "user" && password == "password") {
        std::string otp = generateOTP();

        // In a real application, send the OTP via email or SMS here.
        std::cout << "OTP: " << otp << std::endl; // Displaying for demo purposes

        std::string enteredOTP;
        std::cout << "Enter OTP: ";
        std::cin >> enteredOTP;

        if (enteredOTP == otp) {
            std::cout << "Two-factor authentication successful. Logged in!" << std::endl;
        } else {
            std::cout << "Incorrect OTP. Access denied." << std::endl;
        }
    } else {
        std::cout << "Invalid username or password." << std::endl;
    }

    return 0;
}