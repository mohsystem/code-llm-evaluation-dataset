#include <iostream>
#include <string>

int main() {
    int n;
    std::cout << "Enter the number of strings: ";
    std::cin >> n;
    std::string result;
    for (int i = 0; i < n; i++) {
        std::cout << "Enter string " << (i + 1) << ": ";
        std::string str;
        std::cin >> str;
        result += str;
    }
    std::cout << "Concatenated string: " << result << std::endl;
    return 0;
}