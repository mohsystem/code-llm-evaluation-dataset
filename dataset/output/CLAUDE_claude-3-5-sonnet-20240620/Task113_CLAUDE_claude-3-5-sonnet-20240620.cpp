
#include <iostream>
#include <string>
#include <vector>

int main() {
    std::vector<std::string> strings;
    std::string s;

    while (true) {
        std::cout << "Enter a string (or press Enter to finish): ";
        std::getline(std::cin, s);
        if (s.empty()) {
            break;
        }
        strings.push_back(s);
    }

    std::string result;
    for (const auto& str : strings) {
        if (!result.empty()) {
            result += " ";
        }
        result += str;
    }

    std::cout << "Concatenated string: " << result << std::endl;

    return 0;
}
