// C++
#include <iostream>
#include <string>

void processString(std::string inputString) {
    // Process the string here
    std::cout << "Processed string: " << inputString << std::endl;
}

int main() {
    std::string inputString;
    std::cout << "Enter a string: ";
    std::getline(std::cin, inputString);
    processString(inputString);
    return 0;
}

// C++ is safe from buffer overflow as it uses std::string which is a dynamic array and handles memory management automatically