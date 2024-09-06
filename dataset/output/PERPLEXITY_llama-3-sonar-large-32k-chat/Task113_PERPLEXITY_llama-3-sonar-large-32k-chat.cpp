#include <iostream>
#include <string>

int main() {
    int numStrings;
    std::cout << "Enter the number of strings: ";
    std::cin >> numStrings;
    std::string result = "";
    for (int i = 0; i < numStrings; i++) {
        std::string temp;
        std::cout << "Enter string " << (i + 1) << ": ";
        std::cin >> temp;
        result += temp + " ";
    }
    std::cout << "Concatenated string: " << result << std::endl;
    return 0;
}