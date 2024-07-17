#include <iostream>
#include <vector>

std::vector<std::string> number(const std::vector<std::string>& lines) {
    std::vector<std::string> result;
    for (size_t i = 0; i < lines.size(); ++i) {
        result.push_back(std::to_string(i + 1) + ": " + lines[i]);
    }
    return result;
}

int main() {
    std::vector<std::string> lines = {"a", "b", "c"};
    std::vector<std::string> numbered_lines = number(lines);
    for (const auto &line : numbered_lines) {
        std::cout << line << std::endl;
    }
    return 0;
}