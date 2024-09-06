#include <iostream>
#include <algorithm> 
#include <string>

int main() {
    std::string input_str;
    std::cin >> input_str;
    std::reverse(input_str.begin(), input_str.end());
    std::cout << input_str << std::endl;
    return 0;
}