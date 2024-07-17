#include <iostream>
#include <vector>
#include <string>

std::vector<std::string> numberLines(std::vector<std::string>& lines) {
    for (int i = 0; i < lines.size(); i++) {
        lines[i] = std::to_string(i + 1) + ": " + lines[i];
    }
    return lines;
}

int main() {
    std::vector<std::string> lines = {"a", "b", "c"};
    for (const auto& line : numberLines(lines)) {
        std::cout << line << std::endl;
    }
    return 0;
}