
#include <iostream>
#include <string>
#include <unordered_map>
#include <random>
#include <iomanip>

class TwoFactorAuth {
private:
    std::unordered_map<std::string, std::string> users;
    std::unordered_map<std::string, std::string> otps;
    std::random_device rd;
    std::mt19937 gen;

public:
    TwoFactorAuth() : gen(rd()) {}

    void registerUser(const std::string& username, const std::string& password) {
        users[username] = password;
    }

    bool login(const std::string& username, const std::string& password) {
        if (users.find(username) != users.end() && users[username] == password) {
            std::string otp = generateOTP();
            otps[username] = otp;
            std::cout << "OTP sent: " << otp << std::endl;
            return true;
        }
        return false;
    }

    bool verifyOTP(const std::string& username, const std::string& enteredOTP) {
        if (otps.find(username) != otps.end() && otps[username] == enteredOTP) {
            otps.erase(username);
            return true;
        }
        return false;
    }

private:
    std::string generateOTP() {
        std::uniform_int_distribution<> dis(0, 999999);
        return std::to_string(dis(gen));
    }
};

int main() {
    TwoFactorAuth auth;
    std::string username, password, otp;

    // Register a user
    std::cout << "Register - Enter username: ";
    std::cin >> username;
    std::cout << "Enter password: ";
    std::cin >> password;
    auth.registerUser(username, password);

    // Login
    std::cout << "Login - Enter username: ";
    std::cin >> username;
    std::cout << "Enter password: ";
    std::cin >> password;

    if (auth.login(username, password)) {
        std::cout << "Enter OTP: ";
        std::cin >> otp;

        if (auth.verifyOTP(username, otp)) {
            std::cout << "Login successful!" << std::endl;
        } else {
            std::cout << "Invalid OTP. Login failed." << std::endl;
        }
    } else {
        std::cout << "Invalid username or password." << std::endl;
    }

    return 0;
}
