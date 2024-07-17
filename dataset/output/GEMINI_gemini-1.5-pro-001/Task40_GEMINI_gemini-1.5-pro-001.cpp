#include <iostream>
#include <string>
#include <random>
#include <sstream>
#include <iomanip>

// Function to generate a random CSRF token
std::string generate_csrf_token() {
    std::random_device rd;
    std::mt19937 generator(rd());
    std::uniform_int_distribution<int> distribution(0, 255);

    std::stringstream ss;
    for (int i = 0; i < 32; ++i) {
        ss << std::hex << std::setw(2) << std::setfill('0') << distribution(generator);
    }
    return ss.str();
}

// Function to verify a CSRF token
bool verify_csrf_token(const std::string& request_token, const std::string& session_token) {
    return request_token == session_token;
}

int main() {
    // Generate a CSRF token and store it in a session (simulated)
    std::string session_token = generate_csrf_token();
    std::cout << "Session Token: " << session_token << std::endl;

    // Simulate a request with a CSRF token
    std::string request_token = session_token; 

    // Verify the token
    if (verify_csrf_token(request_token, session_token)) {
        std::cout << "CSRF token is valid.
";
    } else {
        std::cout << "CSRF token is invalid!
";
    }

    return 0;
}