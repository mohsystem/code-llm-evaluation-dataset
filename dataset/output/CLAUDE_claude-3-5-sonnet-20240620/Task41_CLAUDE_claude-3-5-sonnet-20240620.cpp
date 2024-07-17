
#include <iostream>
#include <string>
#include <algorithm>

void processString(std::string &str) {
    std::transform(str.begin(), str.end(), str.begin(),
                   [](unsigned char c){ return std::toupper(c); });
}

int main() {
    std::string input;
    std::cout << "Enter a string: ";
    std::getline(std::cin, input);

    processString(input);
    std::cout << "Processed string: " << input << std::endl;

    return 0;
}
