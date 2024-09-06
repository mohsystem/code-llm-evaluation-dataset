
#include <iostream>
#include <string>
#include <algorithm>

void processInput(const std::string& input) {
    // Process the input (example: print it back)
    std::cout << "Processed input: " << input << std::endl;
}

int main() {
    std::string userInput;
    std::cout << "Enter a string (max 100 characters): ";
    
    // Read input
    std::getline(std::cin, userInput);
    
    // Limit input to 100 characters
    userInput = userInput.substr(0, 100);
    
    processInput(userInput);
    return 0;
}
