#include <iostream>
#include <string>

bool solution(const std::string& str, const std::string& ending) {
    if (str.length() >= ending.length()) {
        return (0 == str.compare (str.length() - ending.length(), ending.length(), ending));
    } else {
        return false;
    }
}

int main() {
    std::cout << solution("abc", "bc") << std::endl;  // returns true
    std::cout << solution("abc", "d") << std::endl;   // returns false
    return 0;
}