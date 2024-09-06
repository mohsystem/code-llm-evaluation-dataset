#include <iostream>
#include <cstdlib>
#include <cctype>

int main(int argc, char *argv[]) {
    if (argc < 2) {
        std::cout << "Please provide a string to convert." << std::endl;
    } else {
        const char* inputStr = argv[1];
        int convertedInt;
        try {
            convertedInt = std::stoi(inputStr);
            std::cout << "Converted integer: " << convertedInt << std::endl;
        } catch (std::invalid_argument &) {
            std::cout << "Invalid input: Not a valid integer." << std::endl;
        }
    }
    return 0;
}