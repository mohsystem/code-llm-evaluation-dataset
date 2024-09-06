
#include <iostream>
#include <string>
#include <random>
#include <chrono>

std::string generateOTP() {
    const std::string DIGITS = "0123456789";
    const int OTP_LENGTH = 6;
    std::string otp;
    
    std::mt19937 rng(std::chrono::steady_clock::now().time_since_epoch().count());
    std::uniform_int_distribution<int> dist(0, DIGITS.length() - 1);
    
    for (int i = 0; i < OTP_LENGTH; ++i) {
        otp += DIGITS[dist(rng)];
    }
    return otp;
}

void sendOTP(const std::string& otp) {
    std::cout << "OTP sent: " << otp << std::endl;
}

bool verifyOTP(const std::string& userOTP, const std::string& generatedOTP) {
    return userOTP == generatedOTP;
}

void login() {
    std::string username, password;
    
    std::cout << "Enter username: ";
    std::cin >> username;
    std::cout << "Enter password: ";
    std::cin >> password;
    
    if (username == "user" && password == "password") {
        std::string otp = generateOTP();
        sendOTP(otp);
        
        std::string userOTP;
        std::cout << "Enter OTP: ";
        std::cin >> userOTP;
        
        if (verifyOTP(userOTP, otp)) {
            std::cout << "Login successful!" << std::endl;
        } else {
            std::cout << "Invalid OTP. Login failed." << std::endl;
        }
    } else {
        std::cout << "Invalid username or password." << std::endl;
    }
}

int main() {
    login();
    return 0;
}
