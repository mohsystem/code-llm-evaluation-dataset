#include <iostream>
#include <string>

int main() {
    std::string input = "HelloWorld";
    int shift = 3;
    std::string encrypted;
    
    for (char c : input) {
        if (std::isalpha(c)) {
            char base = std::islower(c) ? 'a' : 'A';
            encrypted += (c - base + shift) % 26 + base;
        } else {
            encrypted += c;
        }
    }
    
    std::cout << "C++: " << encrypted << std::endl;
    
    return 0;
}
main();