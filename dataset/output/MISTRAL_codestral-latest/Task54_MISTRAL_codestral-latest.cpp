#include <iostream>
#include <random>
#include <string>

std::string generate_otp() {
    const std::string CHARACTERS = "0123456789";
    const int OTP_LENGTH = 6;
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, CHARACTERS.size() - 1);
    std::string otp;
    for (int i = 0; i < OTP_LENGTH; i++) {
        otp += CHARACTERS[dis(gen)];
    }
    return otp;
}

std::string login(const std::string& username, const std::string& password, const std::string& otp) {
    // Here you would normally check the username and password against a database
    // For this example, we'll just assume they're correct
    if (username == "user" && password == "password") {
        if (otp == generate_otp()) {
            return "Login successful";
        } else {
            return "Invalid OTP";
        }
    } else {
        return "Invalid username or password";
    }
}

// Example usage:
int main() {
    std::cout << login("user", "password", generate_otp()) << std::endl;
    return 0;
}