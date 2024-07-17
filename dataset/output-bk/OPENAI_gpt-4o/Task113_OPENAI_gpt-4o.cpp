#include <iostream>
#include <string>

int main() {
    int n;
    std::string result, str;
    
    std::cout << "Enter number of strings to concatenate:" << std::endl;
    std::cin >> n;
    std::cin.ignore(); // Consume the newline

    for(int i = 0; i < n; i++) {
        std::cout << "Enter string " << (i + 1) << ":" << std::endl;
        std::getline(std::cin, str);
        result += str;
    }

    std::cout << "Concatenated string: " << result << std::endl;
    return 0;
}