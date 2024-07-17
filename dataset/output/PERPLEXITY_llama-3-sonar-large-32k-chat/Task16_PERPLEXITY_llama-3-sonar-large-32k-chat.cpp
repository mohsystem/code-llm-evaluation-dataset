#include <string>
#include <iostream>

bool solution(std::string str1, std::string str2) {
    return str1.size() >= str2.size() && str1.substr(str1.size() - str2.size()) == str2;
}

int main() {
    std::cout << std::boolalpha << solution("abc", "bc") << std::endl; // returns true
    std::cout << std::boolalpha << solution("abc", "d") << std::endl; // returns false
    return 0;
}