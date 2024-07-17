#include <iostream>
#include <vector>

std::vector<std::string> number(const std::vector<std::string>& lines) {
    std::vector<std::string> numberedLines;
    for (int i = 0; i < lines.size(); ++i) {
        numberedLines.push_back(std::to_string(i + 1) + ": " + lines[i]);
    }
    return numberedLines;
}

int main() {
    std::vector<std::string> input = {"a", "b", "c"};
    std::vector<std::string> result = number(input);
    for (const auto& line : result) {
        std::cout << line << std::endl;
    }
    return 0;
}