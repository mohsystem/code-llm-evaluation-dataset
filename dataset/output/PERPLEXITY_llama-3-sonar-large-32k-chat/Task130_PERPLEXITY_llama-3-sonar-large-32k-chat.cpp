code here:
#include <iostream>
#include <string>
#include <cgi.h>

int main() {
    std::string origin = getenv("HTTP_ORIGIN");
    if (!origin.empty()) {
        std::cout << "Access-Control-Allow-Origin: " << origin << std::endl;
        std::cout << "Access-Control-Allow-Headers: Content-Type, Authorization" << std::endl;
        std::cout << "Access-Control-Allow-Methods: GET, PUT, POST, DELETE, OPTIONS" << std::endl;
    }
    std::cout << "Content-Type: application/json" << std::endl << std::endl;
    std::cout << "{\"data\": \"Hello, World.\"}" << std::endl;
    return 0;
}