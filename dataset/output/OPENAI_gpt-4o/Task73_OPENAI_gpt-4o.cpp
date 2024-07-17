#include <iostream>
#include <cstring>

void runCPPPasswordCheck(const char* password) {
    if (strcmp(password, "admin123") == 0) {
        std::cout << "C++: Password is valid." << std::endl;
    } else {
        std::cout << "C++: Password is invalid." << std::endl;
    }
}